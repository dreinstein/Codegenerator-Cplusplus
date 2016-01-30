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
};

}

#endif // ATTRIBUTESCRIPTEXCEPTION_H
