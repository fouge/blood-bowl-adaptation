#ifndef SCENETERRAIN_H
#define SCENETERRAIN_H

#include <QGraphicsScene>
#include <QTableView>
#include <QStandardItemModel>

class SceneTerrain : public QTableView
{
public:
    SceneTerrain(int nLignes, int nColonnes, QStandardItemModel* unModele);
    ~SceneTerrain();
    void adapterPage();
};

#endif // SCENETERRAIN_H
