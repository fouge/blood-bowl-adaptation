#ifndef CASE_H
#define CASE_H

#include <QLabel>
#include <QStandardItem>
#include "ballon.h"
#include "enum.h"

class Ballon;
class Joueur;



class Case : public QStandardItem
{
    int sonX, sonY;
    zone saZone;
    Joueur* sonJoueurDessus;
public:
    Case(int unX, int unY, QPixmap*);
    int getLigne();
    int getColonne();
    zone getZone();
    Joueur* getJoueurDessus();
    void setJoueurDessus(Joueur* unJoueur);
    void setBallonDessus(Ballon* unBallon);
};

#endif // CASE_H
