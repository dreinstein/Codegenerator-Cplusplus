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
#ifndef Test
    emit saveAttributeWidget();
#endif
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
        std::unique_ptr<BaseLoadAndFormate> datas =  std::unique_ptr<BaseLoadAndFormate>(new AttributeLoadAndFormate());
        std::vector<std::unique_ptr<Codegenerator::AttributeElements>> vecElements = datas->loadDataSet(fileName);
        fillGuiWithElements(std::move(vecElements[0]));
    }
}


void AttributeWidget::fillGuiWithElements(std::unique_ptr<Codegenerator::AttributeElements> element)
{

    ui->lineEdit_Name->setText(element.get()->getAttribute());
    if(element.get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierPrivate)
    {
        ui->radioButton_Private->setChecked(true);
    }
    if(element.get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierProtected)
    {
        ui->radioButton_Protected->setChecked(true);
    }
    if(element.get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierPublic)
    {
        ui->radioButton_Public->setChecked(true);
    }
    if(element.get()->getModifier() == Codegenerator::CodegeneratorConstants::modifierPublic)
    {
        ui->radioButton_Public->setChecked(true);
    }
    if(element.get()->getIsConstant())
    {
        ui->checkBox_AttributeConst->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributeConst->setChecked(false);
    }
    if(element.get()->getIsPointer())
    {
        ui->checkBox_AttributePointer->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributePointer->setChecked(false);
    }
    if(element.get()->getIsRef())
    {
        ui->checkBox_AttributeReference->setChecked(true);
    }
    else
    {
        ui->checkBox_AttributeReference->setChecked(false);
    }
    if(element.get()->getIsMemoryConstant())
    {
        ui->checkBox_MemoryPointerConst->setChecked(true);
    }
    else
    {
        ui->checkBox_MemoryPointerConst->setChecked(false);
    }
}






/*QString AttributeWidget::getFormatedString()
{

    Codegenerator::AttributeModifiers modifiers;

    modifiers.attribute = ui->lineEdit_Name->text();
    // not availible
    modifiers.defaultValue="";
    modifiers.isConstant = ui->checkBox_AttributeConst->isChecked();
    // passt nicht, nur ein Wert notwendig
    modifiers.isMemoryConstant = ui->checkBox_MemoryPointerConst;
    modifiers.isPointer = ui->checkBox_AttributePointer;
    modifiers.isRef = ui->checkBox_AttributeReference;
    modifiers.typ = ui->comboBox_Type->currentText();
    modifiers.isParameter = parameterSetting;
    modifiers.modifier = Codegenerator::CodegeneratorConstants::modifierPrivate;
    

    if(!parameterSetting)
    {
        if(ui->radioButton_Protected->isChecked())
        {
             modifiers.modifier = Codegenerator::CodegeneratorConstants::modifierProtected;
        }
        else if(ui->radioButton_Public->isChecked())
        {
             modifiers.modifier = Codegenerator::CodegeneratorConstants::modifierPublic;
        }
    }

    QString listElement="";

    // 1. attributeName
    listElement += General::ExtractString::STRINGSEPERATOR;
    listElement += General::ElementStrings::ATTRIBUEELEMENT;
    listElement += General::ExtractString::SUBSTRINGSEPERATOR;
    listElement += ui->lineEdit_Name->text();

    // 2. modifier, if not a parameter
    if(!parameterSetting)
    {
        listElement += General::ExtractString::STRINGSEPERATOR;
        listElement += General::ElementStrings::MODIFIERELEMENT;
        listElement += General::ExtractString::SUBSTRINGSEPERATOR;
        listElement += modifiers.modifier;
    }

    // 3. typ
    listElement += General::ExtractString::STRINGSEPERATOR;
    listElement += General::ElementStrings::TYPELEMENT;
    listElement += General::ExtractString::SUBSTRINGSEPERATOR;
    listElement += modifiers.typ;
    
    
    // 4.typ pointer
    if( modifiers.isPointer)
    {
        listElement += General::ExtractString::STRINGSEPERATOR;
        listElement += General::ElementStrings::ISPOINTERELEMENT;

        // 4.2 pointer const
        if(modifiers.isConstant)
        {
            listElement += General::ExtractString::STRINGSEPERATOR;
            listElement += General::ElementStrings::ISCONSTANTELEMENT;
        }

        // 4.3
        if(modifiers.isMemoryConstant)
        {
            listElement += General::ExtractString::STRINGSEPERATOR;
            listElement += General::ElementStrings::ISMEMORYCONSTANTELEMENT;
        }
    }

    // 5. Reference Typ

    if( modifiers.isRef)
    {
        listElement += General::ExtractString::STRINGSEPERATOR;
        listElement += General::ElementStrings::ISREFERENCEELEMENT;

        // 4.2 pointer const
        if(modifiers.isConstant)
        {
            listElement += General::ExtractString::STRINGSEPERATOR;
            listElement += General::ElementStrings::ISCONSTANTELEMENT;
        }

        // 4.3
        if(ui->checkBox_MemoryReferenceConst->isChecked())
        {
            listElement += General::ExtractString::STRINGSEPERATOR;
            listElement += General::ElementStrings::ISMEMORYCONSTANTELEMENT;
        }
    }

    return listElement;
}*/

