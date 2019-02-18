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
    virtual ~XMLFileException() override;
    Exceptionhandling::ExceptionCodes whatCode() const override final;
    virtual std::string whatDescription() const override final;
private:
    const std::string error = "xml format not valid";
};

}

#endif // XMLFILEEXCEPTIONH_H
