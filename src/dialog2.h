#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QCalendarWidget>
#include <QToolButton>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private slots:
    void chargerDonneesTableau();
   void onCalendarClicked(const QDate &date);
  void onTableItemClicked(QTableWidgetItem *item);

private:
    Ui::Dialog2 *ui;
    QTableWidget *tableWidget;
    QCalendarWidget *calendarWidget;
    QToolButton *prevMonthButton;
    QToolButton *nextMonthButton;
    QSqlQueryModel *model;
};

#endif // DIALOG2_H
