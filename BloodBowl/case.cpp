#include "case.h"

Case::Case(int unX, int unY):sonX(unX),sonY(unY)
{
    if(sonX == 1 || sonX == 26)
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
    sonHerbe = new QLabel;
    sonHerbe->setPixmap(QPixmap("images/terrain/herbe.png"));
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

QLabel* Case::getHerbe()
{
    return sonHerbe;
}

