

#include "Generator.h"
#include "ParserFassade.h"
#include "Utilities.h"


void Generator::generate()
{
    ParserFassade *pFassade = new ParserFassade(General::Languages::CPLUSPLUS);
    pFassade->ParseKeyword();

}
