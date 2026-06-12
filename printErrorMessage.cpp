#include <QString>
#include <QList>
#include <QDebug>
#include "Functions.h"
#include "Error.h"

void printErrorMessage(const QList<Error> & errors)
{
    if (errors.isEmpty()) return;
    qDebug() << "Обнаружены ошбики:\n";
    for (const Error & error : errors)
    {
        qDebug() << error.generateErrorMessage();
    }
}
