#include "sqliteconnector.h"

sqliteconnector::sqliteconnector(QObject *parent)
    : QObject{parent}
{

}

bool sqliteconnector::connectionToDb()
{
    _db = QSqlDatabase::addDatabase(DB_FILE,CONNECTION_NAME);
    _db.setDatabaseName(DB_FILE);
    if(!_db.open())
    {
        QString text = "Can't find data base '";
        text.append(DB_FILE);
        text.append("'");
        QTextStream(stdout) << text << "\n" << _db.lastError().text() << Qt::endl;
        return false;
    }

    return true;
}
