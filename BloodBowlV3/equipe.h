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
    void incrementeTour();
    int getTour();
    int getPoints();
    bool getBlitzEffectue();
    bool getPasseEffectuee();
    Joueur* getLeJoueur(int sonId);
};

#endif // EQUIPE_H
