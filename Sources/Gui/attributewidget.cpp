#include "attributewidget.h"
#include "ui_attributewidget.h"
#include "../Codegen/Codegeneratorconstants.h"
#include "Codegen/Attributeelements.h"
#include "Utilities.h"
#include "loadDatas.h"
#include "memory"
#include "../Codegen/Attributeelements.h"
#include <QFileDialog>


AttributeWidget::AttributeWidget(bool _parameterSetting, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttributeWidget),
    parameterSetting(_parameterSetting)
{
   ui->setupUi(this);

   if(parameterSetting)
   {
       this->setWindowTitle(parameterString);
       ui->radioButton_Private->setDisabled(true);
       ui->radioButton_Protected->setDisabled(true);
       ui->radioButton_Public->setDisabled(true);
   }
   else
   {
       this->setWindowTitle(attributeString);
       ui->checkBox_DefaultValue->setDisabled(false);
   }
   ui->radioButton_Private->setChecked(true);
   ui->radioButton_Protected->setChecked(false);
   ui->radioButton_Public->setChecked(false);
   ui->checkBox_MemoryPointerConst->setDisabled(true);
   ui->lineEdit_DefaultValue->setDisabled(true);
   QStringList itemList;
   itemList << Codegenerator::CodegeneratorConstants::typInt << Codegenerator::CodegeneratorConstants::typDouble << Codegenerator::CodegeneratorConstants::typLong << Codegenerator::CodegeneratorConstants::typQString << Codegenerator::CodegeneratorConstants::typVoid;
   ui->comboBox_Type->addItems(itemList);
   std::unique_ptr<Codegenerator::AttributeElements> vecElements = std::unique_ptr<Codegenerator::AttributeElements> (new Codegenerator::AttributeElements());
}


AttributeWidget::~AttributeWidget()
{
    delete ui;
    ui = nullptr;

}

void AttributeWidget::on_pushButton__Close_clicked()
{
    if(parameterSetting)
    {
        emit closeParameterWidget();
    }
    else
    {
        emit closeAttributeWidget();
    }
}

void AttributeWidget::on_pushButton_Save_clicked()
{
    if(vecElements.size() == 0)
    {
        std::unique_ptr<AttributeLoad> datas =  std::unique_ptr<AttributeLoad>(new AttributeLoad());
        loadDatasFromGuiElements();
    }

    emit saveAttributeWidget();
}

void AttributeWidget::on_checkBox_AttributePointer_clicked()
{
    if(ui->checkBox_AttributePointer->isChecked())
    {
        ui->checkBox_MemoryPointerConst->setDisabled(false);
    }
    else
    {
         ui->checkBox_MemoryPointerConst->setDisabled(true);
    }
}


void AttributeWidget::on_pushButton_Open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("File (*.xml)"));
    if(fileName != "")
    {
        DatasLoad<Codegenerator::AttributeElements> load;
        vecElements = load.loadDatasFromFile(fileName);
        fillGuiWithElements();
    }
}


void AttributeWidget::on_checkBox_DefaultValue_clicked()
{
    if(ui->checkBox_DefaultValue->isChecked())
    {
        ui->lineEdit_DefaultValue->setDisabled(false);
    }
    else
    {
        ui->lineEdit_DefaultValue->setDisabled(true);
    }
}


void AttributeWidget::setGui(Codegenerator::AttributeElements* elements)
{
    ui->lineEdit_Name->setText(elements->getAttribute());
    ui->comboBox_Type->setEditText(elements->getTyp());
    if(elements->getIsConstant())
    {
        ui->checkBox_AttributeConst->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributeConst->setChecked(false);
    }
    if(elements->getIsPointer())
    {
        ui->checkBox_AttributePointer->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributePointer->setChecked(false);
    }
    if(elements->getIsRef())
    {
        ui->checkBox_AttributeReference->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributeReference->setChecked(false);
    }
    if(elements->getIsMemoryConstant())
    {
        ui->checkBox_MemoryPointerConst->setChecked(true);
    }
    else
    {
        ui->checkBox_MemoryPointerConst->setChecked(false);
    }
    if(elements->getIsDefaultValue())
    {
        ui->checkBox_DefaultValue->setDisabled(false);
        ui->checkBox_DefaultValue->setChecked(true);
        ui->lineEdit_DefaultValue->setDisabled(false);
        ui->lineEdit_DefaultValue->setText(vecElements[0].get()->getDefaultValue());
    }
}



