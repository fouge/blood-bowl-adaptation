#ifndef JOUEUR_H
#define JOUEUR_H

#include <QVariant>

class Joueur : public QVariant
{
    int sonInt;
public:
   Joueur(int);
   int getInt();
signals:

public slots:

};
Q_DECLARE_METATYPE(Joueur);

#endif // JOUEUR_H
