#include "OpenfileException.h"

namespace Errorhandling
{



OpenFileException::OpenFileException()
{

}

OpenFileException::~OpenFileException()
{

}

Exceptionhandling::ExceptionCodes OpenFileException::whatCode() const
{
    return Exceptionhandling::ExceptionCodes::OpenFileException;
}

std::string OpenFileException::whatDescription() const
{
    return error;
}

}
