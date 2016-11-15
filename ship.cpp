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

        //Set Position of the Bullet to match orientation of the ship
        if(rotation == 0 or rotation == 360)
            bull->setPos(x()+14,y());
        if(rotation == 30)
            bull->setPos(x()+13,y()+6);
        if(rotation == 60)
            bull->setPos(x()+14, y()+10);
        if(rotation == 90)
            bull->setPos(x(), y()+14);
        if(rotation == 120)
            bull->setPos(x()-6, y()+13);
        if(rotation == 150)
            bull->setPos(x()-10,y()+14);
        if(rotation == 180)
            bull->setPos(x()-14,y());
        if(rotation == 210)
            bull->setPos(x()-13,y()-6);
        if(rotation == 240)
            bull->setPos(x()-14,y()-10);
        if(rotation == 270)
            bull->setPos(x(),y()-14);
        if(rotation == 300)
            bull->setPos(x()+6,y()-13);
        if(rotation == 330)
            bull->setPos(x()+10,y()-14);
        //End Bullet Position

        bull->angle = rotation;
        bull->setRotation(rotation);
        if(bullets.length()<10){
            scene()->addItem(bull);
            bullets.append(bull);
        }
        if(not bullets.isEmpty()){
            for(int i = 0;i<bullets.length(); i++){
                if(bullets[i]->x()>xbounds/2 or bullets[i]->x()<((xbounds/2)*-1) or bullets[i]->y()>ybounds/2 or bullets[i]->y()<((ybounds/2)*-1)){
                    bullets.removeAt(i);
                    scene()->removeItem(bullets[i]);
                }
            }
        }
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
//    QPainterPath path;
//    painter->setRenderHint( QPainter::Antialiasing );
//    painter->setPen( QPen( Qt::white, 2 ) );
//    painter->drawLine(  -8,  0,  8, 0 );
//    painter->drawLine( -8, 0,  0,  -18 );
//    painter->drawLine( 8, 0, 0,  -18 );
//    painter->fillPath (path, QBrush (QColor ("white")));
    QRectF rect = QRectF(0, 0, 30, 30);

    QPainterPath path;
    path.moveTo(rect.left() + (rect.width() / 2), rect.top());
    path.lineTo(rect.bottomLeft());
    path.lineTo(rect.bottomRight());
    path.lineTo(rect.left() + (rect.width() / 2), rect.top());

    painter->fillPath(path, QBrush(QColor ("white")));
}



