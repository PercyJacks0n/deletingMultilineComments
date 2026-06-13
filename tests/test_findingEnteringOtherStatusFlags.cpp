#include <QtTest>
#include "../Functions.h"
#include "../LocationFlagInCode.h"

class TestFindingEnteringOtherStatusFlags : public QObject
{
    Q_OBJECT

private slots:
    void test_normalText();
    void test_startBlockComment();
    void test_startLineComment();
    void test_startString();
    void test_startChar();
};

void TestFindingEnteringOtherStatusFlags::test_normalText()
{
    QString input = "int a = 5;";
    QString result;
    LocationFlagInCode state = flagOuterCode;
    int i = 0;
    int countDirective = 0;
    QString directive = "define";

    while (i < input.length()) {
        findingEnteringOtherStatusFlags(input, i, result, state, countDirective, directive);
    }

    QCOMPARE(result, input);
    QCOMPARE(state, flagOuterCode);
}

void TestFindingEnteringOtherStatusFlags::test_startBlockComment()
{
    QString input = "/* comment */";
    QString result;
    LocationFlagInCode state = flagOuterCode;
    int i = 0;
    int countDirective = 0;
    QString directive = "define";

    findingEnteringOtherStatusFlags(input, i, result, state, countDirective, directive);

    QCOMPARE(result, QString(""));
    QCOMPARE(state, flagMultiLineComment);
    QCOMPARE(i, 2);
}

void TestFindingEnteringOtherStatusFlags::test_startLineComment()
{
    QString input = "// comment";
    QString result;
    LocationFlagInCode state = flagOuterCode;
    int i = 0;
    int countDirective = 0;
    QString directive = "define";

    findingEnteringOtherStatusFlags(input, i, result, state, countDirective, directive);

    QCOMPARE(result, QString("//"));
    QCOMPARE(state, flagOneLineComment);
    QCOMPARE(i, 2);
}

void TestFindingEnteringOtherStatusFlags::test_startString()
{
    QString input = "\"hello\"";
    QString result;
    LocationFlagInCode state = flagOuterCode;
    int i = 0;
    int countDirective = 0;
    QString directive = "define";
    findingEnteringOtherStatusFlags(input, i, result, state, countDirective, directive);

    QCOMPARE(result, QString("\""));
    QCOMPARE(state, flagStringConstant);
    QCOMPARE(i, 1);
}

void TestFindingEnteringOtherStatusFlags::test_startChar()
{
    QString input = "'a'";
    QString result;
    LocationFlagInCode state = flagOuterCode;
    int i = 0;
    int countDirective = 0;
    QString directive = "define";
    findingEnteringOtherStatusFlags(input, i, result, state, countDirective, directive);

    QCOMPARE(result, QString("'"));
    QCOMPARE(state, flagSymbolicConstant);
    QCOMPARE(i, 1);
}

QTEST_MAIN(TestFindingEnteringOtherStatusFlags)
#include "test_findingEnteringOtherStatusFlags.moc"
