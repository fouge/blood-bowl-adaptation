#include "fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale()
{
    fenetreDemarrage();
}

void FenetrePrincipale::fenetreDemarrage()
{
    setWindowTitle("Blood Bowl");
    setWindowIcon(QIcon("images/iconbb.png"));

    layoutGrille = new QGridLayout();

    bannierebb = new QLabel();
    boutonNouvellePartie = new QPushButton("Nouvelle Partie");
    boutonQuitter = new QPushButton("Quitter");

    boutonNouvellePartie->setCursor(Qt::PointingHandCursor);

    boutonQuitter->setCursor(Qt::PointingHandCursor);

    bannierebb->setPixmap(QPixmap("images/ihmbb.png"));

    layoutGrille->addWidget(bannierebb,0,0);
    layoutGrille->addWidget(boutonNouvellePartie,1,0);
    layoutGrille->addWidget(boutonQuitter,2,0);

    this->setLayout(layoutGrille);
    QObject::connect(boutonNouvellePartie, SIGNAL(clicked()), this,
                     SLOT(fenetreSelectionEquipe()));
    QObject::connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void FenetrePrincipale::fenetreSelectionEquipe()
{
    delete(bannierebb);
    delete(boutonNouvellePartie);
    delete(boutonQuitter);

    layoutRace = new QVBoxLayout;
    layoutEquipe = new QVBoxLayout;
    boxSelectionRace = new QGroupBox("Selection Race :",this);
    boxSelectionEquipe = new QGroupBox("Selection Equipe",this);
    comboBoxRace = new QComboBox(this);
    comboBoxEquipe = new QComboBox(this);
    iconRace = new QLabel(this);
    iconEquipe = new QLabel(this);

    iconRace->setPixmap(QPixmap("images/iconhumainbb.png"));
    iconEquipe->setPixmap(QPixmap("images/iconequipebb.png"));

    comboBoxRace->addItem("Humain");
    comboBoxRace->addItem("Orque");
    comboBoxEquipe->addItem("Mittledorf Smashers");
    comboBoxEquipe->addItem("Holy Revengers");
    comboBoxEquipe->addItem("Reikland Reavers");

    layoutRace->addWidget(iconRace);
    layoutRace->addWidget(comboBoxRace);
    layoutEquipe->addWidget(iconEquipe);
    layoutEquipe->addWidget(comboBoxEquipe);
    layoutGrille->addWidget(boxSelectionRace,0,0);
    layoutGrille->addWidget(boxSelectionEquipe,0,1);

    boxSelectionRace->setLayout(layoutRace);
    boxSelectionEquipe->setLayout(layoutEquipe);
    this->setLayout(layoutGrille);

    QObject::connect(comboBoxRace, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(changerEquipes(int)));
    QObject::connect(comboBoxEquipe, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(changerIconEquipe(int)));
}

void FenetrePrincipale::changerEquipes(int index)
{
    switch(index)
    {
        case 0:
            comboBoxEquipe->clear();
            comboBoxEquipe->addItem("Mittledorf Smashers");
            comboBoxEquipe->addItem("Holy Revengers");
            comboBoxEquipe->addItem("Reikland Reavers");
            iconRace->setPixmap(QPixmap("images/iconhumainbb.png"));
            break;
        case 1:
            comboBoxEquipe->clear();
            comboBoxEquipe->addItem("Da Severed Eads");
            comboBoxEquipe->addItem("Greenskin Gutrippers");
            comboBoxEquipe->addItem("Ironcrag Decimators");
            iconRace->setPixmap(QPixmap("images/iconorquebb.png"));
            break;
    }
}

void FenetrePrincipale::changerIconEquipe(int index)
{
    switch(index)
    {
    case 0:
        if (comboBoxRace->currentIndex() == 0)
            iconEquipe->setPixmap(QPixmap("images/iconequipebb.png"));
        if (comboBoxRace->currentIndex() == 1)
            iconEquipe->setPixmap(QPixmap("images/equipe4"));
        break;
    case 1:
        if (comboBoxRace->currentIndex() == 0)
            iconEquipe->setPixmap(QPixmap("images/equipe2"));
        if (comboBoxRace->currentIndex() == 1)
            iconEquipe->setPixmap(QPixmap("images/equipe5"));
        break;
    case 2:
        if (comboBoxRace->currentIndex() == 0)
            iconEquipe->setPixmap(QPixmap("images/equipe3"));
        if (comboBoxRace->currentIndex() == 1)
            iconEquipe->setPixmap(QPixmap("images/equipe6"));
        break;
    }
    minimumSize();
}
