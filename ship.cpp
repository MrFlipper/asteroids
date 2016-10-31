#include "ship.h"

#include <QPainter>

/*************************************************************************************/
/******************* Represents a ship in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

Ship::Ship( qreal x, qreal y ) : QGraphicsItem()
{
  // set Ship pixmap and position
  setPos( x, y );
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

