#include "reguserform.h"
#include "ui_reguserform.h"

reguserform::reguserform(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reguserform)
{
    ui->setupUi(this);

    this->_saveUser = false;
    this->_savePass = false;
}

reguserform::~reguserform()
{
    delete ui;
}

void reguserform::on_butCancel_clicked()
{
    emit signalRegCancelClicked();
}


void reguserform::on_butOk_clicked()
{
    emit signalRegOkClicked(this->_newName,this->_newPass);
}


void reguserform::on_chkSaveUser_stateChanged(int arg1)
{
    if(arg1 == 0) this->_saveUser = false;
    else this->_saveUser = true;
}


void reguserform::on_chkSavePass_stateChanged(int arg1)
{
    if(arg1 == 0) this->_savePass = false;
    else this->_savePass = true;
}


void reguserform::on_editName_editingFinished()
{
    this->_newName= ui->editName->text();
}


void reguserform::on_editPass_editingFinished()
{
    this->_newPass = ui->editPass->text();
}


void reguserform::on_editConfirmPass_editingFinished()
{
    QString confirm = ui->editConfirmPass->text();
    if(confirm != this->_newPass)
        ui->labelInfo->setText(messagePassConfWrong);
    else
        ui->labelInfo->setText(messPassConfMach);
}

