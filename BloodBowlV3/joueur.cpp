#include "joueur.h"
#include <iostream>
#include <QApplication>

//#define jCote 33;
//#define ACTIONEFFECTUE 34;
//#define jMouvement 35;
//#define jForce 36;
//#define jAgilite 37;
//#define jArmure 38;
//#define jId 39;
//#define jX 40;
//#define jY 41;
//#define jNom 42;
//#define jEtat 43;
//#define jType 44;
//#define jEstJoueur 45;

TableModel* Joueur::leTerrain = 0;

int Joueur::id = 0;

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
    sonId = id++;
    std::cout<<sonId<<std::endl;
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


    sonItem->setEditable(true);

    sonItem->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
    sonItem->setData(QVariant(actionEffectue), 34);
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
QStandardItem* Joueur::getItem()
{
    return sonItem;
}
int Joueur::getId()
{
    return sonId;
}

void Joueur::resetData()
{
    int i = sonItem->row();
    int j = sonItem->column();
    leTerrain->item(i, j)->setData(QVariant(sesMouvements), 35);
}
