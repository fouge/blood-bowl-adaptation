#include "joueur.h"


QStandardItemModel* Joueur::leTerrain = 0;

Joueur::Joueur(QStandardItemModel * unTerrain)
{
    leTerrain = unTerrain;
}

Joueur::Joueur(typeJ unType, std::vector<competences> desCompetences, int desMouvements, int uneForce,
               int uneAgilite, int uneArmure, std::string unNom, int unY, int unX,
               bool unCote)
    : QStandardItem(), sonType(unType), sesCompetences(desCompetences),sesMouvements(desMouvements),
      saForce(uneForce), sonAgilite(uneAgilite), sonArmure(uneArmure), sonNom(unNom), sonX(unX), sonY(unY), sonEtat(debout),
    actionEffectue(false), sonCote(unCote)
{

    // enum type{blitzeur, troisquarts, receveur, passeur, ogre, gobelin, bloqueur, troll};

    // associer le pixmap en fonction du coté
    if(unCote)
    {
        switch(sonType)
       {
        case blitzeur:
        {   QPixmap* unQPixmap = new QPixmap("images/joueurs/blitzeur1.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case troisquarts :
        {   QPixmap* unQPixmap = new QPixmap("images/joueurs/troisquart1.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case receveur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/receveur1.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case passeur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/passeur1.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case ogre:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/ogre1.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case gobelin:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/gobelin1.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case bloqueur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/bloqueur1.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case troll:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/troll1.png");
            this->setIcon(QIcon(*unQPixmap));
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
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case troisquarts :
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/troisquart2.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case receveur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/receveur2.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case passeur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/passeur2.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case ogre:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/ogre2.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case gobelin:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/gobelin2.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case bloqueur:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/bloqueur2.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        case troll:
           { QPixmap* unQPixmap = new QPixmap("images/joueurs/troll2.png");
            this->setIcon(QIcon(*unQPixmap));
            break;}
        default: ;
        }
    }



    // ajouter au modele dans la bonne case grace à sonX, sonY et en fonction du coté !
    if(unCote)
    {
        leTerrain->setItem(sonX, sonY+1, this);
    }
    else
    {
        leTerrain->setItem(14-sonX, 26-sonY, this);
    }


}


std::vector<competences> Joueur::getCompetences()
{
    return sesCompetences;
}

typeJ Joueur::getType()
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
