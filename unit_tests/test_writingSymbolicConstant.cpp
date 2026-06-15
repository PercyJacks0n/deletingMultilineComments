#include <QtTest>
#include "../Functions.h"
#include "../LocationFlagInCode.h"

class TestWritingSymbolicConstant : public QObject
{
    Q_OBJECT

private slots:
    void test_normalChar();
    void test_escapedQuote();
    void test_escapedBackslash();
    void test_emptyChar();
};

void TestWritingSymbolicConstant::test_normalChar()
{
    QString input = "'a'";
    QString result;
    LocationFlagInCode state = flagSymbolicConstant;
    int i = 0;

    while (i < input.length()) {
        writingSymbolicConstant(input, i, result, state);
    }

    QCOMPARE(result, input);
    QCOMPARE(state, flagOuterCode);
}

void TestWritingSymbolicConstant::test_escapedQuote()
{
    QString input = "'\\''";
    QString expected = "'\\''";
    QString result;
    LocationFlagInCode state = flagSymbolicConstant;
    int i = 0;

    while (i < input.length()) {
        writingSymbolicConstant(input, i, result, state);
    }

    QCOMPARE(result, expected);
    QCOMPARE(state, flagOuterCode);
}

void TestWritingSymbolicConstant::test_escapedBackslash()
{
    QString input = "'\\\\'";
    QString expected = "'\\\\'";
    QString result;
    LocationFlagInCode state = flagSymbolicConstant;
    int i = 0;

    while (i < input.length()) {
        writingSymbolicConstant(input, i, result, state);
    }

    QCOMPARE(result, expected);
    QCOMPARE(state, flagOuterCode);
}

void TestWritingSymbolicConstant::test_emptyChar()
{
    QString input = "''";
    QString expected = "''";
    QString result;
    LocationFlagInCode state = flagSymbolicConstant;
    int i = 0;

    while (i < input.length()) {
        writingSymbolicConstant(input, i, result, state);
    }

    QCOMPARE(result, expected);
    QCOMPARE(state, flagOuterCode);
}

QTEST_MAIN(TestWritingSymbolicConstant)
#include "test_writingSymbolicConstant.moc"
