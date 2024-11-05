#ifndef ANIMAUX_H
#define ANIMAUX_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class animaux

{ int identifiant,masse,taille;
   QString  categorie, etat,ida;
   bool vaccination;
   QDate date;

public:
   animaux() {}
   animaux(int, QString, float, float,QString,QString,bool,QDate);
   int get_identifiant() { return identifiant; }
   QString get_categorie() { return categorie; }
   float get_masse() { return masse; }
   float get_taille() { return taille; }
   QString get_etat() { return etat; }
   QString get_ida() { return ida; }
   bool get_vaccination() { return vaccination; }
   QDate get_date_vaccination() { return date; }
   void setidentifiant(int n) { identifiant = n; }
   void setcategorie(QString n) { categorie= n; }
   void setmasse(float n) { masse = n; }
   void settaille(float n) { taille = n; }
   void setetat(QString n) { etat = n; }
   void setida(QString n) { ida = n; }
   void set_vaccination(bool vacc) { vaccination=vacc; }
   void set_date_vaccination(QDate d) { date=d; }
   bool ajouter();
   QSqlQueryModel *afficher();
   bool supprimer(int identifiant);
   bool Modifier(int  identifiant,QString categorie, float masse, float taille,QString etat,QString ida,bool vaccination,QDate d);
   QSqlQueryModel* affichernom();
   QSqlQueryModel* chercher(QString critere, QString rech);
   QSqlQueryModel* tri();
   QSqlQueryModel* trinom();
   QSqlQueryModel* tricapacite();
};




#endif // ANIMAUX_H
