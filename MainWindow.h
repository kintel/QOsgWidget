#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include "ui_designertest.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT;
public:
  MainWindow();
  ~MainWindow();

public slots:
};

#endif
