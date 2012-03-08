#ifndef JOUEUR_H
#define JOUEUR_H

#include "case.h"
#include <vector>
#include <string>
#include "equipe.h"
#include "enum.h"

class Case;

class Equipe;

class Joueur
{
    type sonType;
    std::vector<competences> sesCompetences;
    int sesMouvements, saForce, sonAgilite, sonArmure, sonId;
    std::string sonNom;
    Case* saCase;
    etat sonEtat;
    bool actionEffectue, sonCote;
public:
    Joueur(type, std::vector<competences> desCompetences, int desMouvements, int uneForce,
           int uneAgilite, int uneArmure, std::string unNom, Case* uneCase, bool unCote);
    std::vector<competences> getCompetences();
    type getType();
    int getMouvements(), getForce(), getAgilite(), getArmure();
    bool getCote();
    Case* getCase();
    void setCase(Case* uneCase);
};

#endif // JOUEUR_H
