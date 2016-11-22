/*************************************************************************************/

/******************* Represents the scene of the simulation **************************/

/*************************************************************************************/
#include <QTimer>
#include <QMainWindow>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGlobal>

#include "asteroids.h"
#include "scene.h"
#include "ship.h"
#include "mainwindow.h"

/****** Constructor ******/
Scene::Scene() : QGraphicsScene()
{
  // create invisible item to provide default top-left anchor to scene
  addLine( 0, 0, 0, 1, QPen(Qt::transparent, 1) );
  addShip();
  for(int i = 0;i<5;i++)
    addAsteroid();
  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(update()));//refreshes screen on a timer
  timer->start(50);

  QTimer * time = new QTimer();
  connect(time,SIGNAL(timeout()),this,SLOT(collidesWith()));//refreshes screen on a timer
  time->start(50);

}

/***** Adds ship to the scene *****/
void Scene::addShip(){
    // Create new ship in center of screen
    s= new Ship((dw.width()*0.8)/2 , (dw.height()*0.8)/2);

    // Add ship to the scene
    addItem(s);

    // Make it possible for user focus to be on ship
    s->setFlag(QGraphicsItem::ItemIsFocusable);

    //Sets focus on s, so it can be moved by player
    s->setFocus();
}

/***** Creates an asteroid and adds it to the scene *****/
void Scene::addAsteroid(){
    int coord_x, coord_y;
    //Create new Asteroid named "ast"
    Asteroid * ast = new Asteroid;
    // Set coordinates of asteroid to random position
    int zero = rand()%2-1;
    if(zero == 1){
        coord_x = rand()%dw.width()*0.8;
        coord_y = 0;

    }
    else{
        coord_x = 0;
        coord_y = rand()%dw.height()*0.8;
    }

    ast->setPos(coord_x, coord_y);

    //Add Asteroid to scene and list
    addItem(ast);
    roids.append(ast);

}

/********* Controls Ship by checking if certain keys have been pressed **********/
void Scene::keyPressEvent(QKeyEvent *event)
{
    //rotates left by subracting from rotation angle
    if(event->key() == Qt::Key_Left){
        if(s->rotation == 0) s->rotation = 360;
        s->setRotation(s->rotation -= 30);
    }

    //rotates right by adding to rotation angle
    else if(event->key() == Qt::Key_Right){
        if(s->rotation == 360) s->rotation = 0;
            s->setRotation(s->rotation += 30);
    }

    //moves ship relative to angle of rotation
    else if(event->key() == Qt::Key_Up){
        s->xaccel += 2*sin(s->rotation*(3.141592654/180));
        s->yaccel += 2*cos(s->rotation*(3.141592654/180));
        //limits ship speed
        if (s->xaccel > 15) s->xaccel = 15;
        if (s->yaccel > 15) s->yaccel = 15;
        if (s->xaccel < -15) s->xaccel = -15;
        if (s->yaccel < -15) s->yaccel = -15;
    }
    else if(event->key() == Qt::Key_Down){
        int dist = (qAbs(s->x() - roids[0]->x()) + qAbs(s->y() - roids[0]->y()));
        qDebug() << "Estimated Distance: " << dist<< endl<<roids.length();
    }
    //shoots bullet from ship
    else if(event->key() == Qt::Key_Space){

        //If there is less than 15 bullets on screen add one.
        if(bullets.length()<15){

            //Create new bullet
            Bullet * bull = new Bullet();

            //Set Position of the Bullet to match orientation of the ship
            bull->setPos(s->x() + (cos(s->rotation*(3.141592654/180))) , s->y() + (sin(s->rotation*(3.141592654/180))));
            bull->angle = s->rotation;
            bull->setRotation(s->rotation);

            //Add bullet to scene and list of bullets
            addItem(bull);
            bullets.append(bull);
        }

        //Check if bullets are on the screen, then check if they are out of bounds, if they are delete them.
        if(not bullets.isEmpty()){
            for(int i = 0;i<bullets.length()-1; i++){
               if(bullets[i]->outOfBounds == true){
                   delete bullets[i];
                   bullets.removeAt(i);
               }
            }
        }
    }
}

/***** Checks for collision between ship, bullets, and asteroids ******/
void Scene::collidesWith(){
    int dist;
    //Check if asteroids are on screen
    if(not roids.isEmpty()){
        for(int i = 0; i<=roids.length()-1;i++){
            //Estimate distance between ship and asteroids
            dist = (qAbs(s->x() - roids[i]->x()) + qAbs(s->y() - roids[i]->y()))/2;
            //If estimated distance is less than 42 delete ship and asteroid
            if(dist<42 and s->dead == false){
                s->dead=true;
                removeItem(s);
                removeItem(roids[i]);
                roids.removeAt(i);
                return;
            }
            //Check if list of bullets arent empty
            if(not bullets.isEmpty()){
                for(int j = 0; j<=bullets.length()-1; j++){
                    //Estimate distance between bullet and asteroids
                    dist=(qAbs(bullets[j]->x()-roids[i]->x()) + qAbs(bullets[j]->y()-roids[i]->y()))/2;
                    //If distance is less than 42 delete bullet and asteroid
                    if(dist<42){
                        bullets[j]->collided = true;
                        removeItem(bullets[j]);
                        bullets.removeAt(j);

                        roids[i]->hit = true;
                        removeItem(roids[i]);
                        if(roids[i]->size == 1)
                            roids.removeAt(i);
                        else{
                            //splitAsteroid(roids[i]->size);
                            roids.removeAt(i);
                        }
                    }
                }
            }
        }
    }
    // If no asteroids on screen, add 5 more
    else{
        for(int i = 0; i<5; i++)
            addAsteroid();
    }
}

/****** Checks size of asteroid then splits or destroys accordingly ******/
/*void splitAsteroid(int size){
    qDebug()<<"Split!";
}*/
