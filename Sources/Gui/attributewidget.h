#ifndef ATTRIBUTEWIDGET_H
#define ATTRIBUTEWIDGET_H

#include <QWidget>
#include "iwidget.h"

namespace Ui {
class AttributeWidget;
}

class AttributeWidget : public QWidget,public IWidget
{
    Q_OBJECT

public:
    explicit AttributeWidget(bool parameterSetting = false,QWidget *parent = 0);
    ~AttributeWidget();
    QString getFormatedString() override final;

private:
    Ui::AttributeWidget *ui;
    const bool parameterSetting;

signals:
    void closeAttributeWidget();
    void saveAttributeWidget();
private slots:
    void on_pushButton__Close_clicked();
    void on_pushButton_Save_clicked();
    void on_checkBox_AttributePointer_clicked();
    void on_checkBox_AttributeReference_clicked();
private:
    const QString parameterString = "Parameter";
    const QString attributeString = "Attribute";
};

#endif // ATTRIBUTEWIDGET_H
