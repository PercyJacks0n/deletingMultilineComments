#include <QString>
#include <QList>
#include "Functions.h"
#include "Error.h"

// Проверяет, есть ли ошибки в списке
bool hasNoErrors(const QList<Error> & errors)
{
    if (!errors.isEmpty())
    {
        // Если ошибки есть то выводим их
        printErrorMessage(errors);
        return false;
    }
    return true;
}
