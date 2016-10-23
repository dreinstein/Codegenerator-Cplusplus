#ifndef PARSERIMPLEMENTATIONXML_H
#define PARSERIMPLEMENTATIONXML_H

#include <vector>
#include <QString>
#include <map>
#include <qxmlstream.h>

#include "Base/BaseParserImplementation.h"

namespace NParser
{

class ParserImplXML : public BaseParserImpl
{
private:
    const QString at = "@";
    const QString doubleColon = "::";
    const QString emptyChar = " ";
    const QString root = "root";
    const QString classStr = "class";
    mutable QXmlStreamReader reader;
    mutable QString vecElement;
    mutable QString startElement;
    mutable QString className;
    mutable bool isClassPrefixNecessary;
    mutable std::vector<QString> xmlValues;
    void parseAndStoreToVec();
    void storeValue();
    void pushInVectorArray()const;
    bool mustLoopBeInterrupted() const;
    bool isClassString();
public:
    ParserImplXML(){className = "";isClassPrefixNecessary = false;}
    virtual ~ParserImplXML(){;}
    std::vector<QString> doParseForVec(const QString) override final;
    std::map<QString,QString> doParseForMap(const QString)const override final;
    void storeValues() override final;
};

}

#endif // PARSERIMPLEMENTATIONXML_H


