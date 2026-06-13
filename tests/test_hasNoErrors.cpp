#include <QtTest>
#include "../Functions.h"
#include "../Error.h"

class TestHasNoErrors : public QObject
{
    Q_OBJECT

private slots:
    void test_noErrors();
    void test_oneError();
    void test_multipleErrors();
};

void TestHasNoErrors::test_noErrors()
{
    QList<Error> errors;

    bool result = hasNoErrors(errors);

    QCOMPARE(result, true);
}

void TestHasNoErrors::test_oneError()
{
    QList<Error> errors;

    Error error;
    error.type = invalidArgumentsCount;
    error.actualCount = 1;
    error.expectedValue = "2";
    errors.append(error);

    bool result = hasNoErrors(errors);

    QCOMPARE(result, false);
}

void TestHasNoErrors::test_multipleErrors()
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

    bool result = hasNoErrors(errors);

    QCOMPARE(result, false);
}

QTEST_MAIN(TestHasNoErrors)
#include "test_hasNoErrors.moc"
