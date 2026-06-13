#include <QtTest>
#include "../Functions.h"
#include "../Error.h"

class TestCheckCountArgs : public QObject
{
    Q_OBJECT

private slots:
    void test_withoutInputArguments();
    void test_withOneInputArguments();
    void test_withTwoInputArguments();
    void test_withThreeInputArguments();
};

void TestCheckCountArgs::test_withoutInputArguments()
{
    int argc = 1;
    QList<Error> actualErrors;

    checkCountArgs(argc, actualErrors);

    QCOMPARE(actualErrors.size(), 1);

    QCOMPARE(actualErrors[0].type, invalidArgumentsCount);
    QCOMPARE(actualErrors[0].actualCount, argc - 1);
    QCOMPARE(actualErrors[0].expectedValue, "2");
}

void TestCheckCountArgs::test_withOneInputArguments()
{
    int argc = 2;
    QList<Error> actualErrors;

    checkCountArgs(argc, actualErrors);

    QCOMPARE(actualErrors.size(), 1);

    QCOMPARE(actualErrors[0].type, invalidArgumentsCount);
    QCOMPARE(actualErrors[0].actualCount, argc - 1);
    QCOMPARE(actualErrors[0].expectedValue, "2");
}

void TestCheckCountArgs::test_withTwoInputArguments()
{
    int argc = 3;
    QList<Error> actualErrors;

    checkCountArgs(argc, actualErrors);

    QVERIFY(actualErrors.isEmpty());
}

void TestCheckCountArgs::test_withThreeInputArguments()
{
    int argc = 4;
    QList<Error> actualErrors;

    checkCountArgs(argc, actualErrors);

    QCOMPARE(actualErrors.size(), 1);

    QCOMPARE(actualErrors[0].type, invalidArgumentsCount);
    QCOMPARE(actualErrors[0].actualCount, argc - 1);
    QCOMPARE(actualErrors[0].expectedValue, "2");
}

QTEST_MAIN(TestCheckCountArgs)
#include "test_checkCountArgs.moc"
