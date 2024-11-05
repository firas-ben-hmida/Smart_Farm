#pragma once

#include <QtWidgets/QDialog>

#include "ui_chatbox.h"
#include "connectdialogc.h"
#include "clientclass.h"
#include "serverclass.h"

class chatbox : public QDialog
{
    Q_OBJECT

public:
    chatbox(QWidget *parent = nullptr);
    ~chatbox();


private:
    Ui::chatboxClass ui;
    ConnectDialogClass *connect_dialog;
    QVBoxLayout* mainlayout;
    QWidget* textwidget;
    QLineEdit* lineEdit;
    ClientClass *clientObject;
    ServerClass *serverObject;
    enum textAlign { left = 0, right = 1 };
    int sc = 0;


private slots:
    void on_actionConnect_triggered();
    void sendButtonPressed();

protected slots:
    void client(QString, quint16);
    void server(QString, quint16);
    void printMessage(QString, int);

protected:
    void textUI(QString, textAlign);
};
