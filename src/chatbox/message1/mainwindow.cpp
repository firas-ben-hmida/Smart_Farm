#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include"DuMesengerConnectionDialog.h"
#include <QPrinter>
#include <QPainter>
#include<QIntValidator>
#include<QSqlQuery>
#include <QMessageBox>
#include <QtSvg/QSvgRenderer>
#include <QFileDialog>
using namespace DuarteCorporation;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    widget w;
    w.exec();
}
