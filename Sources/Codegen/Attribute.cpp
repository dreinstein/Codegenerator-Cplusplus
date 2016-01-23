#include "Attribute.h"
#include "QFile"
#include <QTextStream>


namespace Codegenerator
{


Attribute::Attribute()
{

}

Attribute::~Attribute()
{

}

void Attribute::generate()
{
    QFile hFile(sourcefilename);
    QFile sFile(heaterfilename);
    QTextStream outh(&hFile);
    QTextStream outs(&sFile);
    hFile.close();
    sFile.close();
}

void Attribute::generate(std::vector<QString>, std::map<QString,QString>,std::vector<QString> strVecKeys)
{
    Q_ASSERT(false);

}


}

