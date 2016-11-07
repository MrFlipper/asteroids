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
  if(event->key() == Qt::Key_Left){//rotates left by subracting from rotation angle
      if(rotation == 0) rotation = 360;
      setRotation(rotation -= 10);

  }
  else if(event->key() == Qt::Key_Right){//rotates right by adding to rotation angle
     if(rotation == 360) rotation = 0;
      setRotation(rotation += 10);
  }
  else if(event->key() == Qt::Key_Up){
      setPos(x()+ sin(rotation*(3.141592654/180))*5,y()- cos(rotation*(3.141592654/180))*5);//moves ship relative to angle of rotation
      //These if statements puts the ship on the opposite side of the screen should it go off screen
      if (pos(),x() >= xbounds/2) setPos(xbounds/2 - xbounds,y());
      else if (pos(),x() <= (xbounds/2 - xbounds)) setPos(xbounds/2,y());
      if (pos(),y() >= ybounds/2) setPos(x(),ybounds/2 - ybounds);
      else if (pos(),y() <= (ybounds/2 - ybounds)) setPos(x(),ybounds/2);
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



