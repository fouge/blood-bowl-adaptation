/**
 * \file      match.cpp
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Définition de la classe \b Match
 *
 */

/** \class Match match.h "match.h" */
#include "match.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
// #include <QtWidgets/QSound>


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

/**
 * \brief       Retourne le resultat d'un lancer d'un dé de 6 faces et affiche son resultat dans le panneaux.
 * \details     Tire un nombre aleatoire et renvoie le reste de la division par 6. <br/>Affiche le resultat dans la fenetre.
 * \return      \e int
 */
int Match::lancer1D6() //donne un chiffre aléatoire entre 1 et 6
{
   // QSound* lancerDes = new QSound("sounds/1D6.wav");
    // lancerDes->play();
    srand(time(NULL));
    int de = rand() % 6 + 1;
    saFenetre->updateResultatsDes(de);
    return de;
}


/**
 * \brief       Accesseur du modele du tableau
 * \return      \e TableModel*
 */
TableModel* Match::getModel()
{
    return sonTableauCases;
}

/**
 * \brief       Accesseur du joueur qui doit jouer.
 * \details     Renvoie 0 ou 1 en fonction de l'Equipe qui joue - (Permet de faire des comparaisons avec des bool) <br/> \e false ou 0: bleu en jeu; \e true ou 1: rouge en jeu
 * \return      \e coach
 */
coach Match::getQuiJoue()
{
    return quiJoue;
}

/**
 * \brief       Mutateur du joueur qui doit jouer.
 * \details     \e false : bleu en jeu; \e true : rouge en jeu
 * \param       bool        cote de l'equipe qui joue.
 * \return      \e void
 */
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

/**
 * \brief       Remise des Equipes à 0.
 * \details     ->blitz n'est plus effectue <br/>->passe n'est plus effectuee <br/>->reset des joueurs des deux equipes - permet d'utiliser la methode à chaque tour ( \e Equipe::resetJoueurs() )
 * \return      \e void
 */
void Match::finTour()
{
    setQuiJoue(!quiJoue);
    sonEquipe1->setBlitzEffectue(false);
    sonEquipe2->setBlitzEffectue(false);
    sonEquipe1->setPasseEffectuee(false);
    sonEquipe2->setPasseEffectuee(false);
    sonEquipe1->resetJoueurs();
    sonEquipe2->resetJoueurs();
}

/**
 * \brief       Accesseur de l'Equipe en fonction du cote du joueur
 * \details     Via le cote du joueur: \e Joueur::getCote()
 * \param       bool        cote de l'equipe ou du joueur
 * \return      \e Equipe*
 */
Equipe* Match::getEquipe(bool cote)
{
    if(cote)
        return sonEquipe1;
    else
        return sonEquipe2;
}

/**
 * \brief       Methode appelee lors d'un turnover
 * \details     Parametre en entree correspond à l'action à effectuer  <br/>0 : action non reussi <br/>1 : but pour les bleus <br/>2 : but pour les rouges
 * \todo        Action non implémenté : <br/>3 : limite de 4 min depassé pour le tour en cours
 * \param       int        cote de l'equipe ou du joueur
 * \return      \e void
 */
void Match::turnover(int action)
{

    // 0 : action non reussi
    // 1 : but pour les bleus
    // 2 : but pour les rouges
    // pas encore implémenté :
    // 3 : limite de 4 min depassé
    switch(action)
    {
    case 0: {QMessageBox* alert = new QMessageBox(QMessageBox::Warning, "Turnover!", "Le joueur n'a pas réussi son action, turnover !");
        alert->show();
        break;}
    case 1: {
        // mettre a jour score dans equipe
        // afficher le score
        // remetre les joueurs en place sur le terrain via touchdownEffectue()
        sonEquipe1->setPoints(sonEquipe1->getPoints() + 1);
        saFenetre->updatePoints(sonEquipe1->getPoints(), sonEquipe2->getPoints());
        QMessageBox* alert = new QMessageBox(QMessageBox::Information, "TOUCHDOWN !", "Les bleus marquent un point !");
        alert->show();
        touchdownEffectue();
        break;}
    case 2: {
        sonEquipe2->setPoints(sonEquipe2->getPoints() + 1);
        saFenetre->updatePoints(sonEquipe2->getPoints(), sonEquipe2->getPoints());
        QMessageBox* alert = new QMessageBox(QMessageBox::Information, "TOUCHDOWN !", "Les rouges marquent un point !");
        alert->show();
        touchdownEffectue();
        break;}
    default : std::cout<<"Turnover inconnu"<<std::endl;
    }
    saFenetre->finDeTour();
}


/**
 * \brief       Methode appelee lors d'un touchdown pour remettre les joueurs en position
 * \details     Parametre en entree correspond à l'action à effectuer  <br/>0 : action non reussi <br/>1 : but pour les bleus <br/>2 : but pour les rouges
 * \todo        Cette methode ne fonctionne pas, probleme lors du switch des items
 * \return      \e void
 */
void Match::touchdownEffectue()
{
//    std::vector<Joueur*>::iterator leIt;
//    for(leIt = sonEquipe2->getSesJoueurs()->begin(); leIt != sonEquipe2->getSesJoueurs()->end(); leIt++)
//    {
//        if((*leIt)->getX() != (*leIt)->getItem()->row() || (*leIt)->getY() != (*leIt)->getItem()->column())
//        {
//    leIt = sonEquipe2->getSesJoueurs()->begin();
//        std::cout<<"Joueur deplacé de "<<(*leIt)->getItem()->row()<<","<<(*leIt)->getItem()->column()<<" vers "<<15-(*leIt)->getX()<<","<<28-(*leIt)->getY()<<std::endl;
//        sonTableauCases->switchItems((*leIt)->getItem(), sonTableauCases->item(14-(*leIt)->getX(), 27-(*leIt)->getY()));
//        }
//    }

//    for(leIt = sonEquipe1->getSesJoueurs()->begin(); leIt != sonEquipe1->getSesJoueurs()->end(); leIt++)
//    {
//        sonTableauCases->switchItems((*leIt)->getItem(), sonTableauCases->item((*leIt)->getX(), (*leIt)->getY()));
//    }
}
