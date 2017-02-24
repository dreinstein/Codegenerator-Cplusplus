#ifndef FUNCTIONWIDGED_H
#define FUNCTIONWIDGED_H

#include <QDialog>

namespace Ui {
class FunctionWidged;
}

class FunctionWidged : public QDialog
{
    Q_OBJECT

public:
    explicit FunctionWidged(QWidget *parent = 0);
    ~FunctionWidged();

private:
    Ui::FunctionWidged *ui;

signals:
    void closeFunctionWidget();
private slots:
    void on_Close_Button_clicked();
    void on_Save_Button_clicked();
    void on_pushButton_SetParameter_clicked();
};

#endif // FUNCTIONWIDGED_H
