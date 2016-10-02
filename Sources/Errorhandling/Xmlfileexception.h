#ifndef XMLFILEEXCEPTIONH_H
#define XMLFILEEXCEPTIONH_H

#include "Exceptionhandling.h"
#include <string>

namespace Errorhandling
{

class XMLFileException : public Exceptionhandling
{
public:
    XMLFileException();
    virtual ~XMLFileException();
    Exceptionhandling::ExceptionCodes whatCode() const throw ();
    virtual std::string whatDescription() const throw ();
private:
    const std::string error = "xml format not valid";
};

}

#endif // XMLFILEEXCEPTIONH_H
