/**
 * \file      joueur.cpp
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Définition de la classe \b Joueur
 *
 */

/** \class Joueur joueur.h "joueur.h" */
#include "joueur.h"

#include <iostream>
#include <QApplication>


TableModel* Joueur::leTerrain = 0;
int Joueur::id = 0;

Joueur::Joueur(TableModel *unModele)
{
    leTerrain = unModele;
}

Joueur::Joueur(typeJ unType, std::vector<competences>* desCompetences, int desMouvements, int uneForce,
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
    if(sonEtat == debout)
    {
    sonItem->setData(QVariant(true),43); // est debout
    }
    sonItem->setData(QVariant(sonType),44);
    sonItem->setData(QVariant(true),45); //est joueur
    sonItem->setData(QVariant(false), 46); // a bloqué
    sonItem->setData(QVariant(false), 47); // a bougé
    sonItem->setData(QVariant(false), 48); // a ballon

    std::vector<competences>::iterator it;
    int valeurRole = 60;
    for(it = sesCompetences->begin(); it != sesCompetences->end(); it++, valeurRole++)
    {
    sonItem->setData(QVariant((*it)), valeurRole);
    }
}

/**
 * \brief       Accesseur qui retourne un tableau de \e competences de l'Equipe
 * \return      \e std::vector<competences>*
 */
std::vector<competences>* Joueur::getCompetences()
{
    return sesCompetences;
}

/**
 * \brief       Accesseur qui retourne le \e type du Joueur
 * \return      \e typeJ
 */
typeJ Joueur::getType()
{
    return sonType;
}

/**
 * \brief       Accesseur qui retourne le nombre de mouvements possibles du Joueur
 * \return      \e int
 */
int Joueur::getMouvements()
{
    return sesMouvements;
}

/**
 * \brief       Accesseur qui retourne la force du Joueur
 * \return      \e int
 */
int Joueur::getForce()
{
    return saForce;
}

/**
 * \brief       Accesseur qui retourne l'agilite du Joueur
 * \return      \e int
 */
int Joueur::getAgilite()
{
    return sonAgilite;
}

/**
 * \brief       Accesseur qui retourne la force de défense ( \e armure ) du Joueur
 * \return      \e int
 */
int Joueur::getArmure()
{
    return sonArmure;
}

/**
 * \brief       Accesseur qui retourne le cote du Joueur : c-a-d l'Equipe
 * \return      \e bool
 */
bool Joueur::getCote()
{
    return sonCote;
}

/**
 * \brief       Accesseur qui retourne le nom du Joueur
 * \return      \e QString
 */
QString Joueur::getNom()
{
    return sonNom;
}

/**
 * \brief       Accesseur qui retourne l'item du Joueur : correspond a la materialisation du joueur dans le tableau (terrain de jeu).
 * \return      \e QStandardItem*
 */
QStandardItem* Joueur::getItem()
{
    return sonItem;
}
/**
 * \brief       Accesseur qui retourne l'Id du Joueur
 * \return      \e int
 */
int Joueur::getId()
{
    return sonId;
}

/**
 * \brief       Mutateur d'item : on reattribue le clone de l'item precedent du Joueur en cas de mouvement
 * \param       QStandardItem*     unItem
 * \return      \e void
 */
void Joueur::setItem(QStandardItem *unItem)
{
    sonItem = unItem;
}
