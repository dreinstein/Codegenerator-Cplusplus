#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ClassForm;

namespace Ui {
class MainWindow;
}

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
