#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class Client
{
public:
    Client(int CIN,int nb_pointsfidelites,int num,QDate date,QString prenom,QString mail,QString nom);
    Client();
    int GetCIN()
    { return CIN; }
    void SetCIN(int val)
    { CIN = val; }
    int getnb_pointsfidelites()
    {return nb_pointsfidelites;}
    void setnb_pointsfidelites(int val)
    {nb_pointsfidelites=val;}
     int Getnum()
     { return num; }
      void Setnum(int val)
      { num = val; }
            QString Getnom()
            { return nom; }
            void Setnom(QString val)
            { nom = val; }
            QString Getprenom()
            { return prenom; }
            void Setprenom(QString val)
            { prenom = val; }
            QString Getmail()
            { return mail; }
            void Setmail(QString val)
            { mail = val; }
            QDate Getdate_naissance()
            { return date_naissance; }
            void Setdate_naissance(QDate val)
            { date_naissance = val; }

            bool ajouter();
            bool chercher(int cin);
            QSqlQueryModel* afficher();
            bool supprimer(int CIN);
            bool modifierNum(int CIN,int num);
            bool modifierPoints(int CIN,int nb_pointsfidelites);
            bool modifierMail(int CIN,QString mail);
            //bool modifierClient(int CIN,int nb_pointsfidelites,int num,QString mail);
            QSqlQueryModel * trinom();
            QSqlQueryModel * triprenom();
            QSqlQueryModel * triDate();
            QSqlQueryModel * triPoints();
            QSqlQueryModel* recherchernomc(QString recherche);
            QSqlQueryModel* rechercher(const QString &recherche);
            QSqlQuery Edit(QString val);
            bool rfidExists(QString uid);
            QString rfidName(QString uid);









private:

    int CIN,nb_pointsfidelites,num;
    QDate date_naissance;
    QString prenom, mail,nom;

};

#endif // CLIENT_H
