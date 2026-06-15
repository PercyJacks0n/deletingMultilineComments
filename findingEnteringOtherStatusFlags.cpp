#include <QString>
#include "Functions.h"
#include "LocationFlagInCode.h"

// Обрабатывает обычный код: ищет начало комментариев и констант
void findingEnteringOtherStatusFlags(const QString & inputCode,
                                     int & i,
                                     QString & result,
                                     LocationFlagInCode & state,
                                     int & countDirective,
                                     const QString & directive)
{
    int len = inputCode.length();
    if (i >= len) return;

    QChar ch = inputCode[i];

    // Если встретили решётку то возможно начало директивы
    if(ch == '#')
    {
        checkPresenceOfDirective(inputCode, i, countDirective, directive);
    }

    // Начало многострочного комментария /*
    if (i + 1 < len && ch == '/' && inputCode[i+1] == '*')
    {
        state = flagMultiLineComment;   // переключаем состояние
        i += 2;                         // пропускаем /*
    }
    // Начало однострочного комментария //
    else if (i + 1 < len && ch == '/' && inputCode[i+1] == '/')
    {
        result += ch;                   // добавляем первый слеш
        result += inputCode[i+1];       // добавляем второй слеш
        state = flagOneLineComment;     // переключаем состояние
        i += 2;
    }
    // Начало строковой константы "
    else if (ch == '"')
    {
        result += ch;
        state = flagStringConstant;
        i++;
    }
    // Начало символьной константы '
    else if (ch == '\'')
    {
        result += ch;
        state = flagSymbolicConstant;
        i++;
    }
    // Обычный символ то просто копируем
    else
    {
       result += ch;
       i++;
    }
}
