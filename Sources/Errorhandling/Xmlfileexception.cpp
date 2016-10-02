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

std::string XMLFileException::whatDescription() const throw ()
{
    return error;
}

Exceptionhandling::ExceptionCodes XMLFileException::whatCode() const throw ()
{
    return ExceptionCodes::XMLNotValidException;
}


}
