#ifndef VECTORDATA
#define VECTORDATA

#endif // VECTORDATA

#include "Utilities.h"
#include <vector>
#include <string>

class ParsingVectorData
{
public:
    ~ParsingVectorData(){;};
    virtual std::vector<std::string> getData() = 0;
    virtual General::Types::DataTypes getDataType() = 0;
};

