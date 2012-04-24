#include "sceneterrain.h"
#include <QHeaderView>
#include "tablemodel.h"
#include "joueur.h"
#include <cstdio>
#include <iostream>


SceneTerrain::SceneTerrain(int nLignes, int nColonnes, TableModel* unModele, FenetrePrincipale* parent):QTableView(),
    sonModele(unModele), joueurSelectionne(false), sonParent(parent), fClic(true), lesMouvementsPossibles(0)
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
    if(current.isValid() && previous.isValid() && fClic)
    {
        firstClic(current, previous);
    }
    else if(current.isValid() && previous.isValid() && !fClic)
    {
        secondClic(current, previous);
    }
    else if(!previous.isValid() && current.isValid())
    {
        if(sonModele->item(current.row(), current.column())->data(45).toBool())
        {
            //on nettoie l'affichage
            sonParent->clearPanneauxJoueurs();
            for(int i(0); i<15; i++)
            {
                for(int j(0); j<28; j++)
                {
                    sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
                }
            }

            // on affiche
            if(sonModele->item(current.row(), current.column())->data(33).toBool())
            {
                sonParent->updatePanneauJoueur(0,sonModele->item(current.row(), current.column()));
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            }
            else
            {
                sonParent->updatePanneauJoueur(1, sonModele->item(current.row(), current.column()));
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            }

            std::vector<QStandardItem*>::iterator leIt;
            for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
                {
                (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
                }

            fClic = 0;
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



void SceneTerrain::firstClic(const QModelIndex &current, const QModelIndex &previous)
{

    if(!sonModele->item(current.row(), current.column())->data(45).toBool() && !sonModele->item(previous.row(), previous.column())->data(45).toBool())
    {
        sonParent->clearPanneauxJoueurs();
        for(int i(0); i<15; i++)
        {
            for(int j(0); j<28; j++)
            {
                sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
            }
        }

        fClic = 1;
    }


    if((sonModele->item(current.row(), current.column())->data(45).toBool() && !sonModele->item(previous.row(), previous.column())->data(45).toBool() && !sonModele->item(current.row(), current.column())->data(33).toBool()) || (sonModele->item(previous.row(), previous.column())->data(33).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(33).toBool()) || (!sonModele->item(current.row(), current.column())->data(33).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && (sonModele->item(current.row(), current.column())->data(33).toBool() != sonModele->item(previous.row(), previous.column())->data(45).toBool())) )
    {
        //on nettoie l'affichage
        sonParent->clearPanneauxJoueurs();
        for(int i(0); i<15; i++)
        {
            for(int j(0); j<28; j++)
            {
                sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
            }
        }



        // on affiche
        if(sonModele->item(current.row(), current.column())->data(33).toBool())
        {
            sonParent->updatePanneauJoueur(0,sonModele->item(current.row(), current.column()));
            lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
        }
        else
        {
            sonParent->updatePanneauJoueur(1, sonModele->item(current.row(), current.column()));
            lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
        }

        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
            {
            (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
            }

        fClic = 0;
    }
        else
    {
        secondClic(current, previous);
    }
}

void SceneTerrain::secondClic(const QModelIndex &current, const QModelIndex &previous)
{
    //si current n'est pas joueur, on nettoie l'affichage des panneaux latéreaux :
        if(!(sonModele->item(current.row(), current.column())->data(45).toBool()))
        {
            sonParent->clearPanneauxJoueurs();
            fClic = 1;
        }


        // si previous et current sont deux joueurs opposés :
        if(previous.isValid() && sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && sonModele->item(previous.row(), previous.column())->data(33).toBool() != sonModele->item(current.row(), current.column())->data(33).toBool())
        {
            // on attaque :
            fClic = 1;
        }

        // si previous et current sont deux joueurs de la meme équipe :
        if(previous.isValid() && sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && sonModele->item(previous.row(), previous.column())->data(33).toBool() == sonModele->item(current.row(), current.column())->data(33).toBool())
        {
            firstClic(current, previous);
        }



        //Deplacement si previous est joueur et current est case
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

            fClic = 1;
        }


        // on actualise l'affichage :
        for(int i(0); i<15; i++)
        {
            for(int j(0); j<28; j++)
            {
                sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
            }
        }

}
