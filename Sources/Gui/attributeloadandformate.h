#ifndef ATTRIBUTELOADANDFORMATE_H
#define ATTRIBUTELOADANDFORMATE_H

#include "baseLoadAndFormate.h"



class AttributeLoadAndFormate : public BaseLoadAndFormate
{
public:
    AttributeLoadAndFormate();
    QString getFormatedString() override final;
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  loadDataSet(QString path) override final;
private:
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>> elementVec;
    static const int attributePos = 1;
};



#endif // ATTRIBUTELOADANDFORMATE_H
