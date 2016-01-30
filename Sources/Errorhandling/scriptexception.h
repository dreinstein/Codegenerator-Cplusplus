#ifndef SCRIPTEXCEPTION_H
#define SCRIPTEXCEPTION_H

#include "Exceptionhandling.h"

namespace Errorhandling
{

class ScriptException : public Exceptionhandling
{
private:
public:
    ScriptException();
    virtual ~ScriptException();
    int whatCode() const throw ();
    virtual std::string whatDescription() const throw ();
};

}

#endif // SCRIPTEXCEPTION_H
