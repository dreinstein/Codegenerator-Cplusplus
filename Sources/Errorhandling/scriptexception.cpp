#include "Scriptexception.h"


namespace Errorhandling
{

ScriptException::ScriptException()
{

}

ScriptException::~ScriptException()
{

}

Exceptionhandling::ExceptionCodes ScriptException::whatCode() const throw ()
{
    return ExceptionCodes::ScriptException;
}

std::string ScriptException::whatDescription() const throw ()
{
    return error;
}

}

