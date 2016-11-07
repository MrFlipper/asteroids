#include "ship.h"
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>
/*************************************************************************************/
/******************* Represents a ship in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

Ship::Ship( qreal x, qreal y ) : QGraphicsItem()
{
  // set Ship pixmap and position
    setPos( x, y );
}

void Ship::keyPressEvent(QKeyEvent *event)
{
  if(event->key() == Qt::Key_Left){
      if(rotation == 0) rotation = 360;
      setRotation(rotation -= 10);

  }
  else if(event->key() == Qt::Key_Right){
      setRotation(rotation += 10);
      if(rotation == 360) rotation = 0;
  }
  else if(event->key() == Qt::Key_Up){
      setPos(x()+cos(rotation),y()+sin(rotation));
      //as you can see, I try to use sin and cos since it rotates like a circle, but results are strange.
  }
  else if(event->key() == Qt::Key_Down){
      setPos(x(),y()+10);
  }
}

/************************************** paint ****************************************/

void  Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // paint ship symbol, must be smaller than bounding rectangle
  painter->setRenderHint( QPainter::Antialiasing );
  painter->setPen( QPen( Qt::black, 2 ) );
    painter->drawLine(  -8,  0,  8, 0 );
    painter->drawLine( -8, 0,  0,  -18 );
    painter->drawLine( 8, 0, 0,  -18 );
}



