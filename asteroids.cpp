#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QTimer>
#include <QObject>
//Necesarry Header files
#include "list.h"
#include "asteroids.h"

/*************************************************************************************/

/******************* Represents an asteroid in the simulation ********************/

/*************************************************************************************/
Asteroid::Asteroid(){}
Asteroid::Asteroid(qreal x, qreal y) : QObject(),QGraphicsItem() {//draws asteroid then moves on a timer
    setPos(x, y);
    xbounds=dw.width()*0.8;
    ybounds=dw.height()*0.8;
    QTimer *times = new QTimer();//checks for movement of asteroid based on time
    connect(times,SIGNAL(timeout()),this,SLOT(move()));
    times->start(50);
}

void  Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  // paint asteroid, must be smaller than bounding rectangle
    painter->setRenderHint( QPainter::Antialiasing );
    painter->setPen( QPen( Qt::red, 2 ) );
    painter->drawEllipse(0,0,100,100);
}
