#ifndef BALLON_H
#define BALLON_H

/**
 * \file      ballon.h
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Déclaration de la classe \b Ballon
 *
 */


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
