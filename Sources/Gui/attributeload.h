#ifndef ATTRIBUTELOADANDFORMATE_H
#define ATTRIBUTELOADANDFORMATE_H


#include "baseLoadAndFormate.h"
namespace Ui
{
    class AttributeWidget;
}

class AttributeWidget;



class AttributeLoad : public BaseLoadAndFormate
{
public:
    AttributeLoad(){;}
    virtual ~AttributeLoad(){;}
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  loadDatasFromFile(QString path) override final;
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>> loadDatasFromGuiElements(Ui::AttributeWidget *ui ) override final;
};



#endif // ATTRIBUTELOADANDFORMATE_H
