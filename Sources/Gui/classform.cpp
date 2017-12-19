#include "classform.h"
#include "ui_classform.h"
#include "Codegen/Codegeneratorconstants.h"
#include <stdio.h>
#include <iostream>
#include <QTextStream>
#include "guidatamanager.h"


ClassForm::ClassForm(GuiDataManager* gDataManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassForm), guiDataManager(gDataManager)
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
     std::shared_ptr<Codegenerator::FunctionElements> fElement = functionFormWidged->getElements().at(0);
    if(doubleClickedParameterIndex == -1)
    {
        guiDataManager->push(fElement);
        ui->classListWidget->addItem( fElement.get()->getString());
    }
    else
    {
        guiDataManager->change(fElement,doubleClickedParameterIndex);
    }
    refreshParamterList();
    closeFunctionFormWidget();
}


void ClassForm::saveAttributeFormWidget()
{
     std::shared_ptr<Codegenerator::AttributeElements> aElement = attributeFormWidged->getElements().at(0);
    if(doubleClickedParameterIndex == -1)
    {
        guiDataManager->push(aElement);
        ui->classListWidget->addItem(aElement.get()->getString());
    }
    else
    {
         guiDataManager->change(aElement,doubleClickedParameterIndex);
    }
    refreshParamterList();
    closeAttributeFormWidget();
}


void ClassForm::on_classListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    doubleClickedParameterIndex = item->listWidget()->currentRow();
    GuiDataManager::WidgetTypes widgedType = guiDataManager->getWidgetTyp(doubleClickedParameterIndex);
    if(GuiDataManager::WidgetTypes::ATTRIBUTTETYPE == widgedType)
    {
        Codegenerator::AttributeElements* ele = guiDataManager->getAttributeElement(doubleClickedParameterIndex);
        on_CreateAttributeButton_clicked();
        attributeFormWidged->setGui(ele);

    }
    else if (GuiDataManager::WidgetTypes::FUNCTIONTYPE == widgedType)
    {
        Codegenerator::FunctionElements* ele = guiDataManager->getFunctionElement(doubleClickedParameterIndex);
        on_CreateFunctionButton_clicked();
        functionFormWidged->setGui(ele);
    }
    else
    {
        Q_ASSERT(false);
    }
}

void ClassForm::refreshParamterList()
{
    ui->classListWidget->clear();
    std::vector<Codegenerator::BaseElements*> bElements = guiDataManager->getElements();
    for(auto ele:bElements)
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
        guiDataManager->deleteItem(index);
        refreshParamterList();
     }
}


void ClassForm::on_pushButton_Down_clicked()
{
    int index = ui->classListWidget->currentRow();
    if((index >= 0) && (index < ui->classListWidget->count()-1))
    {
        guiDataManager->down(index);
        refreshParamterList();
    }
}


void ClassForm::on_pushButton_Up_clicked()
{
    int index = ui->classListWidget->currentRow();
    if(index > 0)
    {
        guiDataManager->up(index);
        refreshParamterList();
    }
}

void ClassForm::on_CreateSourceButton_clicked()
{

}
