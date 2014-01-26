#ifndef LABELSET_H
#define LABELSET_H

#include <QObject>

//Struktura zawierajaca zbior wskaznikow do etykie informacyjnych
class LabelSet : public QObject
{
    Q_OBJECT

public:
    QObject * lblLoud;
    QObject * lblQuit;
    QObject * lblFast;
    QObject * lblSlow;
    QObject * lblNext;

};
#endif // LABELSET_H
