#include <QtGui/QApplication>
#include "FenetrePrincipale.h"
#include "case.h"
#include "equipe.h"
#include "match.h"
#include "terrain.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FenetrePrincipale laFenetre;
    laFenetre.show();

    return app.exec();
}
