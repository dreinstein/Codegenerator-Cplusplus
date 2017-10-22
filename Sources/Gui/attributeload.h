#ifndef ATTRIBUTELOADANDFORMATE_H
#define ATTRIBUTELOADANDFORMATE_H

#include "baseLoadAndFormate.h"



class AttributeLoad : public BaseLoadAndFormate
{
public:
    AttributeLoad();
    virtual ~AttributeLoad();
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  loadDataSet(QString path) override final;
private:
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>> elementVec;

};



#endif // ATTRIBUTELOADANDFORMATE_H
