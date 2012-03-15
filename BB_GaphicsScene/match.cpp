#include "match.h"
#include <iostream>
#include <stdlib.h>


Match::Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2):quiJoue(joueur1), sesTours(16)
{
    //Creation du terrain :
    sonTableauCases = new QStandardItemModel(15, 18, this);

    // 3) on parcours les vecteurs pour créé des cases à l'intérieur :



    //Instanciation des deux équipes :
    Equipe * Equipe1 = new Equipe(raceEquipe1, noEquipe1, sonTableauCases, true);
    Equipe * Equipe2 = new Equipe(raceEquipe2, noEquipe2, sonTableauCases, false);

}

int Match::lancer1D6() //donne un chiffre aléatoire entre 1 et 6
{
    return rand() % 6 + 1;
}

std::vector<std::vector<Case*>*>* Match::getTableauCases()
{
    return sonTableauCases;
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


    // Il faut vérifier le nombre de mouvments possibles !
    //on modifie l'affichage de la case :



    // on enregistre le joueur cliqué:


}

void Match::secondClic(Joueur *unJoueur)
{
    //on enregistre les mouvements possibles pour la suite :


    //on clique sur une case vide
    //


}
