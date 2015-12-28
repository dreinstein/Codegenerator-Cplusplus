#ifndef PARSERIMPLEMENTATIONBASE
#define PARSERIMPLEMENTATIONBASE

class BaseParserImpl
{
public:
    virtual ~BaseParserImpl(){;};
    virtual std::vector<std::string> doParse(std::string) = 0;
};


#endif // PARSERIMPLEMENTATIONBASE

