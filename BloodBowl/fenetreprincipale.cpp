#include "fenetreprincipale.h"
#include "case.h"

FenetrePrincipale::FenetrePrincipale()
{
    fenetreDemarrage();
}

void FenetrePrincipale::fenetreDemarrage()
{
    setWindowTitle("Blood Bowl");
    setWindowIcon(QIcon("images/iconbb.png"));
    setPalette(QPalette(QColor(250, 250, 250)));

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

    setWindowTitle("Selection des Equipes");

    gBoxSelecJ1 = new QVBoxLayout;
    gBoxSelecJ2 = new QVBoxLayout;
    boxSelectionRace = new QGroupBox("Joueur 1 : ",this);
    boxSelectionEquipe = new QGroupBox("Joueur 2 : ",this);
    cBRaceJ1 = new QComboBox(this);
    cBRaceJ2 = new QComboBox(this);
    cBEquipeJ1 = new QComboBox(this);
    cBEquipeJ2 = new QComboBox(this);
    iconRaceJ1 = new QLabel(this);
    iconRaceJ2 = new QLabel(this);
    iconEquipeJ1 = new QLabel(this);
    iconEquipeJ2 = new QLabel(this);
    boutonValiderSelection = new QPushButton("Confirmer");

    boutonValiderSelection->setFixedHeight(40);

    iconRaceJ1->setPixmap(QPixmap("images/iconhumainbb.png"));
    iconRaceJ1->setAlignment(Qt::AlignCenter);
    iconRaceJ2->setPixmap(QPixmap("images/iconhumainbb.png"));
    iconRaceJ2->setAlignment(Qt::AlignCenter);
    iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/mittledorfsmashersicon.png"));
    iconEquipeJ1->setAlignment(Qt::AlignCenter);
    iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/mittledorfsmashersicon.png"));
    iconEquipeJ2->setAlignment(Qt::AlignCenter);

    cBRaceJ1->addItem("Humain");
    cBRaceJ1->addItem("Orque");
    cBRaceJ2->addItem("Humain");
    cBRaceJ2->addItem("Orque");
    cBEquipeJ1->addItem("Mittledorf Smashers");
    cBEquipeJ1->addItem("Holy Revengers");
    cBEquipeJ1->addItem("Reikland Reavers");
    cBEquipeJ2->addItem("Mittledorf Smashers");
    cBEquipeJ2->addItem("Holy Revengers");
    cBEquipeJ2->addItem("Reikland Reavers");

    gBoxSelecJ1->addWidget(iconRaceJ1);
    gBoxSelecJ1->addWidget(cBRaceJ1);
    gBoxSelecJ1->addWidget(iconEquipeJ1);
    gBoxSelecJ1->addWidget(cBEquipeJ1);
    gBoxSelecJ2->addWidget(iconRaceJ2);
    gBoxSelecJ2->addWidget(cBRaceJ2);
    gBoxSelecJ2->addWidget(iconEquipeJ2);
    gBoxSelecJ2->addWidget(cBEquipeJ2);
    layoutGrille->addWidget(boxSelectionRace,0,0);
    layoutGrille->addWidget(boxSelectionEquipe,0,1);
    layoutGrille->addWidget(boutonValiderSelection,1,0,1,2);

    boxSelectionRace->setLayout(gBoxSelecJ1);
    boxSelectionEquipe->setLayout(gBoxSelecJ2);
    this->setLayout(layoutGrille);



    QObject::connect(cBRaceJ1, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(changerEquipesJ1(int)));
    QObject::connect(cBRaceJ2, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(changerEquipesJ2(int)));
    QObject::connect(cBEquipeJ1, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(changerIconEquipeJ1(int)));
    QObject::connect(cBEquipeJ2, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(changerIconEquipeJ2(int)));
    QObject::connect(boutonValiderSelection, SIGNAL(clicked()), this,
                     SLOT(validationSelectionEquipes()));
}

void FenetrePrincipale::changerEquipesJ1(int index)
{
    switch(index)
    {
        case 0:
            cBEquipeJ1->clear();
            cBEquipeJ1->addItem("Mittledorf Smashers");
            cBEquipeJ1->addItem("Holy Revengers");
            cBEquipeJ1->addItem("Reikland Reavers");
            iconRaceJ1->setPixmap(QPixmap("images/iconhumainbb.png"));
            break;
        case 1:
            cBEquipeJ1->clear();
            cBEquipeJ1->addItem("Da Severed 'Eads");
            cBEquipeJ1->addItem("Greenskin Gutrippers");
            cBEquipeJ1->addItem("Ironcrag Decimators");
            iconRaceJ1->setPixmap(QPixmap("images/iconorquebb.png"));
            break;
    }
    iconRaceJ1->setAlignment(Qt::AlignCenter);
}

