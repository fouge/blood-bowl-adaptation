#include "sceneterrain.h"
#include <QHeaderView>

SceneTerrain::SceneTerrain(int nLignes, int nColonnes, QStandardItemModel* unModele):QTableView()
{
    setModel(unModele);

    for(int i=0; i<15; i++)
    {
        setRowHeight(i, 22);
    }
    for(int i=0; i<28; i++)
    {
        setColumnWidth(i, 22);
    }
    setFixedSize(618, 332);
    setCornerButtonEnabled(false);
    setSortingEnabled(false);
    this->verticalHeader()->setVisible(false);
    horizontalHeader()->setVisible(false);
}

SceneTerrain::~SceneTerrain()
{

}


void SceneTerrain::adapterPage()
{

}
