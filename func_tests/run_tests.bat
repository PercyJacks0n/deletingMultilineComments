chcp 1251 > nul

@echo off
set PROG=..\build\Desktop_Qt_6_9_2_MinGW_64_bit-Debug\deletingMultilineComments.exe
set RESULTS=results.txt

echo. > %RESULTS%
echo ######################################## >> %RESULTS%
echo Functional tests for deletingMultilineComments >> %RESULTS%
echo ######################################## >> %RESULTS%

echo. >> %RESULTS%
echo ### 01 No comments ### >> %RESULTS%
%PROG% test1\input.cpp test1\output.cpp >> %RESULTS% 2>&1
type test1\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 02 Block comment one line ### >> %RESULTS%
%PROG% test2\input.cpp test2\output.cpp >> %RESULTS% 2>&1
type test2\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 03 Block comment multiline ### >> %RESULTS%
%PROG% test3\input.cpp test3\output.cpp >> %RESULTS% 2>&1
type test3\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 04 Block comment without spaces ### >> %RESULTS%
%PROG% test4\input.cpp test4\output.cpp >> %RESULTS% 2>&1
type test4\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 05 Block comment at start ### >> %RESULTS%
%PROG% test5\input.cpp test5\output.cpp >> %RESULTS% 2>&1
type test5\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 06 Block comment at end ### >> %RESULTS%
%PROG% test6\input.cpp test6\output.cpp >> %RESULTS% 2>&1
type test6\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 07 Block comment between tokens ### >> %RESULTS%
%PROG% test7\input.cpp test7\output.cpp >> %RESULTS% 2>&1
type test7\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 08 Line comment (remain) ### >> %RESULTS%
%PROG% test8\input.cpp test8\output.cpp >> %RESULTS% 2>&1
type test8\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 09 Comment inside string ### >> %RESULTS%
%PROG% test9\input.cpp test9\output.cpp >> %RESULTS% 2>&1
type test9\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 10 Comment inside char ### >> %RESULTS%
%PROG% test10\input.cpp test10\output.cpp >> %RESULTS% 2>&1
type test10\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 11 Escaped quote in string ### >> %RESULTS%
%PROG% test11\input.cpp test11\output.cpp >> %RESULTS% 2>&1
type test11\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 12 Mixed line and block ### >> %RESULTS%
%PROG% test12\input.cpp test12\output.cpp >> %RESULTS% 2>&1
type test12\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 13 Several comments one line ### >> %RESULTS%
%PROG% test13\input.cpp test13\output.cpp >> %RESULTS% 2>&1
type test13\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 14 Empty file ### >> %RESULTS%
%PROG% test14\input.cpp test14\output.cpp >> %RESULTS% 2>&1
type test14\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 15 Only comment in file ### >> %RESULTS%
%PROG% test15\input.cpp test15\output.cpp >> %RESULTS% 2>&1
type test15\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 16 Invalid extension (.txt) ### >> %RESULTS%
%PROG% test16\input.txt test16\output.cpp >> %RESULTS% 2>&1
if exist test16\output.cpp type test16\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 17 #define directive ### >> %RESULTS%
%PROG% test17\input.cpp test17\output.cpp >> %RESULTS% 2>&1
if exist test17\output.cpp type test17\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 18 Non-existent input file ### >> %RESULTS%
%PROG% nonexistent.cpp test18\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 19 Invalid output path ### >> %RESULTS%
%PROG% test1\input.cpp Z:/nonexistent/folder/out19.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 20 Too many lines (1001) ### >> %RESULTS%
%PROG% test20\input.cpp test20\output.cpp >> %RESULTS% 2>&1
if exist test20\output.cpp type test20\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 21 Line too long (1001 chars) ### >> %RESULTS%
%PROG% test21\input.cpp test21\output.cpp >> %RESULTS% 2>&1
if exist test21\output.cpp type test21\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 22 Empty input path ### >> %RESULTS%
%PROG% "" test22\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 23 Empty output path ### >> %RESULTS%
%PROG% test1\input.cpp "" >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 24 Unclosed comment ### >> %RESULTS%
%PROG% test24\input.cpp test24\output.cpp >> %RESULTS% 2>&1
if exist test24\output.cpp type test24\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 25 Two comments in a row ### >> %RESULTS%
%PROG% test25\input.cpp test25\output.cpp >> %RESULTS% 2>&1
type test25\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 26 English text in comment ### >> %RESULTS%
%PROG% test26\input.cpp test26\output.cpp >> %RESULTS% 2>&1
type test26\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 27 Special chars in comment ### >> %RESULTS%
%PROG% test27\input.cpp test27\output.cpp >> %RESULTS% 2>&1
type test27\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 28 Multiple #define ### >> %RESULTS%
%PROG% test28\input.cpp test28\output.cpp >> %RESULTS% 2>&1
if exist test28\output.cpp type test28\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 29 Very large file (2000 lines) ### >> %RESULTS%
%PROG% test29\input.cpp test29\output.cpp >> %RESULTS% 2>&1
if exist test29\output.cpp type test29\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 30 Comment with tabs and spaces ### >> %RESULTS%
%PROG% test30\input.cpp test30\output.cpp >> %RESULTS% 2>&1
type test30\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 31 Multiple block comments one line ### >> %RESULTS%
%PROG% test31\input.cpp test31\output.cpp >> %RESULTS% 2>&1
type test31\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 32 Block comment with blank lines ### >> %RESULTS%
%PROG% test32\input.cpp test32\output.cpp >> %RESULTS% 2>&1
type test32\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 33 Comment without closing ### >> %RESULTS%
%PROG% test33\input.cpp test33\output.cpp >> %RESULTS% 2>&1
if exist test33\output.cpp type test33\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ### 34 Comment without opening ### >> %RESULTS%
%PROG% test34\input.cpp test34\output.cpp >> %RESULTS% 2>&1
type test34\output.cpp >> %RESULTS% 2>&1

echo. >> %RESULTS%
echo ######################################## >> %RESULTS%
echo All tests completed. Check %RESULTS% >> %RESULTS%
echo ######################################## >> %RESULTS%

type %RESULTS%
pause