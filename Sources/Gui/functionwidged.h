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
    AttributeWidget* attributeFormWidged = nullptr;

signals:
    void closeFunctionWidget();
private slots:
    void on_Close_Button_clicked();
    void on_Save_Button_clicked();
    void on_pushButton_SetParameter_clicked();
    void closeParameterFormWidget();

};

#endif // FUNCTIONWIDGED_H
