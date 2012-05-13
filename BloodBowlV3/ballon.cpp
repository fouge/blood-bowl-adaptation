/**
 * \file      ballon.cpp
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Définition de la classe \b Ballon
 *
 */

/** \class Ballon ballon.h "ballon.h" */
#include "ballon.h"

#include <time.h>
#include <iostream>


Ballon::Ballon(Match* unMatch, TableModel* unModele, SceneTerrain* unTerrain, int x, int y): sonMatch(unMatch), sonModele(unModele), sonTerrain(unTerrain), sonX(x), sonY(y)
{
}


/**
 * \brief       Calcule la distance entre deux points
 * \details     Méthode récursive qui \b place le ballon aléatoirement autour de la position de sa \a case un nombre de fois défini par \a nRebondissements
 * \param       \e QStandardItem*         Item correspondant à la case du tableau dans laquelle le \b ballon se trouve
 * \param       \e int                    Nombre de rebondissements à effectuer
 * \return      \e void
 */
void Ballon::rebondir(QStandardItem *uneCase, int nRebondissements)
{
    int x(uneCase->row());
    int y(uneCase->column());
    srand(time(NULL));
    if(nRebondissements>0)
    {
        switch(rand() % 8 + 1)
        {
        case 1: x = uneCase->row() -1;
                y = uneCase->column() -1;
                break;
        case 2: x = uneCase->row() -1;
                y = uneCase->column();
                break;
        case 3: x = uneCase->row() -1;
                y = uneCase->column() +1;
                break;
        case 4: x = uneCase->row();
                y = uneCase->column() -1;
                break;
        case 5: x = uneCase->row();
                y = uneCase->column() +1;
                break;
        case 6: x = uneCase->row() +1;
                y = uneCase->column() -1;
                break;
        case 7: x = uneCase->row() +1;
                y = uneCase->column();
                break;
        case 8: x = uneCase->row() +1;
                y = uneCase->column() +1;
                break;
        default: ;
        }
        if(x<0)
            x++;
        if(x>14)
            x--;
        if(y<0)
            y++;
        if(y>=26)
            y--;
            std::cout<<"Autre rebond à partir de la case ("<<x<<","<<y<<")"<<std::endl;
            sonX = x;
            sonY = y;
            rebondir(sonModele->item(x,y), nRebondissements-1);

    }
    sonTerrain->recevoirBallon(sonX, sonY);
    sonTerrain->placeBallon(sonX, sonY);
}

/**
 * \brief       Accesseur qui retourne la ligne
 * \details     Retourne la \b ligne ( \a row )
 * \return      \e int
 */
int Ballon::row()
{
    return sonX;
}

/**
 * \brief       Accesseur qui retourne la colonne
 * \details     Retourne la \b colonne ( \a column )
 * \return      \e int
 */
int Ballon::column()
{
    return sonY;
}

/**
 * \brief       Mutateur de colonne ( \a column )
 * \return      \e void
 */
void Ballon::setColumn(int column)
{
    sonY = column;
}

/**
 * \brief       Mutateur de ligne ( \a row )
 * \return      \e void
 */
void Ballon::setRow(int row)
{
    sonX = row;
}
