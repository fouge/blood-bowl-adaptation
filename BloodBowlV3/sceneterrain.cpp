#include "sceneterrain.h"
#include <QHeaderView>
#include "tablemodel.h"
#include "joueur.h"
#include <cstdio>
#include <iostream>


SceneTerrain::SceneTerrain(int nLignes, int nColonnes, TableModel* unModele, FenetrePrincipale* parent):QTableView(), sonModele(unModele), joueurSelectionne(false), sonParent(parent)
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
    if(current.isValid())
    {
    // current est joueur && joueur bleu :
    // modification tableau affichage du joueur bleu
        if((sonModele->item(current.row(), current.column())->data(45).toBool()) && sonModele->item(current.row(), current.column())->data(33).toBool())
        {
            sonParent->updatePanneauJoueur(0,sonModele->item(current.row(), current.column()));
        }

    // current joueur && joueur rouge :
    //modification tableau affichage du joueur rouge
        if(sonModele->item(current.row(), current.column())->data(45).toBool() && !(sonModele->item(current.row(), current.column())->data(33).toBool()))
        {
            sonParent->updatePanneauJoueur(1, sonModele->item(current.row(), current.column()));
        }

    //si current n'est pas joueur, on nettoie l'affichage des panneaux latéreaux :
        if(!(sonModele->item(current.row(), current.column())->data(45).toBool()))
        {
            sonParent->clearPanneauxJoueurs();
        }


    std::vector<QStandardItem*>* lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));

    // si pas joueur séléctionné, on supprime l'affichage mouvements :
    if(!(sonModele->item(current.row(), current.column())->data(45).toBool()))
    {
    for(int i(0); i<15; i++)
    {
        for(int j(0); j<28; j++)
        {
            sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
        }
    }
    }

    // si previous est un joueur et current aussi :
    if(previous.isValid() && sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool())
    {
        // on attaque :

        // on actualise l'affichage :
        for(int i(0); i<15; i++)
        {
            for(int j(0); j<28; j++)
            {
                sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
            }
        }
    }

    // si previous n'est pas un joueur : on affiche les mouvements :
    else if(previous.isValid() && sonModele->item(current.row(), current.column())->data(45).toBool() && !(sonModele->item(previous.row(), previous.column())->data(45).toBool()))
    {
        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
            {
            (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
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


