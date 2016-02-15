#ifndef ATTRIBUTESCRIPTEXCEPTION_H
#define ATTRIBUTESCRIPTEXCEPTION_H

#include "Exceptionhandling.h"
#include "scriptexception.h"
#include <string>


namespace Errorhandling
{

class AttributeScriptException : public ScriptException
{

private:
public:
    AttributeScriptException();
    virtual ~AttributeScriptException();
    virtual std::string whatDescription() const throw ();
private:
    const std::string error = "Script error, error in defining Attribute";
};

}

#endif // ATTRIBUTESCRIPTEXCEPTION_H
