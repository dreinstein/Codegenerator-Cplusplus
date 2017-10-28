#include "attributeload.h"
#include "Parsing/parserimplementationxml.h"
#include "attributewidget.h"
#include "ui_attributewidget.h"
#include "../Codegen/Codegeneratorconstants.h"



std::vector<std::unique_ptr<Codegenerator::AttributeElements>> AttributeLoad::loadDatasFromGuiElements(Ui::AttributeWidget *ui)
{
    std::unique_ptr<Codegenerator::AttributeElements> element;
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>> vecElements;
    vecElements.push_back(std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements()));
    vecElements[0].get()->setAttribute(ui->lineEdit_Name->text());
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
     return std::move(vecElements);
}



std::vector<std::unique_ptr<Codegenerator::AttributeElements>> AttributeLoad::loadDatasFromFile(QString path)
{
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>> vecElements;
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    auto script = parser->doParseForVec(path);

    QString v="";
    auto index = 0;
    auto vecIndex = 0;
    for(auto iterator = script.begin();iterator != script.end();++iterator,++index)
    {
        v = General::ExtractString::extractFirst(script[index]);
        if(v == "attribute")
        {
            vecElements.push_back(std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements()));
            vecElements[vecIndex].get()->resetData();
            vecElements[vecIndex].get()->setElements(script[index]);
            vecIndex++;
        }
    }
    return std::move(vecElements);
}


