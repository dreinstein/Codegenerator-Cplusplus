#include "Functionscriptexception.h"
namespace Errorhandling
{

FunctionScriptException::FunctionScriptException()
{

}

FunctionScriptException::~FunctionScriptException()
{

}

std::string FunctionScriptException::whatDescription() const throw ()
{
    return error;
}

}


