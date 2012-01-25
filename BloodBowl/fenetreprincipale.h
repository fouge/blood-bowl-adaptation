#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QApplication>
#include <QtGui>
#include <QStringList>
#include <QInputDialog>

class FenetrePrincipale : public QWidget
{
    Q_OBJECT

    QLabel *bannierebb, *iconRace, *iconEquipe;
    QPushButton *boutonNouvellePartie, *boutonQuitter;
    QGroupBox *boxSelectionRace, *boxSelectionEquipe;
    QComboBox *comboBoxRace, *comboBoxEquipe;
    QVBoxLayout *layoutRace, *layoutEquipe;
    QGridLayout *layoutGrille;
public:
    FenetrePrincipale();
    void fenetreDemarrage();
public slots:
    void fenetreSelectionEquipe();
    void changerEquipes(int index);
    void changerIconEquipe(int index);
};

#endif // FENETREPRINCIPALE_H
