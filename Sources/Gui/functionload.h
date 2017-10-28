#ifndef FUNCTIONLOAD_H
#define FUNCTIONLOAD_H

#include "baseLoadAndFormate.h"

namespace Ui
{
    class AttributeWidget;
}

class AttributeWidget;


class FunctionLoad : public BaseLoadAndFormate
{
public:
    FunctionLoad(){;}
    virtual ~FunctionLoad(){;}
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  loadDatasFromFile(QString path) override final;
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>> loadDatasFromGuiElements(Ui::AttributeWidget *ui ) override final;
};

#endif // FUNCTIONLOAD_H
