#ifndef MATCH_H
#define MATCH_H

#include "equipe.h"
#include "case.h"
#include "joueur.h"
#include <vector>
#include "terrain.h"

enum coach{joueur1, joueur2};
class Terrain;
class Match
{
    std::vector<std::vector<Case*>*>* sonTableauCases;
    int sesTours;
    coach quiJoue;
    Terrain* sonTerrain;
public:
    Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2);
    void afficheTerrain();
    int lancer1D6();
    Terrain* getTerrain();
    std::vector<Case*> * voirMouvementsPossibles(Case* uneCase);
//    void deplacerJoueur(Case uneCase, int mouvementsRestants);
//    void passerBallon(int unId);
//    void botterBallon(Case uneCase);
//    void rebondirBallon(int nRebonds);
//    void bloquerJoueur(int unId);
//    void voirMouvements(Case uneCase, int nMouvements);

//    void tacler(int unId);
//    void transmission(int unId);
//    void remiseEnJeuBallon(Case uneCase);
//    void mitemps();
//    void turnover();
//    void nouveauTour();
//    bool sortieZoneTacle(Case caseSortie);
};

#endif // MATCH_H
