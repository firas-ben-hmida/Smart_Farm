#include "chatbox.h"
#include "connectdialogc.h"
#include "mymessage.h"

chatbox::chatbox(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    connect(ui.sendButton, &QPushButton::pressed, this, &chatbox::sendButtonPressed);
    ui.sendButton->setEnabled(false);
    connect_dialog = new ConnectDialogClass(this);
    connect(connect_dialog, &ConnectDialogClass::implementServer, this, &chatbox::server);
    connect(connect_dialog, &ConnectDialogClass::implementClient, this, &chatbox::client);
    lineEdit = ui.sentText;
    textwidget = ui.scrollwidget;
    mainlayout = new QVBoxLayout(textwidget);
    mainlayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

chatbox::~chatbox()
{
    delete connect_dialog;
    delete mainlayout;
    delete textwidget;
    delete lineEdit;
}

void chatbox::on_actionConnect_triggered() {

    connect_dialog->setWindowFlags(connect_dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect_dialog->setModal(true);
    connect_dialog->show();
}

void chatbox::sendButtonPressed() {
    sc!=0 ? clientObject->sendMessage(lineEdit->text()): serverObject->sendMessage(lineEdit->text());
    textUI(lineEdit->text(), right);
    lineEdit->clear();
}

void chatbox::printMessage(QString msg, int val) {
    val!=0 ? textUI(msg, right): textUI(msg, left);
}

void chatbox::client(QString ipAddress, quint16 portAddress) {
    sc = 1;
    ui.sendButton->setEnabled(false);
    clientObject = new ClientClass(this);
    if (clientObject->connectToServer(ipAddress, portAddress)) {
        connect(clientObject, &ClientClass::messageReceived, this, &chatbox::printMessage);
        textUI("Connected to the server", right);
        clientObject->sendMessage("Connected to the client");
        ui.sendButton->setEnabled(true);
    }
    else {
        textUI("Failed to connect to the server", right);
    }
}

void chatbox::server(QString ipAddress, quint16 portAddress) {
    sc = 0;
    ui.sendButton->setEnabled(false);
    textUI("Waiting for client...", right);
    serverObject = new ServerClass(this);
    if (serverObject->startServer(ipAddress, portAddress)) {
        connect(serverObject, &ServerClass::messageReceived, this, &chatbox::printMessage);
        ui.sendButton->setEnabled(true);
    }
    else {
        textUI("Failed to connect to the client", right);
    }
}
void chatbox::textUI(QString text, textAlign var) {

    QHBoxLayout* layout = new QHBoxLayout();

    if (var == right) {
        layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
        layout->addWidget(new MyMessage(text));
    }
    else if (var == left) {
        layout->addWidget(new MyMessage(text));
        layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    }

    mainlayout->addLayout(layout);
}
