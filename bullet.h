#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QDesktopWidget>
#include <QtMath>

/****** Class for the bullet ******/
class Bullet: public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
    public:
        Bullet(); //Default Constructor
        int  angle; //angle of bullet
        QDesktopWidget dw; //Bounds of the screen
        bool outOfBounds; //Decides if bullet is out of bounds
        void paint(QPainter*, const QStyleOptionGraphicsItem *option, QWidget *widget);// implement virtual paint function
        QRectF   boundingRect() const//bounding rectangle allowing no screen movement
            {return QRectF(0, 0, 0, 0);}
    public slots:
        void move();
};
#endif // BULLET_H
