#ifndef ATTRIBUTEWIDGET_H
#define ATTRIBUTEWIDGET_H

#include <QWidget>
#include "attributeLoad.h"
#include "ui_attributewidget.h"

namespace Ui {
   class AttributeWidget;
}


class AttributeElements;



class AttributeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttributeWidget(bool parameterSetting = false,QWidget *parent = 0);
    ~AttributeWidget();
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>> getElements() {return vecElements;}
    //std::shared_ptr<Codegenerator::AttributeElements*> getElementPointer() {return &(vecElements[0]);}
   // Ui::AttributeWidget* getUi(){return ui;}
    void setGui(Codegenerator::AttributeElements* elements);


private:
    Ui::AttributeWidget *ui;
    const bool parameterSetting;

signals:
    void closeAttributeWidget();
    void closeParameterWidget();
    void saveAttributeWidget();
private slots:
    void on_pushButton__Close_clicked();
    void on_pushButton_Save_clicked();
    void on_checkBox_AttributePointer_clicked();
    void on_pushButton_Open_clicked();

    void on_checkBox_DefaultValue_clicked();

private:
    void fillGuiWithElements();
    void loadDatasFromGuiElements();
    const QString parameterString = "Parameter";
    const QString attributeString = "Attribute";
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>> vecElements;
};

#endif // ATTRIBUTEWIDGET_H
