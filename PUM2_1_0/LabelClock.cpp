#include <LabelClock.h>
#include <QQuickView>
#include <sailfishapplication.h>
#include <QTimer>


//Konstruktor
LabelClock ::LabelClock ()
{
    value = 0;
    timerState = false;
    m_btnName = "Rozpocznij prezentację";
}
//Destruktor
LabelClock::~LabelClock()
{

}

//Metdoa zwraca sformatowany czas w postaci 0:0:0
QString LabelClock::gettime()
{
    return m_time;
}
//Metoda uruchamiajaca zegar.
void LabelClock::run()
{

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(timerHit()), Qt::DirectConnection);
    timer ->setInterval(10);
    timer->start();
    timerState = true;

}

//metoda ustawia zadany czas
void LabelClock::settime(QString text)
{
    m_time = text;
    emit timeChanged(m_time);
}
//Metoda wywolywana w czasie odliczenia prze timer zadanego interwalu czasowego
void LabelClock::timerHit()
{
    value -= 10;
    m_time = getStringTime(value);
    settime(m_time);
    if(value <=0)
    {
        this->timerStop();
    }

}
//Metoda konwertuje czas podany w ms na tekst w formacie 0:0:0
QString LabelClock::getStringTime(int setValue)
{
    int x = value /1000;
    QString seconds = QString ::number(x %60);
    x/=60;
    QString minutes = QString ::number(x% 60);
    x/= 60;
    QString hours =QString ::number( x%24);
    QString result =  hours + ":"+minutes+":" + seconds;//QString::number(value);
    return result;
}

//Zatrzyamnie zegara.
void LabelClock::timerStop()
{
    if(timerState)
    {
       timer->stop();
       timerState = false;
       m_btnName = "Rozpocznij prezentację";
       setbtnName(m_btnName);
    }
    else
    {
        m_btnName = " Zakończ prezentację";
        setbtnName(m_btnName);
        run();
    }
}

//Metoda zmiania tekst przycisku rozpoczynajacego prezentacja
void LabelClock::setbtnName(QString name)
{
    m_btnName =name ;
    emit btnNameChanged(name);
}

//Metoda zwraca aktualny tekst przycisku rozpoczynajacego prezentacje
QString LabelClock::GetbtnName()
{
    return m_btnName;
}
//Metoda umozliwa zmiane nastwienia zegara za pomoca przyciskow dostepnych w intefejsie.
void LabelClock::timerSet(QString time)
{
    if(time.contains("TimeUp"))
    {
        value += 15000;
    }
    else if(time.contains("TimeDown") &&  value >0)
    {
        value -= 15000;
    }
    QString result = getStringTime(value);
    this->settime(result);
}
