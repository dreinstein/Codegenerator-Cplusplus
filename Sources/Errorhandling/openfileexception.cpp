#include "OpenfileException.h"

namespace Errorhandling
{

OpenFileException::OpenFileException()
{

}

OpenFileException::~OpenFileException()
{

}

Exceptionhandling::ExceptionCodes OpenFileException::whatCode() const throw ()
{
    return ExceptionCodes::OpenFileException;
}

std::string OpenFileException::whatDescription() const throw ()
{
    return error;
}

}
