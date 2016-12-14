
#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
   // QWidget *widget = new QWidget;
   // setCentralWidget(widget);
   // widget->setBaseSize(100,50);
    setObjectName("MainWindow");
    setWindowTitle("Simple Code Generator");
    this->resize(700,500);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
  //  QToolBar *fileToolBar = addToolBar(tr("File"));
    QAction *newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
  //  newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAct);
  //  fileToolBar->addAction(newAct);
}

MainWindow::~MainWindow()
{
	
}


void MainWindow::newFile()
{
    int i;
    ++i;

}
