#include "dialog.h"
#include "ui_dialog.h"
#include<QPieSeries>
#include <QSqlQuery>
#include "client.h"
#include <QChart>
#include <QChartView>
#include <QPieSlice>
#include <QtCharts>
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::afficher()
{
    QSqlQuery query;
    query.prepare("SELECT DATE_NAISSANCE FROM CLIENTS");
    query.exec();


    int countUnder18 = 0;
    int count18to30 = 0;
    int count31to50 = 0;
    int countAbove50 = 0;

    QDate currentDate = QDate::currentDate();

    while (query.next())
    {
        QDate birthdate = query.value("DATE_NAISSANCE").toDate();
        int age = currentDate.year() - birthdate.year();

        // Categorize clients based on age
        if (age < 18) {
            countUnder18++;
        } else if (age <= 30) {
            count18to30++;
        } else if (age <= 50) {
            count31to50++;
        } else {
            countAbove50++;
        }
    }

    // Create a pie chart series:QPieSeries object representing the data points for different age categories (Under 18, 18 to 30, 31 to 50, and Above 50).
    QPieSeries *series = new QPieSeries();
    series->append("Under 18", countUnder18);
    series->append("18 to 30", count18to30);
    series->append("31 to 50", count31to50);
    series->append("Above 50", countAbove50);

    QColor color18to30(50, 205, 50);  // Lime Green
    series->slices().at(1)->setBrush(color18to30);
    series->slices().at(1)->setLabelColor(Qt::black);  // Black label for better visibility

    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible();
        slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(QString::number(slice->percentage(), 'f', 1)));
    }

    // Create a chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Age Statistics of Clients");
    chart->legend()->hide();

    // Create a chart view
    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(420, 300);

    chartView->show();
    //create a QChart object, add series and customize chart properties, and then display it using a QChartView in your application's user interface
}

