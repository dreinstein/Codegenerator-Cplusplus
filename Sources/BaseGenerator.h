#ifndef GENERATOR
#define GENERATOR


#include <string>
#include <vector>
#include <string>

class ParserFassade;
namespace NGenerator
{


class BaseGenerator
{
public:
    virtual ~BaseGenerator(){;};
    virtual void generate()=0;
    virtual void receiveData(std::vector<std::string> strv,int parserId)=0;
    virtual void notify(int id)=0;
    virtual std::vector<std::string> getKeywords()=0;
    virtual std::vector<std::string> getRules()=0;
    virtual std::vector<std::string> getScripts()=0;

protected:
    std::vector<std::string> keywords;
    std::vector<std::string> rules;
    std::vector<std::string> script;
    ParserFassade *pFassade=nullptr;
};
}

#endif // GENERATOR

