#include "employes.h"
#include <QSqlQuery>
#include <QSqlError>
#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QValidator>

Employes::Employes()
{
    identifiant =0; nom="";prenom="";age=0; numero_telephone =0;mail="";pass="";statut="";rfid="";poste="";
}

Employes::Employes(int identifiant,int age,int numero_telephone,QString nom,QString prenom ,QString mail,QString pass,QString statut,QString rfid,QString poste)
{
    this->identifiant=identifiant;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->numero_telephone=numero_telephone;
    this->mail=mail;
    this->pass=pass;
    this->statut=statut;
    this->rfid=rfid;
    this->poste=poste;


}
int Employes::getidentifiant(){return identifiant;}
QString Employes::getnom(){return nom;}
QString Employes::getprenom(){return prenom;}
int Employes::getage(){return age;}
int Employes::getnumero_telephone(){return numero_telephone;}
QString Employes::getmail(){return mail;}
QString Employes::getpass(){return pass;}
QString Employes::getstatut(){return statut;}
QString Employes::getrfid(){return rfid;}
QString Employes::getposte(){return poste;}
void Employes::setidentifiant(int identifiant) { this->identifiant = identifiant;}
void Employes::setnom (QString nom){this->nom=nom;}
void Employes::setprenom (QString prenom){this->prenom=prenom;}
void Employes::setage (int age){this->age=age;}
void Employes::setnumero_telephone (int numero_telephone ){this->numero_telephone=numero_telephone;}
void Employes::setmail (QString mail){this->mail=mail;}
void Employes::setpass (QString pass){this->pass=pass;}
void Employes::setstatut(QString statut) { this->statut = statut; }
void Employes::setrfid(QString rfid){this->rfid=rfid;}
void Employes::setposte (QString poste){this->poste=poste;}


bool Employes::ajouter()
{

    QSqlQuery query;
    QString identifiant_string=QString::number(identifiant);
     QString age_string=QString::number(age);
      QString numero_telephone_string=QString::number(numero_telephone);

      query.prepare("INSERT INTO EMPLOYES(IDENTIFIANT, NUMERO_TELEPHONE, NOM, PRENOM, AGE, MAIL, PASS, STATUT,RFID, POSTE) "
                    "VALUES (:IDENTIFIANT, :NUMERO_TELEPHONE, :NOM, :PRENOM, :AGE, :MAIL, :PASS, :STATUT, :RFID, :POSTE)");

    query.bindValue(":IDENTIFIANT", identifiant_string);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":AGE",age_string);
    query.bindValue(":NUMERO_TELEPHONE", numero_telephone_string);
    query.bindValue(":MAIL", mail);
    query.bindValue(":PASS", pass);
    query.bindValue(":STATUT", statut);
    query.bindValue(":RFID", rfid);
    query.bindValue(":POSTE", poste);


    query.bindValue(":RFID", rfid);

    return query.exec();

}



QSqlQueryModel* Employes:: afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();
       model->setQuery("SELECT* FROM  EMPLOYES");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASS"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("STATUT"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("RFID"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("POSTE"));


    return model;
}


bool Employes::supprimer(int identifiant)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYES WHERE IDENTIFIANT=:IDENTIFIANT");
    query.bindValue(":IDENTIFIANT", identifiant);

    return query.exec();

}



