#include "joueur.h"
#include <iostream>

TableModel* Joueur::leTerrain = 0;


Joueur::Joueur(TableModel *unModele)
{
    leTerrain = unModele;
}

Joueur::Joueur(typeJ unType, std::vector<competences> desCompetences, int desMouvements, int uneForce,
               int uneAgilite, int uneArmure, QString unNom, int unY, int unX,
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
            sonItem->setData(QVariant(QIcon("images/joueurs/blitzeur1.png")), 1) ;
            break;}
        case troisquarts :
        {
            sonItem->setData(QVariant(QIcon("images/joueurs/troisquart1.png")), 1) ;
            break;}
        case receveur:
           {
            sonItem->setData(QVariant(QIcon("images/joueurs/receveur1.png")), 1) ;
            break;}
        case passeur:
           {
            sonItem->setData(QVariant(QIcon("images/joueurs/passeur1.png")), 1) ;
            break;}
        case ogre:
           {
            sonItem->setData(QVariant(QIcon("images/joueurs/ogre1.png")), 1) ;
            break;}
        case gobelin:
           {
            sonItem->setData(QVariant(QIcon("images/joueurs/gobelin1.png")), 1) ;
            break;}
        case bloqueur:
           {
            sonItem->setData(QVariant(QIcon("images/joueurs/bloqueur1.png")), 1) ;
            break;}
        case troll:
           {
            sonItem->setData(QVariant(QIcon("images/joueurs/troll1.png")), 1) ;
            break;}
        default: ;
        }
    }


    else
      {
        switch(sonType)
       {
        case blitzeur:
           { sonItem->setData(QVariant(QIcon("images/joueurs/blitzeur2.png")), 1) ;
            break;}
        case troisquarts :
           { sonItem->setData(QVariant(QIcon("images/joueurs/troisquart2.png")), 1) ;
            break;}
        case receveur:
           { sonItem->setData(QVariant(QIcon("images/joueurs/receveur2.png")), 1) ;
            break;}
        case passeur:
           { sonItem->setData(QVariant(QIcon("images/joueurs/passeur2.png")), 1) ;
            break;}
        case ogre:
           { sonItem->setData(QVariant(QIcon("images/joueurs/ogre2.png")), 1) ;
            break;}
        case gobelin:
           { sonItem->setData(QVariant(QIcon("images/joueurs/gobelin2.png")), 1) ;
            break;}
        case bloqueur:
           { sonItem->setData(QVariant(QIcon("images/joueurs/bloqueur2.png")), 1) ;
            break;}
        case troll:
           { sonItem->setData(QVariant(QIcon("images/joueurs/troll2.png")), 1) ;
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
        sonItem->setData(QVariant(sonCote), 33);
        leTerrain->setItem(15-sonX, 28-sonY, sonItem);
    }


    sonItem->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
    sonItem->setData(QVariant(actionEffectue),34);
    sonItem->setData(QVariant(sesMouvements),35);
    sonItem->setData(QVariant(saForce),36);
    sonItem->setData(QVariant(sonAgilite),37);
    sonItem->setData(QVariant(sonArmure),38);
    sonItem->setData(QVariant(sonId),39);
    sonItem->setData(QVariant(sonX),40);
    sonItem->setData(QVariant(sonY),41);
    sonItem->setData(QVariant(sonNom),42);
    sonItem->setData(QVariant(sonEtat),43);
    sonItem->setData(QVariant(sonType),44);
    sonItem->setData(QVariant(true),45);
    std::vector<competences>::iterator it;
    int valeurRole = 60;
    for(it = sesCompetences.begin(); it != sesCompetences.end(); it++, valeurRole++)
    {
    sonItem->setData(QVariant((*it)), valeurRole);
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
QString Joueur::getNom()
{
    return sonNom;
}

void Joueur::updateAttributs()
{
   actionEffectue=(sonItem->data(34)).toBool();
   sesMouvements=(sonItem->data(35)).toInt();
   sonX=(sonItem->data(40)).toInt();
   sonY=(sonItem->data(41)).toInt();
   //Si il y a un soucis, ça vient de là!!
   //sonEtat=(sonItem->data(43)).value();
}

