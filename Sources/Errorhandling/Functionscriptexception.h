#ifndef FUNCTIONSCRIPTEXCEPTION_H
#define FUNCTIONSCRIPTEXCEPTION_H

#include "Exceptionhandling.h"
#include "scriptexception.h"
#include <string>

namespace Errorhandling
{

class FunctionScriptException : public ScriptException
{
public:
    FunctionScriptException();
    virtual ~FunctionScriptException();// override final;
    virtual std::string whatDescription() const override final;
private:
    const std::string error = "Script error, error in defining Functions";
};

}

#endif // FUNCTIONSCRIPTEXCEPTION_H
