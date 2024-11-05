#ifndef OUBLIE_PWD_H
#define OUBLIE_PWD_H

#include <QDialog>
#include"employes.h"
#include <QMainWindow>
#include <QtSql>
#include"mainwindow.h"

namespace Ui {
class oublie_pwd;
}

class oublie_pwd : public QDialog
{
    Q_OBJECT

public:
    explicit oublie_pwd(QString identifiant ,QWidget *parent = nullptr);
    ~oublie_pwd();

private slots:
    void on_oubliepwd_clicked();

private:
    Ui::oublie_pwd *ui;
   QString m_identifiant;

    Employes E;
};

#endif // OUBLIE_PWD_H










