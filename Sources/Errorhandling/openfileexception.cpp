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
    return ExcetionCode::OpenFileException;
}

std::string OpenFileException::whatDescription() const throw ()
{
    return "Cannot generateFile";
}

}
