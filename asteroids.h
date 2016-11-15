#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <QPolygon>
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>
#include <QDesktopWidget>
#include <QList>
/*************************************************************************************/
/******************* Represents an asteroid in the simulation ********************/
/*************************************************************************************/

class Asteroid : public QObject, public QGraphicsItem
{
    Q_OBJECT
    public:
        Asteroid(); //default constructor
        void  paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );
        QRectF    boundingRect() const{ //bounding rectangle allowing no screen movement
            return QRectF(0,0,0,0);
        }
        double xbounds;
        double ybounds;
        QDesktopWidget dw;
        void setAngle(int& x, int& y); //Decides which direction astroid flys (Glitchy)
        int x_move;
        int y_move;
    public slots:
        void move();
};
#endif // ASTEROIDS_H


