
//#include <iostream>
//#include <fstream>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <windows.h>
#include <string>
#include "Parserimplementation.h"


namespace NParser
{


ParserImpl::ParserImpl()
{

}

ParserImpl::~ParserImpl()
{

}

std::vector<QString> ParserImpl::doParseForVec(QString path)
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
    return values;

}

// get hash fileName(Keyword,path)
std::map<QString, QString> ParserImpl::doParseForMap(QString str)
{
    HANDLE fHandle;
    WIN32_FIND_DATA wfd;
    std::map<QString, QString> map;
    str += "\\";
    QString wcharp= str;
    wcharp += "*";
    auto wstr = wcharp.toStdWString();
    std::wstring fileWString;
    QString valueString = str;
    fHandle=FindFirstFile(wstr.c_str(),&wfd);
    do
    {
        fileWString = wfd.cFileName;
        std::string fileString( fileWString.begin(), fileWString.end() );
        if((fileString != ".") && (fileString != ".."))
        {
            valueString = str;
            valueString.append(fileString.c_str());
            fileString.erase(fileString.end()-4,fileString.end());
            QString mapString(fileString.c_str());
            map[mapString] = valueString;
        }
    }
    while (FindNextFile(fHandle,&wfd));
    FindClose(fHandle);
    return map;
}
}


