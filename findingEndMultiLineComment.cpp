#include <QString>
#include "Functions.h"
#include "LocationFlagInCode.h"

void findingEndMultiLineComment(const QString & inputCode, int & i, LocationFlagInCode & state)
{
    int len = inputCode.length();
    if (i + 1 >= len)
    {
        i++;
        return;
    }

    QChar ch = inputCode[i];

    if (ch == '*' && inputCode[i+1] == '/')
    {
        state = flagOuterCode;
        i += 2;
    }
    else
    {
        i++;
    }
}
