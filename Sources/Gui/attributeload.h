#ifndef ATTRIBUTELOADANDFORMATE_H
#define ATTRIBUTELOADANDFORMATE_H

#include "Codegen/Attributeelements.h"

#include <memory>
#include <vector>

namespace Ui
{
    class AttributeWidget;
}

class AttributeWidget;

using namespace std;

class AttributeLoad
{
public:
    AttributeLoad(){;}
    ~AttributeLoad(){;}
    vector<std::unique_ptr<Codegenerator::AttributeElements>> loadDatasFromFile(QString path);
};



#endif // ATTRIBUTELOADANDFORMATE_H
