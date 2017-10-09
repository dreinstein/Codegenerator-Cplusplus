#include "attributewidget.h"
#include "ui_attributewidget.h"
#include "../Codegen/Codegeneratorconstants.h"
#include "Codegen/Attributeelements.h"
#include "Utilities.h"
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
   }
   else
   {
       this->setWindowTitle(attributeString);
   }
   ui->radioButton_Private->setChecked(true);
   ui->radioButton_Protected->setChecked(false);
   ui->radioButton_Public->setChecked(false);
   ui->checkBox_MemoryPointerConst->setDisabled(true);
   QStringList itemList;
   itemList << Codegenerator::CodegeneratorConstants::typInt << Codegenerator::CodegeneratorConstants::typDouble << Codegenerator::CodegeneratorConstants::typLong << Codegenerator::CodegeneratorConstants::typQString << Codegenerator::CodegeneratorConstants::typVoid;
   ui->comboBox_Type->addItems(itemList);
}

AttributeWidget::~AttributeWidget()
{
    delete ui;
    ui = nullptr;

}

void AttributeWidget::on_pushButton__Close_clicked()
{
   emit closeAttributeWidget();
}

void AttributeWidget::on_pushButton_Save_clicked()
{
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
        std::unique_ptr<BaseLoadAndFormate> datas =  std::unique_ptr<BaseLoadAndFormate>(new AttributeLoad());
        vecElements = datas->loadDataSet(fileName);
        fillGuiWithElements();
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
}




