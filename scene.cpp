#include <QTimer>
#include <QMainWindow>
#include <QDebug>
#include "asteroids.h"
#include "scene.h"
#include "ship.h"
#include "mainwindow.h"


// scene simulates landscape
Scene::Scene() : QGraphicsScene()//constructor
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

void Scene::addShip(){//draws ship(
    s= new Ship((dw.width()*0.8)/2 , (dw.height()*0.8)/2);
    addItem(s);
    s->setFlag(QGraphicsItem::ItemIsFocusable);
    s->setFocus();//Sets focus on s, so it can be moved by player

}
void Scene::addAsteroid(){//draws asteroid
    int coord_x = rand()%dw.width()*0.8;
    int coord_y = rand()%dw.height()*0.8;
    Asteroid * ast = new Asteroid;
    ast->setPos(coord_x, coord_y);
    addItem(ast);
    roids.append(ast);
    ast->move();
    /*for(int i = 0; i<roids.length()-1; i++){
        if(collidesWith(roids[i], s)){
            roids.removeAt(i);
            removeItem(roids[i]);
            removeItem(s);
        }
    }*/
}
bool Scene::collidesWith(QGraphicsItem* item_x, QGraphicsItem* item_y){
    bool collision = item_x->collidesWithItem(item_y);
    return collision;
}
