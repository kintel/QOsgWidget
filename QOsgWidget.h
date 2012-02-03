/*
 * Copyright 2011 Marius Kintel <marius@kintel.net>
 * Consider this file public domain
 *
 */

#ifndef QOSGWIDGET_H_
#define QOSGWIDGET_H_

#include <osgQt/GraphicsWindowQt>
#include <osgViewer/Viewer>
#include <QtCore/QTimer>

class QOsgWidget : public osgQt::GLWidget, public osgViewer::Viewer
{
public:
  QOsgWidget(QWidget* parent = NULL);
#if 0 // For ON_DEMAND debugging
  virtual void frame(double simulationTime);
#endif

protected:
  ~QOsgWidget();

  void setupContext();
};

#endif
