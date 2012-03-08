#include "sceneterrain.h"
#include <QTableWidget>


SceneTerrain::SceneTerrain(int nLignes, int nColonnes):QTableWidget(nLignes, nColonnes)
{
    for(int i=0; i<15; i++)
    {
        setRowHeight(i, 22);
    }
    for(int i=0; i<28; i++)
    {
        setColumnWidth(i, 22);
    }
}

SceneTerrain::~SceneTerrain()
{

}
