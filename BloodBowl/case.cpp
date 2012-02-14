#include "case.h"


Case::Case(int unX, int unY):sonX(unX),sonY(unY)
{
    sonJoueurDessus = 0;
    sonHerbe = new HerbeWidget(this);
    sonJoueur = new JoueurWidget(this);
    if(sonX == 1)
    {
        saZone = enbut;
        sonHerbe->setPixmap(QPixmap("images/terrain/herbeEnButGauche.png"));
    }
    if(sonX == 26)
    {
        saZone = enbut;
        sonHerbe->setPixmap(QPixmap("images/terrain/herbeEnButDroite.png"));
    }
    if ((sonX >= 2 && sonX <=25 && sonY <= 4) || (sonX >= 2 && sonX <=25 && sonY >= 12))
    {
        saZone = laterale;
        sonHerbe->setPixmap(QPixmap("images/terrain/herbe.png"));
    }
    if (sonX >= 2 && sonX <=25 && sonY > 4 && sonY < 12)
    {
        saZone = engagement;
        sonHerbe->setPixmap(QPixmap("images/terrain/herbe.png"));
    }
    if (sonX == 13)
    {
        sonHerbe->setPixmap(QPixmap("images/terrain/herbeMilieuxGauche.png"));
    }
    if (sonX == 14)
    {
        sonHerbe->setPixmap(QPixmap("images/terrain/herbeMilieuxDroite.png"));
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

HerbeWidget* Case::getHerbe()
{
    return sonHerbe;
}
JoueurWidget* Case::getJoueur()
{
    return sonJoueur;
}

void Case::setSonJoueur(QPixmap* lien)
{
    sonJoueur->setPixmap(*lien);
}
void Case::setSonHerbe(QPixmap* lien)
{
    sonHerbe->setPixmap(*lien);
}

