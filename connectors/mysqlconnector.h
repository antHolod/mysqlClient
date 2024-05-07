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
    explicit mysqlconnector(QString,
                            int,
                            QString,
                            QString,
                            QString,
                            QObject *parent = nullptr);
    ~mysqlconnector();

private:
    QSqlDatabase _db;

    QString _host;
    int _port;
    QString _user;
    QString _pass;
    QString _dbName;

    void closeDb();

public:
    QString _lastError;

    bool connectToDb();

signals:
};

#endif // MYSQLCONNECTOR_H
