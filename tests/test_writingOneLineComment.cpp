#include <QtTest>
#include "../Functions.h"
#include "../LocationFlagInCode.h"

class TestWritingOneLineComment : public QObject
{
    Q_OBJECT

private slots:
    void test_copyCharacters();
    void test_newlineEnd();
    void test_multipleCharacters();
};

void TestWritingOneLineComment::test_copyCharacters()
{
    QString input = "comment";
    QString result;
    LocationFlagInCode state = flagOneLineComment;
    int i = 0;

    writingOneLineComment(input, i, result, state);

    QCOMPARE(result, QString("c"));
    QCOMPARE(state, flagOneLineComment);
    QCOMPARE(i, 1);
}

void TestWritingOneLineComment::test_newlineEnd()
{
    QString input = "\n";
    QString result;
    LocationFlagInCode state = flagOneLineComment;
    int i = 0;

    writingOneLineComment(input, i, result, state);

    QCOMPARE(result, QString("\n"));
    QCOMPARE(state, flagOuterCode);
    QCOMPARE(i, 1);
}

void TestWritingOneLineComment::test_multipleCharacters()
{
    QString input = "comment";
    QString result;
    LocationFlagInCode state = flagOneLineComment;
    int i = 0;

    while (i < input.length()) {
        writingOneLineComment(input, i, result, state);
    }

    QCOMPARE(result, input);
    QCOMPARE(state, flagOneLineComment);
}

QTEST_MAIN(TestWritingOneLineComment)
#include "test_writingOneLineComment.moc"
