#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Produit::Produit()
{
     Numero=0;Nom=" ";Type=" ";Emplacement="";Prix=0;qr_code="";

}
Produit::Produit(int Numero,QString Nom,QString Type,QString Emplacement,QDate Date_Prod,QDate Date_F_C,float Prix,QString qr_code)
{this->Numero=Numero;this->Nom=Nom;this->Type=Type;this->Emplacement=Emplacement;this->Date_Prod=Date_Prod;this->Date_F_C=Date_F_C;this->Prix=Prix;this->qr_code=qr_code;}
int Produit::getNumero(){return Numero ;}
QString Produit::getNom(){return Nom ;}
QString Produit::getType(){return Type;}
QString Produit::getEmplacement(){return Emplacement ;}
QDate Produit::getDate_Prod(){return Date_Prod;}
QDate Produit::getDate_F_C(){return Date_F_C;}
float Produit::getPrix(){return Prix;}
QString Produit::getqr_code(){return qr_code;}
void Produit::setNumero(int Numero){this->Numero=Numero;}
void Produit::setNom(QString Nom){this->Nom=Nom;}
void Produit::setType(QString Type){this->Type=Type;}
void Produit::setEmplacement(QString Emplacement){this->Emplacement=Emplacement;}
void Produit::setDate_Prod(QDate Date_Prod){this->Date_Prod=Date_Prod;}
void Produit::setDate_F_C(QDate Date_F_C){this->Date_F_C=Date_F_C;}
void Produit::setPrix(float Prix){this->Prix=Prix;}
void Produit::setqr_code(QString qr_code){this->qr_code=qr_code;}

bool Produit::ajouter()
{
    QSqlQuery query;

          query.prepare("INSERT INTO PRODUITS (Numero,Nom, Type,Emplacement,Date_Prod, Date_F_C,Prix,qr_code) "
                        "VALUES (:Numero, :Nom, :Type , :Emplacement , :Date_Prod, :Date_F_C, :Prix, :qr_code)");
          QString Numero_string= QString::number(Numero);
          QString Prix_string= QString::number(Prix);
          query.bindValue(":Numero",Numero_string);
          query.bindValue(":Nom",Nom);
          query.bindValue(":Type", Type);
          query.bindValue(":Emplacement", Emplacement);
          query.bindValue(":Date_Prod", Date_Prod);
          query.bindValue(":Date_F_C", Date_F_C);
          query.bindValue(":Prix",Prix_string );
          query.bindValue(":qr_code",qr_code );
          return query.exec();
}
QSqlQueryModel* Produit::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM PRODUITS");
         model->setHeaderData(0, Qt::Horizontal,QObject::tr("Numero"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal,QObject::tr("Type"));
         model->setHeaderData(3, Qt::Horizontal,QObject::tr("Emplacement"));
         model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date_Prod"));
         model->setHeaderData(5, Qt::Horizontal,QObject::tr("Date_F_C"));
         model->setHeaderData(6, Qt::Horizontal,QObject::tr("Prix"));
         model->setHeaderData(8, Qt::Horizontal,QObject::tr("qr_code"));



    return model;

}
bool Produit::Supprimer(int Numero)
{

    QSqlQuery query;
          query.prepare("Delete from PRODUITS where Numero=:Numero");
          query.bindValue(0,Numero);

          return query.exec();
}
bool Produit::Modifier( int Numero)
{

    QSqlQuery query;

          query.prepare("UPDATE PRODUITS SET Nom=:Nom,Type=:Type,Emplacement=:Emplacement,Prix=:Prix WHERE Numero=:Numero;");
          QString Numero_string= QString::number(Numero);
          QString Prix_string= QString::number(Prix);

          query.bindValue(":Numero", Numero_string);
          query.bindValue(":Nom", Nom);
          query.bindValue(":Type", Type);
          query.bindValue(":Emplacement", Emplacement);
          query.bindValue(":Prix",Prix_string );
          return query.exec();
}
QSqlQueryModel* Produit::rechercher_1(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<a<<endl;
    model->setQuery("select * from produits where (Nom LIKE lower('%"+a+"%') or Nom LIKE upper('%"+a+"%'))");
    if (model->rowCount() > 0) {
            return model;
        } else {
            delete model;
            return nullptr;
        }
}
QSqlQueryModel* Produit::rechercher_2(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<a<<endl;
    model->setQuery("select * from produits where (Type LIKE lower('%"+a+"%') or Type LIKE upper('%"+a+"%'))");
    if (model->rowCount() > 0) {
            return model;
        } else {
            delete model;
            return nullptr;
        }
}
QSqlQueryModel* Produit::rechercher_3(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<a<<endl;
    model->setQuery("select * from produits where (Emplacement LIKE lower('%"+a+"%') or Emplacement LIKE upper('%"+a+"%'))");
    if (model->rowCount() > 0) {
            return model;
        } else {
            delete model;
            return nullptr;
        }
}
QSqlQueryModel* Produit::rechercher_4(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<a<<endl;
    model->setQuery("select * from produits where (Numero LIKE lower('%"+a+"%') or Numero LIKE upper('%"+a+"%'))");
    if (model->rowCount() > 0) {
            return model;
        } else {
            delete model;
            return nullptr;
        }
}
QSqlQueryModel *Produit::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;
    if(x=="Numero"){
        model->setQuery("select Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix from produits order by Numero");
    }
    else if(x=="Nom"){
        model->setQuery("select Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix from produits order by Nom");
    }
    else if (x=="Type"){
        model->setQuery("select Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix from produits order by Type");
    }
    else if (x=="Emplacement"){
        model->setQuery("select Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix from produits order by Emplacement");
    }
    else if (x=="Date_Prod"){
        model->setQuery("select Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix from produits order by Date_Prod");
    }
    else if (x=="Date_F_C"){
        model->setQuery("select Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix from produits order by Date_F_C");
    }
    else if (x=="Prix"){
        model->setQuery("select Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix from produits order by Prix");
    }
    return model;
}
bool Produit::UpdateQrcodeLink(QString directory, int id) {
    QSqlQuery query;
    query.prepare("UPDATE PRODUITS SET qr_code=:qr_code WHERE Numero=:Numero;");
    query.bindValue(":qr_code", directory);
    query.bindValue(":Numero", id);
    return query.exec();
}
