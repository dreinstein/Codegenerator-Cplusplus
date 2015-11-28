#ifndef GENERATOR
#define GENERATOR

#include <string>

class BaseGenerator
{
public:
    virtual ~BaseGenerator(){;};
    virtual void generate()=0;
    virtual void receiveData(std::vector<std::string> strv,int parserId)=0;
    virtual void notify(int id)=0;
};

#endif // GENERATOR

