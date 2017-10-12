#include "classform.h"
#include "ui_classform.h"
#include "Codegen/Codegeneratorconstants.h"





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
    // save class informations
    this->close();
}

void ClassForm::on_CloseButton_clicked()
{
    this->close();
}

void ClassForm::on_CreateFunctionButton_clicked()
{
    functionFormWidged = new FunctionWidged();
    functionFormWidged->show();

    connect(functionFormWidged, SIGNAL(closeFunctionWidget()),
                        this, SLOT(closeFunctionFormWidget()));

}


void ClassForm::closeFunctionFormWidget()
{
    functionFormWidged->close();
    delete functionFormWidged;
    functionFormWidged = nullptr;
}

void ClassForm::closeAttributeFormWidget()
{
    attributeFormWidged->close();
    delete attributeFormWidged;
    attributeFormWidged = nullptr;

}



void ClassForm::on_CreateAttributeButton_clicked()
{
    attributeFormWidged = new AttributeWidget();
    attributeFormWidged->show();

    connect(attributeFormWidged, SIGNAL(closeAttributeWidget()),
                        this, SLOT(closeAttributeFormWidget()));
    connect(attributeFormWidged, SIGNAL(saveAttributeWidget()),
                        this, SLOT(saveAttributeFormWidget()));

}

void ClassForm::saveAttributeFormWidget()
{
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  attrElements = attributeFormWidged->getElements();
    for(uint i=0;i<attrElements.size();++i)
    {
        ui->classListWidget->addItem(attrElements[i].get()->getString());
    }
    closeAttributeFormWidget();
}










