#include "joueur.h"

Joueur::Joueur(type unType, std::vector<competences> desCompetences, int desMouvements, int uneForce,
               int uneAgilite, int uneArmure, std::string unNom, Case* uneCase,
               bool unCote):sonType(unType), sesCompetences(desCompetences),sesMouvements(desMouvements),
    saForce(uneForce), sonAgilite(uneAgilite), sonArmure(uneArmure), sonNom(unNom), saCase(uneCase), sonEtat(debout), actionEffectue(false), sonCote(unCote)
{
    // on fait le lien dans l'autre sens : la case a un joueur :
    saCase->setJoueurDessus(this);
// enum type{blitzeur, troisquarts, receveur, passeur, ogre, gobelin, bloqueur, troll};


}


std::vector<competences> Joueur::getCompetences()
{
    return sesCompetences;
}

type Joueur::getType()
{
    return sonType;
}

int Joueur::getMouvements()
{
    return sesMouvements;
}

int Joueur::getForce()
{
    return saForce;
}
int Joueur::getAgilite()
{
    return sonAgilite;
}


int Joueur::getArmure()
{
    return sonArmure;
}

bool Joueur::getCote()
{
    return sonCote;
}
Case* Joueur::getCase()
{
    return saCase;
}

void Joueur::setCase(Case * uneCase)
{
    saCase = uneCase;
}
