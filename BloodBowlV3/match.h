#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include "enum.h"
#include "equipe.h"
#include "tablemodel.h"
#include "fenetreprincipale.h"

class FenetrePrincipale;

class Match
{
    TableModel* sonTableauCases;
    int sesTours;
    coach quiJoue;
    Equipe* sonEquipe1, *sonEquipe2;
    FenetrePrincipale* saFenetre;
public:
    Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2, FenetrePrincipale* uneFenetre);
    int lancer1D6();
    TableModel* getModel();
    coach getQuiJoue();
    void setQuiJoue(bool joueur);
    Equipe* getEquipe1();
    Equipe* getEquipe2();
    void finTour();
public slots:
    void turnover(int);
};

#endif // MATCH_H
