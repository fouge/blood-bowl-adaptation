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
        if((sonParent->getLeMatch()->getQuiJoue() == 0 && sonModele->item(current.row(), current.column())->data(33).toBool()) || (sonParent->getLeMatch()->getQuiJoue() != 0 && !sonModele->item(current.row(), current.column())->data(33).toBool()))
        firstClic(current, previous);
    }
    else if(current.isValid() && previous.isValid() && !fClic)
    {
        secondClic(current, previous);
    }
    else if(!previous.isValid() && current.isValid() && (((sonParent->getLeMatch()->getQuiJoue() == 0) && sonModele->item(current.row(), current.column())->data(33).toBool()) || ((sonParent->getLeMatch()->getQuiJoue() != 0) && !sonModele->item(current.row(), current.column())->data(33).toBool())))
    {
        std::cout<<sonModele->item(current.row(), current.column())->data(43).toInt()<<std::endl;
        if(sonModele->item(current.row(), current.column())->data(45).toBool())
        {
            //on nettoie l'affichage
            clearTerrain();

            // on affiche
            if(sonModele->item(current.row(), current.column())->data(33).toBool() )
            {
                sonParent->updatePanneauJoueur(0,sonModele->item(current.row(), current.column()));
                if(sonModele->item(current.row(), current.column())->data(43).toBool() == true)
                    lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
                else
                {
                    std::cout<<"Le joueur se relève pour un coût de 3 cases"<<std::endl;
                    sonModele->item(current.row(), current.column())->setData(QVariant(sonModele->item(current.row(), current.column())->data(35).toInt() - 3), 35);
                    sonModele->item(current.row(), current.column())->setData(QVariant(true), 43);
                    lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
                }
            }
            else
            {
                sonParent->updatePanneauJoueur(1, sonModele->item(current.row(), current.column()));
                if(sonModele->item(current.row(), current.column())->data(43).toBool() == true)
                    lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
                else
                {
                    std::cout<<"Le joueur se relève pour un coût de 3 cases"<<std::endl;
                    sonModele->item(current.row(), current.column())->setData(QVariant(sonModele->item(current.row(), current.column())->data(35).toInt() - 3), 35);
                    sonModele->item(current.row(), current.column())->setData(QVariant(true), 43);
                    lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
                }
            }

            std::vector<QStandardItem*>::iterator leIt;
            for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
                {
                (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
                }


            // Affichage zone de tacle:
            if(sonModele->item(current.row(), current.column())->data(33).toBool())
            {
                afficheZonesTacle(sonParent->getLeMatch()->getEquipe2());
            }
            else
            {
                afficheZonesTacle(sonParent->getLeMatch()->getEquipe1());
            }

            fClic = 0;
            std::cout<<"premier clic sur joueur"<<std::endl;
        }
        else
        {
        std::cout<<"premier clic sur terrain"<<std::endl;
        }
    }

}



