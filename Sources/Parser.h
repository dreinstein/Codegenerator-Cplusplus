///////////////////////////////////////////////////////////
//  Parser.h
//  Implementation of the Class Parser
//  Created on:      01-Nov-2015 19:59:22
//  Original author: udo_2
///////////////////////////////////////////////////////////

#if !defined(EA_FCF5E9F8_027D_4ecf_95D2_B9170D58FE49__INCLUDED_)
#define EA_FCF5E9F8_027D_4ecf_95D2_B9170D58FE49__INCLUDED_

#include "ParserFassade.h"

class Parser
{
public:
    virtual void Parse()=0;
    virtual void GetType()=0;
    virtual void GetDatas()=0;
};
#endif // !defined(EA_FCF5E9F8_027D_4ecf_95D2_B9170D58FE49__INCLUDED_)
