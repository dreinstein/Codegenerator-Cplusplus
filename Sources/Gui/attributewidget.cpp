#include "attributewidget.h"
#include "ui_attributewidget.h"

AttributeWidget::AttributeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttributeWidget)
{
   ui->setupUi(this);
   name="";
   typ="";
   isConst=false;
   isPointer=false;
   isPointerConst=false;
   isReference=false;
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
    emit closeAttributeWidget();
}
