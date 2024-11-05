#ifndef PLANTE_H
#define PLANTE_H

#include <QString>
#include <QDate>
#include <QDateEdit>
#include <QSqlQueryModel>
#include <QComboBox>


class Plante
{
public:
   Plante();
   Plante(int,QString,QString,QDate);
   int getNumero();
   QString getType();
   QString getEmplacement();
   QDate getDate_Plantation();
   void setNumero(int);
   void setType(QString);
   void setEmplacement(QString);
   void setDate_Plantation(QDate);
   bool ajouter();
   QSqlQueryModel* afficher();
   bool Supprimer(int);
    bool Modifier(int);

private:
  int Numero;
   QString Type,Emplacement;
   QDate Date_Plantation;


};

#endif // PLANTE_H
