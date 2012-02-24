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
    Joueur* sonJoueurDessus;
public:
    Case(int unX, int unY);
    int getLigne();
    int getColonne();
    zone getZone();
    Joueur* getJoueurDessus();
    void setJoueurDessus(Joueur* unJoueur);
};

#endif // CASE_H
