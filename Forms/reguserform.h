#ifndef REGUSERFORM_H
#define REGUSERFORM_H

#include <QWidget>

namespace Ui {
class reguserform;
}

class reguserform : public QWidget
{
    Q_OBJECT

public:
    explicit reguserform(QWidget *parent = nullptr);
    ~reguserform();

    bool _saveUser;
    bool _savePass;

private:
    QString _newName;
    QString _newPass;
    const QString messagePassConfWrong = "Password and confirmation do not mach. Please, check your entry is correct";
    const QString messPassConfMach = "Password and confirmation mach";

private slots:
    void on_butCancel_clicked();

    void on_butOk_clicked();

    void on_chkSaveUser_stateChanged(int arg1);

    void on_chkSavePass_stateChanged(int arg1);

    void on_editName_editingFinished();

    void on_editPass_editingFinished();

    void on_editConfirmPass_editingFinished();

private:
    Ui::reguserform *ui;

signals:
    void signalRegOkClicked(QString,QString);
    void signalRegCancelClicked();
};

#endif // REGUSERFORM_H
