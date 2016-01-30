#include "FileNotvalidexception.h"

namespace Errorhandling
{

FileNotValidException::FileNotValidException()
{

}

FileNotValidException::~FileNotValidException()
{

}

int FileNotValidException::whatCode() const throw ()
{
    return ExceptionCode::FileNotValidException;
}

std::string FileNotValidException::whatDescription() const throw ()
{
    return "File is not valid";
}

}


