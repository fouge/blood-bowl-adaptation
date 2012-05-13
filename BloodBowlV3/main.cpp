/**
 * \file      main.cpp
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     S'exécute au lancement du programme
 *
 */

#include <QtGui/QApplication>
#include "fenetreprincipale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetrePrincipale w;
    w.show();

    return a.exec();
}
