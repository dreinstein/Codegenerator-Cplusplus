#include "classform.h"
#include "ui_classform.h"

ClassForm::ClassForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassForm)
{
    ui->setupUi(this);
}

ClassForm::~ClassForm()
{
    delete ui;
}

void ClassForm::on_SaveButton_clicked()
{
    emit closeWidget();
}

void ClassForm::on_CloseButton_clicked()
{
   emit closeWidget();
}
