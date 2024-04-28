#ifndef SQLITECONNECTOR_H
#define SQLITECONNECTOR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QMap>
#include <QTextStream>
#include <QFile>

#define DB_FILE "settings.db"
#define CONNECTION_NAME "sqlite_conn"

class sqliteconnector : public QObject
{
    Q_OBJECT
public:
    explicit sqliteconnector(QObject *parent = nullptr);

private:
    QSqlDatabase _db;

    bool connectionToDb();
    bool restoreDb();
    void closeConnToDb();
    bool addTable();


signals:
    void signalReady(bool);
};

#endif // SQLITECONNECTOR_H
