#ifndef BALLON_H
#define BALLON_H

#include "match.h"

class Match;

class Ballon
{
    Match* sonMatch;
    QStandardItemModel* sonModele;
    int sonX;
    int sonY;
public:
    Ballon(Match*, QStandardItemModel*, int, int);
    void rebondir(QStandardItem* uneCase, int nRebondissements);

};

#endif // BALLON_H
