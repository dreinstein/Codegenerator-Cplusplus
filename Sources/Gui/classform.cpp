#include "classform.h"
#include "ui_classform.h"
#include "Codegen/Codegeneratorconstants.h"
#include <stdio.h>
#include <iostream>
#include <QTextStream>


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

    connect(functionFormWidged, SIGNAL(saveFunctionWidget()),
                        this, SLOT(saveFunctionFormWidget()));

}

void ClassForm::closeFunctionFormWidget()
{
    functionFormWidged->close();
    delete functionFormWidged;
    functionFormWidged = nullptr;
}


void ClassForm::saveFunctionFormWidget()
{
    funcElements.push_back(functionFormWidged->getElements().at(0));
    ui->classListWidget->addItem( funcElements.back().get()->getString());
    elements.push_back(funcElements.back().get());
    closeFunctionFormWidget();
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
    attrElements.push_back(attributeFormWidged->getElements().at(0));
    ui->classListWidget->addItem( attrElements.back().get()->getString());
    elements.push_back(attrElements.back().get());
    closeAttributeFormWidget();
}



void ClassForm::on_classListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    doubleClickedParameterIndex = item->listWidget()->currentRow();
    if(dynamic_cast<Codegenerator::AttributeElements*>(elements[doubleClickedParameterIndex]))
    {
        Codegenerator::AttributeElements* ele = dynamic_cast<Codegenerator::AttributeElements*>(elements[doubleClickedParameterIndex]);
        on_CreateAttributeButton_clicked();
        attributeFormWidged->setGui(ele);

    }
    if(dynamic_cast<Codegenerator::FunctionElements*>(elements[doubleClickedParameterIndex]))
    {
        Codegenerator::FunctionElements* ele = dynamic_cast<Codegenerator::FunctionElements*>(elements[doubleClickedParameterIndex]);
        on_CreateFunctionButton_clicked();
        functionFormWidged->setGui(ele);
    }
}


void ClassForm::refreshParamterList()
{
    ui->classListWidget->clear();
    for(auto ele:elements)
    {
         ui->classListWidget->addItem(ele->getString(true));
    }
}



void ClassForm::on_PushButton_delete_clicked()
{
     int index = ui->classListWidget->currentRow();
     {
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + index;
        elements.erase(it);
        refreshParamterList();
     }
}
