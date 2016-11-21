#ifndef SHIP_H
#define SHIP_H

#include "bullet.h"
#include <QList>
#include <QObject>
#include <QGraphicsItem>
#include <QDesktopWidget>
/*************************************************************************************/
/******************* Represents a ship in the simulation ********************/
/*************************************************************************************/

class Ship : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Ship();//default constructor
    Ship(qreal, qreal);// constructor
    bool death; //Decides if ship is stiil alive
    double rotation; //rotation angle
    double xaccel; //Accelleration in x direction
    double yaccel; //Accelleration in y direction
    QDesktopWidget dw; //Bounds of the screen
    double xbounds; //X position of ship
    double ybounds; //Y position of ship
    void paint(QPainter*, const QStyleOptionGraphicsItem *option, QWidget *widget);// implement virtual paint function
    QRectF   boundingRect() const
    { return QRectF(0, 0, 0, 0);//bounding rectangle allowing no screen movement
    }
public slots:
    void move();
};

#endif  // SHIP_H
