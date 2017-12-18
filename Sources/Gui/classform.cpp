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
    doubleClickedParameterIndex = -1;
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


void ClassForm::on_CreateAttributeButton_clicked()
{
    attributeFormWidged = new AttributeWidget();
    attributeFormWidged->show();

    connect(attributeFormWidged, SIGNAL(closeAttributeWidget()),
                        this, SLOT(closeAttributeFormWidget()));
    connect(attributeFormWidged, SIGNAL(saveAttributeWidget()),
                        this, SLOT(saveAttributeFormWidget()));

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


void ClassForm::saveFunctionFormWidget()
{
    if(doubleClickedParameterIndex == -1)
    {
        funcElements.push_back(functionFormWidged->getElements().at(0));
        ui->classListWidget->addItem( funcElements.back().get()->getString());
        elements.push_back(funcElements.back().get());
    }
    else
    {
        std::vector<std::shared_ptr<Codegenerator::FunctionElements>>  felements = functionFormWidged->getElements();
        funcElements.push_back(felements[0]);
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + doubleClickedParameterIndex;
        elements.insert(it,felements[0].get());
        it = elements.begin() + doubleClickedParameterIndex+1;
        elements.erase(it);
    }
    refreshParamterList();
    closeFunctionFormWidget();
}


void ClassForm::saveAttributeFormWidget()
{
    if(doubleClickedParameterIndex == -1)
    {
        attrElements.push_back(attributeFormWidged->getElements().at(0));
        ui->classListWidget->addItem( attrElements.back().get()->getString());
        elements.push_back(attrElements.back().get());
    }
    else
    {
        std::vector<std::shared_ptr<Codegenerator::AttributeElements>>  aelements = attributeFormWidged->getElements();
        attrElements.push_back(aelements[0]);
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + doubleClickedParameterIndex;
        elements.insert(it,aelements[0].get());
        it = elements.begin() + doubleClickedParameterIndex+1;
        elements.erase(it);
    }
    refreshParamterList();
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
    doubleClickedParameterIndex = -1;
}


void ClassForm::on_PushButton_delete_clicked()
{
     int index = ui->classListWidget->currentRow();
     if(index >=0)
     {
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + index;
        elements.erase(it);
        refreshParamterList();
     }
}

void ClassForm::on_pushButton_Down_clicked()
{
    int index = ui->classListWidget->currentRow();
    if((index >= 0) && (index < ui->classListWidget->count()-1))
    {
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + index;
        Codegenerator::BaseElements *tempElement = elements.at(index);
        elements.erase(it);
        elements.insert(it+1,tempElement);
        refreshParamterList();
    }
}


void ClassForm::on_pushButton_Up_clicked()
{
    int index = ui->classListWidget->currentRow();
    if(index > 0)
    {
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + index;
        Codegenerator::BaseElements *tempElement = elements.at(index);
        elements.erase(it);
        elements.insert(it-1,tempElement);
        refreshParamterList();
    }
}
