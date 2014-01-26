#ifndef LABELCLASS_H
#define LABELCLASS_H

#include <QObject>
#include <QMetaType>

//Klasa sluzaca do obslugi etykiety wyswietlajacej komunikaty serwera.
class LabelClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString msg READ getMsg WRITE setm_msg NOTIFY m_msgChanged)

public :
    LabelClass();
    virtual ~LabelClass();
    //----------- Message
    QString getMsg();
    void setm_msg(QString);

signals:
    void m_msgChanged(QString);

private :
    //komunikat serwera.
    QString m_msg;
};

#endif // LABELCLASS_H
