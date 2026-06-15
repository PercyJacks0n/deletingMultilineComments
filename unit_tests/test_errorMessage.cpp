#include <QtTest>
#include "../Error.h"

class TestGenerateErrorMessage : public QObject
{
    Q_OBJECT

private slots:
    void test_invalidArgumentsCount();
    void test_invalidFileExtension();
    void test_inputFileNotExist();
    void test_outputFileCreateError();
    void test_defineDirectiveFound();
    void test_numberRowsExceeded();
    void test_numberCharactersPerLineExceeded();
};

void TestGenerateErrorMessage::test_invalidArgumentsCount()
{
    Error error;
    error.type = invalidArgumentsCount;
    error.actualCount = 1;
    error.expectedValue = "2";

    QString result = error.generateErrorMessage();
    QString expected = "Неверное количество аргументов: 1, ожидается 2";

    QCOMPARE(result, expected);
}

void TestGenerateErrorMessage::test_invalidFileExtension()
{
    Error error;
    error.type = invalidFileExtension;
    error.actualValue = "exe";
    error.expectedValue = "cpp, c, h";
    error.errorInputFileWay = "test.exe";

    QString result = error.generateErrorMessage();
    QString expected = "Недопустимое расширение файла: exe Разрешены: cpp, c, h";

    QCOMPARE(result, expected);
}

void TestGenerateErrorMessage::test_inputFileNotExist()
{
    Error error;
    error.type = inputFileNotExist;
    error.errorInputFileWay = "nonexistent.cpp";

    QString result = error.generateErrorMessage();
    QString expected = "Файл не существует: nonexistent.cpp";

    QCOMPARE(result, expected);
}

void TestGenerateErrorMessage::test_outputFileCreateError()
{
    Error error;
    error.type = outputFileCreateError;
    error.errorOutputFileWay = "C:\\invalid\\path\\out.cpp";

    QString result = error.generateErrorMessage();
    QString expected = "Не удалось создать выходной файл: C:\\invalid\\path\\out.cpp";

    QCOMPARE(result, expected);
}

void TestGenerateErrorMessage::test_defineDirectiveFound()
{
    Error error;
    error.type = defineDirectiveFound;
    error.actualCount = 3;

    QString result = error.generateErrorMessage();
    QString expected = "Найдена директива #define , количество: 3 штук";

    QCOMPARE(result, expected);
}

void TestGenerateErrorMessage::test_numberRowsExceeded()
{
    Error error;
    error.type = numberRowsExceeded;
    error.actualCount = 1500;

    QString result = error.generateErrorMessage();
    QString expected = "Количество строк 1500 штук превышает 1000";

    QCOMPARE(result, expected);
}

void TestGenerateErrorMessage::test_numberCharactersPerLineExceeded()
{
    Error error;
    error.type = numberCharactersPerLineExceeded;
    error.lineNumbers = {5, 12, 30};

    QString result = error.generateErrorMessage();
    QString expected = "Превышена длина строки 1000 символов в строках:5, 12, 30";

    QCOMPARE(result, expected);
}

QTEST_MAIN(TestGenerateErrorMessage)
#include "test_errorMessage.moc"
