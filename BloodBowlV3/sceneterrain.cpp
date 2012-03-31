#include "sceneterrain.h"
#include <QHeaderView>
#include <QStandardItem>
#include "joueur.h"
#include <cstdio>
#include <iostream>

SceneTerrain::SceneTerrain(int nLignes, int nColonnes, QStandardItemModel* unModele):QTableView(), sonModele(unModele)
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
    // coordonnées de QModelindex de base : 0,0
    // faire +1
    std::cout<<"colonne:"<<current.column()+1<<std::endl;
    std::cout<<"ligne:"<< current.row()+1<<std::endl;

    if(sonModele->item(current.row(), current.column())->data(33).toBool())
    {
        std::cout<<"Equipe bleue"<<std::endl;
    }
    else
    {
       std::cout<<"Equipe rouge"<<std::endl;
    }

}
