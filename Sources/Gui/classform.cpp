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
    auto count = attrElements.size();
    for(uint i=0;i<count;++i)
    {
        writeAttribute(attrElements[i].get());
    }
    closeAttributeFormWidget();
}


void ClassForm::writeAttribute(Codegenerator::AttributeElements* element)
{
    QString list = "";
    if(element->getModifier() == Codegenerator::CodegeneratorConstants::modifierPrivate)
    {
        list += Codegenerator::CodegeneratorConstants::modifierPrivate;
    }
    else if(element->getModifier() == Codegenerator::CodegeneratorConstants::modifierProtected)
    {
        list += Codegenerator::CodegeneratorConstants::modifierProtected;
    }
    else
    {
        list += Codegenerator::CodegeneratorConstants::modifierPublic;
    }
    list += Codegenerator::CodegeneratorConstants::emptyChar;

    if(element->getIsConstant())
    {
        list += Codegenerator::CodegeneratorConstants::constant;
    }
    list += Codegenerator::CodegeneratorConstants::emptyChar;

    list += element->getTyp();
    list += Codegenerator::CodegeneratorConstants::emptyChar;

    if(element->getIsPointer())
    {
        list += Codegenerator::CodegeneratorConstants::pointer;
        if(element->getIsMemoryConstant())
        {
            list += Codegenerator::CodegeneratorConstants::emptyChar;
            list += Codegenerator::CodegeneratorConstants::constant;
        }
    }
    else if(element->getIsRef())
    {
        list += Codegenerator::CodegeneratorConstants::reference;
    }
    list += Codegenerator::CodegeneratorConstants::emptyChar;
    list += element->getAttribute();

    ui->classListWidget->addItem(list);
}







