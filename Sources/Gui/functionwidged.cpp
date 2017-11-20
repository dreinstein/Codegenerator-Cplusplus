#include "functionwidged.h"
#include "ui_attributewidget.h"
#include "Codegen/Functionelements.h"
#include "loadDatas.h"
#include <iostream>
#include <QTextStream>
#include <QFileDialog>


FunctionWidged::FunctionWidged(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FunctionWidged)
{
    ui->setupUi(this);
    doubleClickedParameterIndex = -1;
    funcElements.push_back(std::unique_ptr<Codegenerator::FunctionElements>(new Codegenerator::FunctionElements));
}

FunctionWidged::~FunctionWidged()
{
    delete ui;
}


void FunctionWidged::on_pushButton_SetParameter_clicked()
{
   createParameterFormWidged();
}

void FunctionWidged::closeParameterFormWidget()
{
    parameterFormWidged->close();
    delete parameterFormWidged;
    parameterFormWidged = nullptr;
}


void FunctionWidged::saveParameterFormWidget()
{
    if(doubleClickedParameterIndex == -1)
    {
        saveParameterNew();
    }
    else
    {
        saveParameterEdit();


    }
    parameterFormWidged->close();
}


void FunctionWidged::on_pushButton_Open_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("File (*.xml)"));
    if(fileName != "")
    {
        DatasLoad<Codegenerator::FunctionElements> load;
        funcElements.clear();
        funcElements = load.loadDatasFromFile(fileName);
        fillGuiWithElements();
    }
}

void FunctionWidged::on_pushButton_Save_clicked()
{
    emit saveFunctionWidget();
}

void FunctionWidged::on_pushButton__Close_clicked()
{
     emit closeFunctionWidget();
}

void FunctionWidged::fillGuiWithElements()
{
    ui->edit_FunctionName->setText(funcElements[0].get()->getFunction());
    ui->edit_FunctionReturnValue->setText(funcElements[0].get()->getTyp());
    if(funcElements[0].get()->getIsConstant())
    {
        ui->checkBox_FunctionConstant->setChecked(true);
    }
    else
    {
        ui->checkBox_FunctionConstant->setChecked(false);
    }
    if(funcElements[0].get()->getIsPointer())
    {
    //   ui->checkBox_FunctionPointer->setChecked(true);
    }
    else
    {
    //    ui->checkBox_FunctionPointer->setChecked(false);
    }

    std::vector<Codegenerator::AttributeElements*> parameters = funcElements[0].get()->getFunctionParameters();
    for(Codegenerator::AttributeElements* att : parameters )
    {
        ui->functionListWidget->addItem(att->getString());
    }

}


void FunctionWidged::on_checkBox_FunctionReference_clicked()
{

}

void FunctionWidged::on_checkBox_FunctionPointer_clicked()
{

}

void FunctionWidged::on_functionListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    doubleClickedParameterIndex = item->listWidget()->currentRow();
    std::vector<Codegenerator::AttributeElements*> elements = funcElements[0].get()->getFunctionParameters();
    createParameterFormWidged();
    parameterFormWidged->setGui(elements[doubleClickedParameterIndex]);
}


void FunctionWidged::createParameterFormWidged()
{
    parameterFormWidged = new AttributeWidget(true);
    parameterFormWidged->show();

    connect(parameterFormWidged, SIGNAL(closeParameterWidget()),
                        this, SLOT(closeParameterFormWidget()));

    connect(parameterFormWidged, SIGNAL(saveAttributeWidget()),
                        this, SLOT(saveParameterFormWidget()));
}

void FunctionWidged::saveParameterEdit()
{
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>>  attrElements = parameterFormWidged->getElements();
    std::vector<Codegenerator::AttributeElements*> attributes = funcElements[0]->getFunctionParameters();
    std::vector<Codegenerator::AttributeElements*>::iterator it = attributes.begin() + doubleClickedParameterIndex;
    attributes.insert(it,attrElements[0].get());
    funcElements[0]->emptyFunctionParameters();
    it = attributes.begin() + doubleClickedParameterIndex+1;
    attributes.erase(it);
    doubleClickedParameterIndex = -1;
    ui->functionListWidget->clear();
    for(auto element:attributes)
    {
         funcElements[0]->pushFunctionParameter(element);
         ui->functionListWidget->addItem(element->getString(true));
    }
}

void FunctionWidged::saveParameterNew()
{
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>>  attrElements = parameterFormWidged->getElements();
    funcElements[0]->pushFunctionParameter(attrElements[0].get());
    ui->functionListWidget->addItem(attrElements[0].get()->getString(true));
}
