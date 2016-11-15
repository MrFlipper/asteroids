#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QtMath>
//class for the bullet

class Bullet: public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
    public:
        Bullet();
        int  angle; //angle of bullet
        QRectF   boundingRect() const
        { return QRectF(0, 0, 0, 0);//bounding rectangle allowing no screen movement
        }

    public slots:
        void move()//controls movement of bullet
        {
            setPos(x() + 10*sin(angle*(3.141592654/180)),y()- 10*cos(angle*(3.141592654/180)));
        }
};
#endif // BULLET_H
