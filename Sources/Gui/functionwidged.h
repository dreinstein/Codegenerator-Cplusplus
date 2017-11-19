#ifndef FUNCTIONWIDGED_H
#define FUNCTIONWIDGED_H

#include <QDialog>
#include "Gui/attributewidget.h"
#include "Codegen/Functionelements.h"
#include "ui_functionwidged.h"

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
    //std::vector<std::unique_ptr<Codegenerator::FunctionElements>> getElements() {return std::move(funcElements);}
    std::vector<std::shared_ptr<Codegenerator::FunctionElements>> funcElements;
    void fillGuiWithElements();
    void createParameterFormWidged();

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
    void on_checkBox_FunctionReference_clicked();
    void on_checkBox_FunctionPointer_clicked();
    void on_functionListWidget_itemDoubleClicked(QListWidgetItem *item);
};


#endif // FUNCTIONWIDGED_H
