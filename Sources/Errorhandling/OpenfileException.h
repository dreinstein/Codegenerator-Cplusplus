#ifndef CODEGENERATOREXECPTIONS_H
#define CODEGENERATOREXECPTIONS_H

#include "Exceptionhandling.h"
#include <string>


namespace Errorhandling
{

class OpenFileException: public Exceptionhandling
{
private:
public:
    OpenFileException();
    virtual ~OpenFileException();
    Exceptionhandling::ExceptionCodes whatCode() const throw () override final;
    std::string whatDescription() const throw () override final;
private:
    const std::string error = "annot read File";
};

}

#endif // CODEGENERATOREXECPTIONS_H