void AttributeWidget::loadDatasFromGuiElements()
{
    vecElements.push_back(std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements()));
    vecElements[0].get()->setAttribute(ui->lineEdit_Name->text());
    vecElements[0].get()->setTyp(ui->comboBox_Type->currentText());
    if(ui->radioButton_Private->isChecked())
    {
       vecElements[0].get()->setModifier(Codegenerator::CodegeneratorConstants::modifierPrivate);
    }
    else if(ui->radioButton_Protected->isChecked())
    {
       vecElements[0].get()->setModifier(Codegenerator::CodegeneratorConstants::modifierProtected);
    }
    else
    {
       vecElements[0].get()->setModifier(Codegenerator::CodegeneratorConstants::modifierPublic);
    }
    if(ui->checkBox_AttributeConst->isChecked())
    {
        vecElements[0].get()->setIsConstant(true);
    }
    else
    {
        vecElements[0].get()->setIsConstant(false);
    }
    if(ui->checkBox_AttributePointer->isChecked())
    {
        vecElements[0].get()->setIsPointer(true);
    }
    else
    {
        vecElements[0].get()->setIsPointer(false);
    }
    if(ui->checkBox_AttributeReference->isChecked())
    {
        vecElements[0].get()->setIsRef(true);
    }
    else
    {
        vecElements[0].get()->setIsRef(false);
    }
    if(ui->checkBox_MemoryPointerConst->isChecked())
    {
        vecElements[0].get()->setIsMemoryConstant(true);
    }
    else
    {
        vecElements[0].get()->setIsMemoryConstant(false);
    }
    if(ui->checkBox_DefaultValue->isChecked())
    {
        vecElements[0].get()->setDefaultValue(ui->lineEdit_DefaultValue->text());
    }
}


void AttributeWidget::fillGuiWithElements()
{

    ui->lineEdit_Name->setText(vecElements[0].get()->getAttribute());
    if(vecElements[0].get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierPrivate)
    {
        ui->radioButton_Private->setChecked(true);
    }
    if(vecElements[0].get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierProtected)
    {
        ui->radioButton_Protected->setChecked(true);
    }
    if(vecElements[0].get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierPublic)
    {
        ui->radioButton_Public->setChecked(true);
    }
    if(vecElements[0].get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierPublic)
    {
        ui->radioButton_Public->setChecked(true);
    }
    if(vecElements[0].get()->getIsConstant())
    {
        ui->checkBox_AttributeConst->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributeConst->setChecked(false);
    }
    if(vecElements[0].get()->getIsPointer())
    {
        ui->checkBox_AttributePointer->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributePointer->setChecked(false);
    }
    if(vecElements[0].get()->getIsRef())
    {
        ui->checkBox_AttributeReference->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributeReference->setChecked(false);
    }
    if(vecElements[0].get()->getIsMemoryConstant())
    {
        ui->checkBox_MemoryPointerConst->setChecked(true);
    }
    else
    {
        ui->checkBox_MemoryPointerConst->setChecked(false);
    }
    if(vecElements[0].get()->getIsDefaultValue())
    {
        ui->checkBox_DefaultValue->setDisabled(false);
        ui->checkBox_DefaultValue->setChecked(true);
        ui->lineEdit_DefaultValue->setDisabled(false);
        ui->lineEdit_DefaultValue->setText(vecElements[0].get()->getDefaultValue());
    }
}


