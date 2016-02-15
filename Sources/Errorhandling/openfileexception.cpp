#include "OpenfileException.h"

namespace Errorhandling
{

OpenFileException::OpenFileException()
{

}

OpenFileException::~OpenFileException()
{

}

int OpenFileException::whatCode() const throw ()
{
    return ExceptionCode::OpenFileException;
}

std::string OpenFileException::whatDescription() const throw ()
{
    return error;
}

}
