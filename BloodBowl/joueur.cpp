#include "joueur.h"

Joueur::Joueur(type unType, std::vector<competences> desCompetences, int desMouvements, int uneForce,
               int uneAgilite, int uneArmure, std::string unNom, Case* uneCase,
               etat unEtat):sonType(unType), sesCompetences(desCompetences),sesMouvements(desMouvements),
    saForce(uneForce), sonAgilite(uneAgilite), sonArmure(uneArmure), sonNom(unNom), saCase(uneCase), sonEtat(unEtat), actionEffectue(false)
{
    saCase->sonJoueurDessus=this;
    if(sonType==blitzeur)
    {
        QPixmap* unQPixmap = new QPixmap("images/joueurs/blitzeur.png");
        saCase->setSonJoueur(unQPixmap);
    }
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
