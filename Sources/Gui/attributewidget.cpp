#include "attributewidget.h"
#include "ui_attributewidget.h"

AttributeWidget::AttributeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttributeWidget)
{
   ui->setupUi(this);
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
    emit closeAttributeWidget();
}
