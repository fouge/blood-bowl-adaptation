/**
 * \file      tablemodel.cpp
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Définition de la classe \b TableModel
 * \details   Cette classe hérite de QStandardItemModel pour
 *            convenir aux spécificités des différents modèles possibles.
 */



/** \class TableModel tablemodel.h "tablemodel.h" */
#include "tablemodel.h"

#include <iostream>
#include <QApplication>


TableModel::TableModel(int rows, int columns): QStandardItemModel(rows, columns)
{

}


void TableModel::switchItems(QStandardItem *item1Joueur, QStandardItem *item2Herbe)
{


    QStandardItem *temp1 = item1Joueur->clone();
    QStandardItem *temp2 = item2Herbe->clone();

    std::vector<Joueur*>::iterator leIt;

    // REATTRIBUTION de l'ITEM :
    for(leIt = sonEquipe1->getSesJoueurs()->begin(); leIt != sonEquipe1->getSesJoueurs()->end(); leIt++)
    {
        if(item1Joueur->data(39).toInt() == (*leIt)->getId())
        {
            (*leIt)->setItem(temp1);
        }
    }
    for(leIt = sonEquipe2->getSesJoueurs()->begin(); leIt != sonEquipe2->getSesJoueurs()->end(); leIt++)
    {
        if(item1Joueur->data(39).toInt() == (*leIt)->getId())
        {
            (*leIt)->setItem(temp1);
        }
    }

    setItem(item1Joueur->row(), item1Joueur->column(), temp2);
    setItem(item2Herbe->row(), item2Herbe->column(), temp1);


}

void TableModel::resetAllJoueurs()
{

}

void TableModel::setEquipes(Equipe * Equipe1, Equipe * Equipe2)
{
    sonEquipe1=Equipe1;
    sonEquipe2=Equipe2;
}
