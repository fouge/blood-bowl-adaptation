#ifndef MATCH_H
#define MATCH_H

#include "equipe.h"
#include "case.h"
#include "joueur.h"
#include <vector>

enum coach{joueur1, joueur2};

class Match
{
    std::vector<std::vector<Case*>*>* sonTerrain;
    int sesTours;
    coach quiJoue;
public:
    Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2);
    void afficheTerrain();
    int lancer1D6();
//    void deplacerJoueur(Case uneCase, int mouvementsRestants);
//    void passerBallon(int unId);
//    void botterBallon(Case uneCase);
//    void rebondirBallon(int nRebonds);
//    void bloquerJoueur(int unId);
//    void voirMouvements(Case uneCase, int nMouvements);
//    bool mouvementPossible(Case uneCase);
//    void tacler(int unId);
//    void transmission(int unId);
//    void remiseEnJeuBallon(Case uneCase);
//    void mitemps();
//    void turnover();
//    void nouveauTour();
//    bool sortieZoneTacle(Case caseSortie);
};

#endif // MATCH_H
