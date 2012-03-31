#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include "enum.h"
#include "equipe.h"
#include <QStandardItemModel>

class Match
{
    QStandardItemModel* sonTableauCases;
    int sesTours;
    coach quiJoue;
    // Joueur* sonJoueurFirstClic;
public:
    Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2);
    int lancer1D6();
    QStandardItemModel* getModel();
    //void firstClic(Joueur* unJoueur);
    //void secondClic(Joueur* unJoueur);
};

#endif // MATCH_H
