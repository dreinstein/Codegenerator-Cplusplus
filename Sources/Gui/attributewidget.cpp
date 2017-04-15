#include "attributewidget.h"
#include "ui_attributewidget.h"

AttributeWidget::AttributeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttributeWidget)
{
   ui->setupUi(this);
   name="";
   typ="";
   visiblity = privateString;
   isConst=false;
   isPointer=false;
   isPointerConst=false;
   isReference=false;
   ui->radioButton_Private->setChecked(true);
   ui->radioButton_Protected->setChecked(false);
   ui->radioButton_Public->setChecked(false);
   ui->checkBox_AttributePointerConst->setDisabled(true);
   ui->checkBox_AttributeReferenceConst->setDisabled(true);
   QStringList itemList;
   itemList << "integer" << "double" << "float" << "long" << "string" ;
   ui->comboBox_Type->addItems(itemList);
}

AttributeWidget::~AttributeWidget()
{
    delete ui;
}

void AttributeWidget::on_pushButton__Close_clicked()
{
   emit closeAttributeWidget();
}

void AttributeWidget::on_pushButton_Save_clicked()
{
    name = ui->lineEdit_Name->text();
    typ = ui->comboBox_Type->currentText();
    isConst = ui->checkBox_AttributeConst->isChecked();
    isPointer = ui->checkBox_AttributePointer->isChecked();
    isPointerConst = ui->checkBox_AttributePointerConst->isChecked();
    isReference = ui->checkBox_AttributeReference->isChecked();
    isReferenceConst = ui->checkBox_AttributeReferenceConst->isChecked();
    if(ui->radioButton_Private->isChecked())
    {
        visiblity = privateString;
    }
    else if(ui->radioButton_Protected->isChecked())
    {
        visiblity = protectedString;
    }
    else
    {
        visiblity = publicString;
    }
    emit saveAttributeWidget();
}

void AttributeWidget::on_checkBox_AttributePointer_clicked()
{
    if(ui->checkBox_AttributePointer->isChecked())
    {
        ui->checkBox_AttributePointerConst->setDisabled(false);
    }
    else
    {
         ui->checkBox_AttributePointerConst->setDisabled(true);
    }
}

void AttributeWidget::on_checkBox_AttributeReference_clicked()
{
    if(ui->checkBox_AttributeReference->isChecked())
    {
        ui->checkBox_AttributeReferenceConst->setDisabled(false);
    }
    else
    {
         ui->checkBox_AttributeReferenceConst->setDisabled(true);
    }
}
