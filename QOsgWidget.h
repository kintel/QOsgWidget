/*
 * Copyright 2011-2012 Marius Kintel <marius@kintel.net>
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

  enum DrawMethod { HEARTBEAT, PAINTEVENT };
  void setDrawMethod(DrawMethod method);

  virtual void frame(double simulationTime=USE_REFERENCE_TIME);

  void requestRedraw();
  void glDraw();

protected:
  ~QOsgWidget();

  void setupContext();

private:
  DrawMethod drawmethod;
};

#endif
