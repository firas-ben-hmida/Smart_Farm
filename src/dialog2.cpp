#include "dialog2.h"
#include "ui_dialog2.h"
#include <QDebug>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include <QShowEvent>
#include <QSqlQuery>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);

    tableWidget = new QTableWidget(this);
    calendarWidget = new QCalendarWidget(this);
    QDate minDate(2023, 1, 1);
    QDate maxDate(2023, 12, 31);

    calendarWidget->setDateRange(minDate, maxDate);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableWidget);
    layout->addWidget(calendarWidget);
    setLayout(layout);

    // Définir les en-têtes de colonne
    QStringList headerLabels = {"IDENTIFIANT", "CATEGORIE", "MASSE", "TAILLE", "IDA", "VACCINATION", "DATE_TEST"};
    tableWidget->setColumnCount(headerLabels.size());
    tableWidget->setHorizontalHeaderLabels(headerLabels);

    chargerDonneesTableau();

    this->setFixedSize(1000, 1000);

    prevMonthButton = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
    nextMonthButton = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));

    // ... (disconnect and connect logic similar to Dialog1)

    connect(calendarWidget, &QCalendarWidget::clicked, this, &Dialog2::onCalendarClicked);
    connect(tableWidget, &QTableWidget::itemClicked, this, &Dialog2::onTableItemClicked);
}

void Dialog2::chargerDonneesTableau()
{
    qDebug() << "Chargement des données de la table ANNIMAUX...";

    model = new QSqlQueryModel;

    // Requête SQL pour récupérer les colonnes spécifiées de la table ANNIMAUX avec filtre sur VACCINATION = "0"
    QString query = "SELECT IDENTIFIANT, CATEGORIE, MASSE, TAILLE, IDA, VACCINATION FROM ANNIMAUX WHERE VACCINATION = '0'";
    model->setQuery(query);

    if (model->rowCount() > 0) {
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();

        tableWidget->setRowCount(rowCount);
        const int numberOfDays = 3; // Nombre de jours à ajouter

        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < columnCount; ++j) {
                QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(i, j)).toString());
                tableWidget->setItem(i, j, item);
            }

            // Calculer et ajouter la date pour la colonne DATE_TEST
            QDate currentDate = QDate::currentDate().addDays((i + 1) * numberOfDays);
            QTableWidgetItem *dateTestItem = new QTableWidgetItem(currentDate.toString("yyyy-MM-dd"));
            tableWidget->setItem(i, columnCount, dateTestItem);
        }
    } else {
        qDebug() << "Aucune donnée à afficher pour les animaux avec VACCINATION = '0'.";
    }
}



void Dialog2::onCalendarClicked(const QDate &date)
{
    // Gérer l'événement de clic sur le calendrier si nécessaire
}

void Dialog2::onTableItemClicked(QTableWidgetItem *item)
{
    if (item) {
        int row = item->row();
        int col = item->column();

        qDebug() << "Item clicked at row:" << row << ", column:" << col << " with text:" << item->text();

        // Effectuer des actions supplémentaires en fonction de l'élément cliqué si nécessaire
    }
}

Dialog2::~Dialog2()
{
    delete ui;
}

