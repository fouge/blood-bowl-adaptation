#ifndef TERRAIN_H
#define TERRAIN_H

#include <QApplication>
#include <QtGui>
#include <QStringList>
#include <QInputDialog>
#include <QLabel>
#include "case.h"
#include "match.h"

class Match;
class Terrain : public QWidget
{
    Q_OBJECT
    QGridLayout * grilleTerrain;
    Match* sonMatch;
    std::vector<std::vector<Case*>*> * sonTerrain;
public:
    Terrain(std::vector<std::vector<Case*> *> * unTerrain, Match* unMatch);
public slots:
    void afficheMvts(JoueurWidget *);
};

#endif // TERRAIN_H
