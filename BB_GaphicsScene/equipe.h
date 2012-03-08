#ifndef EQUIPE_H
#define EQUIPE_H

#include "joueur.h"
#include "case.h"
#include "enum.h"

class Joueur;
class Case;


class Equipe
{
    race saRace;
    std::vector<Joueur*>* sesJoueurs;
    bool sonCote;
public:
    Equipe(race, int, std::vector<std::vector<Case*>*>*, bool);
    Case* getCase(int, int, std::vector<std::vector<Case*>*> *, bool);
};

#endif // EQUIPE_H
