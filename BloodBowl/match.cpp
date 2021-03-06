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
        sonTableauCases->push_back(new std::vector<Case*>);
}
    // 3) on parcours les vecteurs pour cr�� des cases � l'int�rieur :
    std::vector<std::vector<Case*>*>::iterator itLigne;
    int x(1);
    for(itLigne = sonTableauCases->begin(); itLigne != sonTableauCases->end(); itLigne++)
    {
        for(int i=1; i<16; i++)
        {
            (*itLigne)->push_back(new Case(x,i)); // chaque case a une coordonn�e
        }
        x++;
    }




    //Instanciation des deux �quipes :
    Equipe * Equipe1 = new Equipe(raceEquipe1, noEquipe1, sonTableauCases, true);
    Equipe * Equipe2 = new Equipe(raceEquipe2, noEquipe2, sonTableauCases, false);

}

void Match::afficheTerrain()
{
}

int Match::lancer1D6() //donne un chiffre al�atoire entre 1 et 6
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
    // on appelle des fonctions qui affichent les caract�ristiques du joueur :


    // Il faut v�rifier le nombre de mouvments possibles !
    //on modifie l'affichage de la case :
    std::vector<Case*>::iterator leIt;
    std::vector<Case*>* lesCases = voirMouvementsPossibles(unJoueur->getCase());
    for(leIt = lesCases->begin(); leIt != lesCases->end(); leIt++)
    {
        (*leIt)->getHerbe()->setGraphicsEffect(new QGraphicsColorizeEffect());
    }


    // on enregistre le joueur cliqu�:
    sonJoueurFirstClic = unJoueur;


}

void Match::secondClic(Joueur *unJoueur)
{
    //on enregistre les mouvements possibles pour la suite :
    std::vector<Case*>::iterator leIt;
    std::vector<Case*>* lesCases = voirMouvementsPossibles(unJoueur->getCase());

    if(sonJoueurFirstClic == unJoueur)
    {
        for(leIt = lesCases->begin(); leIt != lesCases->end(); leIt++)
        {
            (*leIt)->getHerbe()->setGraphicsEffect(0);
        }
    }

    //on clique sur une case vide
    //
    // ne fonctionne pas !
    //
    else if(sonJoueurFirstClic != unJoueur && unJoueur->getCase()->getJoueurDessus()==0)
    {
        qApp->aboutQt();
    }

}
