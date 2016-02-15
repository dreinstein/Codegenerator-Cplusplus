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
    int whatCode() const throw ();
    std::string whatDescription() const throw ();
private:
    const std::string error = "Cannot generateFile";
};

}

#endif // CODEGENERATOREXECPTIONS_H
