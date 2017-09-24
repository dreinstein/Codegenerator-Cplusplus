#ifndef ATTRIBUTEWIDGET_H
#define ATTRIBUTEWIDGET_H

#include <QWidget>
#include "baseLoadAndFormate.h"
#include "attributeLoadAndFormate.h"

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


private:
    Ui::AttributeWidget *ui;
    BaseLoadAndFormate *laf;
    const bool parameterSetting;

signals:
    void closeAttributeWidget();
    void saveAttributeWidget();
private slots:
    void on_pushButton__Close_clicked();
    void on_pushButton_Save_clicked();
    void on_checkBox_AttributePointer_clicked();
    void on_checkBox_AttributeReference_clicked();
    void on_pushButton_Open_clicked();

private:
    const QString parameterString = "Parameter";
    const QString attributeString = "Attribute";
};

#endif // ATTRIBUTEWIDGET_H
