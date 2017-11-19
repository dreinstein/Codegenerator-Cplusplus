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
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>>  attrElements = parameterFormWidged->getElements();
    funcElements[0]->pushFunctionParameter(attrElements[0].get());
    for(uint i=0;i<attrElements.size();++i)
    {
        ui->functionListWidget->addItem(attrElements[i].get()->getString(true));
        QString str = attrElements[i].get()->getString();
        QTextStream out(stdout);
        out <<str;
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
    int index = item->listWidget()->currentRow();
    std::vector<Codegenerator::AttributeElements*> elements = funcElements[0].get()->getFunctionParameters();
    createParameterFormWidged();
    parameterFormWidged->setGui(elements[index]);
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
