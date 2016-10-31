#include "scene.h"
#include "mainwindow.h"
#include <QDesktopWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
  // create main event loop handler and parse command line arguments
  QApplication app(argc, argv);

  // create application main window & enter main event loop
  MainWindow window;
  QDesktopWidget dw;

  int x=dw.width()*0.8;
  int y=dw.height()*0.8;
  window.setFixedSize(x,y);//window's size is fixed at 80% of the user's sceen size
  window.show();
  return app.exec();
}
