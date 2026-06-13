#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"

bool hasNoErrors(const QList<Error> & errors)
{
    if (!errors.isEmpty())
    {
        printErrorMessage(errors);
        return false;
    }
    return true;
}
