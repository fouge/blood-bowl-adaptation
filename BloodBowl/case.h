#ifndef CASE_H
#define CASE_H

#include <QLabel>
#include "joueur.h"

class Joueur;

enum zone{enbut, laterale, engagement};

class Case
{
    int sonX, sonY;
    zone saZone;
    QLabel *sonHerbe, *sonJoueur, *sonBallon;
public:
    Case(int unX, int unY);
    int getLigne();
    int getColonne();
    zone getZone();
    QLabel* getHerbe();
    QLabel* getJoueur();
    Joueur* sonJoueurDessus;

};

#endif // CASE_H
