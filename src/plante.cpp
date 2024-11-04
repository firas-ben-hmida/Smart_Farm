#include "plante.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Plante::Plante()
{
   Numero=0;Type=" ";Emplacement="";

}
Plante::Plante(int Numero,QString Type,QString Emplacement,QDate Date_Plantation)
{this->Numero=Numero;this->Type=Type;this->Emplacement=Emplacement;this->Date_Plantation=Date_Plantation;}
int Plante::getNumero(){return Numero ;}
QString Plante::getType(){return Type;}
QString Plante::getEmplacement(){return Emplacement ;}
QDate Plante::getDate_Plantation(){return Date_Plantation;}
void Plante::setNumero(int Numero){this->Numero=Numero;}
void Plante::setType(QString Type){this->Type=Type;}
void Plante::setEmplacement(QString Emplacement){this->Emplacement=Emplacement;}
void Plante::setDate_Plantation(QDate Date_Plantation){this->Date_Plantation=Date_Plantation;}

bool Plante::ajouter()
{
  QSqlQuery query;

        query.prepare("INSERT INTO PLANTES (Numero, Type,Emplacement,Date_Plantation) "
                      "VALUES (:Numero,:Type , :Emplacement , :Date_Plantation)");
        QString Numero_string= QString::number(Numero);
        query.bindValue(":Numero",Numero_string);
        query.bindValue(":Type", Type);
        query.bindValue(":Emplacement", Emplacement);
        query.bindValue(":Date_Plantation", Date_Plantation);
        return query.exec();
}
QSqlQueryModel* Plante::afficher()
{

  QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT * FROM PLANTES");
       model->setHeaderData(0, Qt::Horizontal,QObject::tr("Numero"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("Type"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("Emplacement"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Date_Plantation"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date_Irrigation"));
       model->setHeaderData(5, Qt::Horizontal,QObject::tr("Nbr_Fs_Irriguee"));
       model->setHeaderData(6, Qt::Horizontal,QObject::tr("Humidite"));



  return model;

}
bool Plante::Supprimer(int Numero)
{

  QSqlQuery query;
        query.prepare("Delete from PLANTES where Numero=:Numero");
        query.bindValue(0,Numero);

        return query.exec();
}
bool Plante::Modifier( int Numero)
{
  QSqlQuery query;

        query.prepare("update PLANTES set Type= :Type,Emplacement= :Emplacement where Numero= :Numero");
        query.bindValue(":Numero", Numero);
        query.bindValue(":Type", Type);
        query.bindValue(":Emplacement", Emplacement);
        return query.exec();
}
