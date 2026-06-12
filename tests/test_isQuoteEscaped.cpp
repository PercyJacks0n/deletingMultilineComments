#include <QtTest>
#include "../Functions.h"

class TestIsQuoteEscaped : public QObject
{
    Q_OBJECT

private slots:
    void test_noBackslashes();
    void test_oneBackslash();
    void test_twoBackslashes();
    void test_threeBackslashes();
    void test_fourBackslashes();
    void test_fiveBackslashes();
    void test_multipleQuotes();
};

void TestIsQuoteEscaped::test_noBackslashes()
{
    QString code = "\"";
    bool result = isQuoteEscaped(code, 0);
    QCOMPARE(result, false);
}

void TestIsQuoteEscaped::test_oneBackslash()
{
    QString code = "\\\"";
    bool result = isQuoteEscaped(code, 1);
    QCOMPARE(result, true);
}

void TestIsQuoteEscaped::test_twoBackslashes()
{
    QString code = "\\\\\"";
    bool result = isQuoteEscaped(code, 2);
    QCOMPARE(result, false);
}

void TestIsQuoteEscaped::test_threeBackslashes()
{
    QString code = "\\\\\\\"";
    bool result = isQuoteEscaped(code, 3);
    QCOMPARE(result, true);
}

void TestIsQuoteEscaped::test_fourBackslashes()
{
    QString code = "\\\\\\\\\"";
    bool result = isQuoteEscaped(code, 4);
    QCOMPARE(result, false);
}

void TestIsQuoteEscaped::test_fiveBackslashes()
{
    QString code = "\\\\\\\\\\\"";
    bool result = isQuoteEscaped(code, 5);
    QCOMPARE(result, true);
}

void TestIsQuoteEscaped::test_multipleQuotes()
{
    QString code = "Hello \\\" world!";
    bool result = isQuoteEscaped(code, 7);
    QCOMPARE(result, true);
}

QTEST_MAIN(TestIsQuoteEscaped)
#include "test_isQuoteEscaped.moc"
