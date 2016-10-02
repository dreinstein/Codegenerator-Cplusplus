#include "FileNotvalidexception.h"

namespace Errorhandling
{

FileNotValidException::FileNotValidException()
{

}

FileNotValidException::~FileNotValidException()
{

}

Exceptionhandling::ExceptionCodes FileNotValidException::whatCode() const throw ()
{
    return ExceptionCodes::FileNotValidException;
}

std::string FileNotValidException::whatDescription() const throw ()
{
    return error;
}

}


