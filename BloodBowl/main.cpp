#include <QtGui/QApplication>
#include "mainwindow.h"
#include "FenetrePrincipale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetrePrincipale laFenetre;
    laFenetre.show();

    return a.exec();
}
