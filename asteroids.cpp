/*************************************************************************************/

/******************* Represents an asteroid in the simulation ********************/

/*************************************************************************************/

#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QTimer>
#include <QObject>
#include "asteroids.h"


Asteroid::Asteroid(){
    xbounds=dw.width()*0.8;
    ybounds=dw.height()*0.8;
    setAngle(x_move, y_move);
    QTimer *times = new QTimer();//checks for movement of asteroid based on time
    connect(times,SIGNAL(timeout()),this,SLOT(move()));
    times->start(50);
}

void  Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  // paint asteroid, must be smaller than bounding rectangle
    painter->setRenderHint( QPainter::Antialiasing );
    painter->setPen( QPen( Qt::white, 2 ) );
    painter->drawEllipse(0,0,100,100);
}

void Asteroid::move(){//changes position on a timer
    //int x_move,y_move;
    //setAngle(x_move,y_move);
    setPos(x()-x_move,y()-y_move);
    //wraps asteroid around if it goes off screen
    if (pos(),x() >= xbounds/2)
        setPos(xbounds/2 - xbounds,y());
    else if (pos(),x() <= (xbounds/2 - xbounds))
        setPos(xbounds/2,y());
    if (pos(),y() >= ybounds/2)
        setPos(x(),ybounds/2 - ybounds);
    else if (pos(),y() <= (ybounds/2 - ybounds))
        setPos(x(),ybounds/2);
}

void Asteroid::setAngle(int& x, int& y){
    int x_move = rand()%2; //Checks if X-coordinate should change
    int y_move = rand()%2; //Checks if Y-Coordinate should change
    x = 0; //Dictates how drastically X-coordinate should change
    y = 0; //Dictates how drastically Y-coordinate should change
    if(x_move==1)
        x = 10;
    x_move = rand()%2; //Reroll to decide if X should move in positive or negative direction
    if(x_move==1)
        x *=-1;
    if(y_move==1)
        y = 10;
    y_move = rand()%2; //Reroll to decide if Y should move in positive or negative direction
    if(y_move==1)
        y *= -1;
}
