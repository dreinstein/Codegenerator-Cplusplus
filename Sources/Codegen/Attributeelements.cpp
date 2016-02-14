#include "QString"
#include "Attributeelements.h"


namespace Codegenerator
{

AttributeElements::AttributeElements()
{

}

void AttributeElements::setElements(QString element)
{
    QStringList stringList = General::ExtractString::extractStringList(element);
    modifierKeyword = General::ExtractString::extractFirst(stringList[0]);
    modifier = General::ExtractString::extractLast(stringList[0]);
    typ = General::ExtractString::extractLast(stringList[1]);
    attribute = General::ExtractString::extractLast(stringList[2]);
}

}
