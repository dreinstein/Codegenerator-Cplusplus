#include "functionwidged.h"
#include "ui_functionwidged.h"
#include "ui_attributewidget.h"

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
    parameterFormWidged = new AttributeWidget(true);
    parameterFormWidged->show();

    connect(parameterFormWidged, SIGNAL(closeAttributeWidget()),
                        this, SLOT(closeParameterFormWidget()));

    connect(parameterFormWidged, SIGNAL(saveAttributeWidget()),
                        this, SLOT(saveParameterFormWidget()));
}

void FunctionWidged::closeParameterFormWidget()
{
    parameterFormWidged->close();
    delete parameterFormWidged;
    parameterFormWidged = nullptr;
}

void FunctionWidged::saveParameterFormWidget()
{
  /*  QString listElement = parameterFormWidged->getFormatedString();
    ui->functionListWidget->addItem(listElement);
    parameterFormWidged->close();
    delete parameterFormWidged;
    parameterFormWidged = nullptr;*/
}


