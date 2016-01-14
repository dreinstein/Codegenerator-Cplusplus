#include "Basecodegenerator.h"
#include "classgenerator.h"


namespace Codegenerator
{



BaseCodegenerator* BaseCodegenerator::getClassForNextElement(QString sindex)
{
    BaseCodegenerator *generator = nullptr;
    sindex = sindex.toLower();
    if("class" == sindex)
    {
        generator = new ClassGenerator();
        return generator;
    }
    Q_ASSERT(false);
}

}
