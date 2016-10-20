#include "parserimplementationxml.h"

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QXmlStreamAttribute>
#include <windows.h>
#include <string>
#include "../Errorhandling/Xmlfileexception.h"
#include "../Errorhandling/OpenfileException.h"


namespace NParser
{


std::vector<QString> ParserImplXML::doParseForVec(const QString path)
{
    QFile fin(path);
    if (fin.open(QIODevice::ReadOnly))
    {
       reader.setDevice(&fin);
       parseAndStoreToVec();
       fin.close();
    }
    else
    {
      throw Errorhandling::OpenFileException();
    }
    return xmlValues;
}


void ParserImplXML::parseAndStoreToVec()
{
    vecElement = emptyChar;
    while(!reader.atEnd() &&  !reader.hasError())
    {

        reader.readNextStartElement();
        // check Error
        if(reader.hasError())
        {
            // this is the end of file
            if(reader.error() == QXmlStreamReader::PrematureEndOfDocumentError)
            {
                break;
            }
            // something other go wrong
            else
            {
                throw Errorhandling::XMLFileException();
            }
        }
        // if root ignore
        if(reader.name() == "root")
        {
            continue;
        }
        // here we should check if we are at root and has to be break the loop
        if(mustLoopBeInterrupted())
        {
            break;
        }

        // store the Values
        storeValue();
   }
}



// get hash fileName(Keyword,path)
std::map<QString, QString> ParserImplXML::doParseForMap(const QString) const
{
    std::map<QString,QString> map;
    Q_ASSERT(true);
    return map;
}

void  ParserImplXML::storeValue()
{
    QString tagElement;
    QXmlStreamAttributes attributeStream;
    QString attribute;
    if(reader.isStartElement())
    {
        tagElement = reader.name().toString();
        if(isClassString())
        {
           className = reader.attributes().at(0).value().toString();
           isClassPrefixNecessary = true;
           return;
        }
        attributeStream = reader.attributes();
        vecElement += at + tagElement + doubleColon;
        if(isClassPrefixNecessary)
        {
            vecElement = at + classStr + doubleColon + className + vecElement;
            // do it only once for the vecElement
            isClassPrefixNecessary = false;
        }
        if(attributeStream.count()>0)
        {
            attribute = attributeStream.at(0).value().toString();
            vecElement += attribute;
            startElement = reader.name().toString();
        }
        else
        {
            vecElement +=  reader.readElementText();
        }
    }
    pushInVectorArray();
}


void ParserImplXML::pushInVectorArray()const
{
    if(reader.isEndElement())
    {
        if(startElement == reader.name().toString())
        {
            xmlValues.push_back(vecElement);
            vecElement.clear();
            startElement = emptyChar;
            if(className !="")
            {
                // classPrefix is necessary for new vecElement
                isClassPrefixNecessary = true;
            }

        }
    }
}

bool ParserImplXML::mustLoopBeInterrupted() const
{
    if(reader.isEndElement())
    {
        if (root == reader.name().toString())
        {
            return true;
        }
    }
    return false;
}

bool ParserImplXML::isClassString()
{
    if(reader.name().toString() == classStr)
    {       
        return true;
    }
    return false;
}


}
