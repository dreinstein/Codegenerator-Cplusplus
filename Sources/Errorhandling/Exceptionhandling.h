#ifndef EXCETIONHANDLING_H
#define EXCETIONHANDLING_H

#include <string>
#include <exception>

using namespace std;

#include <string>

namespace Errorhandling
{

class Exceptionhandling:public exception
{
protected:
    enum class ExceptionCodes
    {
        OpenFileException       = 1,
        ScriptException         = 2,
        FileNotValidException   = 3,
        XMLNotValidException    = 4
    };


public:
   // Excetionhandling();
    virtual ~Exceptionhandling(){;}
    virtual ExceptionCodes whatCode() const throw ()=0;
    virtual std::string whatDescription() const throw () = 0;
};

}

#endif // EXCETIONHANDLING_H
