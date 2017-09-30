
#include <QtGlobal>
#include <QString>
#include "Utilities.h"
#include "Parsing/Parser.h"
#include "Base/BaseGenerator.h"
#include "Base/BaseEvaluator.h"
#include "Evaluator.h"
#include "GeneratorCPlusPlus.h"
#include "Codegen/CPluspluscodegenerator.h"
#include "ParserFassade.h"
#include "Codegeneratorfassade.h"



using namespace NParser;
using namespace Codegenerator;
using namespace General;


namespace NGenerator
{


GeneratorCPlusPlus::GeneratorCPlusPlus(QString str)
{
    pathScript = str;
}


GeneratorCPlusPlus::~GeneratorCPlusPlus()
{

}

void GeneratorCPlusPlus::generate()
{
    keywordsReceived = false;
    rulesReceived = false;
    scriptReceived = false;
    QString pathKeywords = General::FilePath::KeywordsCPlusPlus;
    QString pathRules = General::FilePath::RulesCPlusPlus;

    pCodegeneratorFassade =  std::unique_ptr<CodegeneratorFassade>(new CodegeneratorFassade(this,General::Languages::Parserlanguage::CPLUSPLUS));
    pParserFassade =  std::unique_ptr<ParserFassade>(new ParserFassade(this,General::Languages::Parserlanguage::CPLUSPLUS));
    pEvaluator = std::unique_ptr<BaseEvaluator> (new ScriptEvaluator());

    pParserFassade->ParseKeyword(pathKeywords);
    pParserFassade->ParseRules(pathRules);
    pParserFassade->ParseScript(pathScript);
}

void GeneratorCPlusPlus::notifyDatasGenerated(const General::ParserId::Id parserId)const
{
    // lock data
    switch(parserId)
    {
        case General::ParserId::Id::Keyword:
            pParserFassade->giveKeywordData();
        break;
        case General::ParserId::Id::Rules:
            pParserFassade->giveRulesData();
            break;
        case General::ParserId::Id::Script:
            pParserFassade->giveScriptData();
            break;
        default:
            Q_ASSERT(false);
    }
}

void GeneratorCPlusPlus::notifyCodeGenerated()const
{

}

void GeneratorCPlusPlus::allDatasReceived() const
{
    // evaluate script first (Script keywords regarding defined keywords)
    //@todo evaluate doesn't work
    // @todo also evaluate rules against keywords
  // bool evaluationOk = pEvaluator->evaluate(keywords,script);
    bool evaluate = true;

   if(evaluate)
    {
       // get correct rule
       // parameter script and rule
        pCodegeneratorFassade->generate(script,rules,keywords);
    }
    else
    {
        // showing evaluation was not ok!!
    }
}

// expect keywords and script
// rules are needed later
bool GeneratorCPlusPlus::areAllDatasReceived()
{
    if(keywordsReceived && scriptReceived && rulesReceived)
    {
        keywordsReceived = false;
        rulesReceived = false;
        scriptReceived = false;
        return true;
    }
    return false;
}

void GeneratorCPlusPlus::receiveCode(const std::list<QString>,const std::list<QString>)
{
    Q_ASSERT(false);
}


void GeneratorCPlusPlus::receiveData(const std::vector<QString> strv,const General::ParserId::Id parserId)
{
    switch(parserId)
    {
        case General::ParserId::Id::Keyword:
            keywords = strv;
            keywordsReceived = true;
            if(areAllDatasReceived())
            {
                allDatasReceived();
            }
            break;
        case General::ParserId::Id::Rules:
            Q_ASSERT(false);
            break;
        case General::ParserId::Id::Script:
            script = strv;
            scriptReceived = true;
            if(areAllDatasReceived())
            {
                allDatasReceived();
            }
            // this is the last, assume all is received
            break;
        default:
            Q_ASSERT(false);
    }
}

void GeneratorCPlusPlus::receiveData(const std::map<QString,QString> strv,const General::ParserId::Id parserId)
{
    switch(parserId)
    {
        case General::ParserId::Id::Keyword:
            Q_ASSERT(false);
            break;
        case General::ParserId::Id::Rules:
            rules = strv;
            rulesReceived = true;
            if(areAllDatasReceived())
            {
                allDatasReceived();
            }
            break;
        case General::ParserId::Id::Script:
            Q_ASSERT(false);
            break;
        default:
            Q_ASSERT(false);
    }
}


}



