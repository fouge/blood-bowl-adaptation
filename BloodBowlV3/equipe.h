#ifndef EQUIPE_H
#define EQUIPE_H

#include "joueur.h"
#include "enum.h"

class Joueur;

class TableModel;

class Equipe
{
    race saRace;
    std::vector<Joueur*>* sesJoueurs;
    bool sonCote;
    TableModel* sonModele;
    bool blitzEffectue;
public:
    Equipe(race, int, bool, TableModel*);
    void resetJoueurs();
    std::vector<Joueur*>* getSesJoueurs();
    std::map<int, std::vector<QStandardItem* >* >* zonesTacle();
    void setBlitzEffectue(bool);
};

#endif // EQUIPE_H
