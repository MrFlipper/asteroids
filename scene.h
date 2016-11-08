
#ifndef SCENE_H
#define SCENE_H

class QGraphicsSceneMouseEvent;
#include "ship.h"
#include <QGraphicsScene>

/*************************************************************************************/
/******************** Scene representing the simulated landscape *********************/
/*************************************************************************************/

class Scene : public QGraphicsScene
{
  Q_OBJECT
public:
  Scene();                                      // constructor
  void drawShip();//create ship in center of screen
  Ship *s;
  void drawAsteroid();
signals:
  void  message( QString );// info text message signal
};

#endif  // SCENE_H
