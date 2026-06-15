#include <QtTest>
#include "../Functions.h"
#include "../LocationFlagInCode.h"

class TestFindingEndMultiLineComment : public QObject
{
    Q_OBJECT

private slots:
    void test_closeComment();
    void test_noCloseYet();
    void test_closeWithNewline();
    void test_immediateEndOfString();
};

void TestFindingEndMultiLineComment::test_closeComment()
{
    QString input = "*/";
    LocationFlagInCode state = flagMultiLineComment;
    int i = 0;

    findingEndMultiLineComment(input, i, state);

    QCOMPARE(state, flagOuterCode);
    QCOMPARE(i, 2);
}

void TestFindingEndMultiLineComment::test_noCloseYet()
{
    QString input = "text";
    LocationFlagInCode state = flagMultiLineComment;
    int i = 0;

    findingEndMultiLineComment(input, i, state);

    QCOMPARE(state, flagMultiLineComment);
    QCOMPARE(i, 1);
}

void TestFindingEndMultiLineComment::test_closeWithNewline()
{
    QString input = "*/\n";
    LocationFlagInCode state = flagMultiLineComment;
    int i = 0;

    findingEndMultiLineComment(input, i, state);

    QCOMPARE(state, flagOuterCode);
    QCOMPARE(i, 2);
}

void TestFindingEndMultiLineComment::test_immediateEndOfString()
{
    QString input = "/*";
    LocationFlagInCode state = flagMultiLineComment;
    int i = 0;

    i = 2;

    findingEndMultiLineComment(input, i, state);

    QCOMPARE(state, flagMultiLineComment);
    QCOMPARE(i, 3);
}

QTEST_MAIN(TestFindingEndMultiLineComment)
#include "test_findingEndMultiLineComment.moc"
