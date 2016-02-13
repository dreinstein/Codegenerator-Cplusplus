//////////////////////////////////////////////////////////
//  RulesC++.h
//  Implementation of the Class RulesCPlusPlus
//  Created on:      01-Nov-2015 19:25:21
//  Original author: Udo
///////////////////////////////////////////////////////////

#if !defined(EA_5696B399_2720_4b9a_8D9E_65D0775A88B0__INCLUDED_)
#define EA_5696B399_2720_4b9a_8D9E_65D0775A88B0__INCLUDED_
namespace Parsing
{
class RulesCPlusPlus : public Parser
{

public:
	RulesCPlusPlus();
	virtual ~RulesCPlusPlus();

	hash_map<string,vector<char>> getARules();
	void setARules(hash_map<string,vector<char>> newVal);
		hash_map Get();
		void Read();

private:
	hash_map<string,vector<char>> ARules;
		bool Parse();

};
}
#endif // !defined(EA_5696B399_2720_4b9a_8D9E_65D0775A88B0__INCLUDED_)
