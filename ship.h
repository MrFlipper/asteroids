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
    double rotation = 0; //rotation angle
    QDesktopWidget dw;
    double xbounds=dw.width()*0.8;
    double ybounds=dw.height()*0.8;
    void keyPressEvent(QKeyEvent *event);
    void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );// implement virtual paint function
    QRectF   boundingRect() const
    { return QRectF(0, 0, 0, 0);//bounding rectangle allowing no screen movement
    }
};

#endif  // SHIP_H
