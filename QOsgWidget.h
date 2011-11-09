#ifndef QOSGWIDGET_H_
#define QOSGWIDGET_H_

#include <osgQt/GraphicsWindowQt>
#include <osgViewer/Viewer>
#include <QtCore/QTimer>

class QOsgWidget : public osgQt::GLWidget, public osgViewer::Viewer
{
public:
  QOsgWidget(QWidget* parent = NULL);

protected:
  ~QOsgWidget();

  void paintEvent(QPaintEvent *) { frame(); }
  void setupContext();
  QTimer timer;
};

#endif
