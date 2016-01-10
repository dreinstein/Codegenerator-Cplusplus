#ifndef CODEGENERATOREXECPTIONS_H
#define CODEGENERATOREXECPTIONS_H

#include "Exceptionhandling.h"
#include <string>


namespace Errorhandling
{

class OpenFileException: public Excetionhandling
{
private:
public:
    OpenFileException();
    virtual ~OpenFileException();
    int whatCode() const throw ();
    std::string whatDescription() const throw ();
};

}

#endif // CODEGENERATOREXECPTIONS_H
