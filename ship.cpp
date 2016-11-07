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
      setPos(x()-10,y());
  }
  else if(event->key() == Qt::Key_Right){
      setPos(x()+10,y());
  }
  else if(event->key() == Qt::Key_Up){
      setPos(x(),y()-10);
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

