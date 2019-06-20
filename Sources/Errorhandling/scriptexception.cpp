#include "Scriptexception.h"


namespace Errorhandling
{



Exceptionhandling::ExceptionCodes ScriptException::whatCode() const
{
    return ExceptionCodes::ScriptException;
}

std::string ScriptException::whatDescription() const
{
    return error;
}

}

