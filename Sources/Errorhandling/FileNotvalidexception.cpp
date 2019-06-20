#include "FileNotvalidexception.h"

namespace Errorhandling
{



Exceptionhandling::ExceptionCodes FileNotValidException::whatCode() const
{
    return ExceptionCodes::FileNotValidException;
}

std::string FileNotValidException::whatDescription() const
{
    return error;
}

}


