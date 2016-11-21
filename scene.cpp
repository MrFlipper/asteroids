#include <QTimer>
#include <QMainWindow>
#include <QDebug>
#include <QKeyEvent>
#include "asteroids.h"
#include "scene.h"
#include "ship.h"
#include "mainwindow.h"


// scene simulates landscape

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
  timer->start(33.33);
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
    //Create new Asteroid named "ast"
    Asteroid * ast = new Asteroid;

    // Set coordinates of asteroid to random position
    int coord_x = rand()%dw.width()*0.8;
    int coord_y = rand()%dw.height()*0.8;
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
        if(rotation == 0) rotation = 360;
        s->setRotation(rotation -= 30);
    }

    //rotates right by adding to rotation angle
    else if(event->key() == Qt::Key_Right){
        if(rotation == 360) rotation = 0;
            s->setRotation(rotation += 30);
    }

    //moves ship relative to angle of rotation
    else if(event->key() == Qt::Key_Up){
        s->xaccel += 2*sin(rotation*(3.141592654/180));
        s->yaccel += 2*cos(rotation*(3.141592654/180));
        //limits ship speed
        if (s->xaccel > 15) s->xaccel = 15;
        if (s->yaccel > 15) s->yaccel = 15;
        if (s->xaccel < -15) s->xaccel = -15;
        if (s->yaccel < -15) s->yaccel = -15;
    }

    //shoots bullet from ship
    else if(event->key() == Qt::Key_Space){

        //If there is less than 15 bullets on screen add one.
        if(bullets.length()<15){
            //Create new bullet
            Bullet * bull = new Bullet();

            //Set Position of the Bullet to match orientation of the ship
            bull->setPos(s->x() + (cos(rotation*(3.141592654/180))) , s->y() + (sin(rotation*(3.141592654/180))));
            bull->angle = rotation;
            bull->setRotation(rotation);

            //Add bullet to scene and list of bullets
            addItem(bull);
            bullets.append(bull);
        }

        //Check if bullets are on the screen, then check if they are out of bounds, if they are delete them.
        if(not bullets.isEmpty()){
            for(int i = 0;i<bullets.length()-1; i++){
               if(bullets[i]->outOfBounds == true)
                   bullets.removeAt(i);
            }
        }
    }
}

/***** Checks for collision between ship and asteroids ******/
void Scene::collidesWith(){
    for(int i = 0; i<roids.length()-1; i++){
        if(s->x() == roids[i]->x() && s->y() == roids[i]->y()){
            removeItem(s);
            removeItem(roids[i]);
            roids.removeAt(i);
        }
    }
}
