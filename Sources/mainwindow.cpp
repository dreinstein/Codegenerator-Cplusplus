

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Gui/classform.h"
#include "Gui/guidatamanager.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setObjectName("MainWindow");
    setWindowTitle("Simple Code Generator");
    this->resize(700,500);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *newAct = new QAction(tr("&New"), this);
    QAction *closeAct = new QAction(tr("Close"),this);
    newAct->setShortcuts(QKeySequence::New);
    closeAct->setShortcuts(QKeySequence::Close);
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    connect(closeAct, &QAction::triggered, this, &MainWindow::closeApp);

    fileMenu->addAction(newAct);
    fileMenu->addAction(closeAct);
}


MainWindow::~MainWindow()
{
    if (classFormWidget != nullptr)
    {
        delete classFormWidget;
    }
}

void MainWindow::newFile()
{
    guiDataManager = new GuiDataManager();
    classFormWidget = new ClassForm(guiDataManager);
    classFormWidget->show();

    connect(classFormWidget, SIGNAL(closeWidget()),
                        this, SLOT(closeClassFormWidget()));
}

void MainWindow::closeApp()
{
   this->close();
}


void MainWindow::closeClassFormWidget()
{
    classFormWidget->close();
    delete guiDataManager;
    delete classFormWidget;
    classFormWidget = nullptr;
}


