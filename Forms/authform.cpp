#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthForm)
{
    ui->setupUi(this);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_butOk_clicked()
{
    emit signalOkBtnClicked();
}


void AuthForm::on_butReg_clicked()
{
    emit signalRegBtnClicked();
}


void AuthForm::on_butCancel_clicked()
{
    emit signalCancelBtnClicked();
}


void AuthForm::on_editUser_editingFinished()
{
    this->_user = ui->editUser->text();
}


void AuthForm::on_editPass_editingFinished()
{
    this->_pass = ui->editPass->text();
}

