#include "match.h"
#include <iostream>
#include <stdlib.h>



Match::Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2):quiJoue(joueur1), sesTours(16)
{
    //Creation du terrain :
    sonTableauCases = new QStandardItemModel(15, 28);

    Equipe * Equipe1 = new Equipe(raceEquipe1, noEquipe1, true, sonTableauCases);
    Equipe * Equipe2 = new Equipe(raceEquipe2, noEquipe2, false, sonTableauCases);

}

int Match::lancer1D6() //donne un chiffre al�atoire entre 1 et 6
{
    return rand() % 6 + 1;
}

QStandardItemModel* Match::getModel()
{
    return sonTableauCases;
}

//void Match::firstClic(Joueur *unJoueur)
//{
    // on appelle des fonctions qui affichent les caract�ristiques du joueur :


    // Il faut v�rifier le nombre de mouvments possibles !
    //on modifie l'affichage de la case :



    // on enregistre le joueur cliqu�:


//}

//void Match::secondClic(Joueur *unJoueur)
//{
//    //on enregistre les mouvements possibles pour la suite :


//    //on clique sur une case vide
//    //


//}
