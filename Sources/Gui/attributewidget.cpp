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
    name = ui->lineEdit_AttributeName->text();
    typ = ui->lineEdit_AttributeType->text();
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
    emit closeAttributeWidget();
}
