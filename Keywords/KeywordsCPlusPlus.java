///////////////////////////////////////////////////////////
//  KeywordsCPlusPlus.java
//  Implementation of the Class KeywordsCPlusPlus
//  Created on:      10-Nov-2015 20:34:05
//  Original author: udo_2
///////////////////////////////////////////////////////////

#if !defined(EA_D6842513_20D8_484a_B90D_A989215D270C__INCLUDED_)
#define EA_D6842513_20D8_484a_B90D_A989215D270C__INCLUDED_

#include "Parser.h"

class KeywordsCPlusPlus : public Parser
{

public:
	KeywordsCPlusPlus();
	virtual ~KeywordsCPlusPlus();

	hash_map Get();
	vector<string> GetKeywords();
	hash_map Read();
	void SetKeywords(vector<string> newVal);

private:
	vector<string> Keywords;

	bool Parse();

};
#endif // !defined(EA_D6842513_20D8_484a_B90D_A989215D270C__INCLUDED_)
