/*************************************************************************************/

/******************* Represents an asteroid in the simulation ********************/

/*************************************************************************************/

#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QTimer>
#include <QObject>
#include "asteroids.h"
#include "scene.h"

/****** Constructor ******/
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

/***** Moves the asteroid in a randomly decided angle and velocity *****/
void Asteroid::move(){

    //Set the position of the asteroid
    setPos(x()-x_move,y()-y_move);

    //wraps asteroid around if it goes off screen
    if (x() >= xbounds)
        setPos(x() - xbounds,y());
    else if (x() <= 0)
        setPos(x()+xbounds,y());
    if (y() >= ybounds)
        setPos(x(),y() - ybounds);
    else if (y() <= 0)
        setPos(x(),y()+ybounds);
}

//Sets the angle that the asteroids move and how fast they move
void Asteroid::setAngle(int& x, int& y){   
    x = rand()%20-10;
    y = rand()%20-10;
}
