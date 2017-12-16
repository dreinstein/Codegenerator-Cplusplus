#ifndef BASEELEMENTS_H
#define BASEELEMENTS_H

#include<QString>



namespace Codegenerator
{

class BaseElements
{
public:
    BaseElements(){;}
    virtual ~BaseElements(){;}
    virtual void setElements(QString elements) = 0;
    virtual void defineElements(QString const listelement,QString const element) = 0;
    virtual void resetData() = 0;
    virtual QString getString(bool const  isParameter=false) = 0;

    template <class T>
    T& operator=(const T& classObj) {;}
};

}

#endif // BASEELEMENTS_H
