#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectWin = nullptr;
}

MainWindow::~MainWindow()
{
    if(_isConnected)
    {
        QSettings settings(SETTINGS_FILE,QSettings::IniFormat);
    }

    delete ui;
}

void MainWindow::displayAuthWin()
{
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

    if(QFile::exists(SETTINGS_FILE))
    {
        QSettings settings(SETTINGS_FILE,QSettings::IniFormat);
        if(settings.contains(SETTINGS_GROUP_CONNECT))
        {
            settings.beginGroup(SETTINGS_GROUP_CONNECT);
            int x = settings.value("x").toInt();
            int y = settings.value("y").toInt();
            int w = settings.value("w").toInt();
            int h = settings.value("h").toInt();
            settings.endGroup();

            connectWin->setGeometry(x,y,w,h);
        }
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
    if(host.isEmpty() || port <= 0 || user.isEmpty() || name.isEmpty())
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
        delete connectWin;
        connectWin = nullptr;
    }
    else
    {
        QApplication::quit();
    }
}

