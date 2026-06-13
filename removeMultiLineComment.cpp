#include <QString>
#include "functions.h"
#include "LocationFlagInCode.h"

QString removeMultiLineComment(const QString & inputCode, QList<Error> & errors)
{
    if (inputCode.isEmpty()) return QString();



    QString result;
    LocationFlagInCode state = flagOuterCode;
    int i = 0;
    int len = inputCode.length();

    int countDefine = 0;

    QString directive = "define";

    while (i < len)
    {
        switch (state)
        {
        case flagOuterCode:
            findingEnteringOtherStatusFlags(inputCode, i, result, state, countDefine, directive);
            break;
        case flagMultiLineComment:
            findingEndMultiLineComment(inputCode, i, state);
            break;
        case flagOneLineComment:
            writingOneLineComment(inputCode, i, result, state);
            break;
        case flagStringConstant:
            writingStringConstant(inputCode, i, result, state);
            break;
        case flagSymbolicConstant:
            writingSymbolicConstant(inputCode, i, result, state);
            break;
        }
    }

    if (countDefine != 0)
    {
        Error error;
        error.type = defineDirectiveFound;
        error.actualCount = countDefine;
        errors.append(error);
    }


    return result;
}
