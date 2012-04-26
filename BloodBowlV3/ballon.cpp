#include "ballon.h"

Ballon::Ballon(Match* unMatch, QStandardItemModel* unModele, int x, int y): sonMatch(unMatch), sonModele(unModele), sonX(x), sonY(y)
{
}

void Ballon::rebondir(QStandardItem *uneCase, int nRebondissements)
{
    int x(0);
    int y(0);
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
        if(x >=0 && x <16 && y>= 0 && y<29)
        {
            rebondir(sonModele->item(x,y), nRebondissements-1);
        }
        else
            rebondir(sonModele->item(uneCase->row(), uneCase->column()), nRebondissements-1);
    }

     //on met le ballon sur la bonne case :
   // sonModele->
    sonX = x;
    sonY = y;
}
