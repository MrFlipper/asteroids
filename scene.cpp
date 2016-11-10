#include "asteroids.h"
#include "scene.h"
#include "ship.h"
#include <QTimer>

// scene simulates landscape

Scene::Scene() : QGraphicsScene()//constructor
{
  // create invisible item to provide default top-left anchor to scene
  addLine( 0, 0, 0, 1, QPen(Qt::transparent, 1) );
  drawShip();
  drawAsteroid();
  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(update()));//refreshes screen on a timer
  timer->start(33.33);
}
void Scene::drawShip(){//draws ship
    s= new Ship(0 , 0);
    addItem(s);
    s->setFlag(QGraphicsItem::ItemIsFocusable);
    s->setFocus();//Sets focus on s, so it can be moved by player
}
void Scene::drawAsteroid(){//draws asteroid
        addItem( new Asteroid(1, 100));
}
