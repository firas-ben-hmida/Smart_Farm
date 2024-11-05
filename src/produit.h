#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QDate>
#include <QDateEdit>
#include <QSqlQueryModel>
#include <QComboBox>


class Produit
{
public:
    Produit();
    Produit(int,QString,QString,QString,QDate,QDate,float,QString);
    int getNumero();
    QString getNom();
    QString getType();
    QString getEmplacement();
    QDate getDate_Prod();
    QDate getDate_F_C();
    float getPrix();
    QString getqr_code();
    void setNumero(int);
    void setNom(QString);
    void setType(QString);
    void setEmplacement(QString);
    void setDate_Prod(QDate);
    void setDate_F_C(QDate);
    void setPrix(float);
    void setqr_code(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher_1(QString);
    QSqlQueryModel* rechercher_2(QString);
    QSqlQueryModel* rechercher_3(QString);
     QSqlQueryModel* rechercher_4(QString);
    QSqlQueryModel *trier(QString);

    bool Supprimer(int);
     bool Modifier(int);
     bool UpdateQrcodeLink(QString,int);

private:
   int Numero;
    QString Nom,Type,Emplacement;
    QDate Date_Prod,Date_F_C;
    float Prix;
    QString qr_code;

};

#endif // PRODUIT_H
