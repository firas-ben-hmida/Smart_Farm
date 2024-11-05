#include "oublie_pwd.h"
#include "ui_oublie_pwd.h"
#include"employes.h"
#include <QMessageBox>
#include <QApplication>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
//#include"login.h"
#include <QVBoxLayout>
#include<QCompleter>
#include"mainwindow.h"

oublie_pwd::oublie_pwd(QString identifiant, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::oublie_pwd)


{
    ui->setupUi(this);
    ui->le_passs->setEchoMode(QLineEdit::Password);
    m_identifiant = identifiant; // Assign the value here


}

oublie_pwd::~oublie_pwd()
{
    delete ui;
}

/*void oublie_pwd::on_oubliepwd_clicked()
{
    QString pass = ui->le_passs->text();

        QSqlQuery query;
        query.prepare("UPDATE EMPLOYEE SET PASS = :PASS WHERE IDENTIFIANT = :IDENTIFIANT");
        query.bindValue(":PASS", pass);
        query.bindValue(":IDENTIFIANT", m_identifiant);

        if (query.exec()) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("MOT DE PASSE MODIFIÉ.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                QObject::tr("Failed to update password."),
                QMessageBox::Cancel);
        }
}*/

void oublie_pwd::on_oubliepwd_clicked()
{
    QString pass = ui->le_passs->text();

    qDebug() << "Updating password for IDENTIFIANT:" << m_identifiant << "with new PASS:" << pass;

    QSqlQuery query;
    query.prepare("UPDATE EMPLOYES SET PASS = :PASS WHERE IDENTIFIANT = :IDENTIFIANT");
    query.bindValue(":PASS", pass);
    query.bindValue(":IDENTIFIANT", m_identifiant);


    if (query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("MOT DE PASSE MODIFIÉ.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        qDebug() << "Failed to update password. Error:" << query.lastError().text();
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Failed to update password. Error: %1").arg(query.lastError().text()),
            QMessageBox::Cancel);
    }
}
