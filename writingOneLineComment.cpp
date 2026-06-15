#include <QString>
#include "Functions.h"
#include "LocationFlagInCode.h"

// Копирует однострочный комментарий в результат
void writingOneLineComment(const QString & inputCode, int & i, QString & result, LocationFlagInCode & state)
{
    if (i >= inputCode.length()) return;

    QChar ch = inputCode[i];
    result += ch;   // копируем текущий символ

    // Если дошли до конца строки то выходим из состояния комментария
    if (ch == '\n') {
        state = flagOuterCode;
    }
    i++;
}
