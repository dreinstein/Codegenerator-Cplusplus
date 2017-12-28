#ifndef GUIDATAMANAGER_H
#define GUIDATAMANAGER_H

#include <memory>
#include <vector>
#include "Codegen/Attributeelements.h"
#include "Codegen/Functionelements.h"


class GuiDataManager
{
public:
    enum class WidgetTypes
    {
        ATTRIBUTTETYPE = 0,
        FUNCTIONTYPE =  1,
        ERRORTYP = 255
    };


public:
    explicit  GuiDataManager() = default;
    ~GuiDataManager() = default;
public:
    std::vector<Codegenerator::BaseElements*> getElements() {return elements;}
    void push(const std::shared_ptr<Codegenerator::FunctionElements>);
    void push(const std::shared_ptr<Codegenerator::AttributeElements>);

    void change(const std::shared_ptr<Codegenerator::FunctionElements>, const unsigned int pos);
    void change(const std::shared_ptr<Codegenerator::AttributeElements>, const unsigned int pos);

    Codegenerator::AttributeElements* getAttributeElement(unsigned int pos) const;
    Codegenerator::FunctionElements* getFunctionElement(unsigned int pos) const;


    void up(const unsigned int pos);
    void down(const unsigned int pos);
    void deleteItem(const unsigned int pos);

    WidgetTypes getWidgetTyp(unsigned int pos);


private:
    std::vector<std::shared_ptr<Codegenerator::FunctionElements>>  funcElements;
    std::vector<std::shared_ptr<Codegenerator::AttributeElements>> attrElements;
    std::vector<Codegenerator::BaseElements*> elements;
    void changeBase(Codegenerator::BaseElements* ele, const unsigned int pos);
};

#endif // GUIDATAMANAGER_H
