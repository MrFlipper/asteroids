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
    Scene(); // constructor
    void addShip();//create ship in center of screen
    Ship *s; //pointer to the ship
    QList<Asteroid*> roids; //List of Asteroids
    void addAsteroid(); //Draws an Asteroid
    QDesktopWidget dw; //Size of the users screen
    QList<Bullet*> bullets; //List of bullets on screen
    void keyPressEvent(QKeyEvent *event); //Checks if a button is pressed
    void collidesWith(); //Checks for collision
signals:
    void  message( QString );// info text message signal
};

#endif  // SCENE_H
