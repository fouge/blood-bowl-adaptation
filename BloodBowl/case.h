#ifndef CASE_H
#define CASE_H

#include <QLabel>
#include "joueur.h"
#include "joueurwidget.h"
#include "herbewidget.h"

class Joueur;
class JoueurWidget;
class HerbeWidget;

enum zone{enbut, laterale, engagement};

class Case
{
    int sonX, sonY;
    zone saZone;
    HerbeWidget* sonHerbe;
    QLabel* sonBallon;
    JoueurWidget* sonJoueurWidget;
    Joueur* sonJoueurDessus;
public:
    Case(int unX, int unY);
    int getLigne();
    int getColonne();
    zone getZone();
    HerbeWidget* getHerbe();
    JoueurWidget* getJoueurWidget();
    Joueur* getJoueurDessus();
    void setJoueurDessus(Joueur*);
    void setJoueurWidget(QPixmap* );
    void setSonHerbe(QPixmap* );


};

#endif // CASE_H
