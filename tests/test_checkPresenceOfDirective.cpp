#include <QtTest>
#include "../Functions.h"
#include "../Error.h"

class TestCheckPresenceOfDirective : public QObject
{
    Q_OBJECT

private slots:
    void test_oneDefine();
    void test_defineWithoutSpaces();
    void test_defineWithSpaces();
    void test_notDefine();
};

void TestCheckPresenceOfDirective::test_oneDefine()
{
    QString inputCode = "#define MAX 100";
    int countDirective = 0;
    QString directive = "define";
    int i = 0;

    checkPresenceOfDirective(inputCode, i, countDirective, directive);

    QCOMPARE(countDirective, 1);
}

void TestCheckPresenceOfDirective::test_defineWithoutSpaces()
{
    QString inputCode = "#define MAX 100";
    int i = 0;
    int countDirective = 0;
    QString directive = "define";

    checkPresenceOfDirective(inputCode, i, countDirective, directive);

    QCOMPARE(countDirective, 1);
}

void TestCheckPresenceOfDirective::test_defineWithSpaces()
{
    QString inputCode = "#   define MAX 100";
    int i = 0;
    int countDirective = 0;
    QString directive = "define";

    checkPresenceOfDirective(inputCode, i, countDirective, directive);

    QCOMPARE(countDirective, 1);
}

void TestCheckPresenceOfDirective::test_notDefine()
{
    QString inputCode = "#not_define";
    int i = 0;
    int countDirective = 0;
    QString directive = "define";

    checkPresenceOfDirective(inputCode, i, countDirective, directive);

    QCOMPARE(countDirective, 0);
}


QTEST_MAIN(TestCheckPresenceOfDirective)
#include "test_checkPresenceOfDirective.moc"
