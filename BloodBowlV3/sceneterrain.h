#ifndef SCENETERRAIN_H
#define SCENETERRAIN_H

#include <QGraphicsScene>
#include <QTableView>
#include "tablemodel.h"

class SceneTerrain : public QTableView
{
    TableModel* sonModele;
public:
    SceneTerrain(int nLignes, int nColonnes, TableModel* unModele);
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);
};

#endif // SCENETERRAIN_H
