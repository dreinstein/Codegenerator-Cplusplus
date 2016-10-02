#ifndef SCRIPTEXCEPTION_H
#define SCRIPTEXCEPTION_H

#include "Exceptionhandling.h"

namespace Errorhandling
{

class ScriptException : public Exceptionhandling
{

public:
    ScriptException();
    virtual ~ScriptException();
    Exceptionhandling::ExceptionCodes whatCode() const throw () override final;
    virtual std::string whatDescription() const throw () override ;
private:
    const std::string error = "script Error";
};

}

#endif // SCRIPTEXCEPTION_H
