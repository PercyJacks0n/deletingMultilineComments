#include <QtTest>
#include "../Functions.h"
#include "../Error.h"

class TestPrintErrorMessage : public QObject
{
    Q_OBJECT

private slots:
    void test_printSingleError();
    void test_printMultipleErrors();
    void test_printNoErrors();
    void test_printDifferentErrorTypes();
};

void TestPrintErrorMessage::test_printSingleError()
{
    QList<Error> errors;

    Error error1;
    error1.type = invalidArgumentsCount;
    error1.actualCount = 1;
    error1.expectedValue = "2";
    errors.append(error1);

    printErrorMessage(errors);

    QVERIFY(true);
}

void TestPrintErrorMessage::test_printMultipleErrors()
{
    QList<Error> errors;

    Error error1;
    error1.type = invalidArgumentsCount;
    error1.actualCount = 1;
    error1.expectedValue = "2";
    errors.append(error1);

    Error error2;
    error2.type = invalidFileExtension;
    error2.actualValue = "txt";
    error2.expectedValue = "cpp, c, h";
    errors.append(error2);

    printErrorMessage(errors);

    QVERIFY(true);
}

void TestPrintErrorMessage::test_printNoErrors()
{
    QList<Error> errors;

    printErrorMessage(errors);

    QVERIFY(true);
}

void TestPrintErrorMessage::test_printDifferentErrorTypes()
{
    QList<Error> errors;

    Error error1;
    error1.type = inputFileNotExist;
    error1.errorInputFileWay = "missing.cpp";
    errors.append(error1);

    Error error2;
    error2.type = numberRowsExceeded;
    error2.actualCount = 1500;
    error2.maxAllowed = 1000;
    errors.append(error2);

    Error error3;
    error3.type = numberCharactersPerLineExceeded;
    error3.lineNumbers = {5, 10, 15};
    errors.append(error3);

    printErrorMessage(errors);

    QVERIFY(true);
}

QTEST_MAIN(TestPrintErrorMessage)
#include "test_printErrorMessage.moc"
