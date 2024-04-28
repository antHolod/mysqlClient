#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "Forms/authform.h"
//#include "Forms/reguserform.h"
#include "Forms/connectionform.h"

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
    //bool _isEnter;
    bool _isConnected = false;
    //QString _progUser;
    //QString _progPass;

    //AuthForm *authWin;
    //reguserform *regWin;
    ConnectionForm *connectWin;

public slots:
    //void slotAuthRegButtonClicked();
    //void slotAuthOkButtonClicked();
    //void slotAuthCancelButtonClicked();
    //void slotRegOkButtonClicked(QString,QString);
    //void slotRegCancelButtonClicked();
};
#endif // MAINWINDOW_H
