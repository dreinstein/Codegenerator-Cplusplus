#ifndef PARSERIMPLEMENTATIONBASE
#define PARSERIMPLEMENTATIONBASE

#include <vector>
#include <map>

class BaseParserImpl
{
public:
    virtual ~BaseParserImpl(){;};
    virtual std::vector<QString> doParseForVec(QString) = 0;
    virtual std::map<QString, QString> doParseForMap(QString)=0;
};


#endif // PARSERIMPLEMENTATIONBASE

