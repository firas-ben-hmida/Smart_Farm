#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"employes.h"
#include<QWidget>
#include <QMainWindow>
#include<QObject>
#include <QDialog>
#include"arduino.h"
#include "produit.h"
#include "image.h"
#include "qrcode.h"
#include <QTcpSocket>
#include"arduino.h"
#include"arduino1.h"
#include "plante.h"

#include "client.h"
#include "smtpclient.h"
#include"dialog.h"
#include "animaux.h"
#include "chatbot.h"
QT_BEGIN_NAMESPACE
using namespace qrcodegen;
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString identifiant = "", QWidget *parent = nullptr);

    //explicit MainWindow(QString identifiant, QWidget *parent = nullptr);
    ~MainWindow();
    QString hostname() const;
       quint16 port() const ;
       QString findconnect(const QString& identifiant);

       void on_login_clicked();

signals:
    void statusSelected(const QString &status);

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_ajouter_clicked();
    void on_pb_chercher_clicked();
    void on_pb_trier_clicked();
    void on_pdf_9_clicked();
    void on_le_statut_activated(const QString &arg1);
  //  void on_le_sta_activated(const QString &arg1);


   void on_gestionemployes_quitter_clicked();


   void on_pb_ajouter_produit_clicked();

      void on_pb_Supprimer_produit_clicked();

      void on_pb_modifier_produit_clicked();

      //void on_pb_ok_clicke

      void on_tab_Produit_clicked(const QModelIndex &index);

      //void on_pb_ok_2_clicked();

      void on_le_Nom_cursorPositionChanged(int arg1, int arg2);

      void on_exportPDF_clicked();

      //void on_search_clicked();
      void onRechercheTextChanged(const QString &text);

      //void on_recherche_view_clicked(const QModelIndex &index);

      void on_trier_clicked();

      void on_le_Numero_supp_currentIndexChanged(const QString &arg1);

          void on_le_Numero_modif_2_currentIndexChanged(const QString &arg1);
          void on_qr_code_clicked();

             void on_supprimer_produit_clicked();

             void on_ajouter_produit_clicked();


             void on_statistics_produit_clicked();

             void on_modifier_produit_clicked();

             void on_image_produit_clicked();



             void on_retour_ajout_produit_clicked();

             void on_retour_supp_produit_clicked();

             void on_retour_modif_produit_clicked();

             void on_retour_statistic_produit_clicked();

             void on_retour_image_produit_clicked();

             void on_afficher_produit_clicked();


             void on_gestion_E_clicked();

             void on_gestion_C_clicked();

             void on_gestion_P_clicked();

             void on_bind_clicked();

             void on_ok_clicked();

             void on_cancel_clicked();

             void on_send_clicked();


         //    void on_comboBox_activated(const QString &arg1);
             void connect_RFID();


             void on_login_oublie_clicked();



             void on_gestion_quitter_clicked();




             // salmaa
             void on_pb_ajouterClient_clicked();

               void on_pb_supprimerClient_clicked();

               void on_pb_EditClient_clicked();

               void on_pb_search_clicked();

               void on_le_chercherclient_textChanged(const QString &arg1);

               void on_tab_clients_activated(const QModelIndex &index);

               void on_pb_PDFClient_clicked();

               void on_pb_valider_clicked();

               void on_pb_StatClient_clicked();

               void on_pb_send_clicked();

               //void mailSent(const QString &status);

               void on_pb_gererpoints_clicked();
               void Read();
               //void connect_RFID();

               void on_pb_mailing_clicked();


               void on_pb_chatbox_clicked();

               void on_gestionemployes_quitter_1_clicked();



               void on_login_1_clicked();

               void on_pb_quitterClient_clicked();

               void on_pb_retourclient_clicked();




               //arduino firas

               void information_capteur();

                   void on_ajouter_plante_clicked();

                   void on_afficher_plante_clicked();

                   void on_supprimer_plante_clicked();

                   void on_modifier_plante_clicked();

                   void on_pb_retour_plante_clicked();

                   void on_pushButton_2_clicked();

                   void on_retour1_plante_clicked();

                   void on_pb_ajouter_plante_clicked();

                   void on_pb_supprimer_plante_clicked();

                   void on_pb_modifier_plante_clicked();

                   void on_le_Numero_supp_plante_currentIndexChanged(const QString &arg1);

                   void on_le_Numero_modif_plante_currentIndexChanged(const QString &arg1);

                   void on_retour_modifier_plante_clicked();



                   void on_plante_clicked();

                   void on_retour_modfier_plante_clicked();





                   void on_retour_image_produit_2_clicked();

                   void on_retour_image_produit_3_clicked();

                   void on_retour_image_produit_4_clicked();

                   /////////////////////////////////animaux////////////////////////////
                   void on_pushButton_valider_clicked();



                       void on_pushButton_modifier_clicked();

                       void on_pushButton_supprimer_clicked();

                       void on_pushButton_refresh_clicked();
                       void on_pb_recherche_ich_clicked();

                       void on_pushButton_stat_ich_clicked();


                       void on_pushButton_trierid_ich_clicked();

                       void on_pushButton_triernom_ich_clicked();

                       void on_pushButton_triernom_ich_2_clicked();




                       void on_pb_valider_pdf_clicked();

                       void on_pushButton_annuler_ich_clicked();


                       void on_pushButton_modifier_2_clicked();

                       void on_pushButton_modifier_3_clicked();

                       void on_pushButton_stat_ich_2_clicked();

                       void on_critere_rech_acc_2_textChanged(const QString &arg1);

                       void on_pushButton_annuler_ich_2_clicked();


                       void on_chatbot_clicked();




                       void on_gestion_A_clicked();

private:
    Ui::MainWindow *ui;

    QByteArray data;
    Arduino1 A;
    Produit P;
    Plante Pl;
    Employes E;
    arduino rfidInstance;
    QTcpSocket *mSocket;
    QString mHostname;
    quint16 mPort;
    // objet temporaire
    QString ref;
    QString m_identifiant;  // Add this line to declare m_identifiant
    SMTPClient *smtpClient;
    Client C;
    Dialog d;
    animaux An;
};
inline QString MainWindow::hostname() const
{
    return mHostname;
}
inline quint16 MainWindow::port() const
{
    return  mPort;
}


#endif // MAINWINDOW_H
