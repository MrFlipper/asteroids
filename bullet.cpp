#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QPainter>
#include "bullet.h"
Bullet::Bullet()
{
    QTimer *timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));//does movement based on a timer
        timer->start(50);

}
void Bullet::move()//controls movement of bullet
{
    setPos(x() + 20*sin(angle*(3.141592654/180)),y()- 20*cos(angle*(3.141592654/180)));
}
void Bullet::paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget){// implement virtual paint function
    painter->setPen( QPen( Qt::white, 2 ) );
    painter->drawRect(0,0,2,15);//the bullet
}

