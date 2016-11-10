#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>

Bullet::Bullet()
{
    setRect(0,0,2,15);//the bullet
    QTimer *timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));//does movement based on a timer
        timer->start(50);

}




