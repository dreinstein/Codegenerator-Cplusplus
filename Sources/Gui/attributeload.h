#ifndef ATTRIBUTELOADANDFORMATE_H
#define ATTRIBUTELOADANDFORMATE_H

#include "Codegen/Attributeelements.h"

#include <memory>

namespace Ui
{
    class AttributeWidget;
}

class AttributeWidget;



class AttributeLoad
{
public:
    AttributeLoad(){;}
    ~AttributeLoad(){;}
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>> loadDatasFromFile(QString path);
};



#endif // ATTRIBUTELOADANDFORMATE_H
