#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QPainter>
#include <typeinfo>
#include "scene.h"
#include "bullet.h"
#include "asteroids.h"

/****** Constructor ******/
Bullet::Bullet()
{

    setRect(0,0,2,15);
    //setRect(0,0,2,15);
    outOfBounds=false;
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//does movement based on a timer
    timer->start(50);

}

/****** controls movement of bullet ******/
void Bullet::move()
{
    //Check if Bullet collides with asteroids
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Asteroid)){
            //Remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //Delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //Check if bullet is off screen and deletes it if it is
    if(x() >= dw.width()*0.8 or x() <= 0 or y() >= dw.height()*0.8 or y() <= 0){
        outOfBounds = true;
        scene()->removeItem(this);
        delete this;
        return;
    }
    //Move the bullet with respect to its angle
    setPos(x() + 20*sin(angle*(3.141592654/180)),y()- 20*cos(angle*(3.141592654/180)));

}
void Bullet::paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget){// implement virtual paint function
    painter->setPen( QPen( Qt::white, 2 ) );
    painter->drawRect(0,0,2,15);//the bullet
}

