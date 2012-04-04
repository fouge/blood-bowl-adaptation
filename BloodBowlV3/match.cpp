#include "match.h"
#include <iostream>
#include <stdlib.h>



Match::Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2):quiJoue(joueur1), sesTours(16)
{
    //Creation du terrain :
    sonTableauCases = new TableModel(15, 28);

    for(int i(0); i<15; i++)
    {
        for (int j(0); j<28; j++)
        {
            sonTableauCases->setItem(i, j, new QStandardItem());
            sonTableauCases->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
            sonTableauCases->item(i,j)->setData(QVariant(false), 46);
        }
    }


    Equipe * Equipe1 = new Equipe(raceEquipe1, noEquipe1, true, sonTableauCases);
    Equipe * Equipe2 = new Equipe(raceEquipe2, noEquipe2, false, sonTableauCases);

}

int Match::lancer1D6() //donne un chiffre aléatoire entre 1 et 6
{
    return rand() % 6 + 1;
}

TableModel* Match::getModel()
{
    return sonTableauCases;
}

//void Match::firstClic(Joueur *unJoueur)
//{
    // on appelle des fonctions qui affichent les caractéristiques du joueur :


    // Il faut vérifier le nombre de mouvments possibles !
    //on modifie l'affichage de la case :



    // on enregistre le joueur cliqué:


//}

//void Match::secondClic(Joueur *unJoueur)
//{
//    //on enregistre les mouvements possibles pour la suite :


//    //on clique sur une case vide
//    //


//}
