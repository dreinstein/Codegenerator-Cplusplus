

#include "Generator.h"
#include "ParserFassade.h"
#include "Utilities.h"

namespace Logic
{

using namespace Parser;

void Generator::generate()
{
    ParserFassade *pFassade = new ParserFassade(General::Languages::CPLUSPLUS);
    pFassade->ParseKeyword();

}

}  // end namespace
