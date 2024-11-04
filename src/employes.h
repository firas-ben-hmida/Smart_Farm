#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class Employes
{

public:
   Employes();
   Employes(int,int,int,QString,QString,QString,QString,QString,QString,QString);
   int getidentifiant();
   QString getnom();
   QString getprenom();
   int getage();
   QString getposte();
   int getnumero_telephone();
   QString getmail();
   QString getpass();
   QString getstatut();
   QString getchoix(){return choix;}
   QString getrfid();
   void setidentifiant (int);
   void setnom (QString);
   void setprenom (QString);
   void setage (int );
   void setposte (QString );
   void setnumero_telephone (int );
   void setmail (QString );
   void setpass (QString );
   void setstatut (QString );
   void setchoix(QString choix) { this->choix = choix; }
   void setrfid(QString rfid);




   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer (int );
   bool modifier();
   QSqlQueryModel *afficher_id();
   bool rech(int);
   QSqlQueryModel* rechercher( int );
   QSqlQueryModel *trier_IDENTIFIANT();
   QSqlQueryModel *trier_POSTE();
   QSqlQueryModel *trier_AGE();
   bool rfidExists(QString uid);
   QString rfidName(QString uid);




private:
   int identifiant;
   int age;
   int numero_telephone;
   QString nom;
   QString prenom;
   QString poste;
   QString mail;
   QString pass;
   QString statut;
   QString choix;
   QString rfid;


};


#endif // EMPLOYES_H
