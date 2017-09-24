#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>

//#include "Gui/classform.h"

class ClassForm;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void newFile();
    void closeApp();
    void closeClassFormWidget();
private:
    ClassForm* classFormWidget = nullptr;
};


#endif // MAINWINDOW_H
