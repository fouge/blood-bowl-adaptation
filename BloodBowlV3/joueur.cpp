#include "joueur.h"
#include <iostream>

QStandardItemModel* Joueur::leTerrain = 0;


Joueur::Joueur(QStandardItemModel *unModele)
{
    leTerrain = unModele;
}

Joueur::Joueur(typeJ unType, std::vector<competences> desCompetences, int desMouvements, int uneForce,
               int uneAgilite, int uneArmure, std::string unNom, int unY, int unX,
               bool unCote)
    : sonType(unType), sesCompetences(desCompetences),sesMouvements(desMouvements),
      saForce(uneForce), sonAgilite(uneAgilite), sonArmure(uneArmure), sonNom(unNom), sonX(unX), sonY(unY), sonEtat(debout),
    actionEffectue(false), sonCote(unCote)
{

    sonItem = new QStandardItem();

    if(unCote)
    {
        switch(sonType)
       {
        case blitzeur:
        {
            sonItem->setData(QVariant(QPixmap("images/joueurs/blitzeur1.png")), 1) ;
            break;}
        case troisquarts :
        {
            sonItem->setData(QVariant(QPixmap("images/joueurs/troisquart1.png")), 1) ;
            break;}
        case receveur:
           {
            sonItem->setData(QVariant(QPixmap("images/joueurs/receveur1.png")), 1) ;
            break;}
        case passeur:
           {
            sonItem->setData(QVariant(QPixmap("images/joueurs/passeur1.png")), 1) ;
            break;}
        case ogre:
           {
            sonItem->setData(QVariant(QPixmap("images/joueurs/ogre1.png")), 1) ;
            break;}
        case gobelin:
           {
            sonItem->setData(QVariant(QPixmap("images/joueurs/gobelin1.png")), 1) ;
            break;}
        case bloqueur:
           {
            sonItem->setData(QVariant(QPixmap("images/joueurs/bloqueur1.png")), 1) ;
            break;}
        case troll:
           {
            sonItem->setData(QVariant(QPixmap("images/joueurs/troll1.png")), 1) ;
            break;}
        default: ;
        }
    }


    else
      {
        switch(sonType)
       {
        case blitzeur:
           { sonItem->setData(QVariant(QPixmap("images/joueurs/blitzeur2.png")), 1) ;
            break;}
        case troisquarts :
           { sonItem->setData(QVariant(QPixmap("images/joueurs/troisquart2.png")), 1) ;
            break;}
        case receveur:
           { sonItem->setData(QVariant(QPixmap("images/joueurs/receveur2.png")), 1) ;
            break;}
        case passeur:
           { sonItem->setData(QVariant(QPixmap("images/joueurs/passeur2.png")), 1) ;
            break;}
        case ogre:
           { sonItem->setData(QVariant(QPixmap("images/joueurs/ogre2.png")), 1) ;
            break;}
        case gobelin:
           { sonItem->setData(QVariant(QPixmap("images/joueurs/gobelin2.png")), 1) ;
            break;}
        case bloqueur:
           { sonItem->setData(QVariant(QPixmap("images/joueurs/bloqueur2.png")), 1) ;
            break;}
        case troll:
           { sonItem->setData(QVariant(QPixmap("images/joueurs/troll2.png")), 1) ;
            break;}
        default: ;
        }
    }



    // ajouter au modele dans la bonne case grace à sonX, sonY et en fonction du coté !
    if(unCote)
    {
        sonItem->setData(QVariant(sonCote), 33);
        leTerrain->setItem(sonX - 1, sonY -1, sonItem);
    }
    else
    {
        QVariant yo = QVariant(sonCote);
        sonItem->setData(QVariant(sonCote), 33);
        if(!yo.toBool())
        {
            std::cout<<"joueur créé"<<std::endl;
        }
        leTerrain->setItem(15-sonX, 28-sonY, sonItem);
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
std::string Joueur::getNom()
{
    return sonNom;
}

int Joueur::type() const
{
    return 1000;
}
