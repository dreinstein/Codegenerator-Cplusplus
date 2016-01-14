#ifndef CODEGENERATORIMPL_H
#define CODEGENERATORIMPL_H

#include <QString>
#include <map>
#include <vector>
#include <QFile>

//#include "Basecodegenerator.h"



using namespace std;


namespace Codegenerator
{


class CodegeneratorImpl
{
public:
    CodegeneratorImpl();
    CodegeneratorImpl(std::vector<QString>vecScript,std::map<QString,QString> mapRules,QString fPath);
    ~CodegeneratorImpl();
    void generateCodeFiles();
    void setIndex(int i){index = i;};
    int getIndex(){return index;};
    void write();
 //   BaseCodegenerator* getCodegenerator(QString mapValue);
private:
    QFile heatherFile;//(filenamePath);
    QFile sourceFile;//(filenamePath);
    std::vector<QString> script;
    std::map<QString,QString> rules;
    int index;
    QString filename;
};

}

#endif // CODEGENERATORIMPL_H
