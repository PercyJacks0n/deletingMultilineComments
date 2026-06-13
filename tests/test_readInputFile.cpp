#include <QtTest>
#include <QTemporaryFile>
#include <QFile>
#include <QTextStream>
#include "../Functions.h"
#include "../Error.h"

class TestReadInputFile : public QObject
{
    Q_OBJECT

private slots:
    void test_fileExists_readSuccess();
    void test_fileNotExist();
    void test_emptyFile();
    void test_fileWithContent();
};

void TestReadInputFile::test_fileExists_readSuccess()
{
    QTemporaryFile tempFile;
    QVERIFY(tempFile.open());
    tempFile.write("int main() { return 0; }");
    tempFile.close();

    QList<Error> errors;
    QString content = readInputFile(tempFile.fileName(), errors);

    QCOMPARE(errors.size(), 0);
    QCOMPARE(content, "int main() { return 0; }");
}

void TestReadInputFile::test_fileNotExist()
{
    QList<Error> errors;
    QString content = readInputFile("C:/noexist.cpp", errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, inputFileNotExist);
    QCOMPARE(content, "");
}

void TestReadInputFile::test_emptyFile()
{
    QTemporaryFile tempFile;
    QVERIFY(tempFile.open());
    tempFile.close();

    QList<Error> errors;
    QString content = readInputFile(tempFile.fileName(), errors);

    QCOMPARE(errors.size(), 0);
    QCOMPARE(content, "");
}

void TestReadInputFile::test_fileWithContent()
{
    QTemporaryFile tempFile;
    QVERIFY(tempFile.open());
    tempFile.write("int main(){\nreturn 0;\n}");
    tempFile.close();

    QList<Error> errors;
    QString content = readInputFile(tempFile.fileName(), errors);

    QCOMPARE(errors.size(), 0);
    QVERIFY(content.contains("int main(){"));
    QVERIFY(content.contains("return 0;"));
    QVERIFY(content.contains("}"));
}

QTEST_MAIN(TestReadInputFile)
#include "test_readInputFile.moc"
