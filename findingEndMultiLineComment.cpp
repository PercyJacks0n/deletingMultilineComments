#include <QString>
#include "Functions.h"
#include "LocationFlagInCode.h"

// Пропускает многострочный комментарий до его закрытия */
void findingEndMultiLineComment(const QString & inputCode, int & i, LocationFlagInCode & state)
{
    int len = inputCode.length();
    if (i + 1 >= len)
    {
        i++;
        return;
    }

    QChar ch = inputCode[i];

    // Если нашли закрытие комментария */
    if (ch == '*' && inputCode[i+1] == '/')
    {
        state = flagOuterCode;   // возвращаемся в обычное состояние
        i += 2;                  // пропускаем */
    }
    else
    {
        i++;                     // пропускаем символ внутри комментария
    }
}
