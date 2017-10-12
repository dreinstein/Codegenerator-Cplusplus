#ifndef FUNCTIONWIDGED_H
#define FUNCTIONWIDGED_H

#include <QDialog>
#include "Gui/attributewidget.h"


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
    AttributeWidget* parameterFormWidged = nullptr;

signals:
    void closeFunctionWidget();
    void saveFunctionWidget();

private slots:
    void closeParameterFormWidget();
    void saveParameterFormWidget();
    void on_pushButton_SetParameter_clicked();
    void on_pushButton_Open_clicked();
    void on_pushButton_Save_clicked();
    void on_pushButton__Close_clicked();
};



#endif // FUNCTIONWIDGED_H
