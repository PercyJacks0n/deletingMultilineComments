#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"
#include "ErrorType.h"

// Проверяет количество строк и их длину
void checkSizeOfFile(const QString & inputCode, QList<Error> & errors)
{
    // Разбиваем на строки по символу '\n'
    QStringList lines = inputCode.split('\n');

    // Проверка количества строк максимум 1000
    if (lines.size() > 1000)
    {
        Error error;
        error.type = numberRowsExceeded;            // превышено количество строк
        error.maxAllowed = 1000;                    // максимально допустимое
        error.actualCount = lines.size();           // фактическое количество
        errors.append(error);
    }

    // Собираем номера строк, длина которых превышает 1000 символов
    QList<int> longLines;
    for (int i = 0; i < lines.size(); ++i)
    {
        if (lines[i].length() > 1000)
            longLines.append(i + 1);                // номер строки = индекс + 1
    }

    // Если есть длинные строки то добавляем ошибку
    if (!longLines.isEmpty())
    {
        Error error;
        error.type = numberCharactersPerLineExceeded;  // превышена длина строки
        error.maxAllowed = 1000;
        error.lineNumbers = longLines;                 // список номеров строк
        errors.append(error);
    }
}
