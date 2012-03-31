#ifndef SCENETERRAIN_H
#define SCENETERRAIN_H

#include <QGraphicsScene>
#include <QTableView>
#include <QStandardItemModel>

class SceneTerrain : public QTableView
{
    QStandardItemModel* sonModele;
public:
    SceneTerrain(int nLignes, int nColonnes, QStandardItemModel* unModele);
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);
};

#endif // SCENETERRAIN_H
