#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>

Bullet::Bullet()
{
    setRect(0,0,2,15);
    QTimer *timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(50);

}




