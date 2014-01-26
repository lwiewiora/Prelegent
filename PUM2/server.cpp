#include "server.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <cstdio>
#include "mainwindow.h"
#include "ui_mainwindow.h"


//Konstruktor klasy - Przyjmuje nastepujace parametry
// - QObject *parent      - wskaźnik na obiekt nadrzędny
// - MainWindow * _window - wskaźnik do glownego okna umozliwiajacy wyswietlanie w etykietach
//   przychdzacych komunikatow.
Server::Server(QObject *parent, MainWindow * _window) :
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),
            this, SLOT(on_newConnection()));
    window = _window;
}
//Metoda uruchamia nasluchiwanie serwera na localhost i porcie 10019
void Server::listen()
{
    server->listen(QHostAddress::LocalHost, 10019);
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
        window->ui->textEdit_3->setText(ba.constData());
    }
}
//Zakonczenie polaczenia
void Server::on_disconnected()
{
    printf("Connection disconnected.\n");
    disconnect(socket, SIGNAL(disconnected()));
    disconnect(socket, SIGNAL(readyRead()));
    socket->deleteLater();
}

