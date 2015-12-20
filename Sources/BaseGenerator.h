#ifndef GENERATOR
#define GENERATOR

#include <string>
#include <vector>
#include <string>

#include "../gtest/gtest.h"

namespace Logic
{

class BaseGenerator
{
public:
    virtual ~BaseGenerator(){;};
    virtual void generate()=0;
    virtual void receiveData(std::vector<std::string> strv,int parserId)=0;
    virtual void notify(int id)=0;
protected:
    std::vector<std::string> keywords;
    std::vector<std::string> rules;
};

} // end namespace
#endif // GENERATOR

