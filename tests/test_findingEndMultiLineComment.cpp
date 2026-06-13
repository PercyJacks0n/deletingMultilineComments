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

QTEST_MAIN(TestFindingEndMultiLineComment)
#include "test_findingEndMultiLineComment.moc"