void SceneTerrain::firstClic(const QModelIndex &current, const QModelIndex &previous)
{

    if(!sonModele->item(current.row(), current.column())->data(45).toBool() && !sonModele->item(previous.row(), previous.column())->data(45).toBool())
    {
        clearTerrain();
    }

    // Affichage des mouvements :
    else if((!sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool())
            || (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && (sonModele->item(current.row(), current.column())->data(33).toBool() == sonModele->item(previous.row(), previous.column())->data(33).toBool()) ) )
    {

        //on nettoie l'affichage
        clearTerrain();

        // on affiche si le joueur est debout

        if(sonModele->item(current.row(), current.column())->data(33).toBool() )
        {
            sonParent->updatePanneauJoueur(0,sonModele->item(current.row(), current.column()));
            if(sonModele->item(current.row(), current.column())->data(43).toBool() == true)
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            else
            {
                std::cout<<"Le joueur se relève pour un coût de 3 cases"<<std::endl;
                sonModele->item(current.row(), current.column())->setData(QVariant(sonModele->item(current.row(), current.column())->data(35).toInt() - 3), 35);
                sonModele->item(current.row(), current.column())->setData(QVariant(true), 43);
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            }
        }
        else
        {
            sonParent->updatePanneauJoueur(1, sonModele->item(current.row(), current.column()));
            if(sonModele->item(current.row(), current.column())->data(43).toBool() == true)
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            else
            {
                std::cout<<"Le joueur se relève pour un coût de 3 cases"<<std::endl;
                sonModele->item(current.row(), current.column())->setData(QVariant(sonModele->item(current.row(), current.column())->data(35).toInt() - 3), 35);
                sonModele->item(current.row(), current.column())->setData(QVariant(true), 43);
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            }
        }
        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
            {
            (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
            }

        // Affichage zone de tacle:
        if(sonModele->item(current.row(), current.column())->data(33).toBool())
        {
            afficheZonesTacle(sonParent->getLeMatch()->getEquipe2());
        }
        else
        {
            afficheZonesTacle(sonParent->getLeMatch()->getEquipe1());
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

    if(!(sonModele->item(previous.row(), previous.column())->data(34).toBool()) && (sonModele->item(previous.row(), previous.column())->data(45).toBool() && !sonModele->item(current.row(), current.column())->data(45).toBool()))
    {
        std::cout<<"Deplacement"<<std::endl;
        bool deplacementPossible(false);
        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
        {
            if((*leIt) == sonModele->item(current.row(), current.column()))
            {
              deplacementPossible = true;
            }
        }

        if(deplacementPossible && esquive(previous.row(), previous.column()))
        {
        // on enleve le nombre de mouvements effectués :
        int mvts = sonModele->item(previous.row(), previous.column())->data(35).toInt();
        signed int x = previous.row() - current.row();
        signed int y = previous.column() - current.column();

        if(abs(x) >= abs(y))
        {
            sonModele->item(previous.row(),previous.column())->setData(QVariant(mvts - abs(x)), 35);
        }
        else
        {
            sonModele->item(previous.row(), previous.column())->setData(QVariant(mvts - abs(y)), 35);
        }

        // on déplace le joueur :
        sonModele->switchItems(sonModele->item(previous.row(), previous.column()), sonModele->item(current.row(), current.column()));

        }

        // on nettoie l'affichage :
        clearTerrain();
    }

    else if(!sonModele->item(previous.row(), previous.column())->data(34).toBool() && (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && (sonModele->item(previous.row(), previous.column())->data(33).toBool() != sonModele->item(current.row(), current.column())->data(33).toBool())))
    {
        // on attaque
        // si joueur sur une case adjacente : BLOCAGE


        // si Joueur plus loin : blitz
        // un seul par equipe par tour,
        // enleve un mouvement


        clearTerrain();
        // action effectué
        sonModele->item(previous.row(), previous.column())->setData(QVariant(true), 34);
    }

    else if(!sonModele->item(previous.row(), previous.column())->data(34).toBool() && (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(previous.row(), previous.column())->data(33).toBool() == sonModele->item(current.row(), current.column())->data(33).toBool()))
    {
        // on effectue une passe ou transmission si le joueur a le ballon :
//        if(ballon->row())
//        {
//            clearTerrain();
//            // action effectue :
//            sonModele->item(previous.row(), previous.column())->setData(QVariant(true), 34);
//        }
//        else
        firstClic(current, previous);
    }

}


void SceneTerrain::clearTerrain()
{
    sonParent->clearPanneauxJoueurs();
    for(int i(0); i<15; i++)
    {
        for(int j(0); j<28; j++)
        {
            if(sonModele->item(i, j)->data(45).toBool() && !sonModele->item(i, j)->data(43).toBool())
            {
                sonModele->item(i,j)->setData(QVariant(QBrush(QColor(177,0,0))), Qt::BackgroundRole);
            }
            else
            sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
        }
    }
    fClic = 1;
}


void SceneTerrain::mouseReleaseEvent(QMouseEvent *event)
{
    int action(2);
    if(sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(33).toBool() && sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(45).toBool())
        {
        action = 0;
        std::cout<<"Joueur bleu cliqué"<<std::endl;
        }
    else if(!sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(33).toBool() && sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(45).toBool())
        {
        action = 1;
        std::cout<<"Joueur rouge cliqué releaseEvent"<<std::endl;
        }
    else
        {action = 2;}

    emit cliqueTerrain(action, sonModele->item(rowAt(event->y()), columnAt(event->x())));
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


void SceneTerrain::afficheZonesTacle(Equipe * uneEquipe)
{
    std::map<int, std::vector<QStandardItem* >* >::iterator itMap;
    lesZonesTacle = uneEquipe->zonesTacle();
    for(itMap = lesZonesTacle->begin(); itMap != lesZonesTacle->end(); itMap++)
    {
        std::vector<QStandardItem* >::iterator itVect;
        for(itVect = itMap->second->begin(); itVect != itMap->second->end(); itVect++)
        {
            (*itVect)->setData(QVariant(QBrush(QColor(241,132,22))), Qt::BackgroundRole);
        }
    }

}

bool SceneTerrain::esquive(int row, int column)
{
    bool enZone = false;
    int penalite = 0;
    std::map<int, std::vector<QStandardItem* >* >::iterator itMap;
    for(itMap = lesZonesTacle->begin(); itMap != lesZonesTacle->end(); itMap++)
    {
        std::vector<QStandardItem* >::iterator itVect;
        for(itVect = itMap->second->begin(); itVect != itMap->second->end(); itVect++)
        {
            if(sonModele->item(row, column)==(*itVect))
            {
                penalite++;
                enZone = true;
            }
        }
    }

    if(enZone)
    {
        // esquive
        int de = sonParent->getLeMatch()->lancer1D6();
        sonParent->updateResultatsDes(de);
        if((de + sonModele->item(row, column)->data(37).toInt() - penalite) >= 7)
        {
            return true;
        }
        else
        {
            sonModele->item(row, column)->setData(QVariant(false), 43);
            sonModele->item(row,  column)->setData(QVariant(true), 34);
            sonParent->getLeMatch()->turnover(0);
            return false;
        }
    }
    else
    {
        return true;
    }
}
