#ifndef BALLON_H
#define BALLON_H

#include "match.h"
class SceneTerrain;
class Match;
class Ballon
{
    Match* sonMatch;
    TableModel* sonModele;
    SceneTerrain* sonTerrain;
    int sonX;
    int sonY;
public:
    Ballon(Match*, TableModel*, SceneTerrain* unTerrain, int, int);
    void rebondir(QStandardItem* uneCase, int nRebondissements);
    int row();
    int column();
    void setRow(int row);
    void setColumn(int column);
};

#endif // BALLON_H
