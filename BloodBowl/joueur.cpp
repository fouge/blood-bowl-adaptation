#include "joueur.h"

Joueur::Joueur(type unType, std::vector<competences> desCompetences, int desMouvements, int uneForce,
               int uneAgilite, int uneArmure, std::string unNom, Case* uneCase,
               bool unCote):sonType(unType), sesCompetences(desCompetences),sesMouvements(desMouvements),
    saForce(uneForce), sonAgilite(uneAgilite), sonArmure(uneArmure), sonNom(unNom), saCase(uneCase), sonEtat(debout), actionEffectue(false), sonCote(unCote)
{
    // on fait le lien dans l'autre sens : la case a un joueur :
    saCase->sonJoueurDessus=this;
// enum type{blitzeur, troisquarts, receveur, passeur, ogre, gobelin, bloqueur, troll};
    if(unCote)
    {
        switch(sonType)
       {
        case blitzeur:
        {   QPixmap* unQPixmap = new QPixmap("images/joueurs/blitzeur1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case troisquarts :
        {   QPixmap* unQPixmap = new QPixmap("images/joueurs/troisquart1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case receveur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/receveur1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case passeur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/passeur1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case ogre:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/ogre1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case gobelin:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/gobelin1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case bloqueur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/bloqueur1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case troll:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/troll1.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        default: ;
        }
    }
    else
    {
        switch(sonType)
       {
        case blitzeur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/blitzeur2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case troisquarts :
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/troisquart2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case receveur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/receveur2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case passeur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/passeur2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case ogre:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/ogre2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case gobelin:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/gobelin2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case bloqueur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/bloqueur2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        case troll:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/troll2.png");
            saCase->setSonJoueur(unQPixmap);
            break;}
        default: ;
        }
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

bool Joueur::getCote()
{
    return sonCote;
}
void Joueur::setCase(Case * uneCase)
{
    saCase = uneCase;
}
