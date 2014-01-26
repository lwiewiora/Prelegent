#ifndef MYCLASS_H
#define MYCLASS_H

#include <QGuiApplication>
#include <QQuickView>
#include <QDebug>
#include <QQuickItem>
#include <QQmlEngine>
#include <QQmlComponent>
#include <sailfishapplication.h>
#include "client.h"
#include "server.h"
#include <LabelClock.h>

//Klasa definiuje metody obsugi klienta.
class Common : public QObject
{
    Client c;
    Q_OBJECT
public slots:
    void cppSlot(const QString &msg)
    {
        c.connectToServer();
        printf("Send \n");
    }
    void cppDisconect (const QString &msg)
    {
        printf("Disconnect \n");
        c.Send(msg);
    }
};

#endif // MYCLASS_H
