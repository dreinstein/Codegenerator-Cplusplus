#ifndef CODEGENERATORCONSTANTS_H
#define CODEGENERATORCONSTANTS_H



#include <QString>

namespace Codegenerator
{

    class CodegeneratorConstants
    {
    public:
        static QString tab;
        static QString bracketOpen;
        static QString bracketClose;
        static QString classDefinition;
        static QString newLine;
        static QString colon;
        static QString semiColon;
        static QString comma;
        static QString emptyChar;
        static QString modifierPrivate;
        static QString modifierProtected;
        static QString modifierPublic;
        static QString parameterBracketOpen;
        static QString parameterBracketClose;
        static QString modifier;
        static QString pointer;
        static QString reference;
        static QString constant;
        static QString typInt;
        static QString typVoid;
        static QString typDouble;
        static QString typQString;
        static QString typVectorInt;
        static QString typTestClass;
    };
}

#endif // CODEGENERATORCONSTANTS_H
