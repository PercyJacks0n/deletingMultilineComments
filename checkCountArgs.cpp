#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"

void checkCountArgs(int argc, QList<Error> & errors)
{
    if (argc != 3)
    {
        Error error;
        error.type = invalidArgumentsCount;
        error.actualCount = argc - 1;
        error.expectedValue = "2";
        errors.append(error);
    }
}
