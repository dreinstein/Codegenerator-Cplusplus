#ifndef ATTRIBUTEWIDGET_H
#define ATTRIBUTEWIDGET_H

#include <QWidget>
#include "baseLoadAndFormate.h"
#include "attributeLoad.h"

namespace Ui {
   class AttributeWidget;
}

class BaseLoadAndFormate;



class AttributeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttributeWidget(bool parameterSetting = false,QWidget *parent = 0);
    ~AttributeWidget();
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>> getElements() {return std::move(vecElements);}
    Ui::AttributeWidget* getUi(){return ui;}


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


private:
    void fillGuiWithElements();
    const QString parameterString = "Parameter";
    const QString attributeString = "Attribute";
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>> vecElements;
};

#endif // ATTRIBUTEWIDGET_H
