#include <QString>
#include "Functions.h"

void checkPresenceOfDirective(const QString & inputCode, int & i, int & countDirective, QString & directive)
{
    if (i + 1 >= inputCode.length()) return;

    QString intendedDirective = "";
    int pos = i + 1;

    while (pos < inputCode.length() && (inputCode[pos] == ' ' || inputCode[pos] == '\t'))
    {
        pos++;
    }

    while (pos < inputCode.length())
    {
        QChar ch = inputCode[pos];
        if (ch == ' ' || ch == '\t' || ch == '\n') break;
        intendedDirective += ch;
        pos++;
    }

    if (intendedDirective == directive) countDirective++;
}
