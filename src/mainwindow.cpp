#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QApplication>
#include<QObject>
#include<QValidator>
#include <QMainWindow>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QWidget>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprintdialog.h>
#include <qobject.h>
#include <qmetaobject.h>
#include<QPainter>
#include<QComboBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include<QtDebug>
#include<QDialog>
#include "produit.h"
#include "qrcode.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QSqlQuery>
#include <QRegExpValidator>
#include <QRegExp>
#include <QDateTime>
#include <QDateEdit>
#include <QDate>
#include <QWidget>
#include <QComboBox>
#include "numero.h"
#include <QCoreApplication>
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include "qcustomplot.h"
#include <QImage>
#include <QCoreApplication>
#include <QImage>
#include <QPainter>
#include <QCoreApplication>
#include <QImage>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDate>
#include <QPixmap>
#include<QSqlError>
#include <QTcpSocket>
#include <QTextStream>
#include <QVBoxLayout>
#include<QCompleter>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QApplication>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QWidget>
#include<QMainWindow>
#include "oublie_pwd.h"
#include<client.h>
#include<QMessageBox>
#include<QIntValidator>
#include <QRegularExpression>
#include<QRegularExpressionValidator>
#include "numberformatdelegate.h"
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QStandardItemModel>
#include "dialog.h"
#include <QTextStream>
#include <QTcpSocket>
#include <QtGlobal> // For Qt versions prior to 5.15
#include <QSerialPort>
#include <QTimer>
#include <QTextCodec>
#include<rfid.h>
#include<QPrintDialog>
#include "smtpclient.h"
#include <QSystemTrayIcon>
#include <QFile>
#include <QDateTime>
#include "plante.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QSqlQuery>
#include <QRegExpValidator>
#include <QRegExp>
#include <QDateTime>
#include <QDateEdit>
#include <QDate>
#include <QWidget>
#include <QComboBox>
#include <QCoreApplication>
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QImage>
#include <QCoreApplication>
#include <QImage>
#include <QPainter>
#include <QCoreApplication>
#include <QImage>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDate>
#include <QPixmap>
#include "animaux.h"
#include"dialog3.h"
#include"dialog4.h"
#include"dialog5.h"
#include "STMP/src/SmtpMime"
#include"chatbox.h"
MainWindow::MainWindow(QString identifiant, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),

    m_identifiant(identifiant)


