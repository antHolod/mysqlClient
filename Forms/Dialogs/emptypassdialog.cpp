#include "emptypassdialog.h"
#include "ui_emptypassdialog.h"

EmptyPassDialog::EmptyPassDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmptyPassDialog)
{
    ui->setupUi(this);
    ui->labelInfo->setText(connectInfoNoDb);
}

EmptyPassDialog::~EmptyPassDialog()
{
    delete ui;
}

void EmptyPassDialog::on_btnCancel_clicked()
{
    emit signalGoBack();
}


void EmptyPassDialog::on_btnOk_clicked()
{
    emit signalContinue();
}

