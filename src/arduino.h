#ifndef ARDUINO_H
#define ARDUINO_H

#include <QAbstractItemModel>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<QObject>

class arduino : public QObject
{
    Q_OBJECT

public:
    arduino();
    int connect_arduino(); // permet de connecter le PC à Arduino

        int close_arduino(); // permet de femer la connexion


        QSerialPort* getserial();

        QString getarduino_port_name();

        QByteArray read_from_arduino();
        int write_to_arduino( QByteArray d);


private:
        QSerialPort* serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.) //et des fonctions (envo, lecture de réception,-) sur ce qu'est une voie série pour Arduino.

        static const quint16 arduino_uno_vendor_id=9025;

        static const quint16 arduino_uno_producy_id=67;

        QString arduino_port_name;

        bool arduino_is_available;

        QString SerialBuffer;
        QByteArray SerialData="";

        QByteArray data; // contenant les données lues à partir d'Arduino
};

#endif // ARDUINO_H
