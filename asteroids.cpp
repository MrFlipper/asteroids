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

void Asteroid::move(){
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

//    if(not roids.isEmpty()){
//        for(int i=0; i<roids.length()-1; i++){
//            if(roids[i]->collidesWithItem(s)){
//                removeItem(s);
//                roids.removeAt(i);
//                removeItem(roids[i]);
//                //qDebug() << "Collision!!" ;
//            }
//        }
//    }
}

void Asteroid::setAngle(int& x, int& y){
    x = rand()%20-10; //Checks if X-coordinate should change
    y = rand()%20-10; //Checks if Y-Coordinate should change
}
