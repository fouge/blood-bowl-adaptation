#ifndef EQUIPE_H
#define EQUIPE_H

#include "joueur.h"
#include "case.h"

class Equipe
{
    race saRace;
    std::vector<Joueur*>* sesJoueurs;
public:
    Equipe(race, int, std::vector<std::vector<Case*>*>*);
    Case* getCase(int, int, std::vector<std::vector<Case*>*> *);
};

#endif // EQUIPE_H
