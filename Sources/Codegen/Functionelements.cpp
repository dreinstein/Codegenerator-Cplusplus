#include "Functionelements.h"

namespace Codegenerator
{

FunctionElements::FunctionElements()
{

}

void FunctionElements::setElements(QString element)
{
    AttributeElements::setElements(element);
    QStringList stringList = General::ExtractString::extractStringList(element);
    function = General::ExtractString::extractLast(stringList[3]);
}

}
