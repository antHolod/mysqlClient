#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

    QString getUser() const           {return this->_user;}
    QString getPass() const           {return this->_pass;}

private slots:
    void on_butOk_clicked();
    void on_butReg_clicked();
    void on_butCancel_clicked();
    void on_editUser_editingFinished();
    void on_editPass_editingFinished();

private:
    Ui::AuthForm *ui;

    QString _user;
    QString _pass;

signals:
    void signalOkBtnClicked();
    void signalCancelBtnClicked();
    void signalRegBtnClicked();
};

#endif // AUTHFORM_H
