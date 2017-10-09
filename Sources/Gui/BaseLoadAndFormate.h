#ifndef IWIDGET_H
#define IWIDGET_H

#include <QString>
#include "../Codegen/Attributeelements.h"
#include "memory"




class BaseLoadAndFormate
{
public:
    virtual ~BaseLoadAndFormate(){;}
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  loadDataSet(QString path)=0;
};


#endif // IWIDGET_H
