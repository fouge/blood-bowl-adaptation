#ifndef EQUIPE_H
#define EQUIPE_H

#include "joueur.h"
#include "enum.h"

class Joueur;



class Equipe
{
    race saRace;
    std::vector<Joueur*>* sesJoueurs;
    bool sonCote;
public:
    Equipe(race, int, bool, QStandardItemModel*);
};

#endif // EQUIPE_H
