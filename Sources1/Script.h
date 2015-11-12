///////////////////////////////////////////////////////////
//  Script.h
//  Implementation of the Class Script
//  Created on:      10-Nov-2015 20:47:49
//  Original author: udo_2
///////////////////////////////////////////////////////////

#if !defined(EA_FE4909CE_235D_4d73_82BE_D8EC8F506823__INCLUDED_)
#define EA_FE4909CE_235D_4d73_82BE_D8EC8F506823__INCLUDED_

#include "Parser.h"

class Script : public Parser
{

public:
	Script();
	virtual ~Script();

	hash_map Read();

private:
	bool Parse();

};
#endif // !defined(EA_FE4909CE_235D_4d73_82BE_D8EC8F506823__INCLUDED_)
