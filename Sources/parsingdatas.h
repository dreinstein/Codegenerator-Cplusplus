#ifndef PARSINGDATAS
#define PARSINGDATAS

#include "Utilities.h"

class ParsingDatas
{
public:
    virtual General::Types::DataTypes::Vector getDataType()= 0;
    virtual General::Types::DataTypes::Vector getData(){return nullptr;};
    virtual General::Types::DataTypes::Map getData() {return nullptr;};
};

#endif // PARSINGDATAS


