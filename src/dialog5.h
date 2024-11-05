#ifndef DIALOG5_H
#define DIALOG5_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QCalendarWidget>
#include <QToolButton>
#include <QSystemTrayIcon>

namespace Ui {
class Dialog5;
}

class Dialog5 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog5(QWidget *parent = nullptr);
    ~Dialog5();

private slots:
    void chargerDonneesTableau();
   void onCalendarClicked(const QDate &date);
  void onTableItemClicked(QTableWidgetItem *item);

private:
    Ui::Dialog5 *ui;
    QTableWidget *tableWidget;
    QCalendarWidget *calendarWidget;
    QToolButton *prevMonthButton;
    QToolButton *nextMonthButton;
    QSqlQueryModel *model;
    QSystemTrayIcon *trayIcon;
};

#endif // DIALOG5_H
