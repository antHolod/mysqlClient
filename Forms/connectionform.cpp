#include "connectionform.h"
#include "ui_connectionform.h"
//#include <QDebug>

ConnectionForm::ConnectionForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ConnectionForm)
{
    ui->setupUi(this);
    ui->editPort->setText("3306");
    ui->labelInfo->setText(connectInfoStart);
}

ConnectionForm::~ConnectionForm()
{
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

    if(message.isEmpty()) ui->labelInfo->setText(connectInfoStart);
    else ui->labelInfo->setText(message);
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
    emit btnOkClicked(_Host,_Port,_User,_Password,_Name);
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

