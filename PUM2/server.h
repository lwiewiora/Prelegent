#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "mainwindow.h"
#include <qmainwindow.h>

class QTcpServer;
class QTcpSocket;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0, MainWindow * _window = 0);
    void listen();
signals:

public slots:
    void on_newConnection();
    void on_readyRead();
    void on_disconnected();
private:
    QTcpServer* server;
    QTcpSocket* socket;
    MainWindow * window;
};

#endif // SERVER_H
