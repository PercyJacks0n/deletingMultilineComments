#ifndef ERRORTYPE_H
#define ERRORTYPE_H

/**
 * @file ErrorType.h
 * @brief Перечисление типов ошибок, возникающих при работе программы.
 */

/**
 * @enum ErrorType
 * @brief Типы ошибок
 */
enum ErrorType
{
    invalidArgumentsCount,          ///< Неверное количество аргументов командной строки
    inputFileNotExist,              ///< Входной файл не существует
    outputFileCreateError,          ///< Не удалось создать выходной файл
    defineDirectiveFound,           ///< Найдена директива #define
    numberRowsExceeded,             ///< Превышено количество строк в файле
    numberCharactersPerLineExceeded,///< Превышена длина строки
    invalidFileExtension            ///< Недопустимое расширение входного файла
};

#endif // ERRORTYPE_H
