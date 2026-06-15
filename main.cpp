/**
 * @mainpage Программа для удаления многострочных комментариев
 *
 * @section description Описание программы
 * Программа предназначена для удаления многострочных комментариев
 * из исходного кода на языках C
 *
 * Программа учитывает обход по:
 * - строковым константам "..." — комментарии внутри них не удаляются
 * - символьным константам '...' — комментарии внутри них не удаляются
 * - однострочным комментариям // ... — не удаляются, другой тип комменатрия
 *
 * @section usage Использование
 * \code{.sh}
 * deletingMultilineComments.exe <входной_файл> <выходной_файл>
 * \endcode
 *
 * @section example Пример
 * Входной файл (input.cpp):
 * \code{.cpp}
 * int a = 5;/* комментарий * /int b = 10;
 * \endcode
 * Выходной файл (output.cpp):
 * \code{.cpp}
 * int a = 5;int b = 10;
 * \endcode
 *
 * @section errors Обработка ошибок
 * При некорректных входных данных программа выдаёт сообщение об ошибках и завершается.
 *
 * @author Ежов Д.Д. ПрИн-266
 * @date 15-06-2026
 */

#include <QString>
#include <QList>
#include "Functions.h"
#include <qDebug>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");

    QString inputPath = (argc > 1) ? argv[1] : "";
    QString outputPath = (argc > 2) ? argv[2] : "";

    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};


    checkCountArgs(argc, errors);
    checkExtension(inputPath, allowedExtensions, errors);
    if (!hasNoErrors(errors)) return 1;

    QString inputCode = readInputFile(inputPath, errors);
    if (!hasNoErrors(errors)) return 1;

    checkSizeOfFile(inputCode, errors);
    if (!hasNoErrors(errors)) return 1;

    QString processedCode = removeMultiLineComment(inputCode, errors);
    createOutputFile(processedCode, outputPath, errors);
    if (!hasNoErrors(errors)) return 1;

    return 0;
}
