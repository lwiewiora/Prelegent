#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <LabelClass.h>
#include <LabelSet.h>

class QTcpServer;
class QTcpSocket;

//Klasa odpowiedzialna za obsluge serwera.
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0, LabelClass * lbl=0,LabelSet * lblSet =0);
    void listen();
    void changeLblColor(QString);
signals:
    void getMessage(QString);
public slots:
    void on_newConnection();
    void on_readyRead();
    void on_disconnected();
private:
    QTcpServer* server;
    QTcpSocket* socket;
    LabelClass * labelMsg;
    LabelSet * labelSet;

};

#endif // SERVER_H
