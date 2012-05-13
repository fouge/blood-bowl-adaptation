/**
 * \file      joueur.h
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Déclaration de la classe \b Joueur
 *
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
#include "tablemodel.h"
#include "enum.h"

class TableModel;

class Joueur
{
    QStandardItem* sonItem;
    std::vector<competences>* sesCompetences;
    int sesMouvements, saForce, sonAgilite, sonArmure, sonId, sonX, sonY;
    QString sonNom;
    etat sonEtat;
    typeJ sonType;
    bool actionEffectue, sonCote;
    static TableModel* leTerrain;
    static int id;
public:
    Joueur(TableModel*);
    Joueur(typeJ, std::vector<competences>* desCompetences, int desMouvements, int uneForce,
           int uneAgilite, int uneArmure, QString unNom, int unX, int unY, bool unCote);
    std::vector<competences>* getCompetences();
    typeJ getType();
    int getMouvements(), getForce(), getAgilite(), getArmure(), getId(), getX(), getY();
    bool getCote();
    QString getNom();
    QStandardItem* getItem();
    void setLeTerrain(TableModel*);
    void setItem(QStandardItem* unItem);
    int type() const;
};


#endif // JOUEUR_H
