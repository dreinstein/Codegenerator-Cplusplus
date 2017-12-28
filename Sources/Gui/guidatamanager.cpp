#include "guidatamanager.h"



void GuiDataManager::push(const std::shared_ptr<Codegenerator::FunctionElements> ele)
{
    funcElements.push_back(ele);
    elements.push_back(ele.get());
}


void GuiDataManager::push(const std::shared_ptr<Codegenerator::AttributeElements> ele)
{
    attrElements.push_back(ele);
    elements.push_back(ele.get());
}


void GuiDataManager::change(const std::shared_ptr<Codegenerator::FunctionElements> ele, const unsigned int pos)
{
    if(elements.size() > (pos) )
    {
        funcElements.push_back(ele);
        changeBase(ele.get(), pos);
    }
}

void GuiDataManager::change(const std::shared_ptr<Codegenerator::AttributeElements> ele, const unsigned int pos)
{
    if(elements.size() > (pos) )
    {
        attrElements.push_back(ele);
        changeBase(ele.get(), pos);
    }
}

void GuiDataManager::up(const unsigned int pos)
{
    if((elements.size() > (pos)) && (pos > 0))
    {
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + pos;
        Codegenerator::BaseElements *tempElement = elements.at(pos);
        elements.erase(it);
        elements.insert(it-1,tempElement);
    }
}

void GuiDataManager::down(const unsigned int pos)
{
    if(elements.size() > (pos+1) )
    {
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + pos;
        Codegenerator::BaseElements *tempElement = elements.at(pos);
        elements.erase(it);
        elements.insert(it+1,tempElement);
    }
}


void GuiDataManager::deleteItem(const unsigned int pos)
{
    if(elements.size() > (pos) )
    {
        std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + pos;
        elements.erase(it);
    }
}

GuiDataManager::WidgetTypes GuiDataManager::getWidgetTyp(unsigned int pos)
{
     if(elements.size() > (pos) )
     {
        if(dynamic_cast<Codegenerator::AttributeElements*>(elements[pos]))
        {
             return WidgetTypes::ATTRIBUTTETYPE;
        }
        else if(dynamic_cast<Codegenerator::FunctionElements*>(elements[pos]))
        {
             return WidgetTypes::FUNCTIONTYPE;
        }
        else
        {
            return WidgetTypes::ERRORTYP;
        }
     }
     return WidgetTypes::ERRORTYP;
}


Codegenerator::AttributeElements* GuiDataManager::getAttributeElement(unsigned int pos) const
{
   if(elements.size() > (pos) )
   {
    return  dynamic_cast<Codegenerator::AttributeElements*>(elements[pos]);
   }
   else
   {
       return nullptr;
   }
}


Codegenerator::FunctionElements* GuiDataManager::getFunctionElement(unsigned int pos) const
{
    if(elements.size() > (pos) )
    {
        return  dynamic_cast<Codegenerator::FunctionElements*>(elements[pos]);
    }
    else
    {
        return nullptr;
    }
}


void GuiDataManager::changeBase(Codegenerator::BaseElements* ele, const unsigned int pos)
{
    std::vector<Codegenerator::BaseElements*>::iterator it = elements.begin() + pos;
    elements.insert(it,ele);
    it = elements.begin() + pos+1;
    elements.erase(it);
}




