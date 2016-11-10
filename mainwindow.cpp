
#include "mainwindow.h"
#include "scene.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QMainWindow>

MainWindow::MainWindow() : QMainWindow()//constructor
{
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

/************************************ showMessage ************************************/

void  MainWindow::showMessage( QString msg )
{
  // display message on main window status bar
  statusBar()->showMessage( msg );
}

void MainWindow::startGame()
{
    // create scene and central widget view of scene
    m_scene               = new Scene();
    QGraphicsView*   view = new QGraphicsView( m_scene );
    view->setAlignment( Qt::AlignCenter | Qt::AlignCenter );
    view->setFrameStyle( 0 );
    setCentralWidget( view );
}



