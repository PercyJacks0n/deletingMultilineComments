#include <QString>
#include <QList>
#include <QFileInfo>
#include "Functions.h"
#include "Error.h"

// Проверяет расширение входного файла
void checkExtension(const QString & filePath, QList<QString> & allowedExtensions, QList<Error> & errors)
{
    // Получаем расширение файла
    QFileInfo fileInfo(filePath);
    QString currentExtension = fileInfo.suffix();

    // Проверяем, входит ли расширение в список разрешённых
    if (!allowedExtensions.contains(currentExtension))
    {
        Error error;
        error.type = invalidFileExtension;          // неверное расширение
        error.errorInputFileWay = filePath;          // путь к файлу
        error.actualValue = currentExtension;        // то, что получили
        error.expectedValue = "cpp, c, h";           // то, что ожидали
        errors.append(error);
    }
}
