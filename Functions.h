#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QList>
#include "Error.h"
#include "LocationFlagInCode.h"

void checkCountArgs(int argc, QList<Error> & errors);

void checkExtension(const QString & filePath, QList<QString> & allowedExtensions,QList<Error> & errors);

QString readInputFile(const QString & filePath, QList<Error> & errors);

void checkSizeOfFile(const QString & inputCode, QList<Error> & errors);

void checkPresenceOfDirective(const QString & inputCode, int & i, int & countDirective, QString & directive);

QString removeMultiLineComment(const QString & inputCode, QList<Error> & errors);

void findingEnteringOtherStatusFlags(const QString & inputCode,
                                     int & i,
                                     QString & result,
                                     LocationFlagsInCode & state,
                                     int & countDirective,
                                     QString & directive);

void findingEndMultiLineComment(const QString & inputCode, int & i, LocationFlagsInCode & state);

void writingOneLineComment(const QString & inputCode, int & i, QString & result, LocationFlagsInCode & state);

void writingStringConstant(const QString & inputCode, int & i, QString & result, LocationFlagsInCode & state);

void writingSymbolicConstant(const QString & inputCode, int & i, QString & result, LocationFlagsInCode & state);

bool isQuoteEscaped(const QString & code, int pos);

void createOutputFile(const QString & content, const QString & filePath, QList<Error> & errors);

bool hasNoErrors(const QList<Error> & errors);

void printErrorMessage(const QList<Error> & errors);

#endif // FUNCTIONS_H
