#include <QString>
#include "Functions.h"

bool isQuoteEscaped(const QString &code, int pos)
{
    int backslashCount = 0;
    for (int j = pos - 1; j >= 0 && code[j] == '\\'; j--)
    {
        backslashCount++;
    }
    return (backslashCount % 2 != 0);
}
