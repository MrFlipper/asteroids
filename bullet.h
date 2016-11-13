#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
//class for the bullet

class Bullet: public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
    public:
        Bullet();
        QRectF   boundingRect() const
        { return QRectF(0, 0, 0, 0);//bounding rectangle allowing no screen movement
        }

    public slots:
        void move()//controls movement of bullet
        {
            setPos(x(),y()-10);
        }
};
#endif // BULLET_H
