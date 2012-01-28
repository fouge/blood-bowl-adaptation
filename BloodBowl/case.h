#ifndef CASE_H
#define CASE_H

#include <QLabel>

enum zone{enbut, laterale, engagement};

class Case
{
    int sonX, sonY;
    int leIdDessus;
    zone saZone;
    QLabel *sonHerbe, *sonJoueur, *sonBallon;
public:
    Case(int unX, int unY);
    int getLigne();
    int getColonne();
    zone getZone();
    QLabel* getHerbe();
};

#endif // CASE_H
