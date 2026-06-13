#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"
#include "ErrorType.h"

void checkSizeOfFile(const QString & inputCode, QList<Error> & errors)
{
    QStringList lines = inputCode.split('\n');

    if (lines.size() > 1000)
    {
        Error error;
        error.type = numberRowsExceeded;
        error.maxAllowed = 1000;
        error.actualCount = lines.size();
        errors.append(error);
    }

    QList<int> longLines;
    for (int i = 0; i < lines.size(); ++i)
    {
        if (lines[i].length() > 1000)
            longLines.append(i + 1);
    }

    if (!longLines.isEmpty())
    {
        Error error;
        error.type = numberCharactersPerLineExceeded;
        error.maxAllowed = 1000;
        error.lineNumbers = longLines;
        errors.append(error);
    }
}
