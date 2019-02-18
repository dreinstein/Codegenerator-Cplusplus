#ifndef SCRIPTEXCEPTION_H
#define SCRIPTEXCEPTION_H

#include "Exceptionhandling.h"

namespace Errorhandling
{

class ScriptException : public Exceptionhandling
{

public:
    ScriptException() ;
    virtual ~ScriptException();// override;
    Exceptionhandling::ExceptionCodes whatCode() const override final;
    virtual std::string whatDescription() const override ;
private:
    const std::string error = "script Error";
};

}

#endif // SCRIPTEXCEPTION_H
