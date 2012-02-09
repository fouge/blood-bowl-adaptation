#ifndef TERRAIN_H
#define TERRAIN_H

#include <QApplication>
#include <QtGui>
#include <QStringList>
#include <QInputDialog>
#include <QLabel>
#include "case.h"

class Terrain : public QWidget
{
    Q_OBJECT
    QGridLayout * grilleTerrain;
public:
    Terrain(std::vector<std::vector<Case*> *> * unTerrain);
public slots:
    void afficheMvts(JoueurWidget *);
};

#endif // TERRAIN_H
