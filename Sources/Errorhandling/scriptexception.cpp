#include "Scriptexception.h"


namespace Errorhandling
{

ScriptException::ScriptException()
{

}

ScriptException::~ScriptException()
{

}

int ScriptException::whatCode() const throw ()
{
    return ExceptionCode::ScriptException;
}

std::string ScriptException::whatDescription() const throw ()
{
    return "script Error";
}

}

