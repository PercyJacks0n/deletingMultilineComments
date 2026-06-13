#include "Error.h"

QString Error::generateListLineNumbersExceededCharacterLimit() const
{
    QString linesStr;
    for (int i = 0; i < lineNumbers.size(); ++i)
    {
        if (i > 0) linesStr += ", ";
        linesStr += QString::number(lineNumbers[i]);
    }
    return linesStr;
}

QString Error::generateErrorMessage() const
{
    switch (type)
    {
    case invalidArgumentsCount:
        return "Неверное количество аргументов: " + QString::number(actualCount) +
               ", ожидается " + expectedValue;

    case invalidFileExtension:
        return "Недопустимое расширение файла: " + actualValue +
               " Разрешены: " + expectedValue;

    case inputFileNotExist:
        return "Файл не существует: " + errorInputFileWay;

    case outputFileCreateError:
        return "Не удалось создать выходной файл: " + errorOutputFileWay;

    case defineDirectiveFound:
        return "Найдена директива #define , количество: " + QString::number(actualCount) + " штук";

    case numberRowsExceeded:
        return "Количество строк " + QString::number(actualCount) + " штук превышает 1000";

    case numberCharactersPerLineExceeded:

        return "Превышена длина строки 1000 символов в строках:" + generateListLineNumbersExceededCharacterLimit();

    default:
        return "Неизвестная ошибка";
    }
}

