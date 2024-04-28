#ifndef MYSQLCONNECTOR_H
#define MYSQLCONNECTOR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QTextStream>

class mysqlconnector : public QObject
{
    Q_OBJECT
public:
    explicit mysqlconnector(QObject *parent = nullptr);

private:
    QSqlDatabase _db;

    QString _host;
    int _port;
    QString _user;
    QString _pass;
    QString _dbName;

signals:
};

#endif // MYSQLCONNECTOR_H
