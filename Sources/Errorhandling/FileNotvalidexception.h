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
    int whatCode() const throw ();
    std::string whatDescription() const throw ();
private:
    const std::string error = "File is not valid";
};

}

#endif // FILENOVALIDEXCEPTION_H
