#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsItem>

/*************************************************************************************/
/******************* Represents a ship in the simulation ********************/
/*************************************************************************************/

class Ship : public QGraphicsItem
{
public:
  Ship( qreal, qreal );                          // constructor

  void     paint( QPainter*,
                  const QStyleOptionGraphicsItem*,
                  QWidget* );                       // implement virtual paint function
  QRectF   boundingRect() const
    { return QRectF(0, 0, 0, 0);//bounding rectangle allowing no screen movement
    }
};

#endif  // SHIP_H
