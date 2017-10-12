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


void FunctionWidged::on_pushButton_SetParameter_clicked()
{
    parameterFormWidged = new AttributeWidget(true);
    parameterFormWidged->show();

    connect(parameterFormWidged, SIGNAL(closeParameterWidget()),
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
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  attrElements = parameterFormWidged->getElements();
    auto count = attrElements.size();
    //ui->functionListWidget->addItem(listElement);
    parameterFormWidged->close();
}



void FunctionWidged::on_pushButton_Open_clicked()
{

}

void FunctionWidged::on_pushButton_Save_clicked()
{
    emit saveFunctionWidget();
}

void FunctionWidged::on_pushButton__Close_clicked()
{
     emit closeFunctionWidget();
}
