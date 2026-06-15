#include <QString>
#include "functions.h"
#include "LocationFlagInCode.h"

// Главная функция: удаляет многострочные комментарии из кода
QString removeMultiLineComment(const QString & inputCode, QList<Error> & errors)
{
    if (inputCode.isEmpty()) return QString();

    QString result;                           // результирующая строка
    LocationFlagInCode state = flagOuterCode; // текущее состояние
    int i = 0;                                // текущая позиция в коде
    int len = inputCode.length();

    int countDefine = 0;                      // счётчик директив #define
    QString directive = "define";             // имя директивы для поиска

    // Проходим по всем символам исходного кода
    while (i < len)
    {
        switch (state)
        {
        case flagOuterCode:
            // Обрабатываем обычный код , то есть ищем комментарии и константы
            findingEnteringOtherStatusFlags(inputCode, i, result, state, countDefine, directive);
            break;
        case flagMultiLineComment:
            // Пропускаем многострочный комментарий
            findingEndMultiLineComment(inputCode, i, state);
            break;
        case flagOneLineComment:
            // Копируем однострочный комментарий
            writingOneLineComment(inputCode, i, result, state);
            break;
        case flagStringConstant:
            // Обрабатываем строковую константу
            writingStringConstant(inputCode, i, result, state);
            break;
        case flagSymbolicConstant:
            // Обрабатываем символьную константу
            writingSymbolicConstant(inputCode, i, result, state);
            break;
        }
    }

    // Если нашли директивы #define то добавляем ошибку
    if (countDefine != 0)
    {
        Error error;
        error.type = defineDirectiveFound;
        error.actualCount = countDefine;
        errors.append(error);
    }

    return result;
}
