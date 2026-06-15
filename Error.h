#ifndef ERROR_H
#define ERROR_H

#include <QString>
#include <QList>
#include "ErrorType.h"

/**
 * @file Error.h
 * @brief Класс для хранения информации об ошибке
 */

/**
 * @class Error
 * @brief Представляет одну ошибку, возникшую при выполнении программы
 */
class Error
{
public:
    Error() : type(invalidArgumentsCount), actualCount(0), maxAllowed(0) {}

    ErrorType type;                     ///< Тип ошибки
    QString errorInputFileWay;          ///< Путь к входному файлу
    QString errorOutputFileWay;         ///< Путь к выходному файлу
    QList<int> lineNumbers;             ///< Номера строк, где обнаружена ошибка
    QString actualValue;                ///< Фактическое значение
    QString expectedValue;              ///< Ожидаемое значение
    int actualCount;                    ///< Фактическое количество
    int maxAllowed;                     ///< Максимально допустимое значение

    /**
     * @brief Генерирует форматированное сообщение об ошибке
     * @return Строка с сообщением об ошибке
     */
    QString generateErrorMessage() const;

    /**
     * @brief Генерирует строку со списком номеров строк
     * @return Строка вида "1, 2, 3"
     */
    QString generateListLineNumbersExceededCharacterLimit() const;
};

#endif // ERROR_H
