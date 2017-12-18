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
    ui->radioButton_Private->setChecked(true);
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
    loadDatasFromGuiElements();
    emit saveFunctionWidget();
}

void FunctionWidged::loadDatasFromGuiElements()
{
    if(ui->radioButton_Private->isChecked())
    {
        funcElements[0]->setModifier(Codegenerator::CodegeneratorConstants::modifierPrivate);
    }
    else if (ui->radioButton_Protected->isChecked())
    {
        funcElements[0]->setModifier(Codegenerator::CodegeneratorConstants::modifierProtected);
    }
    else
    {
        funcElements[0]->setModifier(Codegenerator::CodegeneratorConstants::modifierPublic);
    }
    funcElements[0]->setFunction(ui->edit_FunctionName->text());
    funcElements[0]->setTyp(ui->edit_FunctionReturnValue->text());
    funcElements[0]->setIsReturnConstant(ui->checkBox_ReturnConst->isChecked());
    funcElements[0]->setIsMemoryConstant(ui->checkBox_MemoryConst->isChecked());
    funcElements[0]->setIsPointer(ui->checkBox_FunctionPointer->isChecked());
    funcElements[0]->setIsRef(ui->checkBox_FunctionReference->isChecked());
    funcElements[0]->setIsConstant(ui->checkBox_FunctionConst->isChecked());
}

void FunctionWidged::on_pushButton__Close_clicked()
{
     emit closeFunctionWidget();
}

void FunctionWidged::fillGuiWithElements()
{
    setGui(funcElements[0].get());
}


void FunctionWidged::setGui(Codegenerator::FunctionElements* elements)
{
    std::shared_ptr<Codegenerator::FunctionElements> sharedElement = std::make_shared<Codegenerator::FunctionElements>(*elements);
    funcElements.clear();
    funcElements.push_back(sharedElement);
    ui->edit_FunctionName->setText(elements->getFunction());
    ui->edit_FunctionReturnValue->setText(elements->getTyp());
    if(elements->getIsConstant())
    {
        ui->checkBox_FunctionConst->setChecked(true);
    }
    else
    {
        ui->checkBox_FunctionConst->setChecked(false);
    }
    if(elements->getIsPointer())
    {
       ui->checkBox_FunctionPointer->setChecked(true);
    }
    else
    {
        ui->checkBox_FunctionPointer->setChecked(false);
    }

    std::vector<Codegenerator::AttributeElements*> parameters = elements->getFunctionParameters();
    for(Codegenerator::AttributeElements* att : parameters )
    {
        ui->functionListWidget->addItem(att->getString());
    }
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
    it = attributes.begin() + doubleClickedParameterIndex+1;
    attributes.erase(it);
    doubleClickedParameterIndex = -1;
    refreshParamterList(attributes);
}

void FunctionWidged::saveParameterNew()
{
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>>  attrElements = parameterFormWidged->getElements();
    funcElements[0]->pushFunctionParameter(attrElements[0].get());
    ui->functionListWidget->addItem(attrElements[0].get()->getString(true));
}

void FunctionWidged::on_pushButton_deleteParamter_clicked()
{
     int index = ui->functionListWidget->currentRow();
     if(index >=0)
     {
        std::vector<Codegenerator::AttributeElements*> attributes = funcElements[0]->getFunctionParameters();
        std::vector<Codegenerator::AttributeElements*>::iterator it = attributes.begin() + index;
        attributes.erase(it);
        refreshParamterList(attributes);
     }
}

void FunctionWidged::refreshParamterList(std::vector<Codegenerator::AttributeElements*> attributes )
{
    funcElements[0]->emptyFunctionParameters();
    ui->functionListWidget->clear();
    for(auto element:attributes)
    {
         funcElements[0]->pushFunctionParameter(element);
         ui->functionListWidget->addItem(element->getString(true));
    }
}

void FunctionWidged::on_pushButtonParameterUp_clicked()
{
    int index = ui->functionListWidget->currentRow();
    if(index > 0)
    {
        std::vector<Codegenerator::AttributeElements*> attributes = funcElements[0]->getFunctionParameters();
        Codegenerator::AttributeElements *element = attributes.at(index);
        std::vector<Codegenerator::AttributeElements*>::iterator it = attributes.begin() + index -1;
        attributes.insert(it,element);
        it = attributes.begin() + index+1;
        attributes.erase(it);
        refreshParamterList(attributes);
    }
}

void FunctionWidged::on_pushButtonParameterDown_clicked()
{
    int index = ui->functionListWidget->currentRow();
    if((index >= 0) && (index < ui->functionListWidget->count()-1))
    {
        std::vector<Codegenerator::AttributeElements*> attributes = funcElements[0]->getFunctionParameters();
        Codegenerator::AttributeElements *element = attributes.at(index);
        std::vector<Codegenerator::AttributeElements*>::iterator it = attributes.begin() + index + 2;
        attributes.insert(it,element);
        it = attributes.begin() + index;
        attributes.erase(it);
        refreshParamterList(attributes);
    }
}
