///////////////////////////////////////////////////////////
//  Keywords.h
//  Implementation of the Class Parser
//  Created on:      01-Nov-2015 19:58:38
//  Original author: udo_2
///////////////////////////////////////////////////////////

#if !defined(EA_EF42C148_FFCC_4c8d_94ED_9EECBFBB51DA__INCLUDED_)
#define EA_EF42C148_FFCC_4c8d_94ED_9EECBFBB51DA__INCLUDED_

#include "ParserFassade.h"

class Parser
{

public:
	Parser();
	virtual ~Parser();
    ParserFassade *m_ParserFassade = nullptr;

    virtual bool Parse()=0;
    virtual void Read()=0;
    virtual void Write()=0;

};
#endif // !defined(EA_EF42C148_FFCC_4c8d_94ED_9EECBFBB51DA__INCLUDED_)
