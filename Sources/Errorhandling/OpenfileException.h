#ifndef CODEGENERATOREXECPTIONS_H
#define CODEGENERATOREXECPTIONS_H

#include "Exceptionhandling.h"
#include <string>
#include <exception>


namespace Errorhandling
{

class OpenFileException:public Exceptionhandling
{
public:
    OpenFileException(); //noexcept ;
    virtual ~OpenFileException() override;
    virtual ExceptionCodes whatCode() const override;
    virtual std::string whatDescription() const override;
private:
    const std::string error = "cannot read File";
};

}

#endif // CODEGENERATOREXECPTIONS_H
