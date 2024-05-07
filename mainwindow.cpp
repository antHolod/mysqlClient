#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectWin = nullptr;
}

MainWindow::~MainWindow()
{
    if(_isConnected && _saveConnection)
    {
        QSettings settings(settingsFilePath,QSettings::IniFormat);
        settings.beginGroup(SETTINGS_GROUP_CONNECT);
        settings.setValue("host",_dbHost);
        settings.setValue("port",_dbPort);
        settings.setValue("user",_dbUser);
        settings.setValue("name",_dbName);
        settings.endGroup();
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

    /*if(QFile::exists(SETTINGS_FILE))
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
    else qDebug() << "Settings file not find" << Qt::endl;*/

    connectWin->show();
    connect(connectWin,&ConnectionForm::btnCancelClicked,this,&MainWindow::slotConnCancelBtnClicked);
    connect(connectWin,&ConnectionForm::btnOkClicked,this,&MainWindow::slotConnOkBtnClicked);
}

void MainWindow::slotConnOkBtnClicked(QString host,
                                      int port,
                                      QString user,
                                      QString pass,
                                      QString name,
                                      bool save)
{
    if(host.isEmpty() || port <= 0 || user.isEmpty() || name.isEmpty())
    {
        connectWin->setLabelInfo();
        return;
    }

    _db = new mysqlconnector(host,port,user,pass,name);
    if(!_db->connectToDb())
    {
        QString text;
        text.append(connectError);
        text.append(_db->_lastError);
        connectWin->setLabelInfo(text);

        return;
    }

    _dbHost = host;
    _dbPort = port;
    _dbUser = user;
    _dbPass = pass;
    _dbName = name;
    _saveConnection = save;
    this->settingsFilePath = connectWin->settingsFilePath;

    _isConnected = true;
    connectWin->close();
    this->show();
    delete connectWin;
    connectWin = nullptr;
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
        connectWin->close();
        delete connectWin;
        QApplication::quit();
    }
}

