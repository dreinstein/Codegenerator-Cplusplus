#ifndef ATTRIBUTELOADANDFORMATE_H
#define ATTRIBUTELOADANDFORMATE_H

#include "baseLoadAndFormate.h"



class AttributeLoadAndFormate : public BaseLoadAndFormate
{
public:
    AttributeLoadAndFormate();
    QString getFormatedString() override final;
     virtual std::unique_ptr<Codegenerator::AttributeElements> loadDataSet(QString path) override final;
};



#endif // ATTRIBUTELOADANDFORMATE_H
