#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
#include "tablemodel.h"
#include "enum.h"



class Joueur
{
    QStandardItem* sonItem;
    std::vector<competences> sesCompetences;
    int sesMouvements, saForce, sonAgilite, sonArmure, sonId, sonX, sonY;
    QString sonNom;
    etat sonEtat;
    typeJ sonType;
    bool actionEffectue, sonCote;
    static TableModel* leTerrain;
public:
    Joueur(TableModel*);
    Joueur(typeJ, std::vector<competences> desCompetences, int desMouvements, int uneForce,
           int uneAgilite, int uneArmure, QString unNom, int unX, int unY, bool unCote);

    std::vector<competences> getCompetences();
    typeJ getType();
    int getMouvements(), getForce(), getAgilite(), getArmure();
    bool getCote();
    QString getNom();
    QStandardItem* getItem();

    void setLeTerrain(TableModel*);
    int type() const;
    void updateAttributs();
};


#endif // JOUEUR_H
