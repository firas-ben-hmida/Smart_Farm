#include "connectdialogc.h"
#include "ui_ConnectDialog.h"
#include "chatbox.h"

#include <QDialog>
#include <QString>
#include <QRegExpValidator>
#include <QPushButton>
#include <QMessageBox>

ConnectDialogClass::ConnectDialogClass(QWidget* parent): 
	QDialog(parent),
	ui_dialog(new Ui::ConnectDialogClass)
{
	ui_dialog->setupUi(this);

    QLineEdit* ipLine = ui_dialog->ipLineEdit;
    QString ipAddressRegex = "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])|([0-9a-fA-F]{1,4}:){7}([0-9a-fA-F]{1,4})$";
    QRegExpValidator* ipAddressValidator = new QRegExpValidator(QRegExp(ipAddressRegex), this);
    ipLine->setValidator(ipAddressValidator);
    ipLine->setCursorPosition(0);

    QLineEdit* portLine = ui_dialog->portLineEdit;
    QString portRegex = "^[0-9]{5}$";
    QRegExpValidator* portValidator = new QRegExpValidator(QRegExp(portRegex), this);
    portLine->setValidator(portValidator);
    portLine->setCursorPosition(0);
    QRadioButton *serverRadio = ui_dialog->serverRadioButton;
    serverRadio->setChecked(true);

    connect(ui_dialog->connectButton, &QPushButton::clicked, this, &ConnectDialogClass::connectPressed);


}

ConnectDialogClass::~ConnectDialogClass()
{
	delete ui_dialog;
}


void ConnectDialogClass::connectPressed() {

    bool isServer = ui_dialog->serverRadioButton->isChecked();
    quint16 portAddress = ui_dialog->portLineEdit->text().toUInt();
    QString ipAddress = ui_dialog->ipLineEdit->text();
    QRegularExpression regex("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])|([0-9a-fA-F]{1,4}:){7}([0-9a-fA-F]{1,4})$");
    QRegularExpressionMatch matchip = regex.match(ipAddress);

    if (matchip.hasMatch() && portAddress <= 65535 && portAddress >= 49152) {
        (isServer) ? emit implementServer(ipAddress, portAddress) :emit implementClient(ipAddress, portAddress);
        close();
    }
    else if(!matchip.hasMatch()){
        QMessageBox::information(this, "Invalid IP address", "The IP address entered is in the wrong format. Please enter a valid IP address.");
    }
    else if (portAddress > 65535 || portAddress < 49152) {
        QMessageBox::information(this, "Invalid Port number", "The port address entered is wrong. Please enter a port number between 49152 & 65535");
	}
}
