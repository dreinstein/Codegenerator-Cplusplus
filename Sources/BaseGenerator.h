#ifndef GENERATOR
#define GENERATOR


#include <string>
#include <vector>
#include <string>
<<<<<<< HEAD

#include "../gtest/gtest.h"

namespace Logic
=======
class ParserFassade;
namespace NGenerator
>>>>>>> 1ddde97818ee07684ef9aecd16aa4573f14be042
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
    ParserFassade *pFassade=nullptr;
};
}

#endif // GENERATOR

