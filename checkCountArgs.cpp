#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"

// Проверяет количество аргументов командной строки
void checkCountArgs(int argc, QList<Error> & errors)
{
    // Должно быть 3 аргумента: имя программы + входной файл + выходной файл
    if (argc != 3)
    {
        Error error;
        error.type = invalidArgumentsCount;          // тип ошибки
        error.actualCount = argc - 1;               // сколько аргументов передано
        error.expectedValue = "2";                  // ожидаемое количество
        errors.append(error);                       // добавляем в список
    }
}
