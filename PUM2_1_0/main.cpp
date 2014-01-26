
#include <QGuiApplication>
#include <QQuickView>
#include <QDebug>
#include <QQuickItem>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include "sailfishapplication.h"
#include "client.h"
#include "Common.h"
#include "server.h"
#include <QThread>
#include "HelloThread.h"
#include <LabelClass.h>
#include <LabelClock.h>
#include <LabelSet.h>


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(Sailfish::createApplication(argc, argv));
    QScopedPointer<QQuickView> view(Sailfish::createView("main.qml"));
    QScopedPointer<QQuickView> viewPage2(Sailfish::createView("pages/SecondPage.qml"));
    //------------------

    //Label do ktorego sa wrzucane komunikaty z serwera (tekstowe)
    LabelClass * lblC = new LabelClass();
    //Label odpowiedzialny za obsługe zegara
    LabelClock * lblClock = new LabelClock();
    //Zbior labeli odpowiedzialny za zmiane stanu etykiet informacyjnych
    LabelSet  * lblSet = new LabelSet();


    //Powiazanie obiektow LabelClass i LabelClock z elementami interfejsu
    view->rootContext()->setContextProperty("LabelClass",lblC);
    view->rootContext()->setContextProperty("LabelClock",lblClock);

    //----------------------
    //Powiazanie obiektow etykiet z elementami interfejsu.
     QObject * lblLoud = view->rootObject()->findChild<QObject*>("lblLoud");
     lblSet->lblLoud = lblLoud;
     QObject * lblQuit = view->rootObject()->findChild<QObject*>("lblQuit");
     lblSet->lblQuit = lblQuit;
     QObject * lblFast = view->rootObject()->findChild<QObject*>("lblFast");
     lblSet->lblFast = lblFast;
     QObject * lblSlow = view->rootObject()->findChild<QObject*>("lblSlow");
     lblSet ->lblSlow = lblSlow;
     QObject * lblNext = view->rootObject()->findChild<QObject*>("lblNext");
     lblSet ->lblNext = lblNext;
    //----------------------
    //Utworzenie obiektu serwera
    Server * s = new Server(0,lblC,lblSet);
    //nasluchiwanie serwera
    s->listen();
    //--------------------

    //Oniekt klasy Common zawierajacej metody
    Common common;

    lblClock->setbtnName("Rozpocznij prezentację");
    lblClock->settime("0:0:0");

    //--------------------

    //Wyszukanie Page z main.qml.
    QObject *itemPage = view->rootObject()->findChild<QObject*>("pol3");

    //----------------------
    //Powiazanie sygnalow ze slotami
    QObject::connect(itemPage, SIGNAL(qmlSignalTimerChange(QString)),lblClock, SLOT(timerSet(QString)));
    QObject::connect(itemPage, SIGNAL(qmlSignal(QString)),&common, SLOT(cppSlot(QString)));
    QObject::connect(itemPage, SIGNAL(qmlSignal(QString)), &common,SLOT(cppDisconect(QString)));
    QObject::connect(itemPage, SIGNAL(qmlSignalStartClock()),lblClock, SLOT(timerStop()));

    //----------------------

    Sailfish::showView(view.data());


    return app->exec();
}



