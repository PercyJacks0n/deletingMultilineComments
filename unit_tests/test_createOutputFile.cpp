#include <QtTest>
#include <QTemporaryFile>
#include <QFile>
#include <QFileInfo>
#include "../Functions.h"
#include "../Error.h"

class TestCreateOutputFile : public QObject
{
    Q_OBJECT

private slots:
    void test_successfulWrite();
    void test_invalidPath();
    void test_multilineContent();
};

void TestCreateOutputFile::test_successfulWrite()
{
    QTemporaryFile tempFile;
    tempFile.open();
    QString tempPath = tempFile.fileName();
    tempFile.close();

    QList<Error> errors;
    QString content = "int a = 5;\nint b = 10;";

    createOutputFile(content, tempPath, errors);

    QCOMPARE(errors.size(), 0);

    QFile file(tempPath);
    QVERIFY(file.exists());
    QVERIFY(file.open(QIODevice::ReadOnly));

    QTextStream stream(&file);
    QString actualContent = stream.readAll();
    file.close();

    QCOMPARE(actualContent, content);
}

void TestCreateOutputFile::test_invalidPath()
{
    QString invalidPath = "Z:/nonexistent/output.cpp";

    QList<Error> errors;
    QString content = "content";

    createOutputFile(content, invalidPath, errors);

    QCOMPARE(errors.size(), 1);
    QCOMPARE(errors[0].type, outputFileCreateError);
    QCOMPARE(errors[0].errorOutputFileWay, invalidPath);
}

void TestCreateOutputFile::test_multilineContent()
{
    QTemporaryFile tempFile;
    tempFile.open();
    QString tempPath = tempFile.fileName();
    tempFile.close();

    QList<Error> errors;
    QString content =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    return 0;\n"
        "}\n";

    createOutputFile(content, tempPath, errors);

    QCOMPARE(errors.size(), 0);

    QFile file(tempPath);
    QVERIFY(file.open(QIODevice::ReadOnly));

    QString actualContent = file.readAll();
    file.close();

    QCOMPARE(actualContent, content);
}

QTEST_MAIN(TestCreateOutputFile)
#include "test_createOutputFile.moc"
