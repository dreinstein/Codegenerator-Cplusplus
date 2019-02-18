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
    virtual ~FileNotValidException();// override;
    Exceptionhandling::ExceptionCodes whatCode() const override final;
    std::string whatDescription() const override final;
private:
    const std::string error = "File is not valid";
};

}

#endif // FILENOVALIDEXCEPTION_H
