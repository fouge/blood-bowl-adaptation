#include "ballon.h"
#include <time.h>
#include <iostream>

Ballon::Ballon(Match* unMatch, TableModel* unModele, SceneTerrain* unTerrain, int x, int y): sonMatch(unMatch), sonModele(unModele), sonTerrain(unTerrain), sonX(x), sonY(y)
{
}

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

int Ballon::row()
{
    return sonX;
}
int Ballon::column()
{
    return sonY;
}
void Ballon::setColumn(int column)
{
    sonY = column;
}
void Ballon::setRow(int row)
{
    sonX = row;
}
