

#include <QString>
#include <QTextStream>
#include <QFile>
#include <windows.h>
#include <string>
#include "ParserimplementationText.h"
#include "../Errorhandling/OpenfileException.h"


namespace NParser
{




std::vector<QString> ParserImplText::doParseForVec(const QString path)
{

    QFile fin(path);
    QString row;
    std::vector<QString> values;
    if (fin.open(QIODevice::ReadOnly))
    {
       QTextStream in(&fin);
       while (!in.atEnd())
       {
          row = in.readLine();
          values.push_back(row);
       }
       fin.close();
    }
    else
    {
      throw Errorhandling::OpenFileException();
    }
    return values;
}



// get hash fileName(Keyword,path)
std::map<QString, QString> ParserImplText::doParseForMap(QString val) const
{
    HANDLE fHandle;
    WIN32_FIND_DATAA wfd;
    std::map<QString, QString> map;
    QString str = val;
    val += "\\";
    QString wcharp= val;
    wcharp += "*";
 //   auto mstr = wcharp.toStdString();
    std::string fileNString;
    QString valueString = str;
    fHandle=FindFirstFileA(wcharp.toStdString().c_str(),&wfd);
    do
    {
        fileNString = wfd.cFileName;
        std::string fileString( fileNString.begin(), fileNString.end() );
        if((fileString != ".") && (fileString != ".."))
        {
            valueString = val;
            valueString.append(fileString.c_str());
            fileString.erase(fileString.end()-4,fileString.end());
            QString mapString(fileString.c_str());
            map[mapString] = valueString;
        }
    }
    while (FindNextFileA(fHandle,&wfd));
    FindClose(fHandle);
    return map;
}

void ParserImplText::storeValues()
{
    // should not come here
    Q_ASSERT(true);
}

}


