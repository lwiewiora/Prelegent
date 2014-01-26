#include <LabelClass.h>
#include <QQuickView>
#include <sailfishapplication.h>

//Konstruktor
LabelClass ::LabelClass ()
{}
//Destruktor
LabelClass::~LabelClass()
{}

//Metoda zwracjaca komunikat serwera.
QString LabelClass::getMsg()
{
    return m_msg;
}

//Metoda umozliwiajca przypisanie komunikatu do zmiennej i wsylanie sygnalu zmieniajcego
//tekst etykiety.
void LabelClass::setm_msg(QString text)
{
    m_msg = text;
    emit m_msgChanged(text);
}

