
#ifndef SCENE_H
#define SCENE_H

class QGraphicsSceneMouseEvent;
#include "ship.h"
#include "asteroids.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QList>

/*************************************************************************************/
/******************** Scene representing the simulated landscape *********************/
/*************************************************************************************/

class Scene : public QGraphicsScene
{
  Q_OBJECT
public:
    Scene();                                      // constructor
    void drawShip();//create ship in center of screen
    Ship *s; //pointer to the ship
    //QList<Bullet*> bullets;
    QList<Asteroid*> asteroids;
    void drawAsteroid();
signals:
    void  message( QString );// info text message signal
};

#endif  // SCENE_H
