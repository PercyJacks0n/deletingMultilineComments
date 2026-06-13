#include <QtTest>
#include "../Functions.h"
#include "../Error.h"

class TestCheckExtension : public QObject
{
    Q_OBJECT

private slots:
    void test_cppExtension();
    void test_cExtension();
    void test_hExtension();
    void test_txtExtension();
    void test_exeExtension();
    void test_noExtension();
    void test_mixedCaseExtension();
    void test_pathWithSpaces();
};

void TestCheckExtension::test_cppExtension()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("source.cpp", allowedExtensions, errors);

    QCOMPARE(errors.size(), 0);
}

void TestCheckExtension::test_cExtension()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("source.c", allowedExtensions, errors);

    QCOMPARE(errors.size(), 0);
}

void TestCheckExtension::test_hExtension()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("source.h", allowedExtensions, errors);

    QCOMPARE(errors.size(), 0);
}

void TestCheckExtension::test_txtExtension()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("source.txt", allowedExtensions, errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, invalidFileExtension);
    QCOMPARE(errors[0].actualValue, "txt");
    QVERIFY(errors[0].expectedValue.contains("cpp"));
    QVERIFY(errors[0].expectedValue.contains("c"));
    QVERIFY(errors[0].expectedValue.contains("h"));
}

void TestCheckExtension::test_exeExtension()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("program.exe", allowedExtensions, errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, invalidFileExtension);
    QCOMPARE(errors[0].actualValue, "exe");
}

void TestCheckExtension::test_noExtension()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("sourcefile", allowedExtensions, errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, invalidFileExtension);
    QCOMPARE(errors[0].actualValue, "");
}

void TestCheckExtension::test_mixedCaseExtension()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("source.CPP", allowedExtensions, errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, invalidFileExtension);
    QCOMPARE(errors[0].actualValue, "CPP");
}

void TestCheckExtension::test_pathWithSpaces()
{
    QList<Error> errors;
    QList<QString> allowedExtensions = {"cpp", "c", "h"};
    checkExtension("C:/My project/source.cpp", allowedExtensions, errors);

    QCOMPARE(errors.size(), 0);
}

QTEST_MAIN(TestCheckExtension)
#include "test_checkExtension.moc"
