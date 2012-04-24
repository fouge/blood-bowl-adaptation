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
    if(current.isValid())
    {
        std::cout<<"current valide"<<std::endl;
    }
    else
        std::cout<<"current non valide"<<std::endl;
    if(previous.isValid())
    {
        std::cout<<"previous valide"<<std::endl;
    }
    else
        std::cout<<"previous non valide"<<std::endl;


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
            std::cout<<"premier clic sur joueur"<<std::endl;
        }
        else
        {
            if(fClic)
                std::cout<<"fCliv : vrai"<<std::endl;
            else
            {std::cout<<"fCliv : faux"<<std::endl;}

        std::cout<<"premier clic sur terrain"<<std::endl;
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
            if(i >= x-rayon && i<= x+rayon && j>= y-rayon && j <= y+rayon)
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

    else if((!sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool()) || (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && (!sonModele->item(previous.row(), previous.column())->data(45).toBool() && (sonModele->item(current.row(), current.column())->data(33).toBool() == sonModele->item(previous.row(), previous.column())->data(33).toBool()))) )
    // Affichage des mouvements :
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
    if(sonModele->item(previous.row(), previous.column())->data(45).toBool() && !sonModele->item(current.row(), current.column())->data(45).toBool())
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

        // on nettoie l'affichage :
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

    else if(sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && (sonModele->item(previous.row(), previous.column())->data(33).toBool() != sonModele->item(current.row(), current.column())->data(33).toBool()))
    {
        // on attaque
        // ...
        // ...

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

   else
    {
        firstClic(current, previous);
    }


}
