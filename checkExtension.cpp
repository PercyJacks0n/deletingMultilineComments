#include <QString>
#include <QList>
#include <QFileInfo>
#include "Functions.h"
#include "Error.h"

void checkExtension(const QString & filePath, QList<QString> & allowedExtensions, QList<Error> & errors)
{

    QFileInfo fileInfo(filePath);
    QString currentExtension = fileInfo.suffix();

    if (!allowedExtensions.contains(currentExtension))
    {
        Error error;
        error.type = invalidFileExtension;
        error.errorInputFileWay = filePath;
        error.actualValue = currentExtension;
        QStringList extList;
        for (const QString & ext : allowedExtensions) {
            extList << ext;
        }
        error.expectedValue = extList.join(", ");
        errors.append(error);
    }
}
