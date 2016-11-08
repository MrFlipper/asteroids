#include "asteroids.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>
/*************************************************************************************/

/******************* Represents a ship in the simulation ********************/

/*************************************************************************************/
Asteroid::Asteroid(){}
Asteroid::Asteroid(qreal x, qreal y) : QObject(),QGraphicsItem() {
    setPos(x, y);
    xbounds=dw.width()*0.8;
    ybounds=dw.height()*0.8;
    QTimer *times = new QTimer();
    connect(times,SIGNAL(timeout()),this,SLOT(change()));
    times->start(50);
}

void  Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  // paint ship symbol, must be smaller than bounding rectangle
    painter->setRenderHint( QPainter::Antialiasing );
    painter->setPen( QPen( Qt::red, 2 ) );
    painter->drawEllipse(0,0,100,100);
}

