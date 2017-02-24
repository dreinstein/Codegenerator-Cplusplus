#include "functionwidged.h"
#include "ui_functionwidged.h"
//#include "ui_attributewidget.h"

FunctionWidged::FunctionWidged(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FunctionWidged)
{
    ui->setupUi(this);
}

FunctionWidged::~FunctionWidged()
{
    delete ui;
}


void FunctionWidged::on_Close_Button_clicked()
{
    emit closeFunctionWidget();
}

void FunctionWidged::on_Save_Button_clicked()
{
    emit closeFunctionWidget();
}

void FunctionWidged::on_pushButton_SetParameter_clicked()
{
   // functionFormWidged = new FunctionWidged();
   // functionFormWidged->show();
}
