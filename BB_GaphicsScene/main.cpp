#include <QtGui/QApplication>
#include "fenetreprincipale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetrePrincipale laFenetre;
    laFenetre.show();

    return a.exec();
}