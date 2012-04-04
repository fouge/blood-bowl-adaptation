#include "sceneterrain.h"
#include <QHeaderView>
#include "tablemodel.h"
#include "joueur.h"
#include <cstdio>
#include <iostream>

SceneTerrain::SceneTerrain(int nLignes, int nColonnes, TableModel* unModele):QTableView(), sonModele(unModele), joueurSelectionne(false)
{
    setModel(sonModele);

    // init :
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
    setEditTriggers(NoEditTriggers);
    setSelectionMode(QAbstractItemView::SingleSelection);
}

void SceneTerrain::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    this->update(topLeft);
    this->update(bottomRight);
}

void SceneTerrain::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{

    std::vector<QStandardItem*>* lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));

    if(sonModele->item(current.row(), current.column())->data(45).toBool())
    {
        joueurSelectionne = true;
    }
    else
    {
        joueurSelectionne = false;
    }

    //Affichage :
    if(joueurSelectionne)
    {
        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
            {
            (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
            }
    }
    if(!joueurSelectionne || sonModele->item(previous.row(),previous.column())->data(35).toBool() != sonModele->item(current.row(),current.column())->data(35).toBool())
    {
        for(int i(0); i<15; i++)
        {
            for(int j(0); j<28; j++)
            {
                sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
            }
        }
    }



    //Deplacement :
    if(previous.isValid() && sonModele->item(previous.row(), previous.column())->data(45).toBool() && !joueurSelectionne)
    {
        bool deplacementPossible(false);
        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
        {
            if((*leIt) == sonModele->item(current.row(), current.column()))
            {
              deplacementPossible = true;
            }
        }

        if(deplacementPossible)
        {
        sonModele->switchItems(sonModele->item(previous.row(), previous.column()), sonModele->item(current.row(), current.column()));
        }
    }
}

std::vector<QStandardItem*>* SceneTerrain::afficheMouvements(QStandardItem *unItem)
{
    int rayon = unItem->data(35).toInt();
    int x = unItem->row();
    int y = unItem->column();
    std::vector<QStandardItem*>* lesItems = new std::vector<QStandardItem*>();
    for(int i(0); i<15; i++)
    {
        for(int j(0); j<28; j++)
        {
            if(rayon*rayon >= (x-i)*(x-i) + (y-j)*(y-j))
            {
                lesItems->push_back(sonModele->item(i,j));
            }
        }
    }
    return lesItems;
}


