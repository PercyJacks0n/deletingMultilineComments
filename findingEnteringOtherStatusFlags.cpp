#include <QString>
#include "Functions.h"
#include "LocationFlagInCode.h"

void findingEnteringOtherStatusFlags(const QString & inputCode,
                                     int & i,
                                     QString & result,
                                     LocationFlagInCode & state,
                                     int & countDirective,
                                     QString & directive)
{
    int len = inputCode.length();
    if (i >= len) return;

    QChar ch = inputCode[i];

    if(ch == '#')
    {
        checkPresenceOfDirective(inputCode, i, countDirective, directive);
    }

    if (i + 1 < len && ch == '/' && inputCode[i+1] == '*') {
        state = flagMultiLineComment;
        i += 2;
    }

    else if (i + 1 < len && ch == '/' && inputCode[i+1] == '/') {
        result += ch;
        result += inputCode[i+1];
        state = flagOneLineComment;
        i += 2;
    }

    else if (ch == '"') {
        result += ch;
        state = flagStringConstant;
        i++;
    }

    else if (ch == '\'') {
        result += ch;
        state = flagSymbolicConstant;
        i++;
    }

    else {
        result += ch;
        i++;
    }
}
