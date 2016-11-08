
#include "scene.h"
#include "ship.h"
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "asteroids.h"

/*************************************************************************************/
/******************** Scene representing the simulated landscape *********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

Scene::Scene() : QGraphicsScene()
{
  // create invisible item to provide default top-left anchor to scene
  addLine( 0, 0, 0, 1, QPen(Qt::transparent, 1) );
  drawShip();
  drawAsteroid();
  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(update()));
  timer->start(1);
}
void Scene::drawShip(){//draws ship
    s= new Ship(0 , 0);
    addItem(s);
    s->setFlag(QGraphicsItem::ItemIsFocusable);
    s->setFocus();//Sets focus on s, so it can be moved
}
void Scene::drawAsteroid(){
        addItem( new Asteroid(1, 100));
}
