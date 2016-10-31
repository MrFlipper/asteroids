
#ifndef SCENE_H
#define SCENE_H

class QGraphicsSceneMouseEvent;

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
signals:
  void  message( QString );// info text message signal

protected:
  void  mousePressEvent( QGraphicsSceneMouseEvent* );// receive mouse press events

};

#endif  // SCENE_H
