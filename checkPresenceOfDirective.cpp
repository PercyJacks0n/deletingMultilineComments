#include <QString>
#include "Functions.h"

// Проверяет наличие директивы в коде
void checkPresenceOfDirective(const QString & inputCode, int & i, int & countDirective, QString & directive)
{
    // Проверяем, не вышли ли за пределы строки
    if (i + 1 >= inputCode.length()) return;

    // Пропускаем пробелы и табуляции после символа '#'
    int pos = i + 1;
    while (pos < inputCode.length() && (inputCode[pos] == ' ' || inputCode[pos] == '\t'))
    {
        pos++;
    }

    // Собираем название директивы пропуская все символы до пробела/табуляции/конца строки
    QString intendedDirective = "";
    while (pos < inputCode.length())
    {
        QChar ch = inputCode[pos];
        if (ch == ' ' || ch == '\t' || ch == '\n') break;
        intendedDirective += ch;
        pos++;
    }

    // Если нашли нужную директиву то увеличиваем счётчик
    if (intendedDirective == directive) countDirective++;
}
