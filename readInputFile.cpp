#include <QString>
#include <QList>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include "Functions.h"
#include "Error.h"
#include "ErrorType.h"

QString readInputFile(const QString & filePath, QList<Error> & errors)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly))
    {
        Error error;
        error.type = inputFileNotExist;
        error.errorInputFileWay = filePath;
        errors.append(error);
        return "";
    }

    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();
    return content;
}
