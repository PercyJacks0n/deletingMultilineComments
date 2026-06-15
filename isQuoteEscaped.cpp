#include <QString>
#include "Functions.h"

// Проверяет, экранирован ли символ в указанной позиции
bool isQuoteEscaped(const QString &code, int pos)
{
    int backslashCount = 0;

    // Считаем количество обратных слешей перед позицией
    for (int j = pos - 1; j >= 0 && code[j] == '\\'; j--)
    {
        backslashCount++;
    }

    // Чётное количество слешей = не экранирована, закрывает строку
    // Нечётное = экранирована то есть часть строки
    return (backslashCount % 2 != 0);
}
