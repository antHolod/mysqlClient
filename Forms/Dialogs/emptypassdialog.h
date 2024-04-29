#ifndef EMPTYPASSDIALOG_H
#define EMPTYPASSDIALOG_H

#include <QDialog>
#include "../../defines.h"

namespace Ui {
class EmptyPassDialog;
}

class EmptyPassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmptyPassDialog(QWidget *parent = nullptr);
    ~EmptyPassDialog();

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();

private:
    Ui::EmptyPassDialog *ui;

signals:
    void signalContinue();
    void signalGoBack();
};

#endif // EMPTYPASSDIALOG_H
