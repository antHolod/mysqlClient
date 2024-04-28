#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //authWin = nullptr;
    //regWin = nullptr;
    connectWin = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAuthWin()
{
    /*if(authWin != nullptr)
    {
        delete authWin;
        authWin = nullptr;
    }

    authWin = new AuthForm();

    connect(authWin,&AuthForm::signalOkBtnClicked,this,&MainWindow::slotAuthOkButtonClicked);
    connect(authWin,&AuthForm::signalRegBtnClicked,this,&MainWindow::slotAuthRegButtonClicked);
    connect(authWin,&AuthForm::signalCancelBtnClicked,this,&MainWindow::slotAuthCancelButtonClicked);

    authWin->show();*/

    if(connectWin != nullptr)
    {
        delete connectWin;
        connectWin = nullptr;
    }
    connectWin = new ConnectionForm();
    if(_isConnected)
    {
        connectWin->setParent(this);
        connectWin->setWindowModality(Qt::ApplicationModal);
    }
    connectWin->show();
    connect(connectWin,&ConnectionForm::btnCancelClicked,this,&MainWindow::slotConnCancelBtnClicked);
    connect(connectWin,&ConnectionForm::btnOkClicked,this,&MainWindow::slotConnOkBtnClicked);
}

void MainWindow::slotConnOkBtnClicked(QString host,
                                      int port,
                                      QString user,
                                      QString pass,
                                      QString name)
{
    if(host.isEmpty() || port <= 0 || user.isEmpty())
    {
        connectWin->setLabelInfo();
        return;
    }

    _dbHost = host;
    _dbPort = port;
    _dbUser = user;
    _dbPass = pass;
    _dbName = name;
}

void MainWindow::slotConnCancelBtnClicked()
{
    if(_isConnected)
    {
        connectWin->close();
        connectWin = nullptr;
    }
    else
    {
        QApplication::quit();
    }
}

/*void MainWindow::slotAuthRegButtonClicked()
{
    authWin->hide();
    if(regWin != nullptr)
    {
        delete regWin;
        regWin = nullptr;
    }
    regWin = new reguserform();

    regWin->show();
    connect(regWin,&reguserform::signalRegOkClicked,this,&MainWindow::slotRegOkButtonClicked);
    connect(regWin,&reguserform::signalRegCancelClicked,this,&MainWindow::slotRegCancelButtonClicked);

}*/

/*void MainWindow::slotAuthOkButtonClicked()
{

}*/

/*void MainWindow::slotAuthCancelButtonClicked()
{
    if(!_isConnected) QApplication::quit();
    else authWin->close();
}*/

/*void MainWindow::slotRegOkButtonClicked(QString name, QString pass)
{

}*/

/*void MainWindow::slotRegCancelButtonClicked()
{
    regWin->close();
    if(!_isConnected)
        authWin->show();
}*/
