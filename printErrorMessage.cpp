#include <QString>
#include <QList>
#include <QDebug>
#include "Functions.h"
#include "Error.h"

// Выводит сообщения об ошибках в консоль
void printErrorMessage(const QList<Error> & errors)
{
    if (errors.isEmpty()) return;

    // Выводим заголовок
    qDebug() << "Обнаружены ошбики:\n";

    // Для каждой ошибки генерируем сообщение и выводим
    for (const Error & error : errors)
    {
        qDebug() << error.generateErrorMessage();
    }
}
