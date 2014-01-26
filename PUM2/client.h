#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class QTcpSocket;
//Kalasa opisujaca funkcjonalnosc klienta TCP
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    void connectToServer();
    void Send(QString);
signals:

public slots:
    void on_connected();
private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
