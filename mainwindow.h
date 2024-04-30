#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QFile>

#include "Forms/connectionform.h"
#include "connectors/mysqlconnector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayAuthWin();

private:
    Ui::MainWindow *ui;

    QString _dbHost;
    int _dbPort;
    QString _dbUser;
    QString _dbPass;
    QString _dbName;
    bool _isConnected = false;
    ConnectionForm *connectWin;

public slots:
    void slotConnOkBtnClicked(QString,int,QString,QString,QString);
    void slotConnCancelBtnClicked();
};
#endif // MAINWINDOW_H
