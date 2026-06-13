#include <QString>
#include "Functions.h"
#include "LocationFlagInCode.h"

void writingStringConstant(const QString & inputCode, int & i, QString & result, LocationFlagInCode & state)
{
    if (i >= inputCode.length()) return;

    QChar ch = inputCode[i];
    result += ch;

    if (ch == '"') {
        if (!isQuoteEscaped(inputCode, i))
        {
            state = flagOuterCode;
        }
    }
    i++;
}
