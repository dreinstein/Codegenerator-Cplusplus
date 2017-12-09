#ifndef CLASSFORM_H
#define CLASSFORM_H

#include <QWidget>
#include "Gui/functionwidged.h"
#include "Gui/attributewidget.h"
#include "Codegen/baseelements.h"
#include <memory>
#include <vector>

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
    void saveFunctionWidget();
private slots:
    void on_SaveButton_clicked();
    void on_CloseButton_clicked();
    void on_CreateFunctionButton_clicked();
    void closeFunctionFormWidget();
    void saveFunctionFormWidget();
    void closeAttributeFormWidget();
    void on_CreateAttributeButton_clicked();
    void saveAttributeFormWidget();


    void on_classListWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ClassForm *ui;
    FunctionWidged* functionFormWidged = nullptr;
    AttributeWidget* attributeFormWidged = nullptr;
    std::vector<Codegenerator::BaseElements*> elements;
    int doubleClickedParameterIndex;
    Codegenerator::FunctionElements *pEle=nullptr;
    std::vector<std::shared_ptr<Codegenerator::FunctionElements>>  funcElements;
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>> attrElements;
};


#endif // CLASSFORM_H
