#include "client.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <cstdio>


//Konstruktor
Client::Client(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()),
            this, SLOT(on_connected()));
}
//Metoda wywolywana przy polaczeniu z serwerem
void Client::on_connected()
{
    printf("Polaczono");
}

//Metoda umozliwa wyslanie komunikatu tekstowego na serwer.
void Client::Send(QString sendText)
{
    sendText += "\n\0";
    const char *str;
    QByteArray ba;
    ba = sendText.toLatin1();
    str = ba.data();
    socket->write(str);
}

//Metoda laczy sie z serwerem poprzez adres 10.0.2.2 i port 10019
void Client::connectToServer()
{
    socket->connectToHost(QHostAddress("10.0.2.2"), 10019);
}
