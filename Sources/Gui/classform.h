#ifndef CLASSFORM_H
#define CLASSFORM_H

#include <QWidget>
#include "Gui/functionwidged.h"
#include "Gui/attributewidget.h"

namespace Ui {
    class ClassForm;
}


class ClassForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClassForm(QWidget *parent = 0);
    ~ClassForm();

signals:
    void closeFunctionWidget();
private slots:
    void on_SaveButton_clicked();
    void on_CloseButton_clicked();
    void on_CreateFunctionButton_clicked();
    void closeFunctionFormWidget();
    void closeAttributeFormWidget();
    void on_CreateAttributeButton_clicked();
    void saveAttributeFormWidget();


private:
    Ui::ClassForm *ui;
    FunctionWidged* functionFormWidged = nullptr;
    AttributeWidget* attributeFormWidged = nullptr;
};


#endif // CLASSFORM_H
