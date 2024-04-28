#ifndef CONNECTIONFORM_H
#define CONNECTIONFORM_H

#include <QWidget>
#include <QString>
#include "defines.h"

namespace Ui {
class ConnectionForm;
}

class ConnectionForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionForm(QWidget *parent = nullptr);
    ~ConnectionForm();

    void setLabelInfo();

private slots:
    void on_checkSaveConn_stateChanged(int arg1);
    void on_butCancel_clicked();
    void on_butOk_clicked();
    void on_editHost_editingFinished();
    void on_editPort_editingFinished();
    void on_editUser_editingFinished();
    void on_editPass_editingFinished();

private:
    Ui::ConnectionForm *ui;
    bool _saveConnection;
    QString _Host;
    QString _Password;
    QString _User;
    int _Port;
    QString _Name;

signals:
    void btnOkClicked(QString,int,QString,QString,QString);
    void btnCancelClicked();
};

#endif // CONNECTIONFORM_H
