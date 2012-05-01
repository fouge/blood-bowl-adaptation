#include "tablemodel.h"
#include <iostream>
#include <QApplication>


TableModel::TableModel(int rows, int columns): QStandardItemModel(rows, columns)
{

}


void TableModel::switchItems(QStandardItem *item1, QStandardItem *item2)
{


    QStandardItem *temp1 = item1->clone();
    QStandardItem *temp2 = item2->clone();

    std::vector<Joueur*>::iterator leIt;

    // REATTRIBUTION de l'ITEM :
    for(leIt = sonEquipe1->getSesJoueurs()->begin(); leIt != sonEquipe1->getSesJoueurs()->end(); leIt++)
    {
        if(item1->data(39).toInt() == (*leIt)->getId())
        {
            (*leIt)->setItem(temp1);
        }
    }
    for(leIt = sonEquipe2->getSesJoueurs()->begin(); leIt != sonEquipe2->getSesJoueurs()->end(); leIt++)
    {
        if(item1->data(39).toInt() == (*leIt)->getId())
        {
            (*leIt)->setItem(temp1);
        }
    }

    setItem(item1->row(), item1->column(), temp2);
    setItem(item2->row(), item2->column(), temp1);


}

void TableModel::resetAllJoueurs()
{

}

void TableModel::setEquipes(Equipe * Equipe1, Equipe * Equipe2)
{
    sonEquipe1=Equipe1;
    sonEquipe2=Equipe2;
}

