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
    std::vector<std::shared_ptr<Codegenerator::FunctionElements>> funcElements;
    void fillGuiWithElements();
    void createParameterFormWidged();
    void saveParameterEdit();
    void saveParameterNew();
    void refreshParamterList(std::vector<Codegenerator::AttributeElements*> attributes);

    int doubleClickedParameterIndex;

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
    void on_functionListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_deleteParamter_clicked();
    void on_functionListWidget_indexesMoved(const QModelIndexList &indexes);
    void on_functionListWidget_itemSelectionChanged();
    void on_functionListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_functionListWidget_itemChanged(QListWidgetItem *item);
    void on_functionListWidget_itemPressed(QListWidgetItem *item);
    void on_pushButtonParameterUp_clicked();
    void on_pushButtonParameterDown_clicked();
};


#endif // FUNCTIONWIDGED_H
