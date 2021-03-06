///////////////////////////////////////////////////////////
//  Parser.h
//  Implementation of the Class Parser
//  Created on:      01-Nov-2015 19:59:22
//  Original author: udo_2
///////////////////////////////////////////////////////////


#if !defined(EA_FCF5E9F8_027D_4ecf_95D2_B9170D58FE49__INCLUDED_)
#define EA_FCF5E9F8_027D_4ecf_95D2_B9170D58FE49__INCLUDED_

#include <vector>
#include <map>
#include <QString>
#include "Base/BaseGenerator.h"
#include "Utilities.h"
#include <functional>

using namespace NGenerator;


//class BaseGenerator;
namespace NParser
{

class Parser
{
public:
    Parser(){;}
    virtual ~Parser(){;}
    virtual void Parse(const QString)=0;
    virtual void giveData() const =0;
    virtual void registerObservers(BaseGenerator *observer) =0;
protected:
    std::vector<BaseGenerator*> parserObservers;
    std::vector<QString> vecValues;
    std::map<QString,QString> mapValues;
    General::ParserId::Id id;

};
}
#endif // !defined(EA_FCF5E9F8_027D_4ecf_95D2_B9170D58FE49__INCLUDED_)


