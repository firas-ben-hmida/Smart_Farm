#include "client.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
Client::Client()
{
    CIN=0;
    nb_pointsfidelites=0;
    num=0;
    prenom="";
    nom="";
    mail="";
}
Client::Client(int CIN,int nb_pointsfidelites,int num,QDate date,QString prenom,QString mail,QString nom)
{
    this->CIN=CIN;
    this->nb_pointsfidelites= nb_pointsfidelites;
    this->num=num;
    this->date_naissance=date;
    this->prenom=prenom;
    this->nom=nom;
    this->mail=mail;

}
bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTS (CIN,NB_POINTSFIDELITES,PRENOM,MAIL,NOM,NUM,DATE_NAISSANCE) "
                        "VALUES (:CIN, :NB_POINTSFIDELITES, :PRENOM, :MAIL, :NOM, :NUM, :DATE_NAISSANCE)");
    query.bindValue(":CIN", CIN);
    query.bindValue(":NB_POINTSFIDELITES", nb_pointsfidelites);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":MAIL", mail);
    query.bindValue(":NOM", nom);
    query.bindValue(":NUM", num);
    query.bindValue(":DATE_NAISSANCE", date_naissance);
    return query.exec();
}


bool Client::chercher(int CIN)
{
    QSqlQuery query;
    //QString CIN_string = QString::number(cin);
    query.prepare("SELECT CIN FROM CLIENTS WHERE CIN = :CIN");
    query.bindValue(":CIN", CIN);

    if (query.exec() && query.next()) {
        return true;
    } else {
        return false;
    }
}

QSqlQueryModel* Client::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT* FROM CLIENTS");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date De Naissance"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de points de fidelites"));


  return model;
}

bool Client::supprimer(int CIN)
{
    QSqlQuery query;
    query.prepare("Delete from CLIENTS where CIN=:CIN");
    query.bindValue(":CIN", CIN);

    return query.exec();
}

bool Client::modifierMail(int CIN,QString mail)
{
    QSqlQuery query;
    if (!mail.isEmpty()) {
        query.prepare("UPDATE CLIENTS SET  MAIL = :MAIL WHERE CIN = :CIN");
        query.bindValue(":MAIL", mail);
    }

    query.bindValue(":CIN", CIN);
    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Client::modifierPoints(int CIN,int nb_pointsfidelites)
{
    QSqlQuery query;
    if (nb_pointsfidelites!=-1) {
        query.prepare("UPDATE CLIENTS SET NB_POINTSFIDELITES = :NB_POINTSFIDELITES WHERE CIN = :CIN");
        query.bindValue(":NB_POINTSFIDELITES", nb_pointsfidelites);
    }
    query.bindValue(":CIN", CIN);
    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Client::modifierNum(int CIN,int num)
{
    QSqlQuery query;
    if (num!=-1) {
        query.prepare("UPDATE CLIENTS SET  NUM = :NUM WHERE CIN = :CIN");
        query.bindValue(":NUM", num);
    }
    query.bindValue(":CIN", CIN);
    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}
QSqlQuery Client::Edit(QString val)
{
    QSqlQuery qry;
    bool test = true;

    for (const QChar &c : val)
    {
        if (!c.isDigit())
        {
            test = false;
            break;  // Pas besoin de continuer la boucle si un caractère non numérique est trouvé.
        }
    }

    if (test)
    {
        qry.prepare("SELECT * FROM CLIENTS WHERE CIN = :val");
        qry.bindValue(":val", val);
    }
    else
    {
        qry.prepare("SELECT * FROM CLIENTS WHERE NB_POINTSFIDELITES = :val OR PRENOM = :val OR MAIL = :val OR NOM = :val OR NUM = :val OR DATE_NAISSANCE = :val");
        qry.bindValue(":val", val);
    }

    return qry;
}
QSqlQueryModel * Client::trinom()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS order by NOM");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date De Naissance"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de points de fidelites"));
     return model;
}
QSqlQueryModel * Client::triprenom()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS order by PRENOM");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date De Naissance"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de points de fidelites"));
     return model;
}
QSqlQueryModel * Client::triDate()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS order by DATE_NAISSANCE");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date De Naissance"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de points de fidelites"));
     return model;
}
QSqlQueryModel * Client::triPoints()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS order by NB_POINTSFIDELITES DESC");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date De Naissance"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de points de fidelites"));
     return model;
}

QSqlQueryModel* Client::recherchernomc(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTS where NOM LIKE '"+recherche+"%'  OR LOWER(NOM) LIKE '"+recherche+"%' OR UPPER(NOM) LIKE '"+recherche+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date De Naissance"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de points de fidelites"));
    return model;
}
QSqlQueryModel* Client::rechercher(const QString &recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM CLIENTS WHERE ";

    // Ajoutez des conditions pour chaque colonne que vous voulez rechercher
    queryStr += "NOM LIKE :recherche OR ";
    queryStr += "PRENOM LIKE :recherche OR ";
    queryStr += "MAIL LIKE :recherche OR ";
    queryStr += "CIN LIKE :recherche OR ";
    queryStr += "NUM LIKE :recherche OR ";
    queryStr += "DATE_NAISSANCE LIKE :recherche";

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":recherche", "%" + recherche + "%");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else {
        qDebug() << "Erreur de recherche : " ;
    }

    return model;
}
bool Client::rfidExists(QString uid)
{
    QSqlQuery query;
    //changer NOM par rfid
        query.prepare("SELECT * FROM CLIENTS WHERE NOM = :uid");
        query.bindValue(":uid", uid);
        if (query.exec() && query.next())
        {
            qDebug()<<"trouve";
            // If a row is returned, the uid exists in the database
            return true;
        }
    // If no row is returned, the uid does not exist in the database
        else
        {
            qDebug()<<"non trouve";
            return false;
        }


}

QString Client::rfidName(QString uid)
{
    QSqlQuery query;
    //changer NOM par rfid (khater ane hne 7atet fl base de donnee NOM nafs l identifiant mt3 l carte)
        query.prepare("SELECT PRENOM FROM CLIENTS WHERE NOM = :uid");
        query.bindValue(":uid", uid);
        if (query.exec() && query.next())
        {
            // If a row is returned, extract the value of the NOM attribute
            return query.value(0).toString();
        }
        // If no row is returned, return an empty string to indicate failure
        return "";
}

