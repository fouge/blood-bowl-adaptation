/**
 * \file      equipe.h
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Déclaration de la classe \b Equipe
 *
 */

#ifndef EQUIPE_H
#define EQUIPE_H

#include "joueur.h"
#include "enum.h"

class Joueur;

class TableModel;

class Equipe
{
    race saRace;
    std::vector<Joueur*>* sesJoueurs;
    bool sonCote;
    TableModel* sonModele;
    bool blitzEffectue, passeEffectuee;
    int sesRelances, sonNoTour, sesPoints;
public:
    Equipe(race, int, bool, TableModel*);
    void resetJoueurs();
    std::vector<Joueur*>* getSesJoueurs();
    std::map<int, std::vector<QStandardItem* >* >* zonesTacle();
    void setBlitzEffectue(bool);
    void setPasseEffectuee(bool);
    void setPoints(int);
    void incrementeTour();
    int getTour();
    int getPoints();
    bool getBlitzEffectue();
    bool getPasseEffectuee();
    Joueur* getLeJoueur(int sonId);
};

#endif // EQUIPE_H
