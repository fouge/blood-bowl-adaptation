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
    TableModel* sonModele;
public:
    Equipe(race, int, bool, TableModel*);
    void resetJoueurs();
    std::map<int, std::vector<QStandardItem* >* >* zonesTacle();
};

#endif // EQUIPE_H
