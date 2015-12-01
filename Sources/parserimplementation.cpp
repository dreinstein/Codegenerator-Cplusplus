
#include <iostream>
#include <fstream>
#include <string>

#include "Parserimplementation.h"

namespace Parser
{

ParserImpl::ParserImpl()
{

}

std::vector<std::string> ParserImpl::doParse(std::string path)
{
    std::ifstream  fin(path);
    std::string row;
    std::vector<std::string> values;
    while(getline(fin,row))
    {
        values.push_back(row);
    }
    fin.close();
    return values;
}

}
