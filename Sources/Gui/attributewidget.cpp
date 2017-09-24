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
   ui->checkBox_MemoryReferenceConst->setDisabled(true);
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

void AttributeWidget::on_checkBox_AttributeReference_clicked()
{
    if(ui->checkBox_AttributeReference->isChecked())
    {
        ui->checkBox_MemoryReferenceConst->setDisabled(false);
    }
    else
    {
         ui->checkBox_MemoryReferenceConst->setDisabled(true);
    }
}

void AttributeWidget::on_pushButton_Open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("File (*.xml)"));
    std::unique_ptr<AttributeLoadAndFormate> opendata =  std::unique_ptr<AttributeLoadAndFormate>(new AttributeLoadAndFormate());
    std::unique_ptr<Codegenerator::AttributeElements> elements = std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements());
    elements = opendata->loadDataSet(fileName);
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

