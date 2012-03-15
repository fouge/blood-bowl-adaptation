#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
#include <QStandardItem>
#include "enum.h"


class Joueur : public QStandardItem
{

    std::vector<competences> sesCompetences;
    int sesMouvements, saForce, sonAgilite, sonArmure, sonId, sonX, sonY;
    std::string sonNom;
    etat sonEtat;
    typeJ sonType;
    bool actionEffectue, sonCote;
public:
    Joueur(typeJ, std::vector<competences> desCompetences, int desMouvements, int uneForce,
           int uneAgilite, int uneArmure, std::string unNom, int unX, int unY, bool unCote);
    Joueur(QStandardItemModel *);
    std::vector<competences> getCompetences();
    typeJ getType();
    int getMouvements(), getForce(), getAgilite(), getArmure();
    bool getCote();
    void setLeTerrain(QStandardItemModel*);
    static QStandardItemModel* leTerrain;
};

#endif // JOUEUR_H
