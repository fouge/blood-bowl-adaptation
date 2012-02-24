#ifndef MATCH_H
#define MATCH_H

#include "equipe.h"
#include "case.h"
#include "joueur.h"
#include <vector>

enum coach{joueur1, joueur2};
class Terrain;
class Match
{
    std::vector<std::vector<Case*>*>* sonTableauCases;
    int sesTours;
    coach quiJoue;
    Joueur* sonJoueurFirstClic;
public:
    Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2);
    int lancer1D6();
    std::vector<std::vector<Case*> * >* getTableauCases();
    std::vector<Case*> * voirMouvementsPossibles(Case* uneCase);
    void firstClic(Joueur* unJoueur);
    void secondClic(Joueur* unJoueur);
};

#endif // MATCH_H
