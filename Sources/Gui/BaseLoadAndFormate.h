#ifndef IWIDGET_H
#define IWIDGET_H

#include <QString>
#include "../Codegen/Attributeelements.h"
#include "memory"

namespace Ui
{
    class AttributeWidget;
}


class BaseLoadAndFormate
{
public:
    virtual ~BaseLoadAndFormate(){;}
    // load datas from file to vector data set
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>> loadDatasFromFile(QString path)=0;
    // load datas from vector dataset to ui elements
    virtual std::vector<std::unique_ptr<Codegenerator::AttributeElements>> loadDatasFromGuiElements(Ui::AttributeWidget *ui )=0;
};


#endif // IWIDGET_H
