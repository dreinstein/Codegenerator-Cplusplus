#ifndef ATTRIBUTELOADANDFORMATE_H
#define ATTRIBUTELOADANDFORMATE_H

#include "baseLoadAndFormate.h"



class AttributeLoadAndFormate : public BaseLoadAndFormate
{
public:
    AttributeLoadAndFormate();
    QString getFormatedString() override final;
    virtual void loadDataSet(QString path) override final;
    virtual std::unique_ptr<Codegenerator::AttributeElements> getElement() override final;

private:
    std::unique_ptr<Codegenerator::AttributeElements> elements;
    static const int attributePos = 1;
};



#endif // ATTRIBUTELOADANDFORMATE_H
