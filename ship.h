#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsItem>
#include <QDesktopWidget>
/*************************************************************************************/
/******************* Represents a ship in the simulation ********************/
/*************************************************************************************/

class Ship : public QGraphicsItem
{
public:
    Ship( qreal, qreal );// constructor 
    double rotation; //rotation angle
    QDesktopWidget dw;
    void keyPressEvent(QKeyEvent *event);
    double xbounds;
    double ybounds;
    void paint(QPainter*, const QStyleOptionGraphicsItem *option, QWidget *widget);// implement virtual paint function
    QRectF   boundingRect() const
    { return QRectF(0, 0, 0, 0);//bounding rectangle allowing no screen movement
    }
};

#endif  // SHIP_H
