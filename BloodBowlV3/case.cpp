#include "case.h"

Case::Case(int unX, int unY, QPixmap* lePixmap): QStandardItem(QPixmap(*lePixmap), 0), sonX(unX),sonY(unY)
{

//setVisible = 0 ?
    if(sonX == 1)
    {
        saZone = enbut;
    }
    if(sonX == 26)
    {
        saZone = enbut;
    }
    if ((sonX >= 2 && sonX <=25 && sonY <= 4) || (sonX >= 2 && sonX <=25 && sonY >= 12))
    {
        saZone = laterale;
    }
    if (sonX >= 2 && sonX <=25 && sonY > 4 && sonY < 12)
    {
        saZone = engagement;
    }

}

int Case::getLigne()
{
    return sonX;
}

int Case::getColonne()
{
    return sonY;
}
zone Case::getZone()
{
    return saZone;
}


Joueur* Case::getJoueurDessus()
{
    return sonJoueurDessus;
}

void Case::setJoueurDessus(Joueur* unJoueur)
{
    sonJoueurDessus = unJoueur;
}

