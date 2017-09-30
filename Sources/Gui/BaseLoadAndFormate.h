#ifndef IWIDGET_H
#define IWIDGET_H

#include <QString>
#include "../Codegen/Attributeelements.h"
#include "memory"




class BaseLoadAndFormate
{
public:
    virtual QString getFormatedString() = 0;
    virtual std::unique_ptr<Codegenerator::AttributeElements> getElement() = 0;
    virtual void loadDataSet(QString path)=0;
};


#endif // IWIDGET_H
