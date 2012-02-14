#include "match.h"
#include <iostream>
#include <stdlib.h>


Match::Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2):quiJoue(joueur1), sesTours(16)
{
    //Creation du terrain :
    // 1) un vecteur (vecteur vertical) contient 26 vecteurs
    // 2) Pour les 26 cases du vecteur, on instancie un vecteur (vecteur en ligne)
    sonTableauCases = new std::vector<std::vector<Case*>*>;
    for(int i=0; i<26; i++)
{
        sonTableauCases->push_back(new std::vector<Case*>); // 2
}
    // 3) on parcours les vecteurs pour créé des cases à l'intérieur :
    std::vector<std::vector<Case*>*>::iterator itLigne;
    int x(1);
    for(itLigne = sonTableauCases->begin(); itLigne != sonTableauCases->end(); itLigne++)
    {
        for(int i=1; i<16; i++)
        {
            (*itLigne)->push_back(new Case(x,i)); // chaque case a une coordonnée
        }
        x++;
    }




    //Instanciation des deux équipes :
    Equipe * Equipe1 = new Equipe(raceEquipe1, noEquipe1, sonTableauCases, true);
    Equipe * Equipe2 = new Equipe(raceEquipe2, noEquipe2, sonTableauCases, false);

    sonTerrain = new Terrain(sonTableauCases, this);
}

void Match::afficheTerrain()
{
}

int Match::lancer1D6() //donne un chiffre aléatoire entre 1 et 6
{
    return rand() % 6 + 1;
}

Terrain* Match::getTerrain()
{
    return sonTerrain;
}

std::vector<Case*>* Match::voirMouvementsPossibles(Case* uneCase)
{
    std::vector<std::vector<Case*>*>::iterator itLigne;
    std::vector<Case*>::iterator itColonne;
    std::vector<Case*>* lesMvtsPossibles = new std::vector<Case*>;
    itLigne = sonTableauCases->begin();
    itLigne += uneCase->getLigne();
    itColonne = (*itLigne)->begin();
    itColonne += uneCase->getColonne();
    lesMvtsPossibles->push_back(*itColonne);
    itColonne--;
    lesMvtsPossibles->push_back(*itColonne);
    itColonne--;
    lesMvtsPossibles->push_back(*itColonne);
    itLigne--;
    itColonne = (*itLigne)->begin();
    itColonne += uneCase->getColonne();
    lesMvtsPossibles->push_back(*itColonne);
    itColonne --;
    lesMvtsPossibles->push_back(*itColonne);
    itColonne --;
    lesMvtsPossibles->push_back(*itColonne);
    itLigne--;
    itColonne = (*itLigne)->begin();
    itColonne += uneCase->getColonne();
    lesMvtsPossibles->push_back(*itColonne);
    itColonne--;
    lesMvtsPossibles->push_back(*itColonne);
    itColonne--;
    lesMvtsPossibles->push_back(*itColonne);
    return lesMvtsPossibles;
}

void Match::firstClic(Joueur *unJoueur)
{
    // on appelle des fonctions qui affichent les caractéristiques du joueur :


    //on sauvegarde le joueur cliqué :
    sonJoueurFirstClic = unJoueur;

}

void Match::secondClic(Joueur *unJoueur)
{



}
