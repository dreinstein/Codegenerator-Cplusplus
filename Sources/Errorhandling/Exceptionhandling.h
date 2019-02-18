#ifndef EXCETIONHANDLING_H
#define EXCETIONHANDLING_H

#include <string>


using namespace std;

#include <string>

namespace Errorhandling
{

class Exceptionhandling//:public std::exception
{
public:
    enum class ExceptionCodes
    {
        OpenFileException       = 1,
        ScriptException         = 2,
        FileNotValidException   = 3,
        XMLNotValidException    = 4
    };


public:
    Exceptionhandling(){;}
    virtual ~Exceptionhandling(){;}
    virtual ExceptionCodes whatCode() const = 0;
    virtual std::string whatDescription() const  = 0;
};

}

#endif // EXCETIONHANDLING_H
