#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QList>
#include "Error.h"
#include "LocationFlagInCode.h"

/**
 * @file Functionsh
 * @brief Объявления основных функций программы
 */

/**
 * @brief Проверяет количество аргументов командной строки
 * @param[in] argc Количество аргументов
 * @param[out] errors Список ошибок
 */
void checkCountArgs(int argc, QList<Error> & errors);

/**
 * @brief Проверяет расширение входного файла
 * @param[in] filePath Путь к файлу
 * @param[in] allowedExtensions Список разрешённых расширений
 * @param[out] errors Список ошибок
 */
void checkExtension(const QString & filePath, QList<QString> & allowedExtensions, QList<Error> & errors);

/**
 * @brief Читает содержимое входного файла
 * @param[in] filePath Путь к файлу
 * @param[out] errors Список ошибок
 * @return Содержимое файла в виде строки, или пустую строку при ошибке
 */
QString readInputFile(const QString & filePath, QList<Error> & errors);

/**
 * @brief Проверяет размер файла - количество строк и их длину
 * @param[in] inputCode Исходный код программы
 * @param[out] errors Список ошибок
 */
void checkSizeOfFile(const QString & inputCode, QList<Error> & errors);

/**
 * @brief Проверяет наличие директивы #define в коде
 * @param[in] inputCode Исходный код
 * @param[in,out] i Текущая позиция в коде
 * @param[in,out] countDirective Счётчик найденных директив
 * @param[in] directive Имя искомой директивы
 */
void checkPresenceOfDirective(const QString & inputCode, int i, int & countDirective, const QString & directive);

/**
 * @brief Удаляет многострочные комментарии из кода
 * @param[in] inputCode Исходный код
 * @param[out] errors Список ошибок
 * @return Код без многострочных комментариев
 */
QString removeMultiLineComment(const QString & inputCode, QList<Error> & errors);

/**
 * @brief Обрабатывает обычный код вне комментариев и констант
 * @param[in] inputCode Исходный код
 * @param[in,out] i Текущая позиция
 * @param[out] result Результирующая строка
 * @param[in,out] state Текущее состояние автомата
 * @param[in,out] countDirective Счётчик директив
 * @param[in] directive Имя искомой директивы
 */
void findingEnteringOtherStatusFlags(const QString & inputCode,
                                     int & i,
                                     QString & result,
                                     LocationFlagInCode & state,
                                     int & countDirective,
                                     QString & directive);

/**
 * @brief Пропускает многострочный комментарий
 * @param[in] inputCode Исходный код
 * @param[in,out] i Текущая позиция
 * @param[in,out] state Текущее состояние
 */
void findingEndMultiLineComment(const QString & inputCode, int & i, LocationFlagInCode & state);

/**
 * @brief Обрабатывает однострочный комментарий
 * @param[in] inputCode Исходный код
 * @param[in,out] i Текущая позиция
 * @param[out] result Результирующая строка
 * @param[in,out] state Текущее состояние
 */
void writingOneLineComment(const QString & inputCode, int & i, QString & result, LocationFlagInCode & state);

/**
 * @brief Обрабатывает строковую константу
 * @param[in] inputCode Исходный код
 * @param[in,out] i Текущая позиция
 * @param[out] result Результирующая строка
 * @param[in,out] state Текущее состояние
 */
void writingStringConstant(const QString & inputCode, int & i, QString & result, LocationFlagInCode & state);

/**
 * @brief Обрабатывает символьную константу
 * @param[in] inputCode Исходный код
 * @param[in,out] i Текущая позиция
 * @param[out] result Результирующая строка
 * @param[in,out] state Текущее состояние
 */
void writingSymbolicConstant(const QString & inputCode, int & i, QString & result, LocationFlagInCode & state);

/**
 * @brief Проверяет, экранирован ли символ в указанной позиции
 * @param[in] code Исходный код
 * @param[in] pos Позиция проверяемого символа
 * @return true, если экранирован, false если нет
 */
bool isQuoteEscaped(const QString & code, int pos);

/**
 * @brief Создаёт выходной файл с обработанным кодом
 * @param[in] content Содержимое файла
 * @param[in] filePath Путь к выходному файлу
 * @param[out] errors Список ошибок
 */
void createOutputFile(const QString & content, const QString & filePath, QList<Error> & errors);

/**
 * @brief Проверяет, есть ли ошибки в списке
 * @param[in] errors Список ошибок
 * @return true, если ошибок нет, false, если есть
 */
bool hasNoErrors(const QList<Error> & errors);

/**
 * @brief Выводит сообщения об ошибках в консоль
 * @param[in] errors Список ошибок
 */
void printErrorMessage(const QList<Error> & errors);

#endif // FUNCTIONS_H
