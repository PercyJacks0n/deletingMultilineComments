#include <QTextStream>
#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"
#include "ErrorType.h"
#include <QFile>

void createOutputFile(const QString & content,
                      const QString & filePath,
                      QList<Error> & errors)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly))
    {
        Error error;
        error.type = outputFileCreateError;
        error.errorOutputFileWay = filePath;
        errors.append(error);
        return;
    }

    QTextStream stream(&file);
    stream << content;

    file.close();
}