void FenetrePrincipale::changerEquipesJ2(int index)
{
    switch(index)
    {
        case 0:
            cBEquipeJ2->clear();
            cBEquipeJ2->addItem("Mittledorf Smashers");
            cBEquipeJ2->addItem("Holy Revengers");
            cBEquipeJ2->addItem("Reikland Reavers");
            iconRaceJ2->setPixmap(QPixmap("images/iconhumainbb.png"));
            break;
        case 1:
            cBEquipeJ2->clear();
            cBEquipeJ2->addItem("Da Severed 'Eads");
            cBEquipeJ2->addItem("Greenskin Gutrippers");
            cBEquipeJ2->addItem("Ironcrag Decimators");
            iconRaceJ2->setPixmap(QPixmap("images/iconorquebb.png"));
            break;
    }
    iconRaceJ2->setAlignment(Qt::AlignCenter);
}


void FenetrePrincipale::changerIconEquipeJ1(int index)
{
    switch(index)
    {
    case 0:
        if (cBRaceJ1->currentIndex() == 0)
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/mittledorfsmashersicon.png"));
        if (cBRaceJ1->currentIndex() == 1)
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/daseveredeadsicon.png"));
        break;
    case 1:
        if (cBRaceJ1->currentIndex() == 0)
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/holyrevengersicon.png"));
        if (cBRaceJ1->currentIndex() == 1)
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/greenskingutrippersicon.png"));
        break;
    case 2:
        if (cBRaceJ1->currentIndex() == 0)
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/reiklandreaversicon.png"));
        if (cBRaceJ1->currentIndex() == 1)
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/ironcragdecimatorsicon.png"));
        break;
    }
    iconEquipeJ1->setAlignment(Qt::AlignCenter);
}

void FenetrePrincipale::changerIconEquipeJ2(int index)
{
    switch(index)
    {
    case 0:
        if (cBRaceJ2->currentIndex() == 0)
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/mittledorfsmashersicon.png"));
        if (cBRaceJ2->currentIndex() == 1)
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/daseveredeadsicon.png"));
        break;
    case 1:
        if (cBRaceJ2->currentIndex() == 0)
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/holyrevengersicon.png"));
        if (cBRaceJ2->currentIndex() == 1)
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/greenskingutrippersicon.png"));
        break;
    case 2:
        if (cBRaceJ2->currentIndex() == 0)
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/reiklandreaversicon.png"));
        if (cBRaceJ2->currentIndex() == 1)
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/ironcragdecimatorsicon.png"));
        break;
    }
    iconEquipeJ2->setAlignment(Qt::AlignCenter);
}

void FenetrePrincipale::validationSelectionEquipes()
{
    int indexRaceJ1(cBRaceJ1->currentIndex()),
            indexRaceJ2(cBRaceJ2->currentIndex()),
            indexEquipeJ1(cBEquipeJ1->currentIndex()),
            indexEquipeJ2(cBEquipeJ2->currentIndex());
    race raceEquipeJ1, raceEquipeJ2;

    if(indexRaceJ1 == 0)
        raceEquipeJ1 = humains;
    if(indexRaceJ1 == 1)
        raceEquipeJ1 = orques;
    if(indexRaceJ2 == 0)
        raceEquipeJ2 = humains;
    if(indexRaceJ2 == 1)
        raceEquipeJ2 = orques;



    fenetreMatch(raceEquipeJ1,indexEquipeJ1,raceEquipeJ2,indexEquipeJ2);
}

void FenetrePrincipale::fenetreMatch(race raceEquipeJ1, int indexEquipeJ1, race raceEquipeJ2, int indexEquipeJ2)
{
    delete(iconRaceJ1);
    delete(iconRaceJ2);
    delete(iconEquipeJ1);
    delete(iconEquipeJ2);
    delete(cBRaceJ1);
    delete(cBRaceJ2);
    delete(cBEquipeJ1);
    delete(cBEquipeJ2);
    delete(boutonValiderSelection);
    delete(boxSelectionRace);
    delete(boxSelectionEquipe);

    leMatch = new Match(raceEquipeJ1,indexEquipeJ1,raceEquipeJ2,indexEquipeJ2);

    layoutGrille->addWidget(leMatch->getTerrain());
}


