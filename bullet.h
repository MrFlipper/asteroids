#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QDesktopWidget>
#include <QtMath>
//class for the bullet

class Bullet: public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
    public:
        Bullet();
        int  angle; //angle of bullet
        QDesktopWidget dw; //Bounds of the screen
        bool outOfBounds;
        void paint(QPainter*, const QStyleOptionGraphicsItem *option, QWidget *widget);// implement virtual paint function
        QRectF   boundingRect() const
            {return QRectF(0, 0, 0, 0);}//bounding rectangle allowing no screen movement
    public slots:
        void move();
};
#endif // BULLET_H
