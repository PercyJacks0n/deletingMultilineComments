#include <QString>
#include "Functions.h"
#include "LocationFlagInCode.h"

// Копирует символьную константу в результат
void writingSymbolicConstant(const QString & inputCode, int & i, QString & result, LocationFlagInCode & state)
{
    if (i >= inputCode.length()) return;

    QChar ch = inputCode[i];
    result += ch;   // копируем текущий символ

    // Если встретили закрывающую кавычку
    if (ch == '\'')
    {
        // Проверяем, не экранирована ли она
        if (!isQuoteEscaped(inputCode, i))
        {
            state = flagOuterCode;   // выходим из символа
        }
    }
    i++;
}
