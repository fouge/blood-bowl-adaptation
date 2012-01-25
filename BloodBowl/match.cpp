#include "match.h"
#include <iostream>
#include <stdlib.h>


Match::Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2):quiJoue(joueur1), sesTours(16)
{
    //Creation du terrain :
    // 1) un vecteur (vecteur vertical) contient 26 vecteurs
    // 2) Pour les 26 cases du vecteur, on instancie un vecteur (vecteur en ligne)
    sonTerrain = new std::vector<std::vector<Case*>*>;
    for(int i=0; i<26; i++)
{
        sonTerrain->push_back(new std::vector<Case*>); // 2
}
    // 3) on parcours les vecteurs pour créé des cases à l'intérieur :
    std::vector<std::vector<Case*>*>::iterator itLigne;
    int x(1);
    for(itLigne = sonTerrain->begin(); itLigne != sonTerrain->end(); itLigne++)
    {
        for(int i=1; i<16; i++)
    {
            (*itLigne)->push_back(new Case(x,i)); // chaque case a une coordonnée
    }
        x++;
    }




    //Instanciation des deux équipes :
    Equipe * Equipe1 = new Equipe(raceEquipe1, noEquipe1, sonTerrain);
    Equipe * Equipe2 = new Equipe(raceEquipe2, noEquipe2, sonTerrain);



}

void Match::afficheTerrain()
{
    std::vector<std::vector<Case*>*>::iterator itLigne;
    std::vector<Case*>::iterator itColonne;
    for(itLigne = sonTerrain->begin(); itLigne != sonTerrain->end(); itLigne++)
    {
        for(itColonne = (*itLigne)->begin(); itColonne != (*itLigne)->end(); itColonne++)
        {
            std::cout<<'('<<(*itColonne)->getLigne()<<','<<(*itColonne)->getColonne()<<')'<<(*itColonne)->getZone();
        }
        std::cout<<std::endl;
    }
}

int Match::lancer1D6()
{
    return rand() % 6 + 1;
}
