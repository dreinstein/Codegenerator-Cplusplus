#include "Xmlfileexception.h"
#include "Exceptionhandling.h"



namespace Errorhandling
{

XMLFileException::XMLFileException()
{

}

XMLFileException::~XMLFileException()
{

}

std::string XMLFileException::whatDescription() const
{
    return error;
}

Exceptionhandling::ExceptionCodes XMLFileException::whatCode() const
{
    return ExceptionCodes::XMLNotValidException;
}


}
