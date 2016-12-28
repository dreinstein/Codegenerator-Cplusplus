#include "functionwidged.h"
#include "ui_functionwidged.h"

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
