#ifndef JOUEUR_H
#define JOUEUR_H
#include "case.h"
#include <vector>
#include <string>

class Case;

enum type{blitzeur, troisquarts, receveur, passeur, ogre, gobelin, bloqueur, troll};
enum race{humains, orques};
enum etat{debout, parterre};
enum competences{esquive, reception, dexterite, passe, blocage, perso,
                 cerveauLent, chataigne, craneEpais, lancerCoequipier,
                 minus, poidsPlume, grosDebile, regeneration, toujoursAffame};

class Joueur
{
    type sonType;
    std::vector<competences> sesCompetences;
    int sesMouvements, saForce, sonAgilite, sonArmure, sonId;
    std::string sonNom;
    Case* saCase;
    etat sonEtat;
    bool actionEffectue;
public:
    Joueur(type, std::vector<competences> desCompetences, int desMouvements, int uneForce,
           int uneAgilite, int uneArmure, std::string unNom, Case* uneCase, bool unCote);
    std::vector<competences> getCompetences();
    type getType();
    int getMouvements(), getForce(), getAgilite(), getArmure();
};

#endif // JOUEUR_H
