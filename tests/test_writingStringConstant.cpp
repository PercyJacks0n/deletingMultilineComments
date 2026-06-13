#include <QtTest>
#include "../Functions.h"
#include "../LocationFlagInCode.h"

class TestWritingStringConstant : public QObject
{
    Q_OBJECT

private slots:
    void test_normalString();
    void test_escapedQuote();
    void test_emptyString();
    void test_stringWithBackslash();
};

void TestWritingStringConstant::test_normalString()
{
    QString input = "\"hello world\"";
    QString result;
    LocationFlagInCode state = flagStringConstant;
    int i = 0;

    while (i < input.length()) {
        writingStringConstant(input, i, result, state);
    }

    QCOMPARE(result, input);
    QCOMPARE(state, flagOuterCode);
}

void TestWritingStringConstant::test_escapedQuote()
{
    QString input = "\"hello\\\"world\"";
    QString expected = "\"hello\\\"world\"";
    QString result;
    LocationFlagInCode state = flagStringConstant;
    int i = 0;

    while (i < input.length()) {
        writingStringConstant(input, i, result, state);
    }

    QCOMPARE(result, expected);
    QCOMPARE(state, flagOuterCode);
}

void TestWritingStringConstant::test_emptyString()
{
    QString input = "\"\"";
    QString expected = "\"\"";
    QString result;
    LocationFlagInCode state = flagStringConstant;
    int i = 0;

    while (i < input.length()) {
        writingStringConstant(input, i, result, state);
    }

    QCOMPARE(result, expected);
    QCOMPARE(state, flagOuterCode);
}

void TestWritingStringConstant::test_stringWithBackslash()
{
    QString input = "\"hello\\world\"";
    QString expected = "\"hello\\world\"";
    QString result;
    LocationFlagInCode state = flagStringConstant;
    int i = 0;

    while (i < input.length()) {
        writingStringConstant(input, i, result, state);
    }

    QCOMPARE(result, expected);
    QCOMPARE(state, flagOuterCode);
}

QTEST_MAIN(TestWritingStringConstant)
#include "test_writingStringConstant.moc"
