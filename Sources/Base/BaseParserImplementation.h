#ifndef PARSERIMPLEMENTATIONBASE
#define PARSERIMPLEMENTATIONBASE

#include <vector>
#include <map>

class BaseParserImpl
{
public:
    virtual ~BaseParserImpl(){;}
    virtual std::vector<QString> doParseForVec(const QString) = 0 ;
    virtual void storeValues()=0;
    virtual std::map<QString, QString> doParseForMap(const QString)const=0;
};


#endif // PARSERIMPLEMENTATIONBASE

