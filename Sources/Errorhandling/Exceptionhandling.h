#ifndef EXCETIONHANDLING_H
#define EXCETIONHANDLING_H

#include <string>
#include <exception>

using namespace std;

#include <string>

namespace Errorhandling
{

class Excetionhandling:public exception
{
protected:
    enum ExcetionCode
    {
        OpenFileException = 1
    };


public:
   // Excetionhandling();
    virtual ~Excetionhandling(){;};
    virtual int whatCode() const throw ()=0;
    virtual std::string whatDescription() const throw () = 0;
};

}

#endif // EXCETIONHANDLING_H
