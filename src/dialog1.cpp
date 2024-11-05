#include "dialog1.h"
#include "ui_dialog1.h"
#include<QSqlQuery>
#include "animaux.h"
#include <QMessageBox>
#include <QApplication>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include"mainwindow.h"
#include <QVBoxLayout>
#include<QCompleter>
#include<QPushButton>
#include<QTableWidget>
#include<QSqlQuery>
#include<QTableView>
#include <QStandardItemModel>
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}



void Dialog1::on_pushButton_valider_clicked()
{
    int identifiant = ui->lineEdit_id->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM ANNIMAUX WHERE IDENTIFIANT = :identifiant");
    query.bindValue(":identifiant", identifiant);

    if (query.exec() && query.next()) {
        // Affichage du tableau
        QTableWidget *tableWidget = new QTableWidget(1, 6, this);
        tableWidget->resize(800, 600);
        tableWidget->setHorizontalHeaderLabels(QStringList() << "Identifiant" << "Categorie" << "Masse" << "Taille" << "État" << "IDA");

        tableWidget->setItem(0, 0, new QTableWidgetItem(query.value("IDENTIFIANT").toString()));
        tableWidget->setItem(0, 1, new QTableWidgetItem(query.value("CATEGORIE").toString()));
        tableWidget->setItem(0, 2, new QTableWidgetItem(query.value("MASSE").toString()));
        tableWidget->setItem(0, 3, new QTableWidgetItem(query.value("TAILLE").toString()));
        tableWidget->setItem(0, 4, new QTableWidgetItem(query.value("ETAT").toString()));
        tableWidget->setItem(0, 5, new QTableWidgetItem(query.value("IDA").toString()));

        tableWidget->show();
    }
}
