#include "dialog5.h"
#include "ui_dialog5.h"
#include <QDebug>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include <QShowEvent>
#include <QSqlQuery>
#include <QSystemTrayIcon>

Dialog5::Dialog5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog5)
{
    ui->setupUi(this);
    trayIcon = new QSystemTrayIcon(QIcon("C:/Users/ASUS/Desktop/2A/projet_2A c++/SmartFarm/gfx/notification.jpg"), this);
    trayIcon->setVisible(true);

    tableWidget = new QTableWidget(this);
    calendarWidget = new QCalendarWidget(this);
    QDate minDate(2024, 1, 1);
    QDate maxDate(2024, 12, 31);

    calendarWidget->setDateRange(minDate, maxDate);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableWidget);
    layout->addWidget(calendarWidget);
    setLayout(layout);

    // Définir les en-têtes de colonne
    QStringList headerLabels = {"IDENTIFIANT", "CATEGORIE", "MASSE", "TAILLE", "IDA", "VACCINATION", "JOUR_VACCINATION"};
    tableWidget->setColumnCount(headerLabels.size());
    tableWidget->setHorizontalHeaderLabels(headerLabels);

    chargerDonneesTableau();

    this->setFixedSize(1100, 900);

    connect(calendarWidget, &QCalendarWidget::clicked, this, &Dialog5::onCalendarClicked);
    connect(tableWidget, &QTableWidget::itemClicked, this, &Dialog5::onTableItemClicked);

    QSystemTrayIcon trayIcon(QIcon("C:/Users/ASUS/Desktop/2A/projet c++/integration finale/notification.jpg"));
    trayIcon.setVisible(true);
    QSqlQuery query;
    query.prepare("SELECT IDENTIFIANT, DATE_VACCINATION FROM ANNIMAUX WHERE VACCINATION = '0'");

    if (query.exec()) {
        while (query.next()) {
            int identifiant = query.value(0).toInt();
            QDate dateVaccination = query.value(1).toDate();
            QDate dateNotification = dateVaccination.addDays(-2);
            if (dateNotification == QDate::currentDate()) {
                trayIcon.show();
                trayIcon.showMessage("Alerte Vaccination",
                    "L'animal N°:" + QString::number(identifiant) + " doit être vacciné dans 2 jours.",
                    QSystemTrayIcon::Information, 15000);
            }
        }
    }

}
void Dialog5::chargerDonneesTableau() {
    qDebug() << "Chargement des données de la table ANNIMAUX...";

    model = new QSqlQueryModel;

    QString query = "SELECT IDENTIFIANT, CATEGORIE, MASSE, TAILLE, IDA, VACCINATION, DATE_VACCINATION FROM ANNIMAUX WHERE VACCINATION = '0'";
    model->setQuery(query);

    if (model->rowCount() > 0) {
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();

        tableWidget->setRowCount(rowCount);

        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < columnCount - 1; ++j) {
                QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(i, j)).toString());
                tableWidget->setItem(i, j, item);
            }

            QString dateVaccinationStr = model->data(model->index(i, columnCount - 1)).toString();
            QString jourVaccinationStr = dateVaccinationStr.split("T").first();
            QTableWidgetItem *jourVaccinationItem = new QTableWidgetItem(jourVaccinationStr);
            tableWidget->setItem(i, columnCount - 1, jourVaccinationItem);
        }
    } else {
        qDebug() << "Aucune donnée à afficher pour les animaux avec VACCINATION = '0'.";
    }
}

void Dialog5::onCalendarClicked(const QDate &date) {
    for (int i = 0; i < tableWidget->rowCount(); ++i) {
        QTableWidgetItem *jourVaccinationItem = tableWidget->item(i, tableWidget->columnCount() - 1);
        if (jourVaccinationItem) {
            QDate jourVaccination = QDate::fromString(jourVaccinationItem->text(), "yyyy-MM-dd");
            if (jourVaccination == date) {
                tableWidget->setRowHidden(i, false);
            } else {
                tableWidget->setRowHidden(i, true);
            }
        }
    }
}

void Dialog5::onTableItemClicked(QTableWidgetItem *item) {
    if (item) {
        int row = item->row();
        int col = item->column();
        qDebug() << "Item clicked at row:" << row << ", column:" << col << " with text:" << item->text();
    }
}

Dialog5::~Dialog5() {
    delete ui;
}
