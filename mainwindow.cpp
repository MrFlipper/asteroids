#include <QMenuBar>
#include <QStatusBar>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QMainWindow>
#include "mainwindow.h"
#include "scene.h"

//constructor
MainWindow::MainWindow() : QMainWindow(){
  // add drop down menus
  QMenu* fileMenu = menuBar()->addMenu("&File");
  fileMenu->addAction("&New",this,SLOT(startGame()));
  fileMenu->addAction("&Close",this,SLOT(close()));
  fileMenu->addAction("&Quit",this,SLOT(close()));

  // create scene and central widget view of scene
   startGame();

  // connect message signal from scene to showMessage slot
  connect( m_scene, SIGNAL(message(QString)), this, SLOT(showMessage(QString)) );

  // add status bar message
  statusBar()->showMessage("Game has started");

}

// display message on main window status bar
void  MainWindow::showMessage( QString msg )
{
   statusBar()->showMessage( msg );
}

// create scene and central widget view of scene
void MainWindow::startGame()
{
    m_scene               = new Scene();
    QGraphicsView*   view = new QGraphicsView( m_scene );
    view->setAlignment( Qt::AlignLeft | Qt::AlignTop );
    view->setFrameStyle( 0 );
    m_scene->setBackgroundBrush(Qt::black);
    setCentralWidget( view );
}



