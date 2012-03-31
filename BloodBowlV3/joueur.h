#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
#include <QStandardItem>
#include "enum.h"
#include <QStandardItemModel>


class Joueur
{
    QStandardItem* sonItem;
    std::vector<competences> sesCompetences;
    int sesMouvements, saForce, sonAgilite, sonArmure, sonId, sonX, sonY;
    std::string sonNom;
    etat sonEtat;
    typeJ sonType;
    bool actionEffectue, sonCote;
    static QStandardItemModel* leTerrain;
public:
    Joueur(QStandardItemModel*);
    Joueur(typeJ, std::vector<competences> desCompetences, int desMouvements, int uneForce,
           int uneAgilite, int uneArmure, std::string unNom, int unX, int unY, bool unCote);

    std::vector<competences> getCompetences();
    typeJ getType();
    int getMouvements(), getForce(), getAgilite(), getArmure();
    bool getCote();
    std::string getNom();
    void setLeTerrain(QStandardItemModel*);
    int type() const;

};

#endif // JOUEUR_H
