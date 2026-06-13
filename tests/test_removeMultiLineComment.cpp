#include <QtTest>
#include "../Functions.h"
#include "../LocationFlagInCode.h"

class TestRemoveMultiLineComment : public QObject
{
    Q_OBJECT

private slots:
    void test_noComments();
    void test_simpleComment();
    void test_commentAtStart();
    void test_commentAtEnd();
    void test_commentOnNewLine();
    void test_commentInsideLine();
    void test_commentWithBlankLines();
    void test_commentBeforeCode();
    void test_commentAfterCode();
    void test_commentInString();
    void test_commentInChar();
    void test_severalCommentsInOneLine();
    void test_severalCommentsInDifferentLines();
    void test_commentWithoutSpaces();
    void test_commentAtFileStartNoNewline();
    void test_commentAtFileEndNoNewline();
    void test_onlyCommentInFile();
    void test_emptyFile();
    void test_commentBetweenTokens();
    void test_commentWithSpecialChars();
    void test_commentWithRussianText();
    void test_lineCommentNotRemoved();
    void test_lineCommentWithBlockInside();
    void test_mixedLineAndBlock();
    void test_complexExample();
};

void TestRemoveMultiLineComment::test_noComments()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    int b = 10;\n"
        "    std::cout << a << b << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, input);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_simpleComment()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    /* это комментарий */\n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    \n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentAtStart()
{
    QString input =
        "/* комментарий в начале */\n"
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "\n"
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentAtEnd()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    return 0;\n"
        "}\n"
        "/* комментарий в конце */\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    return 0;\n"
        "}\n"
        "\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentOnNewLine()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    /* комментарий */\n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    \n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentInsideLine()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    std::cout << /* int */ x << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    std::cout <<  x << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentWithBlankLines()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    /*\n"
        "\n"
        "       середина\n"
        "\n"
        "    */\n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    \n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentBeforeCode()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    /* табуляция */int a = 5;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentAfterCode()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5; /* конец строки */\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5; \n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentInString()
{
    QString input =
        "#include <iostream>\n"
        "#include <string>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    std::string s = \"/* это не комментарий */\";\n"
        "    std::cout << s << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "#include <string>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    std::string s = \"/* это не комментарий */\";\n"
        "    std::cout << s << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentInChar()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    char ch = '/*';\n"
        "    std::cout << ch << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    char ch = '/*';\n"
        "    std::cout << ch << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_severalCommentsInOneLine()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5; /* первый */ int b = 10; /* второй */ int c = 15;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5;  int b = 10;  int c = 15;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_severalCommentsInDifferentLines()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "/* первый */\n"
        "int a = 5;\n"
        "/* второй */\n"
        "int b = 10;\n"
        "/* третий */\n"
        "int main() { return 0; }\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "\n"
        "int a = 5;\n"
        "\n"
        "int b = 10;\n"
        "\n"
        "int main() { return 0; }\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentWithoutSpaces()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a=5;/*комментарий*/int b=10;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a=5;int b=10;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentAtFileStartNoNewline()
{
    QString input = "/* комментарий */#include <iostream>\nint main() { return 0; }";
    QString expected = "#include <iostream>\nint main() { return 0; }";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentAtFileEndNoNewline()
{
    QString input = "#include <iostream>\nint main() { return 0; }/* комментарий */";
    QString expected = "#include <iostream>\nint main() { return 0; }";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_onlyCommentInFile()
{
    QString input = "/* комментарий */\n";
    QString expected = "\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_emptyFile()
{
    QString input = "";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, "");
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentBetweenTokens()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int/* комментарий */a = 5;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    inta = 5;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentWithSpecialChars()
{
    QString input =
        "/* спецсимволы !@#$%^&*()_+-=[]{};:'\"<>?,./ */\n"
        "#include <iostream>\n"
        "int main() { return 0; }\n";

    QString expected =
        "\n"
        "#include <iostream>\n"
        "int main() { return 0; }\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_commentWithRussianText()
{
    QString input =
        "/* это комментарий на русском */\n"
        "#include <iostream>\n"
        "int main() { return 0; }\n";

    QString expected =
        "\n"
        "#include <iostream>\n"
        "int main() { return 0; }\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_lineCommentNotRemoved()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5; // это однострочный комментарий\n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int a = 5; // это однострочный комментарий\n"
        "    int b = 10;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_lineCommentWithBlockInside()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    // комментарий с /* многострочным внутри */\n"
        "    int a = 5;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    // комментарий с /* многострочным внутри */\n"
        "    int a = 5;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_mixedLineAndBlock()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    // оставить это\n"
        "    int a = 5; /* удалить это */\n"
        "    // оставить и это\n"
        "    int b = 10;\n"
        "    /* удалить\n"
        "       этот\n"
        "       коммент */\n"
        "    int c = 15;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "int main()\n"
        "{\n"
        "    // оставить это\n"
        "    int a = 5; \n"
        "    // оставить и это\n"
        "    int b = 10;\n"
        "    \n"
        "    int c = 15;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

void TestRemoveMultiLineComment::test_complexExample()
{
    QString input =
        "#include <iostream>\n"
        "\n"
        "/*\n"
        " * Автор: студент\n"
        " * Дата: 2026\n"
        " */\n"
        "int main()\n"
        "{\n"
        "    int x = 10; // инициализация x\n"
        "    /* вывод */\n"
        "    std::cout << x << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QString expected =
        "#include <iostream>\n"
        "\n"
        "\n"
        "int main()\n"
        "{\n"
        "    int x = 10; // инициализация x\n"
        "    \n"
        "    std::cout << x << std::endl;\n"
        "    return 0;\n"
        "}\n";

    QList<Error> errors;
    QString result = removeMultiLineComment(input, errors);
    QCOMPARE(result, expected);
    QCOMPARE(errors.size(), 0);
}

QTEST_MAIN(TestRemoveMultiLineComment)
#include "test_removeMultiLineComment.moc"
