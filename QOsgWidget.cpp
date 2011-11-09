#include "QOsgWidget.h"

#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>

QOsgWidget::QOsgWidget(QWidget* parent) : osgQt::GLWidget(parent)
{
  setupContext();
  this->addEventHandler(new osgViewer::StatsHandler);
  this->setCameraManipulator(new osgGA::TrackballManipulator);

  connect(&this->timer, SIGNAL(timeout()), this, SLOT(update()));
  this->timer.start(10);
}

QOsgWidget::~QOsgWidget()
{
}

void QOsgWidget::setupContext()
{
  osg::DisplaySettings *ds = osg::DisplaySettings::instance().get();
  osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits(ds);
  traits->x = this->x();
  traits->y = this->y();
  traits->width = this->width();
  traits->height = this->height();
  traits->doubleBuffer = true;
  traits->inheritedWindowData = new osgQt::GraphicsWindowQt::WindowData(this);
  
  // This requires Qt to be the main window system while building OSG:
  //  osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
  // This should work independent of how OSG was built:
  osg::ref_ptr<osgQt::GraphicsWindowQt> gw = new osgQt::GraphicsWindowQt(traits.get());

  getCamera()->setGraphicsContext(gw.get());
  getCamera()->setViewport(traits->x, traits->y, traits->width, traits->height);
  getCamera()->setProjectionMatrixAsPerspective(30.0f, 1.0f*traits->width/traits->height, 1.0f, 10000.0f);
  gw->getEventQueue()->getCurrentEventState()->setWindowRectangle(traits->x, traits->y, traits->width, traits->height);
 
  // FIXME: Is this necessary? 
  // GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;
  // _camera->setDrawBuffer(buffer);
  // _camera->setReadBuffer(buffer);
}

