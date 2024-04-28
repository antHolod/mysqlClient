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
    emit btnOkClicked(_Host,_Port,_User,_Password);
}


void ConnectionForm::on_editHost_editingFinished()
{
    _Host = ui->editHost->text();
}


void ConnectionForm::on_editPort_editingFinished()
{
    _Port = ui->editPort->text().toInt();
}


void ConnectionForm::on_editUser_editingFinished()
{
    _User = ui->editUser->text();
}


void ConnectionForm::on_editPass_editingFinished()
{
    _Password = ui->editPass->text();
}

