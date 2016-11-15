#include "ship.h"
#include "scene.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QtMath>
/*************************************************************************************/
/******************* Represents a ship in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

Ship::Ship( qreal x, qreal y ) : QGraphicsItem()
{
  // set Ship pixmap and position
    setPos( x, y );
    rotation = 0; //represents rotation angle
    //represents ship speed
    xaccel = 0;
    yaccel = 0;
    //sets boundaries of ship
    xbounds=dw.width()*0.8;
    ybounds=dw.height()*0.8;
    QTimer *times = new QTimer();//moves ship based on time
    connect(times,SIGNAL(timeout()),this,SLOT(move()));
    times->start(50);
}

void Ship::keyPressEvent(QKeyEvent *event)//controls ship by key presses
{
    if(event->key() == Qt::Key_Left){//rotates left by subracting from rotation angle
        if(rotation == 0) rotation = 360;
        setRotation(rotation -= 30);
    }
    else if(event->key() == Qt::Key_Right){//rotates right by adding to rotation angle
        if(rotation == 360) rotation = 0;
            setRotation(rotation += 30);
  }
    else if(event->key() == Qt::Key_Up){//moves ship relative to angle of rotation
        xaccel += sin(rotation*(3.141592654/180));
        yaccel += cos(rotation*(3.141592654/180));
        //limits ship speed
        if (xaccel > 10) xaccel = 10;
        if (yaccel > 10) yaccel = 10;
        if (xaccel < -10) xaccel = -10;
        if (yaccel < -10) yaccel = -10;
    }
    else if(event->key() == Qt::Key_Space){//shoots bullet from ship (only moves up for now)
        Bullet * bull = new Bullet();
        bull->setPos(x(),y());
        bull->angle = rotation;
        bull->setRotation(rotation);
        scene()->addItem(bull);
        bullets.append(bull);
    }
}

void Ship::move(){
    if((xaccel > 0 || yaccel > 0) || (xaccel < 0 || yaccel < 0)){
        setPos(x()+xaccel,y()-yaccel);
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
}

void  Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // paint ship symbol, must be smaller than bounding rectangle
    painter->setRenderHint( QPainter::Antialiasing );
    painter->setPen( QPen( Qt::black, 2 ) );
    painter->drawLine(  -8,  0,  8, 0 );
    painter->drawLine( -8, 0,  0,  -18 );
    painter->drawLine( 8, 0, 0,  -18 );
}



