#ifndef ERROR_H
#define ERROR_H
#include <QString>
#include <QList>
#include "ErrorType.h"

class Error
{
public:
    ErrorType type;
    QString errorInputFileWay;
    QString errorOutputFileWay;
    QList<int> lineNumbers;
    QString actualValue;
    QString expectedValue;
    int actualCount;
    int maxAllowed;

    QString generateErrorMessage() const;
    QString generateListLineNumbersExceededCharacterLimit() const;
};
#endif // ERROR_H
