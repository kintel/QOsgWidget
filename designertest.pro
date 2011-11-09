TARGET = designertest
CONFIG += qt osg
OSG += Qt
QT += opengl
include(common.pri)

FORMS += designertest.ui

HEADERS += MainWindow.h \
           QOsgWidget.h

SOURCES += main.cpp \
           MainWindow.cpp \
           QOsgWidget.cpp

