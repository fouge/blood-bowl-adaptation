#ifndef SCENETERRAIN_H
#define SCENETERRAIN_H

#include <QGraphicsScene>
#include <QTableWidget>

class SceneTerrain : public QTableWidget
{
public:
    SceneTerrain(int nLignes, int nColonnes);
    ~SceneTerrain();
};

#endif // SCENETERRAIN_H
