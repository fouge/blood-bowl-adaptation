/**
 * \file      equipe.cpp
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     D�finition de la classe \b Equipe
 *
 */

/** \class Equipe Equipe.h "equipe.h" */
#include "equipe.h"

#include "joueur.h"
#include <iostream>
#include <QtWidgets/QApplication>

Equipe::Equipe(race uneRace, int uneComposition, bool cote, TableModel* unModele):sesPoints(0), saRace(uneRace), sonCote(cote), sonModele(unModele), blitzEffectue(false), passeEffectuee(false), sonNoTour(0)
{

    Joueur* leJoueurModele = new Joueur(unModele);
//competences :
//esquive, reception, dexterite, passe, blocage, perso,
//cerveaulent, chataigne, crane, epais, lancercoequipier,
//minus, poidsplume, grosdebile, regeneration, toujoursaffame
    std::vector<competences>* lesCompetencesReceveurs = new std::vector<competences>();
    lesCompetencesReceveurs->push_back(esquive);
    lesCompetencesReceveurs->push_back(reception);

    std::vector<competences>* lesCompetencesPasseurs = new std::vector<competences>();
    lesCompetencesPasseurs->push_back(dexterite);
    lesCompetencesPasseurs->push_back(passe);

    std::vector<competences>* lesCompetencesBlitzeurs = new std::vector<competences>();
    lesCompetencesBlitzeurs->push_back(blocage);

    std::vector<competences>* lesCompetencesOgres = new std::vector<competences>();
    lesCompetencesOgres->push_back(perso);
    lesCompetencesOgres->push_back(cerveauLent);
    lesCompetencesOgres->push_back(chataigne);
    lesCompetencesOgres->push_back(craneEpais);
    lesCompetencesOgres->push_back(lancerCoequipier);

    std::vector<competences>* lesCompetencesGobelins = new std::vector<competences>();
    lesCompetencesGobelins->push_back(esquive);
    lesCompetencesGobelins->push_back(minus);
    lesCompetencesGobelins->push_back(poidsPlume);

    std::vector<competences>* lesCompetencesTroll = new std::vector<competences>();
    lesCompetencesTroll->push_back(perso);
    lesCompetencesTroll->push_back(chataigne);
    lesCompetencesTroll->push_back(grosDebile);
    lesCompetencesTroll->push_back(lancerCoequipier);
    lesCompetencesTroll->push_back(regeneration);
    lesCompetencesTroll->push_back(toujoursAffame);


    std::vector<competences>* AucuneCompetence = new std::vector<competences>();


    sesJoueurs = new std::vector<Joueur*>();

    if(saRace == humains)
        {
            sesJoueurs = new std::vector<Joueur*>();
            switch(uneComposition)
            {
            case 0:
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Leo Ulman", 13, 3, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Baldric Advar", 11, 8, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Bertolf Valdred", 13, 13, sonCote));
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Leo Ulman", 5, 8, sonCote));
                sesJoueurs->push_back(new Joueur(receveur, (lesCompetencesReceveurs), 8, 2, 3, 7, "Otto Meinard", 12, 2, sonCote));
                sesJoueurs->push_back(new Joueur(receveur, (lesCompetencesReceveurs), 6, 3, 3, 8, "Edgar Le Couard", 12, 14, sonCote));
                sesJoueurs->push_back(new Joueur(ogre, (lesCompetencesOgres), 8, 2, 3, 7, "Maxime Girard", 14, 8, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Boris Le Destructeur", 13, 6, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Griswold L'Affreux", 14, 7, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Karl Le Troubadour", 14, 9, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Hob le Bel",13, 10, sonCote));
                break;
            case 1:
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Hans Flick", 5, 5, sonCote));
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Gothard Seppel", 5, 11, sonCote));
                sesJoueurs->push_back(new Joueur(receveur, (lesCompetencesReceveurs), 8, 2, 3, 7, "Bertolf Gottlob", 12, 2, sonCote));
                sesJoueurs->push_back(new Joueur(receveur, (lesCompetencesReceveurs), 8, 2, 3, 7, "Mordred Wilfried", 12, 14, sonCote));
                sesJoueurs->push_back(new Joueur(ogre, (lesCompetencesOgres), 5, 5, 2, 9, "Aggrut Devis-Tete", 14, 8, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 7, 3, 3, 8, "Gerhart Leopold",14, 3, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Hector le Bavard", 14, 6, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Admmund le Droit", 14, 7, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Davion le Verteux", 14, 9, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Viggo le Buveur", 14, 10, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Fracist le Gros", 14, 13, sonCote));
                break;
            case 2:
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Jacob von Altdorf",5, 5, sonCote));
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Fat Mittbrot", 5, 11, sonCote));
                sesJoueurs->push_back(new Joueur(receveur, (lesCompetencesReceveurs), 8, 2, 3, 7, "Fast Ben Jansen", 12, 2, sonCote));
                sesJoueurs->push_back(new Joueur(receveur, (lesCompetencesReceveurs), 8, 2, 3, 7, "Gregor Meissen", 12, 14, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Sebastien Chabal", 13, 3,  sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Christiano Ronaldo", 13, 5,  sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Cyril Fougeray", 13, 11,  sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Johnny Boy",13, 13,  sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Bobby Marley",14, 7,  sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 6, 3, 3, 8, "Skrillex", 14, 9,  sonCote));
                sesJoueurs->push_back(new Joueur(ogre, (lesCompetencesOgres), 5, 5, 2, 9, "Zugg", 14, 8,  sonCote));
                break;

            default: ;
            }
        }

        if(saRace == orques)
        {
            switch(uneComposition)
            {
            case 0:
            {
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Aznok", 5 , 8, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Globrotta Casse'Main", 14 , 6, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Ulgrot Mange'Coeur", 14 , 7, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Ugluk Mange'tete", 14 ,9, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Ugroth Casse'Crane", 14 , 10, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Mug-guzzla", 12 , 2, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Ugglut Gutlug", 13 , 3, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Flashgit-Stompfoot", 13 , 13, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Roglut-Zigzagga", 12 , 14, sonCote));
                sesJoueurs->push_back(new Joueur(gobelin, (lesCompetencesGobelins), 6, 2, 3, 7, "Kursh", 11 , 5, sonCote));
                sesJoueurs->push_back(new Joueur(gobelin, (lesCompetencesGobelins), 6, 2, 3, 7, "Molgor", 11 , 11, sonCote));

                break;
            }
            case 1:
            {
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Gorfang MangeTaTete", 14 , 6, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Grubak Broye'main", 14 , 10, sonCote));
                sesJoueurs->push_back(new Joueur(gobelin, (lesCompetencesGobelins), 6, 2, 3, 7, "Makefile", 11 , 5, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Grogu Grintouf", 13 , 3, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gutnok", 13 , 13, sonCote));
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Muchteef-slogga", 5 , 8, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Stilaz", 11 , 8, sonCote));
                sesJoueurs->push_back(new Joueur(gobelin, (lesCompetencesGobelins), 6, 2, 3, 7, "Makedir", 11 , 11, sonCote));
                sesJoueurs->push_back(new Joueur(troll, (lesCompetencesTroll), 6, 2, 3, 7, "Powed", 14 , 8, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 5, 3, 3, 9, "Ragzag", 14 , 7, sonCote));
                sesJoueurs->push_back(new Joueur(troisquarts, (AucuneCompetence), 5, 3, 3, 9, "Lugnub", 14 , 9, sonCote));

                break;
            }
            case 2:
            {
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Crase'Cerveau", 14 , 6, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Ecari'seur", 14 , 7, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Crase'Main", 14, 9, sonCote));
                sesJoueurs->push_back(new Joueur(bloqueur, (AucuneCompetence), 4, 4, 2, 9, "Gobfang", 14, 10, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Flatfoot", 13, 3, sonCote));
                sesJoueurs->push_back(new Joueur(blitzeur, (lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gutslop", 13, 13, sonCote));
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Tokber", 5 , 5, sonCote));
                sesJoueurs->push_back(new Joueur(passeur, (lesCompetencesPasseurs), 6, 3, 3, 8, "Krolor", 5 , 11, sonCote));
                sesJoueurs->push_back(new Joueur(gobelin, (lesCompetencesGobelins), 6, 2, 3, 7, "Taksh", 12 , 2, sonCote));
                sesJoueurs->push_back(new Joueur(gobelin, (lesCompetencesGobelins), 6, 2, 3, 7, "Weeit", 12 , 14, sonCote));
                sesJoueurs->push_back(new Joueur(troll, (lesCompetencesTroll), 6, 2, 3, 7, "Trak'k", 14 , 8, sonCote));
                break;
            }
            default: ;
            }
        }
    }

/**
 * \brief       Fait un reset des joueurs en fin de tour
 * \details     Chaque joueur est caract�ris� sur le jeu par un item. Cette methode permet de remettre les items dans leur etat de debut de tour.
 *               <br/> -> remise des mouvements des joueurs
 *               <br/> -> l'action et le blocage du joueur n'est plus dans l'etat \e "effectue"
 * \return      \e std::map<int, std::vector<QStandardItem * > * >*
 */
void Equipe::resetJoueurs()
{
    std::vector<Joueur*>::iterator leIt;
    for(leIt = sesJoueurs->begin(); leIt != sesJoueurs->end(); leIt++)
    {
        //on remet les mouvements des joueurs
        (*leIt)->getItem()->setData(QVariant((*leIt)->getMouvements()), 35);
        //l'action du joueur n'est pas effectu�e :
        (*leIt)->getItem()->setData(QVariant(false), 34);
        // remise a z�ro mouvement et blocage
        (*leIt)->getItem()->setData(QVariant(false), 46);
        (*leIt)->getItem()->setData(QVariant(false), 47);
    }
    setBlitzEffectue(false);
}


/**
 * \brief       Permet d'avoir tous les items en zone de tacle tries par Joueur.
 * \details     Cette methode retourne les zones de tacle de chaque joueur de l'Equipe en fonction de leur Id
 * \return      \e std::map<int, std::vector<QStandardItem * > * >*
 */
std::map<int, std::vector<QStandardItem * > * >* Equipe::zonesTacle()
{
    std::map<int, std::vector<QStandardItem* >* >* lesZonesTacle = new std::map<int, std::vector<QStandardItem* >* >;
    std::vector<Joueur*>::iterator leIt;

    for(leIt = sesJoueurs->begin(); leIt != sesJoueurs->end(); leIt++)
    {
        std::vector<QStandardItem* >* zoneTacle = new std::vector<QStandardItem* >;
        int x = (*leIt)->getItem()->row();
        int y = (*leIt)->getItem()->column();
        if((*leIt)->getItem()->data(43).toBool() == true)
        {
        if(x-1>=0 && y-1>=0)
        zoneTacle->push_back(sonModele->item(x-1, y-1));
        if(x-1>=0)
        zoneTacle->push_back(sonModele->item(x-1, y));
        if(x-1>=0 && y+1<28)
        zoneTacle->push_back(sonModele->item(x-1, y+1));
        if(y-1>=0)
        zoneTacle->push_back(sonModele->item(x, y-1));
        if(y+1<28)
        zoneTacle->push_back(sonModele->item(x, y+1));
        if(x+1<15 && y-1>=0)
        zoneTacle->push_back(sonModele->item(x+1, y-1));
        if(x+1<15)
        zoneTacle->push_back(sonModele->item(x+1, y));
        if(x+1<15 && y+1<28)
        zoneTacle->push_back(sonModele->item(x+1, y+1));

        if(!zoneTacle->empty())
        lesZonesTacle->insert(std::pair<int, std::vector<QStandardItem* >* >((*leIt)->getItem()->data(39).toInt(), zoneTacle));
        }
    }
    return lesZonesTacle;
}

/**
 * \brief       Accesseur qui retourne les \e Joueurs sous forme d'un tableau
 * \return      \e std::vector<Joueur*>*
 */
std::vector<Joueur*>* Equipe::getSesJoueurs()
{
    return sesJoueurs;
}

/**
 * \brief       Mutateur de \a blitzEffectue
 * \param       bool           \e true si le blitz est effectue, \e false pour une remise � zero.
 * \return      \e void
 */
void Equipe::setBlitzEffectue(bool unBool)
{
    blitzEffectue = unBool;
}

/**
 * \brief       Incr�mente le nombre de tour effectue par l'Equipe.
 * \return      \e void
 */
void Equipe::incrementeTour()
{
    sonNoTour++;
}

/**
 * \brief       Accesseur qui retourne le numero de tour de l'Equipe.
 * \return      \e int
 */
int Equipe::getTour()
{
    return sonNoTour;
}

/**
 * \brief       Accesseur qui retourne le nombre de points de l'Equipe.
 * \return      \e int
 */
int Equipe::getPoints()
{
    return sesPoints;
}

/**
 * \brief       Accesseur qui retourne \e vrai si le \b blitz de l'Equipe a �t� effectu�
 * \details     Un seul \b blitz par tour par Equipe.
 * \return      \e bool
 */
bool Equipe::getBlitzEffectue()
{
    return blitzEffectue;
}

/**
 * \brief       Mutateur pour modifier si la passe de l'Equipe est effectuee ou non dans le tour
 * \param       int           points
 * \return      \e void
 */
void Equipe::setPoints(int points)
{
    sesPoints = points;
}

/**
 * \brief       Mutateur pour modifier si la passe de l'Equipe est effectuee ou non dans le tour
 * \param       bool           \e true si la passe est effectuee, \e false pour une remise � zero.
 * \return      \e void
 */
void Equipe::setPasseEffectuee(bool unBool)
{
    passeEffectuee = unBool;
}

/**
 * \brief       Accesseur qui retourne \e vrai si la \b passe de l'Equipe a �t� effectu�e
 * \details     Une seule \b passe par tour par Equipe.
 * \return      \e bool
 */
bool Equipe::getPasseEffectuee()
{
    return passeEffectuee;
}

/**
 * \brief       Accesseur qui retourne le \e Joueur via son \e Id
 * \param       int                    Id du \e Joueur
 * \return      \e Joueur
 */
Joueur* Equipe::getLeJoueur(int sonId)
{
    Joueur* res;
    std::vector<Joueur*>::iterator leIt;
    for(leIt = sesJoueurs->begin(); leIt != sesJoueurs->end(); leIt++)
    {
        if((*leIt)->getId() == sonId)
        {
            res = (*leIt);
        }
    }
    return res;
}
