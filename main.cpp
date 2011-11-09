#include <QApplication>
#include <QDebug>

#include "MainWindow.h"

#include <osgDB/ReadFile>

int main(int argc, char **argv)
{
  int retval;
  QApplication app(argc, argv);

  MainWindow mainwin;


  mainwin.osgwidget->setSceneData(osgDB::readNodeFile("cow.osgt"));


  mainwin.show();
  retval = app.exec();

  return retval;
}
