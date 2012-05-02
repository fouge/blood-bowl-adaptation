#include "match.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QApplication>
#include <QMessageBox>


Match::Match(race raceEquipe1, int noEquipe1, race raceEquipe2, int noEquipe2, FenetrePrincipale* uneFenetre):quiJoue(joueur1), sesTours(16), saFenetre(uneFenetre)
{
    //Creation du terrain :
    sonTableauCases = new TableModel(15, 28);

    for(int i(0); i<15; i++)
    {
        for (int j(0); j<28; j++)
        {
            sonTableauCases->setItem(i, j, new QStandardItem());
            sonTableauCases->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
            sonTableauCases->item(i,j)->setData(QVariant(false), 45);
        }
    }

    std::cout<<"Joueur bleu joue"<<std::endl;

    sonEquipe1 = new Equipe(raceEquipe1, noEquipe1, true, sonTableauCases);
    sonEquipe2 = new Equipe(raceEquipe2, noEquipe2, false, sonTableauCases);

    sonTableauCases->setEquipes(sonEquipe1, sonEquipe2);

}

int Match::lancer1D6() //donne un chiffre aléatoire entre 1 et 6
{
    srand(time(NULL));
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
    sonEquipe1->setBlitzEffectue(false);
    sonEquipe2->setBlitzEffectue(false);
    sonEquipe1->resetJoueurs();
    sonEquipe2->resetJoueurs();
}

Equipe* Match::getEquipe1()
{
    return sonEquipe1;
}

Equipe* Match::getEquipe2()
{
    return sonEquipe2;
}

void Match::turnover(int action)
{

    // 0 : action non reussi
    // 1 : but
    // pas encore implémenté :
    // 2 : limite de 4 min depassé
    switch(action)
    {
    case 0: {QMessageBox* alert = new QMessageBox(QMessageBox::Warning, "Turnover!", "Le joueur n'a pas réussi son action, turnover !");
        alert->show();
        break;}
    case 1: {QMessageBox* alert = new QMessageBox(QMessageBox::Information, "Turnover!", "Buuuut !");
        alert->show();
        break;}
    default : std::cout<<"Turnover inconnu"<<std::endl;
    }
    saFenetre->finDeTour();
}
