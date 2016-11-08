#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <QPolygon>
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>
#include <QDesktopWidget>
/*************************************************************************************/
/******************* Represents an asteroid in the simulation ********************/
/*************************************************************************************/

class Asteroid : public QObject, public QGraphicsItem
{
    Q_OBJECT
    public:
        Asteroid();
        Asteroid(qreal, qreal);
        void  paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );
        QRectF    boundingRect() const{ //bounding rectangle allowing no screen movement
            return QRectF(0,0,0,0);
        }
        double xbounds;
        double ybounds;
        QDesktopWidget dw;
    public slots:
        void change(){
            setPos(x(),y()-10);
            if (pos(),x() >= xbounds/2)
                setPos(xbounds/2 - xbounds,y());
            else if (pos(),x() <= (xbounds/2 - xbounds))
                setPos(xbounds/2,y());
            if (pos(),y() >= ybounds/2)
                setPos(x(),ybounds/2 - ybounds);
            else if (pos(),y() <= (ybounds/2 - ybounds))
                setPos(x(),ybounds/2);
        }
};
#endif // ASTEROIDS_H


