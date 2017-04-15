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



void ClassForm::on_CreateAttributeButton_clicked()
{
    attributeFormWidged = new AttributeWidget();
    attributeFormWidged->show();

    connect(attributeFormWidged, SIGNAL(closeAttributeWidget()),
                        this, SLOT(closeAttributeFormWidget()));
    connect(attributeFormWidged, SIGNAL(saveAttributeWidget()),
                        this, SLOT(saveAttributeFormWidget()));

}

void ClassForm::closeAttributeFormWidget()
{
    attributeFormWidged->close();
    delete attributeFormWidged;
    attributeFormWidged = nullptr;
}

void ClassForm::saveAttributeFormWidget()
{

    addListElement();
    attributeFormWidged->close();
    delete attributeFormWidged;
    attributeFormWidged = nullptr;
}


void ClassForm::addListElement()
{
    QString constType = "const";
    QString pointer = "*";
    QString reference = "&";
    QString emptySpace = " ";

    QString attributeName = attributeFormWidged->getName();
    QString attributeType = attributeFormWidged->getTyp();
    bool attributeIsConst = attributeFormWidged->getIsConst();
    bool attributeIsPointer = attributeFormWidged->getIsPointer();
    bool attributeIsReference = attributeFormWidged->getIsReference();
    bool attributeIsPointerConst = attributeFormWidged->getIsPointerConst();
    bool attributeIsReferenceConst = attributeFormWidged->getIsReferenceConst();
    QString visiblity = attributeFormWidged->getVisiblity();

    QString listElement = visiblity;
    listElement += emptySpace;
    listElement += emptySpace;

    if(attributeIsConst)
    {
        listElement += constType;
        listElement += emptySpace;
        listElement += emptySpace;
    }
    listElement += attributeType;
    listElement += emptySpace;
    listElement += emptySpace;

    if(attributeIsPointer)
    {
        listElement += pointer;
        listElement += emptySpace;
        listElement += emptySpace;
    }
    if(attributeIsPointerConst)
    {
        listElement += constType;
        listElement += emptySpace;
        listElement += emptySpace;
    }
    if(attributeIsReference)
    {
        listElement += reference;
        listElement += emptySpace;
        listElement += emptySpace;
    }
    if(attributeIsReferenceConst)
    {
        listElement += constType;
        listElement += emptySpace;
        listElement += emptySpace;
    }
    listElement += attributeName;


    ui->classListWidget->addItem(listElement);

}


