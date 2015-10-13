#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	// jetzt wirds wild
    ui->setupUi(this);
	
	// nun wir werde sehen
}

MainWindow::~MainWindow()
{
    delete ui;
	
	// this is delete
}
