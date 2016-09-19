#ifndef CLASSELEMENTS_H
#define CLASSELEMENTS_H

#include <QString>
#include "Utilities.h"

namespace Codegenerator
{

class ClassElements
{
public:
    ClassElements();
    ~ClassElements(){;}
    QString getClassName() {return className;}
private:
    QString className;
};

}

#endif // CLASSELEMENTS_H
