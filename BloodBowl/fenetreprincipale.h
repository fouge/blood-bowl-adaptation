#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QApplication>
#include <QtGui>
#include <QStringList>
#include <QInputDialog>
#include "match.h"

class FenetrePrincipale : public QWidget
{
    Q_OBJECT

    QLabel *bannierebb, *iconRaceJ1, *iconRaceJ2, *iconEquipeJ1, *iconEquipeJ2;
    QPushButton *boutonNouvellePartie, *boutonQuitter, *boutonValiderSelection;
    QGroupBox *boxSelectionRace, *boxSelectionEquipe;
    QComboBox *cBRaceJ1, *cBRaceJ2, *cBEquipeJ1, *cBEquipeJ2;
    QVBoxLayout *gBoxSelecJ1, *gBoxSelecJ2, *fenetreSelection;
    QGridLayout *layoutGrille;
    Match *leMatch;
public:
    FenetrePrincipale();
    void fenetreDemarrage();
    void fenetreMatch(race, int, race, int);
public slots:
    void fenetreSelectionEquipe();
    void changerEquipesJ1(int index);
    void changerEquipesJ2(int index);
    void changerIconEquipeJ1(int index);
    void changerIconEquipeJ2(int index);
    void validationSelectionEquipes();
};

#endif // FENETREPRINCIPALE_H
