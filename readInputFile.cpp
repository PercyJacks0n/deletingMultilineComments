#include <QString>
#include <QList>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include "Functions.h"
#include "Error.h"
#include "ErrorType.h"

// Читает содержимое входного файла
QString readInputFile(const QString & filePath, QList<Error> & errors)
{
    QFile file(filePath);

    // Пытаемся открыть файл для чтения
    if (!file.open(QIODevice::ReadOnly))
    {
        // Если не удалось то добавляем ошибку
        Error error;
        error.type = inputFileNotExist;
        error.errorInputFileWay = filePath;
        errors.append(error);
        return "";
    }

    // Читаем всё содержимое
    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();
    return content;
}
