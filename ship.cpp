/*************************************************************************************/
/******************* Represents a ship in the simulation *****************************/
/*************************************************************************************/

#include <QKeyEvent>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QtMath>
#include "ship.h"
#include "scene.h"
#include "bullet.h"
#include "asteroids.h"

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

/***************Controls Ship by checking if certain keys have been pressed**********/

void Ship::keyPressEvent(QKeyEvent *event)
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
        xaccel += 2*sin(rotation*(3.141592654/180));
        yaccel += 2*cos(rotation*(3.141592654/180));
        //limits ship speed
        if (xaccel > 15) xaccel = 15;
        if (yaccel > 15) yaccel = 15;
        if (xaccel < -15) xaccel = -15;
        if (yaccel < -15) yaccel = -15;
    }
    else if(event->key() == Qt::Key_Down){
        if(not bullets.isEmpty()){
            scene()->removeItem(bullets[0]);
            bullets.removeFirst();
        }
    }
    else if(event->key() == Qt::Key_Space){//shoots bullet from ship
        //Set Position of the Bullet to match orientation of the ship
        if(bullets.length()<15){
            Bullet * bull = new Bullet();
            bull->setPos(x() + (cos(rotation*(3.141592654/180))) , y() + (sin(rotation*(3.141592654/180))));
            bull->angle = rotation;
            bull->setRotation(rotation);
            scene()->addItem(bull);
            bullets.append(bull);

        }
        //Check if bullets are on the screen, then check if they are out of bounds, if they are delete them.
        if(not bullets.isEmpty()){
            for(int i = 0;i<bullets.length()-1; i++){
                if(bullets[i]->x() >= xbounds or bullets[i]->x() <= 0
                        or bullets[i]->y() >= ybounds or bullets[i]->y()<=0){
                    bullets.removeAt(i);
                    scene()->removeItem(bullets[i]);
                }
                /*for(int j = 0; j<Scene().roids.length();j++){
                    if(bullets[i]->collidesWithItem(Scene().roids[j])){
                        bullets.removeAt(i);
                        scene()->removeItem(bullets[i]);
                        scene()->removeItem(Scene().roids[j]);
                    }
                }*/
            }
        }
    }
}
void Ship::move(){
    setFocus();
    if((xaccel > 0 || yaccel > 0) || (xaccel < 0 || yaccel < 0)){
        setPos(x()+xaccel,y()-yaccel);
        //wraps asteroid around if it goes off screen
        if (x() >= xbounds)
           setPos(x() - xbounds,y());
        else if (x() <= 0)
           setPos(x() + xbounds,y());
        if (y() >= ybounds)
           setPos(x(),y() - ybounds);
        else if (y() <= 0)
           setPos(x(), y() + ybounds);
    }
}
void  Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   //Creates a ship by drawing a rectangle and tracing a path
        //May create a bounds issue later when dealing with collisions (Untested)
    QRectF rect = QRectF(-10, -15, 25, 30);
    QPainterPath path;
    path.moveTo(rect.left() + (rect.width() / 2), rect.top());
    path.lineTo(rect.bottomLeft());
    path.lineTo(rect.bottomRight());
    path.lineTo(rect.left() + (rect.width() / 2), rect.top());
    painter->fillPath(path, QBrush(QColor ("white")));
}



