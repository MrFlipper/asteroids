
#include "scene.h"
#include "ship.h"

#include <QGraphicsSceneMouseEvent>

/*************************************************************************************/
/******************** Scene representing the simulated landscape *********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

Scene::Scene() : QGraphicsScene()
{
  // create invisible item to provide default top-left anchor to scene
  addLine( 0, 0, 0, 1, QPen(Qt::transparent, 1) );
  drawShip();
}

/********************************** mousePressEvent **********************************/

void  Scene::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
  // only interested if left mouse button pressed
  if ( event->button() != Qt::LeftButton ) return;

  // create new Ship at point where user clicked scene
  qreal  x = event->scenePos().x();
  qreal  y = event->scenePos().y();
  addItem( new Ship( x, y ) );

  // emit informative message
  emit message( QString("Ship add at %1,%2").arg(x).arg(y) );
}
void Scene::drawShip(){//draws ship
addItem( new Ship(0,0));
}

