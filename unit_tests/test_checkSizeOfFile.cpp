#include <QtTest>
#include "../Functions.h"
#include "../Error.h"

class TestCheckSizeOfFile : public QObject
{
    Q_OBJECT

private slots:
    void test_normalFile();
    void test_exceedRows();
    void test_exceedCharacters();
    void test_exceedBoth();
    void test_emptyFile();
    void test_exactLimitRows();
    void test_exactLimitCharacters();
};

void TestCheckSizeOfFile::test_normalFile()
{
    QString inputCode =
        "Строка 1\n"
        "Строка 2\n"
        "Строка 3";

    QList<Error> errors;
    checkSizeOfFile(inputCode, errors);

    QCOMPARE(errors.size(), 0);
}

void TestCheckSizeOfFile::test_exceedRows()
{
    QStringList lines;
    for (int i = 0; i < 1001; ++i) {
        lines << "Строка " + QString::number(i);
    }
    QString inputCode = lines.join('\n');

    QList<Error> errors;
    checkSizeOfFile(inputCode, errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, numberRowsExceeded);
    QCOMPARE(errors[0].actualCount, 1001);
    QCOMPARE(errors[0].maxAllowed, 1000);
}

void TestCheckSizeOfFile::test_exceedCharacters()
{
    QString longLine = QString(1001, 'x');
    QString inputCode = "Первая строка\n" + longLine + "\nПоследняя строка";

    QList<Error> errors;
    checkSizeOfFile(inputCode, errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, numberCharactersPerLineExceeded);
    QCOMPARE(errors[0].maxAllowed, 1000);
    QCOMPARE(errors[0].lineNumbers.size(), 1);
    QCOMPARE(errors[0].lineNumbers[0], 2);
}

void TestCheckSizeOfFile::test_exceedBoth()
{
    QStringList lines;
    for (int i = 0; i < 1001; ++i) {
        if (i == 500) {
            lines << QString(1001, 'y');
        } else {
            lines << "Первая строка " + QString::number(i);
        }
    }
    QString inputCode = lines.join('\n');

    QList<Error> errors;
    checkSizeOfFile(inputCode, errors);

    QCOMPARE(errors.size(), 2);

    QCOMPARE(errors[0].type, numberRowsExceeded);
    QCOMPARE(errors[0].actualCount, 1001);

    QCOMPARE(errors[1].type, numberCharactersPerLineExceeded);
    QCOMPARE(errors[1].lineNumbers.size(), 1);
}

void TestCheckSizeOfFile::test_emptyFile()
{
    QString inputCode = "";

    QList<Error> errors;
    checkSizeOfFile(inputCode, errors);

    QCOMPARE(errors.size(), 0);
}

void TestCheckSizeOfFile::test_exactLimitRows()
{
    QStringList lines;
    for (int i = 0; i < 1000; ++i) {
        lines << "Строка " + QString::number(i);
    }
    QString inputCode = lines.join('\n');

    QList<Error> errors;
    checkSizeOfFile(inputCode, errors);

    QCOMPARE(errors.size(), 0);
}

void TestCheckSizeOfFile::test_exactLimitCharacters()
{
    QString exactLine = QString(1000, 'a');
    QString inputCode = exactLine;

    QList<Error> errors;
    checkSizeOfFile(inputCode, errors);

    QCOMPARE(errors.size(), 0);
}

QTEST_MAIN(TestCheckSizeOfFile)
#include "test_checkSizeOfFile.moc"
