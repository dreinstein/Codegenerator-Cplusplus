

#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Utilities.h"
#include <QString>
#include <vector>
#include "Base/BaseGenerator.h"
#include "Parser.h"

using namespace NGenerator;

namespace NParser
{



class KeywordsCPlusPlus:public Parser{
public:
    virtual ~KeywordsCPlusPlus(){;}
    void Parse(const QString std) override final;
    void giveData() const override final;
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer) override final;
};
}

#endif // KEYWORDCPLUSPLUS


