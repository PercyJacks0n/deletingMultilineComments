#include <QTextStream>
#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"
#include "ErrorType.h"
#include <QFile>

// Создаёт выходной файл и записывает в него обработанный код
void createOutputFile(const QString & content, const QString & filePath, QList<Error> & errors)
{
    QFile file(filePath);

    // Пытаемся открыть файл для записи
    if (!file.open(QIODevice::WriteOnly))
    {
        // Если не удалось то добавляем ошибку
        Error error;
        error.type = outputFileCreateError;
        error.errorOutputFileWay = filePath;
        errors.append(error);
        return;
    }

    // Записываем содержимое и закрываем файл
    QTextStream stream(&file);
    stream << content;
    file.close();
}
