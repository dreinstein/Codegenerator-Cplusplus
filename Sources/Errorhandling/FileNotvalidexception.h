#ifndef FILENOVALIDEXCEPTION_H
#define FILENOVALIDEXCEPTION_H

#include <string>
#include "Exceptionhandling.h"

namespace Errorhandling
{

class FileNotValidException : public Exceptionhandling
{
public:
    FileNotValidException();
    virtual ~FileNotValidException();
    Exceptionhandling::ExceptionCodes whatCode() const throw () override final;
    std::string whatDescription() const throw () override final;
private:
    const std::string error = "File is not valid";
};

}

#endif // FILENOVALIDEXCEPTION_H
