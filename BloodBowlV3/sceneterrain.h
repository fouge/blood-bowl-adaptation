#ifndef SCENETERRAIN_H
#define SCENETERRAIN_H

#include <QGraphicsScene>
#include <QTableView>
#include "tablemodel.h"
#include "fenetreprincipale.h"

class FenetrePrincipale;

class SceneTerrain : public QTableView
{
    TableModel* sonModele;
    bool joueurSelectionne;
    FenetrePrincipale* sonParent;
public:
    SceneTerrain(int nLignes, int nColonnes, TableModel* unModele, FenetrePrincipale* parent);
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);
    std::vector<QStandardItem*>* afficheMouvements(QStandardItem* unItem);
};

#endif // SCENETERRAIN_H
