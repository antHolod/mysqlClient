#include "connectionform.h"
#include "ui_connectionform.h"
//#include <QDebug>
#include <QDir>
#include <QFile>

ConnectionForm::ConnectionForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ConnectionForm)
{
    ui->setupUi(this);
    ui->editPort->setText("3306");
    ui->labelInfo->setText(connectInfoStart);
    emptyPass = nullptr;

    settingsFilePath = QDir::currentPath();
    settingsFilePath.append("/");
    settingsFilePath.append(SETTINGS_FILE);

    int x = 0,y = 0,w = 0,h = 0;
    QSettings settings(settingsFilePath,QSettings::IniFormat);
    settings.beginGroup(SETTINGS_GROUP_CONNECT);
    if(settings.value("w").toInt() > 0)
        w = settings.value("w").toInt();
    if(settings.value("h").toInt() > 0)
        h = settings.value("h").toInt();
    if(settings.value("x").toInt() > 0)
        x = settings.value("x").toInt();
    if(settings.value("y").toInt() > 0)
        y = settings.value("y").toInt();

    if(!settings.value("host").toString().isEmpty())
        ui->editHost->setText(settings.value("host").toString());
    if(!settings.value("port").toString().isEmpty())
        ui->editPort->setText(settings.value("port").toString());
    if(!settings.value("user").toString().isEmpty())
        ui->editUser->setText(settings.value("user").toString());
    if(!settings.value("name").toString().isEmpty())
        ui->editDbName->setText(settings.value("name").toString());
    settings.endGroup();

    if(x != 0 && y != 0 && w != 0 && h != 0)
    {
        this->resize(w,h);
        this->move(x,y);
    }
}

ConnectionForm::~ConnectionForm()
{
    int x = this->x();
    int y = this->y();
    int w = this->width();
    int h = this->height();
    QSettings settings(settingsFilePath,QSettings::IniFormat);
    //qDebug() << "Exit: " << settings.fileName() << Qt::endl;
    settings.beginGroup(SETTINGS_GROUP_CONNECT);
    settings.setValue("x",x);
    settings.setValue("y",y);
    settings.setValue("w",w);
    settings.setValue("h",h);
    settings.endGroup();

    delete ui;
}

void ConnectionForm::setLabelInfo()
{
    QString message;
    if(ui->editHost->text().isEmpty())
    {
        if(!message.isEmpty())
            message.append("\n");
        message.append(connectInfoNoHost);
    }
    if(ui->editPort->text().isEmpty())
    {
        if(!message.isEmpty())
            message.append("\n");
        message.append(connectInfoNoPort);
    }
    if(ui->editUser->text().isEmpty())
    {
        if(!message.isEmpty())
            message.append("\n");
        message.append(connectInfoNoName);
    }
    if(ui->editDbName->text().isEmpty())
    {
        if(!message.isEmpty())
            message.append("\n");
        message.append(connectInfoNoDb);
    }

    if(message.isEmpty()) ui->labelInfo->setText(connectInfoStart);
    else
    {
        ui->labelInfo->setText(message);
        focusOnField();
    }
}

void ConnectionForm::setLabelInfo(const QString &text)
{
    ui->labelInfo->setText(text);
    focusOnField();
}


void ConnectionForm::on_checkSaveConn_stateChanged(int arg1)
{
    if(!arg1) _saveConnection = false;
    else _saveConnection = true;

    /*QString str = _saveConnection ? "Save" : "Not save";

    qDebug() << str << Qt::endl;*/
}


void ConnectionForm::on_butCancel_clicked()
{
    emit btnCancelClicked();
}


void ConnectionForm::on_butOk_clicked()
{
    if(ui->editPass->text().isEmpty())
    {
        if(emptyPass != nullptr)
        {
            delete emptyPass;
            emptyPass = nullptr;
        }
        emptyPass = new EmptyPassDialog(this);
        emptyPass->setWindowModality(Qt::WindowModal);
        emptyPass->show();
        connect(emptyPass,&EmptyPassDialog::signalContinue,this,&ConnectionForm::onEmptyPassOkClicked);
        connect(emptyPass,&EmptyPassDialog::signalGoBack,this,&ConnectionForm::onEmptyPassCancelClicked);
    }
    else
        emit btnOkClicked(_Host,_Port,_User,_Password,_Name,_saveConnection);
}


void ConnectionForm::on_editHost_editingFinished()
{
    //setLabelInfo();
    _Host = ui->editHost->text();
}


void ConnectionForm::on_editPort_editingFinished()
{
    //setLabelInfo();
    _Port = ui->editPort->text().toInt();
}


void ConnectionForm::on_editUser_editingFinished()
{
    //setLabelInfo();
    _User = ui->editUser->text();
}


void ConnectionForm::on_editPass_editingFinished()
{
    //setLabelInfo();
    _Password = ui->editPass->text();
}


void ConnectionForm::on_editDbName_editingFinished()
{
    _Name = ui->editDbName->text();
}

void ConnectionForm::onEmptyPassOkClicked()
{
    emit btnOkClicked(_Host,_Port,_User,_Password,_Name,_saveConnection);
    closeEmptyPassDialog();
}

void ConnectionForm::onEmptyPassCancelClicked()
{
    closeEmptyPassDialog();
    ui->editPass->setFocus();
}

void ConnectionForm::closeEmptyPassDialog()
{
    if(emptyPass == nullptr) return;

    emptyPass->close();
    delete emptyPass;
    emptyPass = nullptr;
}

void ConnectionForm::focusOnField()
{
    if(ui->editHost->text().isEmpty())
        ui->editHost->setFocus();
    else if(ui->editPort->text().isEmpty())
        ui->editPort->setFocus();
    else if(ui->editUser->text().isEmpty())
        ui->editUser->setFocus();
    else if(ui->editPass->text().isEmpty())
        ui->editPass->setFocus();
    else if(ui->editDbName->text().isEmpty())
        ui->editDbName->setFocus();
}

