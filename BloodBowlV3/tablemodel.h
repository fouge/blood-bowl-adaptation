#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QStandardItemModel>
#include "equipe.h"

class Equipe;

class TableModel : public QStandardItemModel
{
    Equipe *sonEquipe1, *sonEquipe2;
public:
    TableModel(int, int);
    void switchItems(QStandardItem* item1Joueur, QStandardItem* item2Herbe);
    void resetAllJoueurs();
    void setEquipes(Equipe*, Equipe*);

};

#endif // TABLEMODEL_H
