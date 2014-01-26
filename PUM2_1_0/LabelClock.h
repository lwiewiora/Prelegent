#ifndef LABELCLOCK_H
#define LABELCLOCK_H

#include "QObject"
#include <QTimer>

// Klasa opisuje obsluge etykiety wyswietlajacej czas oraz przycisku rozpoczynajacego przentacje.
class LabelClock : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString time READ gettime WRITE settime NOTIFY timeChanged)
    Q_PROPERTY(QString btnName READ GetbtnName WRITE setbtnName NOTIFY btnNameChanged)

public :
    LabelClock();
    virtual ~LabelClock();
    //-----------clock
    QTimer * timer;
    QString gettime();
    void settime(QString);
    void run();
    QString getStringTime(int value);
    //-----------btnName
    QString GetbtnName();
    void setbtnName(QString);

signals:

    //-----------clock
    void timeChanged(QString);

    //-----------btnName
    void btnNameChanged(QString);

private :

    //aktualny czas w formcie "0:0:0";
    QString m_time;
    //tekst ktory ma byc wyswietlony na przycisku rozpoczenia/zakonczenia prezetnacji.
    QString m_btnName;
    //aktualna wartosc zegara w ms.
    int value;
    //stan zegara - wlaczony/wylaczony
    bool timerState;

private slots:
    void timerHit();
    void timerStop();
    void timerSet(QString time);

};

#endif // LABELCLOCK_H
