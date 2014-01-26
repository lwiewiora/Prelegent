#include "server.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <cstdio>
#include <HelloThread.h>

//Konstruktor klasy - Przyjmuje nastepujace parametry
// - QObject *parent    - wskaźnik na obiekt nadrzędny
// - LabelClass * lbl   - wskaznik do obiektu powiaznego z etykieta komunikatow
// - LabelSet * lblSet  - wskaznik do obiektu przechowujacego wskazniki powizane z etykiatemi informacyjnymi.
Server::Server(QObject *parent, LabelClass * lbl, LabelSet * lblSet) :
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),
            this, SLOT(on_newConnection()));

    labelMsg = lbl;
    labelSet = lblSet;
}

//Metoda uruchamia nasluchiwanie serwera na adresie 10.0.2.15 i porcie 10018
void Server::listen()
{
    emit getMessage("Listen Server \n");
    labelMsg->setm_msg("Listen Server");
    server->listen(QHostAddress("10.0.2.15"), 10018);
}

//Metoda wykonywana przy nawiazaniu nowego polaczenia
void Server::on_newConnection()
{
    socket = server->nextPendingConnection();
    if(socket->state() == QTcpSocket::ConnectedState)
    {
        printf("Polaczono.\n");
    }

    connect(socket, SIGNAL(disconnected()),
            this, SLOT(on_disconnected()));
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(on_readyRead()));


}
// Metoda odczytyje dane przychodzace z serwera
void Server::on_readyRead()
{
    while(socket->canReadLine())
    {
        QByteArray ba = socket->readLine();
        if(strcmp(ba.constData(), "!exit\n") == 0)
        {
            socket->disconnectFromHost();
            break;
        }
        printf(">> %s", ba.constData());
        changeLblColor(ba.constData());
    }

}

//Zakonczenie polaczenia
void Server::on_disconnected()
{
    printf("Rozlaczono.\n");
    disconnect(socket, SIGNAL(disconnected()));
    disconnect(socket, SIGNAL(readyRead()));
    socket->deleteLater();
}

//Na podstawie komunikatow zmieniamy aktywnosc kontrolek
void Server::changeLblColor(QString colorName)
{
        //Komunikat - Glosniej
        if(colorName.contains("#0"))
        {
            labelSet->lblLoud->setProperty("color","white");
        }
        //Wylacz komunikat - Glosniej
        else if(colorName.contains("#1"))
        {
            labelSet->lblLoud->setProperty("color","red");
        }
        else if(colorName.contains("#2"))
        {
            labelSet->lblQuit->setProperty("color","white");
        }
        else if(colorName.contains("#3"))
        {
            labelSet->lblQuit->setProperty("color","red");
        }
        else if(colorName.contains("#4"))
        {
            labelSet->lblFast->setProperty("color","white");
        }
        else if(colorName.contains("#5"))
        {
            labelSet->lblFast->setProperty("color","red");
        }
        else if(colorName.contains("#6"))
        {
            labelSet->lblSlow->setProperty("color","white");
        }
        else if(colorName.contains("#7"))
        {
            labelSet->lblSlow->setProperty("color","red");
        }
        else if(colorName.contains("#8"))
        {
            labelSet->lblNext->setProperty("color","white");
        }
        else if(colorName.contains("#9"))
        {
            labelSet->lblNext->setProperty("color","red");
        }
        else
        {
            labelMsg->setm_msg(colorName);
        }
}
