#include "mysqlconnector.h"

mysqlconnector::mysqlconnector(QString host,
                               int port,
                               QString user,
                               QString pass,
                               QString db,
                               QObject *parent)
    : QObject{parent},_host{host},_port{port},_user{user},_pass{pass},_dbName{db}
{

}

mysqlconnector::~mysqlconnector()
{
    closeDb();
}

bool mysqlconnector::connectToDb()
{
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setHostName(_host);
    _db.setPort(_port);
    _db.setUserName(_user);
    _db.setPassword(_pass);
    _db.setDatabaseName(_dbName);

    if(_db.open())
        return true;
    else
        _lastError = _db.lastError().text();

    return false;
}

void mysqlconnector::closeDb()
{
    _db.close();
}
