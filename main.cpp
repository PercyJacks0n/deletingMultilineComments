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