{
    ui->setupUi(this);

    ui->tableauanimaux->setModel(An.afficher());
    ui->tableauanimaux->setModel(An.afficher());
    ui->lineEdit_ma->setValidator(new QRegExpValidator(QRegExp("[0-9.]{0,255}"),this));
    ui->lineEdit_taille->setValidator(new QRegExpValidator(QRegExp("[0-9.]{0,255}"),this));
         ui->tab_plante->setModel(Pl.afficher());// permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
         ui->le_Emplacement_plante->addItem("champ 1");
         ui->le_Emplacement_plante->addItem("champ 2");
         ui->le_Emplacement_plante->addItem("champ 3");
         ui->le_Emplacement_plante->addItem("champ 4");
         ui->le_Emplacement_modif_plante->addItem("champ 1");
         ui->le_Emplacement_modif_plante->addItem("champ 2");
         ui->le_Emplacement_modif_plante->addItem("champ 3");
         ui->le_Emplacement_modif_plante->addItem("champ 4");
         QDate Date_Plantation = QDate::currentDate();
         ui->le_Date_plante->setDate(Date_Plantation);
         ui->le_Date_plante->setMinimumDate(Date_Plantation);


    ui->port_2->setText("121212");
    ui->port_2->setDisabled(true);
    ui->le_identifiant->setValidator(new QIntValidator(100, 9999999, this));
    ui->tab_emp->setModel(E.afficher());

    ui->ide->setPlaceholderText("Votre ID");
    ui->mdp->setPlaceholderText("Votre Mot De Passe");
    ui->gestionemployes_2->setCurrentIndex(0);

   int ret=rfidInstance.connect_arduino();
            qDebug() <<"ret="<<ret;
            switch(ret){
            case(0):qDebug()<<"Arduino is available and connected to : "<< rfidInstance.getarduino_port_name();
              break;
            case(1):qDebug()<<"Arduino is available but not connected to : "<< rfidInstance.getarduino_port_name();
                break;
            case(-1):qDebug()<<"Arduino is not available ";
           }
            ref="";
     QObject::connect(rfidInstance.getserial(),SIGNAL(readyRead()),this,SLOT(connect_RFID()));









           connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::onRechercheTextChanged);
           QPixmap pix("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/logo_produit.png");
           ui->label_produit_logo->setPixmap(pix.scaled(121,101,Qt::KeepAspectRatio));
           QPixmap pix1("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/qrcode.png");
           ui->label_produit_qr->setPixmap(pix1.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix2("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/PDF_produit.png");
           ui->label_produit_PDF->setPixmap(pix2.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix3("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/statistics_produit.png");
           ui->label_produit_statistics->setPixmap(pix3.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix4("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/recherche_produit.png");
           ui->label_produit_recherche->setPixmap(pix4.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix5("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/trier_produit.png");
           ui->label_produit_trier->setPixmap(pix5.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix6("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/retour_produit.png");
           ui->label_produit_retour_ajout->setPixmap(pix6.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix7("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/retour_produit.png");
           ui->label_produit_retour_supp_1->setPixmap(pix7.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix8("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/retour_produit.png");
           ui->label_produit_retour_modif_1->setPixmap(pix8.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix19("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/retour_produit.png");
           ui->quitter->setPixmap(pix19.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix20("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/retour_produit.png");
           ui->statistics_retour->setPixmap(pix20.scaled(20,20,Qt::KeepAspectRatio));

           QPixmap pix11("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/ajouter_produit.png");
           ui->label_produit_ajout_produit->setPixmap(pix11.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix12("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/supprimer_produit.png");
           ui->label_produit_supp_produit->setPixmap(pix12.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix13("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/modifier_produit.png");
           ui->label_produit_modif_produit->setPixmap(pix13.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix14("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/supprimer_produit.png");
           ui->label_supprimerunproduit->setPixmap(pix14.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix15("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/modifier_produit.png");
           ui->label_modifierunproduit->setPixmap(pix15.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix16("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/ajouter_produit.png");
           ui->label_ajouterunproduit->setPixmap(pix16.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix17("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/image_produit_informations.png");
           ui->label_afficherlesproduits->setPixmap(pix17.scaled(20,20,Qt::KeepAspectRatio));
           QPixmap pix18("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/image_produit_produit.jpg");
           ui->label_imageduproduit->setPixmap(pix18.scaled(20,20,Qt::KeepAspectRatio));






         ui->tab_Produit->setItemDelegateForColumn(0,new numero(this));
        ui->tab_Produit->setSelectionBehavior(QAbstractItemView::SelectRows); // selects a whole row
        ui->le_Nom->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z]*"), this));
        ui->le_Nom->setMaxLength(10);
        ui->le_Nom_modif->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z]*"), this));
        /*ui->le_Numero->setValidator(new QRegExpValidator(QRegExp("[0-9]{3}"), this));*/
        ui->le_Nom_modif->setMaxLength(10);
        ui->le_Prix->setValidator(new QRegExpValidator(QRegExp("[0-9.]{0,255}"), this));
        ui->le_Numero->setValidator( new QIntValidator(0,99999, this));
       /* ui->le_Prix->setValidator( new QIntValidator(0,999999, this));*/
        ui->le_Prix_modif->setValidator( new QIntValidator(0,999999, this));
        ui->le_Numero_supp->setValidator( new QIntValidator(0,99999999, this));
        ui->le_Numero_modif->setValidator( new QIntValidator(0,99999999, this));
        int Numero=ui->le_Numero->text().toInt();
        QString Numero_string= QString::number(Numero);
        ui->recherche->setPlaceholderText("search");
        ui->le_Numero->setPlaceholderText("tapez le Numero");
        ui->le_Nom->setPlaceholderText("tapez le Nom");
        /*ui->le_Type->setPlaceholderText("tapez le Type");*/
        /*ui->le_Emplacement->setPlaceholderText("tapez l'emplacement");*/
        ui->le_Prix_2->setPlaceholderText("tapez le Prix");
        ui->tab_Produit->setModel(P.afficher());
        QDate Date_Prod = QDate::currentDate();
        ui->le_Date_Prod->setDate(Date_Prod);
        QDate Date_F_C = QDate::currentDate();
        ui->le_Date_F_C->setDate(Date_F_C);
        ui->le_Date_F_C->setMinimumDate(Date_F_C);
        ui->le_Date_Prod->setMinimumDate(Date_Prod);
        /*ui->le_Numero_modif_1->setDisabled(true);*/
        setWindowTitle("Gestion des Produits");
        ui->le_Type->addItem("animal");
        ui->le_Type->addItem("vegetal");
        QString recherche=ui->recherche->text();
        ui->le_Emplacement->addItem("entrepot 1");
        ui->le_Emplacement->addItem("entrepot 2");
        ui->le_Emplacement->addItem("entrepot 3");
        ui->le_Emplacement->addItem("entrepot 4");
        QString objet =ui->combo_objet->currentText();
         ui->combo_objet->addItem("Numero");
        ui->combo_objet->addItem("Nom");
        ui->combo_objet->addItem("Type");
        ui->combo_objet->addItem("Emplacement");
        ui->le_Emplacement_modif->addItem("entrepot 1");
        ui->le_Emplacement_modif->addItem("entrepot 2");
        ui->le_Emplacement_modif->addItem("entrepot 3");
        ui->le_Emplacement_modif->addItem("entrepot 4");
        ui->combobox_tri->addItem("Numero");
        ui->combobox_tri->addItem("Nom");
        ui->combobox_tri->addItem("Type");
        ui->combobox_tri->addItem("Emplacement");
        ui->combobox_tri->addItem("Date_Prod");
        ui->combobox_tri->addItem("Date_F_C");
        ui->combobox_tri->addItem("Prix");



        ui->le_Numero_2->setReadOnly(true);
        ui->le_Nom_2->setReadOnly(true);
        ui->le_Type_2->setReadOnly(true);
        ui->le_Emplacement_2->setReadOnly(true);
        ui->le_Date_Prod_3->setReadOnly(true);
        ui->le_Date_F_C_2->setReadOnly(true);
        ui->le_Prix->setReadOnly(true);
        ui->le_Numero_modif->setReadOnly(true);
        ui->letypemodif->setReadOnly(true);
        ui->le_Date_Prod_modif->setReadOnly(true);
        ui->le_Date_F_C_modif->setReadOnly(true);

        //salmaaaaaaaa
        ui->password->setEchoMode(QLineEdit::Password);
           // Supposons que votre QTableView soit nommé 'tableView'
           ui->tab_clients->setStyleSheet("QTableView { border: 2px solid green; }");

            ui->tab_clients->setModel(C.afficher());
            ui->tab_clients->setItemDelegateForColumn(0, new Numberformatdelegate(this));
            ui->tab_clients->setItemDelegateForColumn(5, new Numberformatdelegate(this));

           // permet de lancer



           ui->le_numTelclient->setValidator(new QIntValidator(10000000, 99999999, this));
           ui->le_nbPointsFidelites->setValidator(new QIntValidator(100, 999, this));

           QRegularExpression regexNomPrenom("^[A-Za-z ]+$");
           QRegularExpressionValidator *nomprenomValidator= new QRegularExpressionValidator(regexNomPrenom,this);
           ui->le_prenomclient->setValidator(nomprenomValidator);

           ui->le_nom->setValidator(nomprenomValidator);

           QRegularExpression regexcin("^132\\d{5}$");
           QRegularExpressionValidator *cinValidator= new QRegularExpressionValidator(regexcin,this);
           ui->le_cinclient->setValidator(cinValidator);
           mSocket = new QTcpSocket(this);
           connect(mSocket, &QTcpSocket::readyRead, [&](){
               QTextStream T(mSocket);

               auto text = T.readAll();
               ui->textEdit->append(text);
               QSerialPort serial;
       });
           int ret1=A.connect_arduino(); // lancer la connexion à arduino
               switch(ret1){
               case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                   break;
               case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                  break;
               case(-1):qDebug() << "arduino is not available";
               }
                QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(information_capteur()));



}


QSerialPort serial;

MainWindow::~MainWindow()
{
    delete ui;
}








void MainWindow::on_pb_ajouter_clicked()
{
   int identifiant=ui->le_identifiant->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   int age=ui->le_age->text().toInt();
   int numero_telephone=ui->le_numero_telephone->text().toInt();
   QString mail=ui->le_mail->text();
   QString pass=ui->le_pass->text();
   QString statut=ui->le_statut->currentText();
   QString rfid=ui->le_rfid->text();
   QString poste=ui->le_poste->text();




   Employes E(identifiant, age, numero_telephone, nom, prenom,mail,pass,statut,rfid, poste);
bool test=E.ajouter();
QMessageBox msgBox;
if (test)

{ msgBox.setText("Ajout avec succes.");
  ui->tab_emp->setModel(E.afficher());
}
else
   msgBox.setText("Echec d'ajout");
   msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
   Employes E;
   E.setidentifiant(ui->le_id_supp->text().toInt());
   bool test=E.supprimer(E.getidentifiant());
   QMessageBox msgBox;
   if (test)
   {msgBox.setText("Suppression avec succes.");
   ui->tab_emp->setModel(E.afficher());
   }
   else
       msgBox.setText("Echec de suppression");
       msgBox.exec();
}

void MainWindow::on_pushButton_ajouter_clicked()
{
}



void MainWindow::on_pb_modifier_clicked()
{
    int identifiant=ui->le_identifiant->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int age=ui->le_age->text().toInt();
    int numero_telephone=ui->le_numero_telephone->text().toInt();
    QString mail=ui->le_mail->text();
    QString pass=ui->le_pass->text();
    QString statut=ui->le_statut->currentText();
    QString rfid=ui->le_rfid->text();
    QString poste=ui->le_poste->text();




    Employes E(identifiant, age, numero_telephone, nom, prenom,mail,pass,statut,rfid, poste);
 bool test=E.modifier();
 QMessageBox msgBox;
 if (test)

 { msgBox.setText("Modifier avec succes.");
   ui->tab_emp->setModel(E.afficher());
 }
 else
    msgBox.setText("Echec de modifier");
    msgBox.exec();

}
void MainWindow::on_pb_chercher_clicked()
{
    Employes E;
    int identifiant=ui->rech_id->text().toUInt();

    bool test = E.rech(identifiant);
    QMessageBox msgBox;

    if (test) {
        msgBox.setText("Recherche avec succès.");
        ui->tab_emp->setModel(E.rechercher(identifiant));
    } else {
        msgBox.setText("Employes inexistant");
        msgBox.exec();
    }
 }

void MainWindow::on_pb_trier_clicked()
{
    Employes E;
    if (ui->trier_id->isChecked())
    {
        ui->tab_emp->setModel(E.trier_IDENTIFIANT());
    } else if (ui->trier_poste->isChecked())
    {
        ui->tab_emp->setModel(E.trier_POSTE());
    }else if (ui->trier_age->isChecked())
    {
        ui->tab_emp->setModel(E.trier_AGE());
    }

}


void MainWindow::on_pdf_9_clicked()
{
    QString strStream,strTitle;
            QTextStream out(&strStream);

            const int rowCount = ui->tab_emp->model()->rowCount();
            const int columnCount = ui->tab_emp->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>Employes</title>\n").arg(strTitle)
                <<  "<head> Les employes non payés</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2 style='width:100%;'>\n";

            // headers
            out << "h1 {" <<
                    "   text-align: center;" // Center-align the h1 element
                   << "}";
            out << "<h1> Liste Des Employes </h1>";
            out << "<br>";
            out << "<br>";
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tab_emp->isColumnHidden(column))
                    out << "<th>" << ui->tab_emp->model()->headerData(column, Qt::Horizontal).toString() << "</th>";
            out << "</tr></thead>\n";


            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_emp->isColumnHidden(column)) {
                        QString data = ui->tab_emp->model()->data(ui->tab_emp->model()->index(row, column)).toString().simplified();
                        out << QString("<td style='width:200px' bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void MainWindow::on_le_statut_activated(const QString &arg1)
{
    QString choix;
    if(arg1 == "Employes")
    {choix = "Employes";}
    else if(arg1 == "Client")
    {choix = "Client";}
    else if(arg1 == "Produit")
    {choix = "Produit";}
    else if(arg1 == "Animal")
    {choix = "Animal";}
    else if(arg1 == "Fournisseur")
    {choix = "Fournisseur";}
    ui->label->setText(choix);

}







void MainWindow::on_pb_ajouter_produit_clicked()
{
    QSqlQuery query;
    QString saisie1 = ui->le_Date_F_C->text();
    QString saisie = ui->le_Numero->text();
            if (saisie.length() == 5) {

                QString numeroComplet = "321" + saisie;
                ui->le_Numero->setText(numeroComplet);}
    int Numero=ui->le_Numero->text().toInt();
    QString Nom=ui->le_Nom->text();
    QString Type=ui->le_Type->currentText();
    QString Emplacement=ui->le_Emplacement->currentText();
    QDate Date_Prod=ui->le_Date_Prod->date();
    QDate Date_F_C=ui->le_Date_F_C->date();
    float Prix=ui->le_Prix_2->text().toDouble();
    QString qr_code;

    int test1=0;
    int nbr=0;
    if(Numero==0|| Prix==0 || Nom=="")
    {
        test1=1;
    }
    query.prepare("SELECT * FROM PRODUITS WHERE Numero=:Numero");
    query.bindValue(":Numero",ui->le_Numero->text().toInt());
    query.exec();
   if(Numero==0 && Prix==0&& Nom=="")
    {
        ui->le_Numero_erreur->setText("Vérifier le numero!!");
        ui->le_Numero_erreur->setStyleSheet("color: red;");
        ui->le_Nom_erreur->setText("Vérifier le nom!!");
        ui->le_Nom_erreur->setStyleSheet("color: red;");
        ui->le_Prix_erreur->setText("Vérifier le Prix!!");
        ui->le_Prix_erreur->setStyleSheet("color: red;");
    }

     else if(test1==1)
    {
        if(Numero==0)
        {
            ui->le_Numero_erreur->setText("Vérifier le numero!!");
            ui->le_Numero_erreur->setStyleSheet("color: red;");
        }
    else if(Nom=="")
    {
            ui->le_Nom_erreur->setText("Vérifier le nom!!");
            ui->le_Nom_erreur->setStyleSheet("color: red;");
    }

    else if(Prix==0)
    {
            ui->le_Prix_erreur->setText("Vérifier le Prix!!");
            ui->le_Prix_erreur->setStyleSheet("color: red;");
    }
    }
   else if(saisie.length()<5)
   {
       QMessageBox::critical(nullptr, QObject::tr("ok"),
                   QObject::tr("ajout failed.\n"
                               "Le numero est obligatoirement constitué de 5 chiffres.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
      /* ui->le_Numero_modif_erreur->setText("Vérifier Numero!!");
       ui->le_Numero_modif_erreur->setStyleSheet("color: red;");*/

   }
   else if (Nom.length() < 3) {
       QMessageBox::critical(nullptr, QObject::tr("problem"),
                           QObject::tr("ajout failed.\n"
                                       "Le nom doit comporter au moins trois caractères.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else if(Date_Prod>=Date_F_C)
   {
       QMessageBox::critical(nullptr, QObject::tr("problem"),
                           QObject::tr("ajout failed.\n"
                                       "vérifier les dates.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
   }

    else
    {
        while(query.next())
        {
            nbr++;
        }
        if(nbr!=0)
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("ajout failed.\n"
                                    "Numero existe deja.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {

    Produit P(Numero,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix,qr_code);
    bool test=P.ajouter();
    if(test)
    {
        int Numero=ui->le_Numero->text().toInt();
        QString Numero_string= QString::number(Numero);
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_Produit->setModel(P.afficher());
        QSqlQuery qry;
        qry.prepare("SELECT * FROM PRODUITS WHERE Numero=:Numero");
        qry.bindValue(":Numero",ui->le_Numero->text().toInt());
        int id=ui->le_Numero->text().toInt();
        qry.exec();
        QString  Numer,Nom,Type,Emplacement,Date_Prod,Date_F_C,Prix,Num;
        while(qry.next())
        {
            Numer=qry.value(0).toString();
            Nom=qry.value(1).toString();
            Type=qry.value(2).toString();
            Emplacement=qry.value(3).toString();
            Date_Prod=qry.value(4).toString();
            Date_F_C=qry.value(5).toString();
            Prix=qry.value(6).toString();
       }
        Num=QString(Num);
                 Num="Numero:"+Numer+"\n Nom:"+Nom+"\n Type:"+Type+"\n Emplacement:"+Emplacement+" \n Date_Prod:"+Date_Prod+" \n Date_F_C:"+Date_F_C+" \n Prix:"+Prix;
            QrCode  qr = QrCode::encodeText(Num.toUtf8().constData(), QrCode::Ecc::HIGH);
          QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
          for (int y = 0; y < qr.getSize(); y++) {
              for (int x = 0; x < qr.getSize(); x++) {
                  int color = qr.getModule(x, y);
                  if(color==0)
                      im.setPixel(x, y,qRgb(254, 254, 254));
                  else
                      im.setPixel(x, y,qRgb(0, 0, 0));
              }
          }
          im=im.scaled(300,300);
          QByteArray ba;
          QBuffer buffer(&ba);
          buffer.open(QIODevice::WriteOnly);
          im.save(&buffer, "png");
          QSaveFile file("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/qrcode/"+Numer+".png");
          file.open(QIODevice::WriteOnly);
          file.write(ba);

          file.commit();
          QString directory = "C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/qrcode/"+Numer+".png";
          Produit P;
          bool qrqr = P.UpdateQrcodeLink(directory,id);
          if (qrqr) {
              QMessageBox::information(nullptr, QObject::tr("Qr code link succesfully added to the database"),
                                       QObject::tr("Qr code effectué\n"
                                                   "Click cancel to exit."), QMessageBox::Cancel);
              ui->tab_Produit->setModel(P.afficher());
          } else
          {
          QMessageBox::information(nullptr, QObject::tr("Error"),QObject::tr("failed"));
          }

    }
    ui->le_Numero->clear();
    ui->le_Numero_erreur->clear();
    ui->le_Nom->clear();
    ui->le_Nom_erreur->clear();
    QDate Date_Prod = QDate::currentDate();
    ui->le_Date_Prod->setDate(Date_Prod);
    QDate Date_F_C = QDate::currentDate();
    ui->le_Date_F_C->setDate(Date_F_C);
    ui->le_Prix->clear();
    ui->le_Prix_erreur->clear();
        }}


}

void MainWindow::on_pb_Supprimer_produit_clicked()
{
    Produit P1;
    P1.setNumero(ui->le_Numero_supp->currentText().toInt());
    int Numero=ui->le_Numero_supp->currentText().toInt();
    if(Numero==0)
    {
       /* ui->le_Numero_supp_1->setText("Vérifier Numero!!");
        ui->le_Numero_supp_1->setStyleSheet("color: red;");*/

    }
    else{
    bool test=P1.Supprimer(P1.getNumero());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        int Numero=ui->le_Numero_supp->currentText().toInt();
        QString imagePath =QString::number(Numero);
        QFile imagefile;
        imagefile.remove("C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/qrcode/"+imagePath+".png");
        ui->tab_Produit->setModel(P.afficher());
        ui->le_Numero_supp->clear();
        ui->le_Numero_2->clear();
        ui->le_Nom_2->clear();
        ui->le_Type_2->clear();
        ui->le_Emplacement_2->clear();
        ui->le_Date_Prod_3->clear();
        ui->le_Date_F_C_2->clear();
        ui->le_Prix->clear();
    }
    }
}

void MainWindow::on_pb_modifier_produit_clicked()
{
    Produit P2;
    P2.setNumero(ui->le_Numero_modif_2->currentText().toInt());
    P2.setNom(ui->le_Nom_modif->text());
    P2.setType(ui->letypemodif->text());
    P2.setPrix(ui->le_Prix_modif->text().toInt());
    P2.setEmplacement(ui->le_Emplacement_modif->currentText());
    QString Nom=ui->le_Nom_modif->text();
    float Prix=ui->le_Prix_modif->text().toDouble();
    int Numero=ui->le_Numero_modif_2->currentText().toInt();
    int test1=0;
    if( Nom=="" || Prix==0 )
    {
        test1=1;
    }
    if(Numero==0)
    {
       /* ui->le_Numero_modif_erreur->setText("Vérifier Numero!!");
        ui->le_Numero_modif_erreur->setStyleSheet("color: red;");*/
    }

    else if (test1==1)
    {

        if(Nom=="")
        {
            ui->le_Nom_modif_erre->setText("Vérifier Nom/champ vide!!");
            ui->le_Nom_modif_erre->setStyleSheet("color: red;");
        }
        else if(Prix==0)
        {
            ui->le_Prix_modif_erre->setText("Vérifier Prix/champ vide!!");
            ui->le_Prix_modif_erre->setStyleSheet("color: red;");
        }

    }
    else if (Nom.length() < 3) {
        QMessageBox::critical(nullptr, QObject::tr("problem"),
                            QObject::tr("ajout failed.\n"
                                        "Le nom doit comporter au moins trois caractères.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
    bool test=P2.Modifier(P2.getNumero());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Modification successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_Produit->setModel(P.afficher());
        ui->le_Numero_modif->clear();
         ui->le_Numero_modif_2->clear();

        ui->le_Numero_modif->clear();
        ui->le_Nom_modif->clear();
        ui->letypemodif->clear();
        ui->le_Date_Prod_modif->clear();
        ui->le_Date_F_C_modif->clear();
        ui->le_Prix_modif->clear();
        ui->le_Prix_modif_erre->clear();
        ui->le_Nom_modif_erre->clear();
    }
}
}



void MainWindow::on_tab_Produit_clicked(const QModelIndex &index)
{
    QString val=ui->tab_Produit->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUITS WHERE Numero='"+val+"' or Type='"+val+"'");

    if (query.exec()) {
                if (query.next()) {
    ui->gestionemployes_2->setCurrentIndex(7);

    ui->le_Numero_supp->setCurrentText(query.value(0).toString());
    ui->le_Numero_2->setText(query.value(0).toString());
    ui->le_Nom_2->setText(query.value(1).toString());
    ui->le_Type_2->setText(query.value(2).toString());
    ui->le_Emplacement_2->setText(query.value(3).toString());
    ui->le_Date_Prod_3->setText(query.value(4).toString());
    ui->le_Date_F_C_2->setText(query.value(5).toString());
    ui->le_Prix->setText(query.value(6).toString());
    /*ui->le_Numero_supp->setReadOnly(true);*/
    ui->le_Numero_2->setReadOnly(true);
    ui->le_Nom_2->setReadOnly(true);
    ui->le_Type_2->setReadOnly(true);
    ui->le_Emplacement_2->setReadOnly(true);
    ui->le_Date_Prod_3->setReadOnly(true);
    ui->le_Date_F_C_2->setReadOnly(true);
    ui->le_Prix->setReadOnly(true);
                }}
    query.prepare("SELECT * FROM PRODUITS WHERE Nom='"+val+"'");

    if (query.exec()) {
                if (query.next()) {
    ui->gestionemployes_2->setCurrentIndex(3);

    ui->le_Numero_modif_2->setCurrentText(query.value(0).toString());
    ui->le_Numero_modif->setText(query.value(0).toString());
    ui->le_Nom_modif->setText(query.value(1).toString());
    ui->letypemodif->setText(query.value(2).toString());
    ui->le_Emplacement_modif->setCurrentText(query.value(3).toString());
    ui->le_Date_Prod_modif->setText(query.value(4).toString());
    ui->le_Date_F_C_modif->setText(query.value(5).toString());
    ui->le_Prix_modif->setText(query.value(6).toString());
    /*ui->le_Numero_modif->setReadOnly(true);*/
    ui->le_Numero_modif->setReadOnly(true);
    ui->letypemodif->setReadOnly(true);
    /*ui->le_Emplacement_modif->setReadOnly(true);*/
    ui->le_Date_Prod_modif->setReadOnly(true);
    ui->le_Date_F_C_modif->setReadOnly(true);



                }}

}






void MainWindow::on_le_Nom_cursorPositionChanged(int a, int b)
{
    a=0;
    b=0;
    QString saisie = ui->le_Numero->text();
            if (saisie.length() == 5) {

                QString numeroComplet = "321" + saisie;
                ui->le_Numero->setText(numeroComplet);}

}

void MainWindow::on_exportPDF_clicked()
{
   QString defaultFileName = "Produit.pdf";
        QString saveFilePath = QFileDialog::getSaveFileName(this, tr("Export PDF"), QDir::homePath() + "/" + defaultFileName, tr("PDF Files (*.pdf)"));

        if (!saveFilePath.isEmpty()) {
            QPrinter printer(QPrinter::HighResolution);
            printer.setOutputFileName(saveFilePath);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFormat(QPrinter::PdfFormat);

            QPainter painter(&printer);
            painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

            QAbstractItemModel* model = ui->tab_Produit->model();

            if (model) {
                int rowCount = model->rowCount();
                int columnCount = model->columnCount();


                QTextDocument doc;
                QTextCursor cursor(&doc);
                QString titleText = "<span style=\"color: red; font-size: 18px;\">Liste des Produits</span><br><br>";
                            doc.setHtml(titleText);
                 QString tableHtml = "<table style=\"border-collapse: collapse; width: 100%; border: 1px solid black; font-size: 4px;\">";
                tableHtml += "<tr style=\"background-color: #ccc;\">";
                for (int col = 0; col < columnCount - 2; ++col) { // Exclude the last 2 columns
                    QVariant data = model->headerData(col, Qt::Horizontal);
                    tableHtml += "<th style=\"border: 1px solid black; padding: 8px;\">" + data.toString() + "</th>";
                }
                tableHtml += "</tr>";
                for (int row = 0; row < rowCount; ++row) {
                    tableHtml += "<tr>";
                    for (int col = 0; col < columnCount - 2; ++col) { // Exclude the last 2 columns
                        QModelIndex index = model->index(row, col);
                        QVariant data = model->data(index);
                        tableHtml += "<td style=\"border: 1px solid black; padding: 8px;\">" + data.toString() + "</td>";
                    }
                    tableHtml += "</tr>";
                }

                tableHtml += "</table>";

                // Set the HTML content for the QTextDocument
                doc.setHtml(tableHtml);

                // Manually scale the painter by a factor of 100
                painter.scale(30.0, 30.0);

                // Render the QTextDocument onto the PDF
                doc.setPageSize(printer.pageRect().size());
                doc.drawContents(&painter);

            }

            painter.end();
        }

}


void MainWindow::onRechercheTextChanged(const QString &text)
{
    Produit P;
    QSqlQuery query;

    //QString recherche=ui->recherche->text();
    QString recherche=text;
    if(ui->combo_objet->currentText()=="Numero")
    {

        if(recherche=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("search failed.\n"
                                    "champ vide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if(P.rechercher_4(recherche)==nullptr)
        {
            QMessageBox::critical(nullptr, QObject::tr("problem"),
                                QObject::tr("ajout failed.\n"
                                            "chiffre ou numero n'existe pas.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            ui->tab_Produit->setModel(P.rechercher_4(recherche));
         }


    }
    else if(ui->combo_objet->currentText()=="Nom")
    {

        if(recherche=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("search failed.\n"
                                    "champ vide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if(P.rechercher_1(recherche)==nullptr)
        {
            QMessageBox::critical(nullptr, QObject::tr("problem"),
                                QObject::tr("ajout failed.\n"
                                            "caractère ou non n'existe pas.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            ui->tab_Produit->setModel(P.rechercher_1(recherche));
         }


    }
    else if(ui->combo_objet->currentText()=="Type")
    {

        if(recherche=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("search failed.\n"
                                    "champ vide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if(P.rechercher_2(recherche)==nullptr)
        {
            QMessageBox::critical(nullptr, QObject::tr("problem"),
                                QObject::tr("ajout failed.\n"
                                            "caractère ou non n'existe pas.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            ui->tab_Produit->setModel(P.rechercher_2(recherche));
         }


    }
    else if(ui->combo_objet->currentText()=="Emplacement")
    {

        if(recherche=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("search failed.\n"
                                    "champ vide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if(P.rechercher_3(recherche)==nullptr)
        {
            QMessageBox::critical(nullptr, QObject::tr("problem"),
                                QObject::tr("ajout failed.\n"
                                            "caractère ou non n'existe pas.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            ui->tab_Produit->setModel(P.rechercher_3(recherche));
         }


    }



}



void MainWindow::on_trier_clicked()
{
    Produit P;
    QString tri=ui->combobox_tri->currentText();
    ui->tab_Produit->setModel(P.trier(tri));

}




void MainWindow::on_le_Numero_supp_currentIndexChanged(const QString &arg1)
{
    QString val=ui->le_Numero_supp->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUITS WHERE Numero='"+val+"'");

    if (query.exec()) {
                if (query.next()) {


    ui->le_Numero_supp->setCurrentText(query.value(0).toString());
    ui->le_Numero_2->setText(query.value(0).toString());
    ui->le_Nom_2->setText(query.value(1).toString());
    ui->le_Type_2->setText(query.value(2).toString());
    ui->le_Emplacement_2->setText(query.value(3).toString());
    ui->le_Date_Prod_3->setText(query.value(4).toString());
    ui->le_Date_F_C_2->setText(query.value(5).toString());
    ui->le_Prix->setText(query.value(6).toString());
    /*ui->le_Numero_supp->setReadOnly(true);*/
    ui->le_Numero_2->setReadOnly(true);
    ui->le_Nom_2->setReadOnly(true);
    ui->le_Type_2->setReadOnly(true);
    ui->le_Emplacement_2->setReadOnly(true);
    ui->le_Date_Prod_3->setReadOnly(true);
    ui->le_Date_F_C_2->setReadOnly(true);
    ui->le_Prix->setReadOnly(true);
                }}
}


void MainWindow::on_le_Numero_modif_2_currentIndexChanged(const QString &arg1)
{
    QString val=ui->le_Numero_modif_2->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUITS WHERE Numero='"+val+"'");

    if (query.exec()) {
                if (query.next()) {
                    ui->le_Numero_modif_2->setCurrentText(query.value(0).toString());
                    ui->le_Numero_modif->setText(query.value(0).toString());
                    ui->le_Nom_modif->setText(query.value(1).toString());
                    ui->letypemodif->setText(query.value(2).toString());
                    ui->le_Emplacement_modif->setCurrentText(query.value(3).toString());
                    ui->le_Date_Prod_modif->setText(query.value(4).toString());
                    ui->le_Date_F_C_modif->setText(query.value(5).toString());
                    ui->le_Prix_modif->setText(query.value(6).toString());
                    /*ui->le_Numero_modif->setReadOnly(true);*/
                    ui->le_Numero_modif->setReadOnly(true);
                    ui->letypemodif->setReadOnly(true);
                    /*ui->le_Emplacement_modif->setReadOnly(true);*/
                    ui->le_Date_Prod_modif->setReadOnly(true);
                    ui->le_Date_F_C_modif->setReadOnly(true);




                }}

}




void MainWindow::on_qr_code_clicked()
{
    QString folderPath = "C:/Users/ASUS/Desktop/2A/projet_2A c++/integration finale/qrcode";

        // Ouvrir l'explorateur de fichiers avec le dossier qrcode
        QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
}

void MainWindow::on_supprimer_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(8);
}

void MainWindow::on_ajouter_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(7);
}


void MainWindow::on_statistics_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(10);
}

void MainWindow::on_modifier_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(9);
}

void MainWindow::on_image_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(11);
    QPixmap pix("C:/Users/ASUS/Desktop/CRUD + metiers/image.png");
    ui->label_pic->setPixmap(pix.scaled(500,500,Qt::KeepAspectRatio));
}


void MainWindow::on_retour_ajout_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(6);
}

void MainWindow::on_retour_supp_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(6);
}

void MainWindow::on_retour_modif_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(6);
}

void MainWindow::on_retour_statistic_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(6);
}

void MainWindow::on_retour_image_produit_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(6);
}

void MainWindow::on_afficher_produit_clicked()
{
     ui->tab_Produit->setModel(P.afficher());
}






void MainWindow::on_gestion_E_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(2);
}

void MainWindow::on_gestion_C_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(4);

}

void MainWindow::on_gestion_P_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(6);

    QSystemTrayIcon trayIcon(QIcon("C:/Users/ASUS/Desktop/projet c++/integration/notification.jpg"));

     trayIcon.setVisible(true);
      QSqlQuery query13 ;
      query13.prepare("select * from produits where Date_F_C=:Date_F_C");
      query13.bindValue(":Date_F_C",QDate::currentDate().addDays(2));

             if (query13.exec()) {
             while (query13.next()) {
                 QDate dateFinConsommation = query13.value(5).toDate();
                 int Numero=query13.value(0).toInt();
                 if (dateFinConsommation <= QDate::currentDate().addDays(2) ) {

                     trayIcon.show();
                     trayIcon.showMessage("News","La date de fin de consommation du produit N°:" + QString::number(Numero) + " s'approche (" + dateFinConsommation.toString("dd-MM-yyyy") + ")", QSystemTrayIcon::Information, 15000);

                 }
             }}

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(22, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Nombre de produits selon l'emplacement et le type");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 <<3<<4<<5<<6;

   labels << "entrepot1" << "entrepot2"<<"entrepot3"<<"entrepot4"<<"type_animal" <<"type_vegetal";
    // Add data:
    QVector<double> regenData;
    QSqlQuery query1;
    QSqlQuery query2;
    QSqlQuery query3;
    QSqlQuery query4;
    QSqlQuery query5;
    QSqlQuery query6;
    int nbr=0;
    int nbr1=0;
    int nbr2=0;
    int nbr3=0;
    int nbr4=0;
    int nbr5=0;
    query1.prepare("select * from produits where Emplacement =:Emplacement");
    query1.bindValue(":Emplacement","entrepot 1");
    if (query1.exec()) {
        // Récupérez le résultat de la requête
        while(query1.next()) {
            nbr++;}}
    query2.prepare("select * from produits where Emplacement =:Emplacement");
    query2.bindValue(":Emplacement","entrepot 2");
    if (query2.exec()) {
        // Récupérez le résultat de la requête
        while(query2.next()) {
            nbr1 ++;}}
    query3.prepare("select * from produits where Emplacement =:Emplacement");
    query3.bindValue(":Emplacement","entrepot 3");
    if (query3.exec()) {
        // Récupérez le résultat de la requête
        while (query3.next()) {
            nbr2 ++;}}
    query4.prepare("select * from produits where Emplacement =:Emplacement");
    query4.bindValue(":Emplacement","entrepot 4");
    if (query4.exec()) {
        // Récupérez le résultat de la requête
        while(query4.next()) {
            nbr3 ++;}}
    query5.prepare("select * from produits where Type =:Type");
    query5.bindValue(":Type","animal");
    if (query5.exec()) {
        // Récupérez le résultat de la requête
        while(query5.next()) {
            nbr4 ++;}}
    query6.prepare("select * from produits where Type =:Type");
    query6.bindValue(":Type","vegetal");
    if (query6.exec()) {
        // Récupérez le résultat de la requête
        while(query6.next()) {
            nbr5 ++;}}
    regenData<<nbr<<nbr1<<nbr2<<nbr3<<nbr4<<nbr5;
     regen->setData(ticks, regenData);

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
     ui->customPlot->xAxis->setLabel("Emplacement                               Type");
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,50);
    ui->customPlot->yAxis->setPadding(5);
    ui->customPlot->yAxis->setLabel("Nombre de Produits");// a bit more space to the left border
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


     QSqlQueryModel * modal12=new QSqlQueryModel();
     QSqlQuery query22;
     query22.prepare("select Numero from produits");
     query22.exec();
     modal12->setQuery(query22);
     ui->le_Numero_supp->setModel(modal12);
     QSqlQueryModel * modal11=new QSqlQueryModel();
     QSqlQuery query16;
     query16.prepare("select Numero from produits");
     query16.exec();
     modal11->setQuery(query16);
     ui->le_Numero_modif_2->setModel(modal11);

}
void MainWindow:: information_capteur()
{
   /* QSystemTrayIcon trayIcon(QIcon("C:/Users/ASUS/Desktop/projet c++/arduino/arduino/notification.jpg")); // Remplacez par le chemin réel de votre icône
                  trayIcon.setVisible(true);*/
    data=A.read_from_arduino();
    qDebug() <<"data recived from arduino :"<< data.trimmed();
    data = data.trimmed();
    QSqlQuery query;

          query.prepare("update PLANTES set Humidite= :Humidite where Emplacement= :Emplacement");
          query.bindValue(":Emplacement", "champ 1");
          query.bindValue(":Humidite",data.toInt());
          query.exec();
    query.prepare("SELECT * FROM PLANTES WHERE Emplacement=:Emplacement");
    query.bindValue(":Emplacement","champ 1");
    if (query.exec()) {
        if(query.next()) {
            int humidite=query.value(6).toInt();
            if(humidite>500)
            {
                A.write_to_arduino("1");
                //QSqlQuery query2;

                query.prepare("UPDATE PLANTES SET DATE_IRRIGATION =:DATE_IRRIGATION WHERE Emplacement=:Emplacement");
                query.bindValue(":Emplacement","champ 1");
                query.bindValue(":DATE_IRRIGATION", QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss"));
                query.exec();
                QSqlQuery query3;
                query3.prepare("SELECT * FROM PLANTES ");

                if (query3.exec()) {
                    while (query3.next()) {
                        //Récupérer l'ID de la plante
                        int plantID = query3.value(0).toInt();
                        // Récupérer la valeur actuelle de NBR_FS_IRRIGUEE
                        int currentNbr =query3.value(5).toInt();

                        // Incrémenter NBR_FS_IRRIGUEE de 1
                        int newNbr = currentNbr + 1;

                        // Mettre à jour NBR_FS_IRRIGUEE pour la plante actuelle
                         QSqlQuery query3;
                        query3.prepare("UPDATE PLANTES SET NBR_FS_IRRIGUEE =:NBR_FS_IRRIGUEE WHERE Numero = :Numero AND Emplacement = :Emplacement");
                        query3.bindValue(":Numero",plantID);
                        query3.bindValue(":Emplacement","champ 1");
                       query3.bindValue(":NBR_FS_IRRIGUEE", newNbr);
                      query3.exec();}}
                      ui->tab_plante->setModel(Pl.afficher());
            }


        }
    }


    /*if(data=="1")
    {
    trayIcon.show();
    trayIcon.showMessage("warning","Les plantes manquent de l'eau" , QSystemTrayIcon::Critical, 15000);
    }
    if(data=="2")
    {
       trayIcon.show();
        trayIcon.showMessage("News","pompe ouverte" , QSystemTrayIcon::Critical, 1500);

    }
     else if(data=="3")
     {
            trayIcon.show();
             trayIcon.showMessage("News","pompe fermée" , QSystemTrayIcon::Critical, 1500);

      }*/



}
void MainWindow::on_send_clicked()
{
    QTextStream T(mSocket);
    T << ui->nickname->text() <<" : " << ui->message->text();
    mHostname = ui->nickname->text();
    qDebug() << "Socket state: " << mSocket->state();

    mPort = 121212;
    mSocket->flush();
    ui->message->clear();
    auto text = T.readAll();
    ui->textEdit->append(text);
}

/*void MainWindow::on_bind_clicked()
{
   DuMesengerConnection D (this);
   if(D.exec() == QDialog ::Rejected){
       return;
   }
   mSocket->connectToHost(D.hostname(),D.port());


}*/


void MainWindow::on_ok_clicked()
{

hide();
}

void MainWindow::on_cancel_clicked()
{
hide();
}




void MainWindow::on_bind_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(3);
}

void MainWindow::on_gestionemployes_quitter_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(1);
}


QString MainWindow::findconnect(const QString& identifiant)
{
    QString statut;
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE IDENTIFIANT=:IDENTIFIANT");
    query.bindValue("IDENTIFIANT",identifiant.toInt());

    if(query.exec() && query.next())
    {
        statut = query.value(6).toString();
    }
    return statut;

}

/*void MainWindow::on_login_2_clicked()
{
    bool test = false;
    QString identifiant = ui->ide->text();
    QString pass = ui->mdp->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE IDENTIFIANT=:IDENTIFIANT AND PASS=:PASS");
    query.bindValue(":IDENTIFIANT", identifiant);
    query.bindValue(":PASS", pass);

    if (!query.exec())
    {
        QMessageBox::critical(this, "Erreur de la base de données", "Échec de la requête : " + query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            QString IdFromDB = query.value(0).toString();
            QString passwordFromDB = query.value(7).toString();

            if (IdFromDB == identifiant && passwordFromDB == pass)
            {
                hide();
                QString status = findconnect(identifiant);
                //menu M(status);
                menu* M = new menu (status, this);
                M->exec();


                delete M;

                test = true;
            }
        }
        if (!test) {
                   QMessageBox::critical(this, "Erreur d'authentification", "Aucun enregistrement ne correspond aux identifiants fournis.");
                   // Ajoutez ici d'autres actions que vous souhaitez effectuer en cas d'échec d'authentification
               }
           }
       }*/

void MainWindow::connect_RFID()
{
    data= rfidInstance.read_from_arduino();
    for(int i=0;i<data.length();i++)

    {
        if(data[i]=='D' || data[i]==')')
        {
            qDebug() << "ref= " << ref ;
            if(data[i]=='D')
            {
                Employes E; //remplacez avec le nom de votre classe

                 // cas ou elle n'existe
                if(E.rfidExists(ref))
                    {
                    ui->gestionemployes_2->setCurrentIndex(1);

                    QByteArray data1;
                    data1.append('1');
                    rfidInstance.write_to_arduino("1");//envoie 1 a arduino et enclenche /demarre le processus 1

                    qDebug()<<"carte existante";

                    //prend la valeur du nom
                    QString prenom = E.rfidName(ref);


                    QByteArray nomData(prenom.toUtf8(), 8);
                   rfidInstance.write_to_arduino(nomData);
                   qDebug()<<nomData;
    // hneeeeeeeee
                    /*bool test=false;
                    hide();
                    QString status = findconnect(identifiant);
                    //menu M(status);
                    menu* M = new menu (status, this);
                    M->exec();


                    test = true;*/

                    }
                else
                {
                    rfidInstance.write_to_arduino("2"); // envoie 2 a arduino et enclenche /demarre le processus 2

                    qDebug()<<"carte inexistante";
                }
            }

             ref.clear();
              }
        else if(!(data[i]=='\r' || data[i]=='\n'))
        {
             ref=ref+data[i];

        }
                }

    }


/*void MainWindow::on_login_clicked()
{
    bool test = false;
    QString identifiant = ui->ide->text();
    QString pass = ui->mdp->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE IDENTIFIANT=:IDENTIFIANT AND PASS=:PASS");
    query.bindValue(":IDENTIFIANT", identifiant);
    query.bindValue(":PASS", pass);

    if (!query.exec())
    {
        QMessageBox::information(this, "Error !!", "DB error: " + query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            QString IdFromDB = query.value(0).toString();
            QString passwordFromDB = query.value(6).toString();

            if (IdFromDB == identifiant && passwordFromDB == pass)
            {

                ui->gestionemployes_2->setCurrentIndex(1); // or another index that corresponds to the desired page



                test = true;
            }
        }


       }




}*/




/*void MainWindow::on_login_clicked()
{
                QString identifiant = ui->ide->text();
                QString pass = ui->mdp->text();



    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE IDENTIFIANT=:IDENTIFIANT AND PASS=:PASS");
    query.bindValue(":IDENTIFIANT", identifiant);
    query.bindValue(":PASS", pass);
    query.exec();



    if (query.exec() && query.next()) {
        qDebug()<<"hello";
        QMessageBox::information(this,"CONNECTED","Connecté");
         ui->gestionemployes_2->setCurrentIndex(1);

    }
    else {
        QMessageBox::warning(this,"INVALID","veuillez entrer un nom d'utilisateur ou un mot de passe valide");
    }
}*/





void MainWindow::on_login_oublie_clicked()
{
    QString identifiant = ui->ide->text();

     QSqlQuery query;
     query.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE IDENTIFIANT=:IDENTIFIANT");
     query.bindValue(":IDENTIFIANT", identifiant);
     query.exec();

     if (query.next()) {
         QString count = query.value(0).toString();
         if (count > 0) {
             // Si le CIN existe, ouvrez Dialog2 pour permettre la modification du mot de passe
             oublie_pwd *oublie_pwd_dialog = new oublie_pwd(identifiant, this);

             oublie_pwd_dialog->exec();
         } else {
             QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                 QObject::tr("IDENTIFIANT N'EXISTE PAS.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
     }
}


void MainWindow::on_gestion_quitter_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(0);

}





void MainWindow::on_pb_ajouterClient_clicked()
{
    QString cinText = ui->le_cinclient->text();
    QString nbPointsFidelitesText = ui->le_nbPointsFidelites->text();
    QDate date_naissance= ui->le_dateclient->date();
    QString prenom=ui->le_prenomclient->text();
    QString mail=ui->le_mailclient->text();
    QString nom= ui->le_nomclient->text();
    QString numText = ui->le_numTelclient->text();

     if (cinText.isEmpty() || nbPointsFidelitesText.isEmpty() || prenom.isEmpty() || mail.isEmpty() || nom.isEmpty() || numText.isEmpty())
         {
             QMessageBox::warning(nullptr, "Champ vide", "Veuillez remplir tous les champs.");
             return;
         }

         QRegularExpression regexmail("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
         QRegularExpressionValidator emailValidator(regexmail, this);
         int pos = 0;
         if (emailValidator.validate(mail, pos) != QValidator::Acceptable)
         {
             QMessageBox::critical(nullptr, "Email incorrect", "Veuillez saisir une adresse email valide.");
             return;
         }

     int CIN=ui->le_cinclient->text().toInt();
     int nb_pointsfidelites=ui->le_nbPointsFidelites->text().toInt();
     int num=ui->le_numTelclient->text().toInt();

    Client C(CIN,nb_pointsfidelites,num,date_naissance,prenom,mail,nom);
     bool test1=C.chercher(CIN);
    if(test1==false)
    {
        bool test=C.ajouter();
    if(test)
    {
        ui->tab_clients->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("success"),
                                 QObject::tr("Ajout effectue\n"
                                            "Click cancel to exit") , QMessageBox::Cancel);
        ui->le_cinclient->clear();
         ui->le_nbPointsFidelites->clear();
         QDate date(2000, 1, 1);
         ui->le_dateclient->setDate(date);
       ui->le_prenomclient->clear();
        ui->le_mailclient->clear();
         ui->le_nomclient->clear();
         ui->le_numTelclient->clear();

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                              QObject::tr("Ajout non effectue\n"
                                         "Click cancel to exit") , QMessageBox::Cancel);
    }
    }
    else if(test1)
    {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                              QObject::tr("Client deja existant\n"
                                         "Click cancel to exit") , QMessageBox::Cancel);
    }

}



void MainWindow::on_pb_supprimerClient_clicked()
{
    Client C;
    C.SetCIN(ui->le_cinclient->text().toInt());
    bool test1 = C.chercher(C.GetCIN());

    if (test1)
    {
        QSqlQuery query;
        query.prepare("SELECT PRENOM, NOM, MAIL, NB_POINTSFIDELITES, NUM FROM CLIENTS WHERE CIN = :CIN");
        query.bindValue(":CIN", C.GetCIN());

        if (query.exec() && query.next())
        {
            QString prenom = query.value(0).toString();
            QString nom = query.value(1).toString();
            QString mail = query.value(2).toString();
            QString nb_points = query.value(3).toString();
            QString num = query.value(4).toString();
            QDate date=query.value(5).toDate();
             ui->le_dateclient->setDate(date);
            QString clientName = prenom + " " + nom;

            QMessageBox msgBox;
           msgBox.setText("Voulez-vous vraiment supprimer le client : " + clientName + " dont les donnees sont les suivants:\n Nombre de points:\n"+nb_points+"\n mail:\n"+mail+"\n Num:\n"+num +"\nDate:\n" + date.toString("dd.MM.yyyy"));
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Cancel);

            int choice = msgBox.exec();
            if (choice == QMessageBox::Ok)
            {
                bool test = C.supprimer(C.GetCIN());
                if (test)
                {
                    ui->tab_clients->setModel(C.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Suppression effectuée"), QMessageBox::Ok);
                }
                else
                {
                    QMessageBox::critical(nullptr, QObject::tr("Échec"), QObject::tr("Échec de la suppression"), QMessageBox::Ok);
                }
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la récupération du nom et du prénom du client"), QMessageBox::Ok);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Client non existant"), QObject::tr("Client non trouvé"), QMessageBox::Ok);
    }
    ui->le_cinclient->clear();
}

void MainWindow::on_pb_EditClient_clicked()
{
    Client C;
    int CIN = ui->le_cinclient->text().toInt();
    QString cin_string = ui->le_cinclient->text();

    QString mail = ui->le_mailclient->text();
QString nom=ui->le_nomclient->text();
QString prenom=ui->le_prenomclient->text();
QDate date=ui->le_dateclient->date();
    QString nb_pointsfidelitesstring = ui->le_nbPointsFidelites->text();

    QString num_string = ui->le_numTelclient->text();

    if (cin_string.isEmpty() && nb_pointsfidelitesstring.isEmpty() && num_string.isEmpty() && mail.isEmpty())
    {
        QMessageBox::information(this, "Aucune modification", "Aucun champ n'a été modifié.");
    }
    if (!cin_string.isEmpty() && nb_pointsfidelitesstring.isEmpty() && num_string.isEmpty() && mail.isEmpty())
    {
        QMessageBox::information(this, "Aucune modification", "Veuillez remplir au moins un autre champs à part le cin.");
    }

    else
    {
        bool test = C.chercher(CIN);
        if (test)
        {
            bool modificationRequise = false;

            if (!nb_pointsfidelitesstring.isEmpty() && nb_pointsfidelitesstring != QString::number(C.getnb_pointsfidelites()))
            {
                int nb_pointsfidelites = nb_pointsfidelitesstring.toInt();
                C.modifierPoints(CIN, nb_pointsfidelites);
                modificationRequise = true;
            }

            if (!num_string.isEmpty() && num_string != QString::number(C.Getnum()))
            {
                int num = num_string.toInt();
                C.modifierNum(CIN, num);
                modificationRequise = true;
            }

            if (!mail.isEmpty())
            {
                QRegularExpression regexmail("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
                QRegularExpressionValidator emailValidator(regexmail, this);
                int pos = 0;
                if (emailValidator.validate(mail, pos) != QValidator::Acceptable)
                {
                    QMessageBox::critical(nullptr, "Email incorrect", "Veuillez saisir une adresse email valide.");
                    return;
                }
                else
                {
                    C.modifierMail(CIN, mail);
                    modificationRequise = true;
                }
            }
            if (!nom.isEmpty() || !prenom.isEmpty() || date != QDate(2000, 1, 1))
            {

                           QMessageBox::critical(nullptr, "ERREUR","Vous avez changé des champs non modifiable (impossible de modifier ni le nom ni le prenom ni la date!), veuillez verifier.");
                           return;
            }
            if (modificationRequise)
            {
                QSqlQuery query;
                query.prepare("SELECT PRENOM, NOM, MAIL, NB_POINTSFIDELITES, NUM,DATE_NAISSANCE FROM CLIENTS WHERE CIN = :CIN");
                query.bindValue(":CIN", CIN);

                if (query.exec() && query.next())
                {
                    QString prenom = query.value(0).toString();
                    QString nom = query.value(1).toString();
                    QString mail = query.value(2).toString();
                    QString nb_points = query.value(3).toString();
                    QString num = query.value(4).toString();
                   QDate date=query.value(5).toDate();
                    ui->le_dateclient->setDate(date);

                    QString clientName = prenom + " " + nom;

                    QMessageBox msgBox;
                    msgBox.setText("Voulez-vous vraiment modifier le client : " + clientName + " dont les données sont les suivantes:\n Nombre de points:\n" + nb_points + "\n mail:\n" + mail + "\n Num:\n" + num + "\nDate:\n" + date.toString("dd.MM.yyyy"));

                    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                    msgBox.setDefaultButton(QMessageBox::Cancel);

                    int choice = msgBox.exec();
                    if (choice == QMessageBox::Ok)
                    {
                QSqlQueryModel *updateModel = C.afficher();
                ui->tab_clients->setModel(updateModel);
                QMessageBox::information(this, "Succès", "Le client a été modifié avec succès.");
                ui->le_cinclient->clear();
                ui->le_mailclient->clear();
                ui->le_nbPointsFidelites->clear();
                ui->le_numTelclient->clear();


                    }
                }
                else
                {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la récupération du nom et du prénom du client"), QMessageBox::Ok);
                }
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Client non existant"), "Impossible de le modifier.");
        }
    }
}

void MainWindow::on_pb_search_clicked()
{
    Client C;
    QString nom=ui->le_chercherclient->text();
    QSqlQueryModel* sortedModel = C.recherchernomc(nom);
    ui->tab_clients->setModel(sortedModel);
}

void MainWindow::on_le_chercherclient_textChanged(const QString &arg1)
{
    Client C;
    QSqlQueryModel* filteredModel = C.rechercher(arg1);
    ui->tab_clients->setModel(filteredModel);
}

void MainWindow::on_tab_clients_activated(const QModelIndex &index)
{
    QString val = index.sibling(index.row(), 0).data().toString();

    QSqlQuery qry;
    Client c;
    qry = c.Edit(val);

    if (qry.exec())
    {
        while (qry.next())
        {
            ui->le_cinclient->setText(qry.value(0).toString());
            ui->le_nbPointsFidelites->setText(qry.value(1).toString());
            QDate date = qry.value(7).toDate();
            ui->le_dateclient->setDate(date);

            ui->le_prenomclient->setText(qry.value(2).toString());
            ui->le_mailclient->setText(qry.value(3).toString());
            ui->le_nomclient->setText(qry.value(4).toString());
            ui->le_numTelclient->setText(qry.value(5).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Couldn't fill.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}
void MainWindow::on_pb_PDFClient_clicked()
{
    QTableView* tableViewc = ui->tab_clients;

    if (!tableViewc)
    {
        QMessageBox::critical(nullptr, "ERREUR", "Table view not found.");
        return;
    }

    QAbstractItemModel* model = tableViewc->model(); 

    if (!model)
    {
        QMessageBox::critical(nullptr, "ERREUR", "Model not found.");
        return;
    }

    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "Clients.pdf", "PDF files (*.pdf)");
    if (filePath.isEmpty())
    {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QTextDocument document;
    QTextCursor cursor(&document);

    // Concatenate the entire HTML content in a QString
    QString htmlContent = "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              "<title>Liste de Clients</title>\n"
                              "<style>"
                              "table {"
                              "   border-collapse: collapse;"
                              "   width: 100%;"
                              "}"
                              "th, td {"
                              "   border: 1px solid #dddddd;"
                              "   text-align: left;"
                              "   padding: 8px;"
                              "}"
                              "th {"
                              "   background-color: #F5B7B1;"
                              "}"
                              "</style>"
                              "</head>\n"
                              "<body bgcolor=#FDFEFE link=#5000A0>\n"
                              "<img src='file:///C:/Users/souai/OneDrive/Desktop/projet c++/Atelier_Connexion/371537865_1198387914453156_6072290607355430941_n.png' alt='Logo' style='float: right; width: 50px; height: auto;'>"
                              "<h1>Liste de Clients</h1>"
                              "<table>\n";   // Removed border, cellspacing, and cellpadding attributes

    htmlContent += "<thead><tr>";
    for (int column = 0; column < columnCount; column++) {
        if (!tableViewc->isColumnHidden(column)) {
            htmlContent += QString("<th>%1</th>").arg(model->headerData(column, Qt::Horizontal).toString());
        }
    }
    htmlContent += "</tr></thead>\n";

    for (int row = 0; row < rowCount; row++) {
        htmlContent += "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!tableViewc->isColumnHidden(column)) {
                QString data = model->data(model->index(row, column)).toString().simplified();
                htmlContent += QString("<td>%1</td>").arg((!data.isEmpty()) ? data : "&nbsp;");
            }
        }
        htmlContent += "</tr>\n";
    }

    htmlContent += "</table>\n"
                   "</body>\n"
                   "</html>\n";

    // Insert the entire HTML content at once
    cursor.insertHtml(htmlContent);

    document.print(&printer);
}





void MainWindow::on_pb_valider_clicked()
{
    Client c;
        if(ui->comboBoxClient->currentIndex()==0){
            ui->tab_clients->setModel(c.trinom());

        }
        else if (ui->comboBoxClient->currentIndex()==1)
        {
            ui->tab_clients->setModel(c.triPoints());

        }
        else if(ui->comboBoxClient->currentIndex()==2)
        {
            ui->tab_clients->setModel(c.triprenom());

        }
        else if(ui->comboBoxClient->currentIndex()==3)
        {
            ui->tab_clients->setModel(c.triDate());
        }
        else
        {

            QMessageBox::critical(nullptr, "ERREUR", "Pas de combox avec cette indice!");
            return;
        }
}

void MainWindow::on_pb_StatClient_clicked()
{
    Dialog d;
   d.afficher();
   d.exec();
}

void MainWindow::on_pb_send_clicked() {
    SMTPClient smtp("smtp.gmail.com", 465, SMTPClient::SslConnection);

     QString username = ui->username->text();
    QString password = ui->password->text();
    QString recipient = ui->rcpt->text();
    QString subject = ui->subject->text();
    QString messageContent = ui->msg->toPlainText();




    smtp.setUser(username);
    smtp.setPassword(password);

    MimeMessage message;

    message.setSender(new EmailAddress(username, "MAIL from SmartFarm"));
    message.addRecipient(new EmailAddress(recipient, "Recipient"));
    message.setSubject(subject);

    MimeText text;
    text.setText(messageContent);
    message.addPart(&text);

    if (smtp.connectToHost()) {
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Connection to host successful.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                              QObject::tr("Failed to connect to host.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    if (smtp.login()) {
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Login successful.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                              QObject::tr("Failed to login.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    if (smtp.sendMail(message)) {
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Mail sent.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                              QObject::tr("Failed to send mail.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    smtp.quit();
}



void MainWindow::on_pb_gererpoints_clicked()
    {
        QSqlQuery query;
        query.prepare("SELECT NB_POINTSFIDELITES, PRENOM, Mail, NOM FROM CLIENTS ORDER BY NB_POINTSFIDELITES DESC ");

        if (query.exec() && query.next())
        {
            QString nom = query.value(3).toString();
            QString prenom = query.value(1).toString();
            int nbPoints = query.value(0).toInt();
            QString gmail=query.value(2).toString();

            if (nbPoints >= 100)
            {
                double montantAchat = 100.0; // Montant de l'achat à titre d'exemple
                double remisePourcentage = 50.0; // 50% de remise
                double remise = montantAchat * (remisePourcentage / 100.0);
                double montantAvecRemise = montantAchat - remise;

                QString codePromo = QString::number(qrand() % ((999999 + 1) - 100000) + 100000);
                 QMessageBox promoDialog;
                            promoDialog.setWindowTitle("Code Promo");
                            promoDialog.setText(QString("Le code promo de %1 %2 est : %3").arg(prenom, nom, codePromo));

                            promoDialog.exec();

                QMessageBox::information(this, "Remise attribuée selon le code de promo",
                                         QString("Le client %1 %2 a atteint %3 points de fidélité. Il bénéficie d'une remise de %4% sur son prochain achat.\n"
                                                 "Montant avec remise : %5")
                                             .arg(prenom, nom, QString::number(nbPoints), QString::number(remisePourcentage), QString::number(montantAvecRemise, 'f', 2)));

                SMTPClient smtp("smtp.gmail.com", 465, SMTPClient::SslConnection);
                smtp.setUser("Your Email");
                smtp.setPassword("Your API Key");

                // Now we create a MimeMessage object. This will be the email.

                MimeMessage message;

                message.setSender(new EmailAddress("Your Email", "MAIL from SmartFarm "));
                message.addRecipient(new EmailAddress(gmail, "FIRAS_TEST"));
                message.setSubject("OFFRE SPECIALES");

                // Now add some text to the email.
                // First we create a MimeText object.

                MimeText text;

                text.setText("I hope this message finds you well. We are happy to inform you that you have a reduction on your next purchase, your codepromo is: "+ codePromo+".Have a nice day!"


                                                                                                                                                                          "Sincerely,\n"

                                                                                                                                                                          "SMART FARM");

                // Now add it to the mail

                message.addPart(&text);
                smtp.quit();

            }
            else
            {
                QMessageBox::information(this, "Pas de remise",
                                         QString("Aucune remise n'est attribuée. Le client %1 %2 n'a pas atteint 100 points de fidélité.").arg(prenom, nom));
            }
        }
        else
        {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération du client avec le nombre maximal de points.");
        }
}
/*void MainWindow::connect_RFID()

{
    data= rfidInstance.read_from_arduino();
    for(int i=0;i<data.length();i++)
    {
        if(data[i]=='D' || data[i]==')')
        {
            qDebug() << "ref= " << ref ;
            if(data[i]=='D')
            {
                Client c; //remplacez avec le nom de votre classe

                 // cas ou elle n'existe
                if(c.rfidExists(ref))
                    {

                        QByteArray data1;
                        data1.append('1');
                        rfidInstance.write_to_arduino("1");//envoie 1 a arduino et enclenche /demarre le processus 1

                        qDebug()<<"carte existante";

                        //prend la valeur du nom
                        QString prenom = c.rfidName(ref);


                        QByteArray nomData(prenom.toUtf8(), 8);
                       rfidInstance.write_to_arduino(nomData);
                       qDebug()<<nomData;


                }
            else
                {
                    //inexistante

                        rfidInstance.write_to_arduino("2"); // envoie 2 a arduino et enclenche /demarre le processus 2

                        qDebug()<<"carte inexistante";

                }
            }
            ref.clear();

        }
        else if(!(data[i]=='\r' || data[i]=='\n'))
        {
             ref=ref+data[i];

        }

    }
}*/

void MainWindow::on_pb_mailing_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(5);

}

void MainWindow::on_pb_chatbox_clicked()
{

    chatbox *chat1= new chatbox;
    chat1->show();
    chatbox *chat2= new chatbox;
    chat2->show();


}

void MainWindow::on_gestionemployes_quitter_1_clicked()
{
     ui->gestionemployes_2->setCurrentIndex(1);
}



void MainWindow::on_login_1_clicked()
{
    QSqlQuery query;
    QString identifiant = ui->ide->text();
    QString pass = ui->mdp->text();

    query.prepare("SELECT statut FROM EMPLOYES WHERE IDENTIFIANT=:IDENTIFIANT AND PASS=:PASS");
    query.bindValue(":IDENTIFIANT", identifiant);
    query.bindValue(":PASS", pass);

    if(identifiant ==""   ||  pass =="")
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("login failed.\n"
                                "vérifier identifiant ou mot de passe .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
    if( query.exec() && query.next())
    {
        ui->gestionemployes_2->setCurrentIndex(1);
        QString statut=query.value(0).toString();
        ui->gestion_A->setDisabled(true);
        ui->gestion_C->setDisabled(true);
        ui->gestion_E->setDisabled(true);
        ui->gestion_F->setDisabled(true);
        ui->gestion_P->setDisabled(true);
        ui->plante->setDisabled(true);
        if (statut.toLower().contains("client"))
        {
            ui->gestion_C->setDisabled(false);
        }
       if (statut.toLower().contains("employee"))
                    {
            ui->gestion_E->setDisabled(false);



        }
        if (statut.toLower().contains("produit"))
                    {
            ui->gestion_P->setDisabled(false);
            ui->plante->setDisabled(false);
        }
        if (statut.toLower().contains("animal"))
                    {
            ui->gestion_A->setDisabled(false);
        }
        if (statut.toLower().contains("plante"))
        {
            ui->plante->setDisabled(false);
        }
    /*else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("login failed.\n"
                                "identifiant ou mot de passe n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }*/}

}
    ui->ide->clear();
    ui->mdp->clear();
}

void MainWindow::on_pb_quitterClient_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(1);
}

void MainWindow::on_pb_retourclient_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(4);
}















/*void MainWindow::on_irrigation_clicked()
{
    A.write_to_arduino("1");
    QSqlQuery query;

    query.prepare("UPDATE PLANTES SET DATE_IRRIGATION = :DATE_IRRIGATION");
    query.bindValue(":DATE_IRRIGATION", QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss"));
    query.exec();
    QSqlQuery query1;
    query1.prepare("SELECT * FROM PLANTES ");

    if (query1.exec()) {
        while (query1.next()) {
            // Récupérer l'ID de la plante
            int plantId = query1.value(0).toInt();

            // Récupérer la valeur actuelle de NBR_FS_IRRIGUEE
            int currentNbr =query1.value(5).toInt();

            // Incrémenter NBR_FS_IRRIGUEE de 1
            int newNbr = currentNbr + 1;

            // Mettre à jour NBR_FS_IRRIGUEE pour la plante actuelle
             QSqlQuery query1;
            query1.prepare("UPDATE PLANTES SET NBR_FS_IRRIGUEE = :NBR_FS_IRRIGUEE WHERE Numero = :Numero;");
           query1.bindValue(":NBR_FS_IRRIGUEE", newNbr);
            query1.bindValue(":Numero", plantId);
            query1.exec();}}
          ui->tab_Plante->setModel(P.afficher());

}*/



void MainWindow::on_ajouter_plante_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(14);
}

void MainWindow::on_afficher_plante_clicked()
{
    ui->tab_plante->setModel(Pl.afficher());
}

void MainWindow::on_supprimer_plante_clicked()
{
    QSqlQuery query;
        query.prepare("SELECT * FROM PLANTES WHERE Numero=:Numero");
        query.bindValue(":Numero",ui->le_Numero_supp_plante->currentText().toInt());
        if (query.exec()) {
                            if(query.next()) {
                ui->le_Numero_supp1_plante->setText(query.value(0).toString());
                ui->le_Type_supp_plante->setText(query.value(1).toString());
                ui->le_Emplacement_supp_plante->setText(query.value(2).toString());
                ui->le_Date_supp1_plante->setText(query.value(3).toString());
                ui->le_Date_supp_plante->setText(query.value(4).toString());
                ui->le_Nbr_supp_plante->setText(query.value(5).toString());
                ui->le_Numero_supp1_plante->setReadOnly(true);
                ui->le_Type_supp_plante->setReadOnly(true);
                ui->le_Emplacement_supp_plante->setReadOnly(true);
                ui->le_Date_supp1_plante->setReadOnly(true);
                ui->le_Date_supp_plante->setReadOnly(true);
                ui->le_Nbr_supp_plante->setReadOnly(true);

                            }}
    ui->gestionemployes_2->setCurrentIndex(15);
}

void MainWindow::on_modifier_plante_clicked()
{
    QSqlQuery query;
        query.prepare("SELECT * FROM PLANTES WHERE Numero=:Numero");
        query.bindValue(":Numero",ui->le_Numero_modif_plante->currentText().toInt());
        if (query.exec()) {
                            if(query.next()) {
                ui->le_Numero_modif1_plante->setText(query.value(0).toString());
                ui->le_Type_modif_plante->setText(query.value(1).toString());
                ui->le_Emplacement_modif_plante->setCurrentText(query.value(2).toString());
                ui->le_Date_modif1_plante->setText(query.value(3).toString());
                ui->le_Date_modif_plante->setText(query.value(4).toString());
                ui->le_Nbr_modif_plante->setText(query.value(5).toString());
                ui->le_Numero_modif1_plante->setReadOnly(true);
                ui->le_Date_modif1_plante->setReadOnly(true);
                ui->le_Date_modif_plante->setReadOnly(true);
                ui->le_Nbr_modif_plante->setReadOnly(true);

                            }}

    ui->gestionemployes_2->setCurrentIndex(16);
}

void MainWindow::on_pb_retour_plante_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(13);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(0);
}

void MainWindow::on_retour1_plante_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(13);
}
void MainWindow::on_retour_modifier_plante_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(0);

}


void MainWindow::on_pb_ajouter_plante_clicked()
{
    int Numero=ui->ali->text().toInt();
     QString Type=ui->le_Type_plante->text();
    QString Emplacement=ui->le_Emplacement_plante->currentText();
     QDate Date_Plantation=ui->le_Date_plante->date();
     Plante P(Numero,Type,Emplacement,Date_Plantation);
     bool test=Pl.ajouter();
     if(test)
     {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("ajout successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_plante->setModel(Pl.afficher());
      }
     else
     {

            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                     QObject::tr("ajout failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void MainWindow::on_pb_supprimer_plante_clicked()
{
     int Numero=ui->le_Numero_supp_plante->currentText().toInt();

      bool test=Pl.Supprimer(Numero);
      if(test)
      {
              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("suppresion successful.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tab_plante->setModel(Pl.afficher());
       }
      else
      {

             QMessageBox::critical(nullptr, QObject::tr("not ok"),
                      QObject::tr("suppresion failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }


}

void MainWindow::on_pb_modifier_plante_clicked()
{
     int Numero=ui->le_Numero_modif_plante->currentText().toInt();
     bool test=Pl.Modifier(Numero);
     if(test)
     {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("modification successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_plante->setModel(Pl.afficher());
      }
     else
     {

            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                     QObject::tr("modification failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void MainWindow::on_le_Numero_supp_plante_currentIndexChanged(const QString &arg1)
{
    QString val=ui->le_Numero_supp_plante->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM PLANTES WHERE Numero='"+val+"'");
        if (query.exec()) {
                            if(query.next()) {
                                ui->le_Numero_supp_plante->setCurrentText(query.value(0).toString());
                ui->le_Numero_supp1_plante->setText(query.value(0).toString());
                ui->le_Type_supp_plante->setText(query.value(1).toString());
                ui->le_Emplacement_supp_plante->setText(query.value(2).toString());
                ui->le_Date_supp1_plante->setText(query.value(3).toString());
                ui->le_Date_supp_plante->setText(query.value(4).toString());
                ui->le_Nbr_supp_plante->setText(query.value(5).toString());
                ui->humidite_2->setText(query.value(6).toString());
                ui->le_Numero_supp1_plante->setReadOnly(true);
                ui->le_Type_supp_plante->setReadOnly(true);
                ui->le_Emplacement_supp_plante->setReadOnly(true);
                ui->le_Date_supp1_plante->setReadOnly(true);
                ui->le_Date_supp_plante->setReadOnly(true);
                ui->le_Nbr_supp_plante->setReadOnly(true);
                ui->humidite_2->setReadOnly(true);

                            }}

}

void MainWindow::on_le_Numero_modif_plante_currentIndexChanged(const QString &arg1)
{
    QString val=ui->le_Numero_modif_plante->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM PLANTES WHERE Numero='"+val+"'");
        if (query.exec()) {
                            if(query.next()) {
                                ui->le_Numero_modif_plante->setCurrentText(query.value(0).toString());
                ui->le_Numero_modif1_plante->setText(query.value(0).toString());
                ui->le_Type_modif_plante->setText(query.value(1).toString());
                ui->le_Emplacement_modif_plante->setCurrentText(query.value(2).toString());
                ui->le_Date_modif1_plante->setText(query.value(3).toString());
                ui->le_Date_modif_plante->setText(query.value(4).toString());
                ui->le_Nbr_modif_plante->setText(query.value(5).toString());
                 ui->humidite->setText(query.value(6).toString());
                ui->le_Numero_modif1_plante->setReadOnly(true);
                ui->le_Date_modif1_plante->setReadOnly(true);
                ui->le_Date_modif_plante->setReadOnly(true);
                ui->le_Nbr_modif_plante->setReadOnly(true);
                ui->humidite->setReadOnly(true);

                            }}

}



void MainWindow::on_plante_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select Numero from plantes");
    query.exec();
    modal->setQuery(query);
     ui->le_Numero_supp_plante->setModel(modal);
     QSqlQueryModel * modal1=new QSqlQueryModel();
     QSqlQuery query12;
     query12.prepare("select Numero from plantes");
     query12.exec();
     modal1->setQuery(query12);
     ui->le_Numero_modif_plante->setModel(modal1);
    ui->gestionemployes_2->setCurrentIndex(13);
}

void MainWindow::on_retour_modfier_plante_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(13);
}




void MainWindow::on_retour_image_produit_2_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(6);
}

void MainWindow::on_retour_image_produit_3_clicked()
{
     ui->gestionemployes_2->setCurrentIndex(1);
}

void MainWindow::on_retour_image_produit_4_clicked()
{
     ui->gestionemployes_2->setCurrentIndex(1);
}
/////////////////////////////////////////////animaux/////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_valider_clicked()
{
    int identifiant=ui->lineEdit_id->text().toInt();
    QString categorie=ui->categorie->currentText();
    float masse=ui->lineEdit_ma->text().toFloat();
    float taille=ui->lineEdit_taille->text().toFloat();
    QString etat=ui->etat->currentText();
    QString ida=ui->IDA->currentText();
    bool vacc;
    if(ui->vacc->currentText()=="oui"){
        vacc=true;
    }
    else{
        vacc=false;
    }
    QDate date=ui->date_vacc->date();
    //controle de saisie
    if(identifiant<100000||identifiant>999999)
    {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("l'identifiant doit contenir 6 chiffres exactement.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_id->setStyleSheet("QLineEdit { border: 2px solid red; }");
          return;
    }
    else {
        ui->lineEdit_id->setStyleSheet("");
    }
    QStringList test = {"malade", "sain"};  bool estDifferent = true;
     foreach (const QString &element, test) {
         if (element == etat) {
             estDifferent = false;
             break;
         }
     }if(estDifferent)
    {

        QMessageBox::critical(nullptr, QObject::tr("problem"),
                    QObject::tr("ajout failed.\n"
                                "vérifier ETAT/etat=malade/sain\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->etat->setStyleSheet("QComboBox { border: 2px solid red; }");

    }
     else {
         ui->etat->setStyleSheet("");
     }


     if (categorie.length() < 3 || categorie.length() > 13){
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("categorie doit contenir minimum 4 lettres et maximum 13 lettres.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
         ui->categorie->setStyleSheet("QComboBox { border: 2px solid red; }");
         return;

     }
     else{
         ui->categorie->setStyleSheet("");
     }

     if (ida.isEmpty()){ QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("ida ne doit pas etre vide .\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
         ui->IDA->setStyleSheet("QComboBox { border: 2px solid red; }");
         return;

     }
     else{
         ui->IDA->setStyleSheet("");
     }







int nbr=0;
    QSqlQuery query;
     query.prepare("SELECT * FROM ANNIMAUX WHERE IDENTIFIANT=:IDENTIFIANT");
     query.bindValue(":IDENTIFIANT",ui->lineEdit_id->text());
     query.exec();

     while(query.next())
     {
         nbr++;
     }
     if(nbr!=0)
     {
         QMessageBox::critical(nullptr, QObject::tr("not ok"),
                     QObject::tr("ajout failed.\n"
                                 "IDENTIFIANT existe deja.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit_id->setStyleSheet("QLineEdit { border: 2px solid red; }");
     }
     else{
    animaux A(identifiant,categorie,masse,taille,etat,ida,vacc,date);
      bool test =A.ajouter();
      if (test)

      {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("ajout effectué.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableauanimaux->setModel(A.afficher());
    }
      else
          QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                      QObject::tr("Ajout non effectué.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}}





void MainWindow::on_pushButton_modifier_clicked()
{
    int identifiant=ui->lineEdit_id->text().toInt();
    QString categorie=ui->categorie->currentText();
    float masse=ui->lineEdit_ma->text().toFloat();
    float taille=ui->lineEdit_taille->text().toFloat();
    QString etat=ui->etat->currentText();
    QString ida=ui->IDA->currentText();
    bool vacc;
    if(ui->vacc->currentText()=="oui"){
        vacc=true;
    }
    else{
        vacc=false;
    }
    QDate date=ui->date_vacc->date();
// controle de saisie
    if(identifiant<100000||identifiant>999999)
    {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("l'identifiant doit contenir 6 chiffres exactement.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_id->setStyleSheet("QLineEdit { border: 2px solid red; }");
          return;
    }
    else {
        ui->lineEdit_id->setStyleSheet("");
    }
    QStringList test = {"malade", "sain"};  bool estDifferent = true;
     foreach (const QString &element, test) {
         if (element == etat) {
             estDifferent = false;
             break;
         }
     }if(estDifferent)
    {

        QMessageBox::critical(nullptr, QObject::tr("problem"),
                    QObject::tr("ajout failed.\n"
                                "vérifier ETAT/etat=malade/sain\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->etat->setStyleSheet("QLineEdit { border: 2px solid red; }");

    }
     else {
         ui->etat->setStyleSheet("");
     }


     if (categorie.length() < 4 || categorie.length() > 13){
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("categorie doit contenir minimum 4 lettres et maximum 13 lettres.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
         ui->categorie->setStyleSheet("QLineEdit { border: 2px solid red; }");
         return;

     }
     else{
         ui->categorie->setStyleSheet("");
     }

     if (ida.isEmpty()){ QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("ida ne doit pas etre vide .\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
         ui->IDA->setStyleSheet("QLineEdit { border: 2px solid red; }");
         return;

     }
     else{
         ui->IDA->setStyleSheet("");
     }










    QSqlQuery query;
       query.prepare("SELECT COUNT(*) FROM ANNIMAUX WHERE IDENTIFIANT=:IDENTIFIANT");
       query.bindValue(":IDENTIFIANT", identifiant);
       query.exec();

       if (query.next()) {
           int count = query.value(0).toInt();
           if (count > 0) {
      animaux a(identifiant,categorie,masse,taille,etat,ida,vacc,date);
      if(a.Modifier(identifiant,categorie,masse,taille,etat,ida,vacc,date)){
          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Modified successfully"), QMessageBox::Cancel);
          ui->tableauanimaux->setModel(a.afficher());
      }
      else{
          QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                      QObject::tr("Modification Failed"), QMessageBox::Cancel);
      }


            }
           else {
                   QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("ID N'EXISTE PAS.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}

    }   }


void MainWindow::on_pushButton_supprimer_clicked()
{
  animaux A1;A1.setidentifiant(ui->lineEdit_supp->text().toInt());
 bool test=A1.supprimer(A1.get_identifiant());
 if (test)
 {
     QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("Suppression effectué avec succés.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tableauanimaux->setModel(An.afficher());
}
 else{
     QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                 QObject::tr("Suppression non effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);}}

void MainWindow::on_pushButton_refresh_clicked()
{
  ui->tableauanimaux->setModel(An.afficher());
}
void MainWindow::on_pb_recherche_ich_clicked()
{



    }

void MainWindow::on_pushButton_trierid_ich_clicked()
{
    animaux E;

    ui->tableauanimaux->setModel(E.tri());

    bool test=E.tri();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("tri effectué. \n"
                                             "click Cancel to exist."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("tri non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_triernom_ich_clicked()
{

        animaux E;

        ui->tableauanimaux->setModel(E.trinom());

        bool test=E.tri();
        if(test){
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("tri effectué. \n"
                                                 "click Cancel to exist."),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("tri non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


}


void MainWindow::on_pushButton_triernom_ich_2_clicked()
{
    animaux E;

    ui->tableauanimaux->setModel(E.tricapacite());

    bool test=E.tri();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("tri effectué. \n"
                                             "click Cancel to exist."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("tri non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QPainter>

void MainWindow::on_pushButton_stat_ich_clicked()
{
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();

        QSqlQueryModel model;
        model.setQuery("SELECT * FROM ANNIMAUX WHERE CATEGORIE='Cheval'");
        int number1 = model.rowCount();
        series->append("Mammifères", number1);
        series->setLabelsVisible(true);
        series->slices().at(0)->setLabel("Mammifères");

        model.setQuery("SELECT * FROM ANNIMAUX WHERE CATEGORIE='Oiseaux'");
        int number2 = model.rowCount();
        series->append("Oiseaux", number2);
        series->setLabelsVisible(true);
        series->slices().at(1)->setLabel("Oiseaux");

        model.setQuery("SELECT * FROM ANNIMAUX WHERE CATEGORIE='Reptiles'");
        int number3 = model.rowCount();
        series->append("Reptiles", number3);
        series->setLabelsVisible(true);
        series->slices().at(2)->setLabel("Reptiles");

        model.setQuery("SELECT * FROM ANNIMAUX WHERE CATEGORIE='Mouton'");
        int number4 = model.rowCount();
        series->append("Amphibiens", number4);
        series->setLabelsVisible(true);
        series->slices().at(3)->setLabel("Amphibiens");
        model.setQuery("SELECT * FROM ANNIMAUX WHERE CATEGORIE='vache'");
        int number5 = model.rowCount();
        series->append("Amphibiens", number5);
        series->setLabelsVisible(true);
        series->slices().at(4)->setLabel("vache");

    int total = number1 + number2 + number3 + number4 + number5;

    QString a = QString("cheval" + QString::number((number1 * 100) / total, 'f', 2) + "%");
    QString b = QString("Oiseaux " + QString::number((number2 * 100) / total, 'f', 2) + "%");
    QString c = QString("Reptiles" + QString::number((number3 * 100) / total, 'f', 2) + "%");
    QString d = QString("mouton" + QString::number((number4 * 100) / total, 'f', 2) + "%");
    QString e = QString("vache" + QString::number((number5 * 100) / total, 'f', 2) + "%");



    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Pourcentage des Animaux selon la Catégorie");
    chart->legend()->setFont(QFont("Arial", 10));


    chart->setBackgroundBrush(QColor("#ffaaff"));

    QtCharts::QChart::AnimationOptions options = QtCharts::QChart::AllAnimations;
    chart->setAnimationOptions(options);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTitleFont(QFont("Arial", 25));
    chartView->resize(1000, 500);
    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);

    chartView->show();
}

#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QImage>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTextDocument>

void MainWindow::on_pb_valider_pdf_clicked()
{
    QString defaultFileName = ui->le_pdf_name->text()+".pdf"; // Default file name
    QString saveFilePath = QFileDialog::getSaveFileName(this, tr("Export PDF"), QDir::homePath() + "/" + defaultFileName, tr("PDF Files (*.pdf)"));

    if (!saveFilePath.isEmpty()) {
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFileName(saveFilePath);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFormat(QPrinter::PdfFormat);

        QPainter painter(&printer);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

        QAbstractItemModel* model = ui->tableauanimaux->model();

        if (model) {
            int rowCount = model->rowCount();
            int columnCount = model->columnCount();

            // Create a QTextDocument to format the data as an HTML table
            QTextDocument doc;
            QTextCursor cursor(&doc);

            // Adjust the font size to make the text larger
            QString tableHtml = "<table style=\"border-collapse: collapse; width: 100%; border: 1px solid black; font-size: 4px;\">";

            // Add table header
            tableHtml += "<tr style=\"background-color: #ccc;\">";
            for (int col = 0; col < columnCount - 2; ++col) { // Exclude the last 2 columns
                QVariant data = model->headerData(col, Qt::Horizontal);
                tableHtml += "<th style=\"border: 1px solid black; padding: 8px;\">" + data.toString() + "</th>";
            }
            tableHtml += "</tr>";

            // Loop through the rows and columns to populate the table
            for (int row = 0; row < rowCount; ++row) {
                tableHtml += "<tr>";
                for (int col = 0; col < columnCount - 2; ++col) { // Exclude the last 2 columns
                    QModelIndex index = model->index(row, col);
                    QVariant data = model->data(index);

                    // Append the data to the table cell with border and adjusted font size
                    tableHtml += "<td style=\"border: 1px solid black; padding: 8px;\">" + data.toString() + "</td>";
                }
                tableHtml += "</tr>";
            }

            tableHtml += "</table>";

            // Set the HTML content for the QTextDocument
            doc.setHtml(tableHtml);

            // Manually scale the painter by a factor of 100
            painter.scale(30.0, 30.0);

            // Render the QTextDocument onto the PDF
            doc.setPageSize(printer.pageRect().size());
            doc.drawContents(&painter);
        }

        painter.end();
    }
}

/*
void MainWindow::on_pb_valider_pdf_clicked()
         {
    QString pdf_name = ui->le_pdf_name->text();
       QString name = "C:/Users/21694/Desktop/trvail/Atelier_Connexion" + pdf_name + ".pdf";


       QPrinter printer;
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName(name);


       printer.setOrientation(QPrinter::Landscape);

       QPainter painter;

       if (!printer.isValid()) {
           qWarning("Failed to create PDF printer. Check the output file path.");
           return;
       }

       if (!painter.begin(&printer)) {
           qWarning("Failed to open file. Is it writable?");
           return;
       }




       QFont titleFont("Arial", 20, QFont::Bold);
       QPen titlePen(Qt::black);
       painter.setFont(titleFont);
       painter.setPen(titlePen);
       painter.drawText(0, 30, printer.width(), 50, Qt::AlignCenter, "Liste des Animaux");


       QFont companyFont("Arial", 16, QFont::Bold);
       QPen companyPen(Qt::black);
       painter.setFont(companyFont);
       painter.setPen(companyPen);
       painter.drawText(0, 70, printer.width(), 50, Qt::AlignCenter, "Application : Boss Abdelli ");


       QDateTime currentDateTime = QDateTime::currentDateTime();
       QString dateTimeString = "Exporté le " + currentDateTime.toString("dd/MM/yyyy à hh:mm:ss");
       QFont dateTimeFont("Arial", 12);
       QPen dateTimePen(Qt::black);
       painter.setFont(dateTimeFont);
       painter.setPen(dateTimePen);
       painter.drawText(0, 110, printer.width(), 30, Qt::AlignCenter, dateTimeString);

       QSqlQuery query;
       qDebug() << query.exec("SELECT * FROM ANNIMAUX");

       if (query.isActive()) {
           const int tableStartX = 50;
           const int tableStartY = 150;
           const int columnWidth = 120;
           const int columnSpacing = 10;
           const int additionalWidthForFournisseur = 80;
           int currentX = tableStartX;
           int currentY = tableStartY;

           QFont headerFont("Arial", 14, QFont::Bold);
           QFont cellFont("Arial", 12);
           QPen headerPen(Qt::black);
           QPen cellPen(Qt::black);

           painter.setFont(headerFont);
           painter.setPen(headerPen);

           // Lignes horizontales entre les rangées
           painter.drawLine(tableStartX, tableStartY, 10 * (columnWidth + columnSpacing) + tableStartX, tableStartY);
           currentY += 30;

           // Draw table headers avec un fond coloré
           painter.setBrush(QColor(200, 200, 200));
           painter.drawRect(tableStartX, tableStartY, 10 * (columnWidth + columnSpacing), 30);
           QStringList headers = {"IDENTIFIANT", "CATEGORIE", "MASSE", "TAILLE", "ETAT", "IDA"};


           currentX = tableStartX;
           currentY += 30;

           painter.setFont(cellFont);
           painter.setPen(cellPen);

           while (query.next()) {
               // Lignes horizontales entre les rangées
               painter.drawLine(tableStartX, currentY, 10 * (columnWidth + columnSpacing) + tableStartX, currentY);
               for (int column = 0; column < 9; ++column) {
                   int columnWidthWithSpacing = (column == 8) ? columnWidth + columnSpacing + additionalWidthForFournisseur : columnWidth + columnSpacing;
                   painter.drawText(currentX, currentY, columnWidthWithSpacing, 20, Qt::AlignCenter, query.value(column).toString());
                   currentX += columnWidthWithSpacing;
               }
               currentY += 20;
               currentX = tableStartX;
           }
       } else {
           qWarning("Failed to execute SQL query.");
       }

       painter.end();
       QMessageBox::information(nullptr, QObject::tr("Exportation_PDF"),
        QObject::tr("Exportation PDF avec succès\n"
             "Click Cancel to exit."), QMessageBox::Ok);
       ui->le_pdf_name->hide();

       ui->pb_valider_pdf->hide();
       ;}*/




void MainWindow::on_pushButton_annuler_ich_clicked()
{
    ui->lineEdit_id->setText("");
    ui->categorie->setCurrentText("");
    ui->lineEdit_ma->setText("");
    ui->lineEdit_taille->setText("");
    ui->etat->setCurrentText("");
    ui->IDA->setCurrentText("");
    ui->lineEdit_id->setStyleSheet("");
    ui->categorie->setStyleSheet("");
    ui->lineEdit_ma->setStyleSheet("");
    ui->lineEdit_taille->setStyleSheet("");
    ui->etat->setStyleSheet("");
    ui->IDA->setStyleSheet("");
    ui->gestionemployes_2->setCurrentIndex(1);
}



void MainWindow::on_pushButton_modifier_2_clicked()
{
    Dialog3 d;
    d.exec();
}

void MainWindow::on_pushButton_modifier_3_clicked()
{
    Dialog4 d1;
    d1.exec();
}

void MainWindow::on_pushButton_stat_ich_2_clicked()
{
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();

        QSqlQueryModel model;
        model.setQuery("SELECT * FROM ANNIMAUX WHERE IDA='Viande'");
        int number1 = model.rowCount();
        series->append("Viande", number1);
        series->setLabelsVisible(true);
        series->slices().at(0)->setLabel("Viande");

        model.setQuery("SELECT * FROM ANNIMAUX WHERE IDA='Graines'");
        int number2 = model.rowCount();
        series->append("Graines", number2);
        series->setLabelsVisible(true);
        series->slices().at(1)->setLabel("Graines");

        model.setQuery("SELECT * FROM ANNIMAUX WHERE IDA='Insectes'");
        int number3 = model.rowCount();
        series->append("Insectes", number3);
        series->setLabelsVisible(true);
        series->slices().at(2)->setLabel("Insectes");

        model.setQuery("SELECT * FROM ANNIMAUX WHERE IDA='Plante'");
        int number4 = model.rowCount();
        series->append("Plante", number4);
        series->setLabelsVisible(true);
        series->slices().at(3)->setLabel("Plante");

    int total = number1 + number2 + number3 + number4;

    QString a = QString("Viande" + QString::number((number1 * 100) / total, 'f', 2) + "%");
    QString b = QString("Graines " + QString::number((number2 * 100) / total, 'f', 2) + "%");
    QString c = QString("Insectes" + QString::number((number3 * 100) / total, 'f', 2) + "%");
    QString d = QString("Plante" + QString::number((number4 * 100) / total, 'f', 2) + "%");



    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Pourcentage des Animaux selon l'IDA");
    chart->legend()->setFont(QFont("Arial", 10));


    chart->setBackgroundBrush(QColor("#ffaaff"));

    QtCharts::QChart::AnimationOptions options = QtCharts::QChart::AllAnimations;
    chart->setAnimationOptions(options);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTitleFont(QFont("Arial", 25));
    chartView->resize(1000, 500);
    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);

    chartView->show();
}

void MainWindow::on_critere_rech_acc_2_textChanged(const QString &arg1)
{
    QString critere=ui->critere_rech_acc->currentText();
    QString rech= ui->critere_rech_acc_2->text();

    if(ui->critere_rech_acc_2->text() == "")
        {
            ui->tableauanimaux->setModel(An.afficher());
        }
        else
        {

              ui->tableauanimaux->setModel(An.chercher(critere,rech));
        }
}

void MainWindow::on_pushButton_annuler_ich_2_clicked()
{
Dialog5 d2;
d2.exec();

}

void MainWindow::on_chatbot_clicked()
{
    chatbot *chat= new chatbot;
    chat->show();
}


void MainWindow::on_gestion_A_clicked()
{
    ui->gestionemployes_2->setCurrentIndex(17);
}
