#ifndef CONNECTIONFORM_H
#define CONNECTIONFORM_H

#include <QWidget>
#include <QString>
#include <QSettings>

#include "defines.h"
#include "Dialogs/emptypassdialog.h"

namespace Ui {
class ConnectionForm;
}

class ConnectionForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionForm(QWidget *parent = nullptr);
    ~ConnectionForm();

    QString settingsFilePath;
    void setLabelInfo();
    void setLabelInfo(const QString&);

private slots:
    void on_checkSaveConn_stateChanged(int arg1);
    void on_butCancel_clicked();
    void on_butOk_clicked();
    void on_editHost_editingFinished();
    void on_editPort_editingFinished();
    void on_editUser_editingFinished();
    void on_editPass_editingFinished();
    void on_editDbName_editingFinished();
    void onEmptyPassOkClicked();
    void onEmptyPassCancelClicked();

private:
    Ui::ConnectionForm *ui;
    EmptyPassDialog *emptyPass;
    bool _saveConnection = false;
    QString _Host;
    QString _Password;
    QString _User;
    int _Port;
    QString _Name;

    void closeEmptyPassDialog();
    void focusOnField();

signals:
    void btnOkClicked(QString,int,QString,QString,QString,bool);
    void btnCancelClicked();
};

#endif // CONNECTIONFORM_H
