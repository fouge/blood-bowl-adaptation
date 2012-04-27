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

    std::cout<<"Joueur bleu joue"<<std::endl;

    sonEquipe1 = new Equipe(raceEquipe1, noEquipe1, true, sonTableauCases);
    sonEquipe2 = new Equipe(raceEquipe2, noEquipe2, false, sonTableauCases);

}

int Match::lancer1D6() //donne un chiffre aléatoire entre 1 et 6
{
    return rand() % 6 + 1;
}

TableModel* Match::getModel()
{
    return sonTableauCases;
}
coach Match::getQuiJoue()
{
    return quiJoue;
}
void Match::setQuiJoue(bool joueur)
{
    switch(joueur)
    {
    case 0:{ quiJoue = joueur1;
        break;}
    case 1:{ quiJoue = joueur2;
        break;}
    }
}

void Match::finTour()
{
    setQuiJoue(!quiJoue);

    // reset des mouvements des joueurs :
    if(quiJoue)
    {
        sonEquipe1->resetJoueurs();
    }
    else
    {
        sonEquipe2->resetJoueurs();
    }

}