bool Employes::modifier()
{
    QSqlQuery query;
    QString identifiant_string=QString::number(identifiant);
     QString age_string=QString::number(age);
      QString numero_telephone_string=QString::number(numero_telephone);

         qDebug() << "IDENTIFIANT: " << identifiant;
         qDebug() << "NOM: " << nom;
         qDebug() << "PRENOM: " << prenom;
         qDebug() << "AGE: " << age;
         qDebug() << "NUMERO_TELEPHONE: " << numero_telephone;
         qDebug() << "MAIL: " << mail;
         qDebug() << "PASS: " << pass;
         qDebug() << "STATUT: " << statut;
         qDebug() << "RFID: " << rfid;
         qDebug() << "POSTE: " << poste;



    query.prepare("UPDATE EMPLOYES SET NUMERO_TELEPHONE = :NUMERO_TELEPHONE,NOM= :NOM , PRENOM = :PRENOM, AGE = :AGE, MAIL = :MAIL, PASS = :PASS, STATUT = :STATUT,RFID = :RFID, POSTE= :POSTE  WHERE IDENTIFIANT = :IDENTIFIANT");

    query.bindValue(":IDENTIFIANT", identifiant_string);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":AGE", age_string);
    query.bindValue(":NUMERO_TELEPHONE", numero_telephone_string);
    query.bindValue(":MAIL", mail);
    query.bindValue(":PASS", pass);
    query.bindValue(":STATUT", statut);
    query.bindValue(":RFID", rfid);
    query.bindValue(":POSTE", poste);


    if (query.exec()) {
            qDebug() << "La requête SQL a été exécutée avec succès.";
        } else {
            qDebug() << "Erreur de requête SQL : " << query.lastError().text();
        }
    return query.exec();
}

QSqlQueryModel *Employes::afficher_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM EMPLOYES ORDER BY IDENTIFIANT ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASS"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("STATUT"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("RFID"));
          model->setHeaderData(9, Qt::Horizontal, QObject::tr("POSTE"));


          return model;
}

bool Employes::rech(int identifiant)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE IDENTIFIANT = :IDENTIFIANT");
    query.bindValue(":IDENTIFIANT", identifiant);
    return query.exec(); // Ceci vérifie si la requête a été exécutée avec succès, mais pas si des résultats ont été trouvés
}

QSqlQueryModel* Employes::rechercher( int identifiant)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE IDENTIFIANT = :IDENTIFIANT");
    query.bindValue(":IDENTIFIANT", identifiant);

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASS"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("STATUT"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("RFID"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("POSTE"));


    } else {
      // qDebug() << "Erreur de requête :" << query.lastError().text();
        delete model;
        model = nullptr;
    }

    return model;
}


QSqlQueryModel *Employes::trier_IDENTIFIANT()
{
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * from EMPLOYES order by IDENTIFIANT ASC");
    model->setQuery("select * from EMPLOYES ORDER BY IDENTIFIANT ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));//narjaa mbaad lli aamltou fl DB
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("RFID"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("POSTE"));

    qry->exec();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel *Employes::trier_POSTE()
{
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * from EMPLOYES order by POSTE ASC");
    model->setQuery("select * from EMPLOYES ORDER BY POSTE ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));//narjaa mbaad lli aamltou fl DB
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("RFID"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("POSTE"));

    qry->exec();
    model->setQuery(*qry);
    return model;
}

QSqlQueryModel *Employes::trier_AGE()
{
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * from EMPLOYES order by AGE ASC");
    model->setQuery("select * from EMPLOYES ORDER BY AGE ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));//narjaa mbaad lli aamltou fl DB
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("RFID"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("POSTE"));

    qry->exec();
    model->setQuery(*qry);
    return model;
}


bool Employes::rfidExists(QString uid)
{
    QSqlQuery query;
    //changer NOM par rfid
        query.prepare("SELECT * FROM EMPLOYES WHERE RFID = :uid");
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

QString Employes::rfidName(QString uid)
{
    QSqlQuery query;
    //changer NOM par rfid (khater ane hne 7atet fl base de donnee NOM nafs l identifiant mt3 l carte)
        query.prepare("SELECT PRENOM FROM EMPLOYES WHERE RFID = :uid");
        query.bindValue(":uid", uid);
        if (query.exec() && query.next())
        {
            // If a row is returned, extract the value of the NOM attribute
            return query.value(0).toString();
        }
        // If no row is returned, return an empty string to indicate failure
        return "";
}
