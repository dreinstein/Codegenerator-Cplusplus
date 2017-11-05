#ifndef FUNCTIONLOAD_H
#define FUNCTIONLOAD_H


#include "Codegen/Functionelements.h"
#include <memory>


namespace Ui
{
    class AttributeWidget;
}

class AttributeWidget;


class FunctionLoad
{
public:
    FunctionLoad(){;}
    ~FunctionLoad(){;}
    std::vector<std::unique_ptr<Codegenerator::FunctionElements>> loadDatasFromFile(QString path);
};

#endif // FUNCTIONLOAD_H
