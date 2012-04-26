#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QApplication>
#include <QtGui>
#include "match.h"
#include "sceneterrain.h"

class SceneTerrain;

class FenetrePrincipale : public QWidget
{
    Q_OBJECT

    //QLabel fenetreDemarrage + fenetreSelectionEquipe
    QLabel *bannierebb, *iconRaceJ1, *iconRaceJ2, *iconEquipeJ1, *iconEquipeJ2;

    //QLabel Barre Superieure
    QLabel  *texteEquipeJ1, *texteEquipeJ2, *scoreEquipeJ1, *scoreEquipeJ2;

    //QLabel Panneau Coach 1
    QLabel  *texteRelancesJ1, *nbRelancesJ1, *texteTourJ1, *nbTourJ1,
            *mouvementJ1, *forceJ1, *agiliteJ1, *armureJ1, *nomJ1, *posteJ1,
            *mouvementJ1Chiffre, *forceJ1Chiffre, *agiliteJ1Chiffre, *armureJ1Chiffre,
            *nomJ1Texte, *posteJ1Texte;

    //QLabel Panneau Coach 2
    QLabel  *texteRelancesJ2, *nbRelancesJ2,*texteTourJ2, *nbTourJ2,
            *mouvementJ2, *forceJ2,*agiliteJ2,*armureJ2,*nomJ2, *posteJ2,
            *mouvementJ2Chiffre, *forceJ2Chiffre, *agiliteJ2Chiffre, *armureJ2Chiffre,
            *nomJ2Texte, *posteJ2Texte;

    QPushButton *boutonNouvellePartie, *boutonQuitter, *boutonValiderSelection,
                *finDeTourC1, *finDeTourC2;
    QGroupBox *boxSelectionRace, *boxSelectionEquipe, *boxJoueurJ1, *boxJoueurJ2;
    QComboBox *cBRaceJ1, *cBRaceJ2, *cBEquipeJ1, *cBEquipeJ2;
    QVBoxLayout *gBoxSelecJ1, *gBoxSelecJ2, *fenetreSelection;
    QHBoxLayout *barreSuperieure;
    QGridLayout *layoutGrille, *panneauJ1, *panneauJ2, *boxJoueurJ1Layout, *boxJoueurJ2Layout, *terrain;


    QPixmap *pixEquipe1, *pixEquipe2;
    SceneTerrain* sonTerrain;
    Match* leMatch;
public:
    FenetrePrincipale();
    void fenetreDemarrage();
    void fenetreMatch(race, int, race, int);
    void clearPanneauxJoueurs();
    Match* getLeMatch();
public slots:
    void fenetreSelectionEquipe();
    void changerEquipesJ1(int index);
    void changerEquipesJ2(int index);
    void changerIconEquipeJ1(int index);
    void changerIconEquipeJ2(int index);
    void validationSelectionEquipes();
    void updatePanneauJoueur(int action, QStandardItem* leJoueur);


    // a implementer :
    void finDeTour();
    void changementJoueur();
};

#endif // FENETREPRINCIPALE_H
