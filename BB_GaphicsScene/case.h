#ifndef CASE_H
#define CASE_H

#include <QLabel>
#include "ballon.h"
#include "joueur.h"
#include "enum.h"

class Ballon;
class Joueur;



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
    void setBallonDessus(Ballon* unBallon);
};

#endif // CASE_H
