#include "fenetreprincipale.h"

#include "tablemodel.h"

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
    //boutonNouvellePartie->setFont(policeBB);

    boutonQuitter->setCursor(Qt::PointingHandCursor);
   // boutonQuitter->setFont(policeBB);

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

    //boxSelectionRace->setFont(policeBB);
    //boxSelectionEquipe->setFont(policeBB);

    boutonValiderSelection->setFixedHeight(40);
    //boutonValiderSelection->setFont(policeBB);

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
    //cBRaceJ1->setFont(policeBB);
    //cBRaceJ2->setFont(policeBB);
    cBEquipeJ1->addItem("Mittledorf Smashers");
    cBEquipeJ1->addItem("Holy Revengers");
    cBEquipeJ1->addItem("Reikland Reavers");
    cBEquipeJ2->addItem("Mittledorf Smashers");
    cBEquipeJ2->addItem("Holy Revengers");
    cBEquipeJ2->addItem("Reikland Reavers");
    //cBEquipeJ1->setFont(policeBB);
    //cBEquipeJ2->setFont(policeBB);

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

    setWindowTitle("Blood Bowl");
    barreSuperieure = new QHBoxLayout;
    panneauJ1 = new QGridLayout;
    panneauJ2 = new QGridLayout;
    boxJoueurJ1 = new QGroupBox(this);
    boxJoueurJ2 = new QGroupBox(this);
    boxJoueurJ1Layout = new QGridLayout(boxJoueurJ1);
    boxJoueurJ2Layout = new QGridLayout(boxJoueurJ2);
    texteEquipeJ1 = new QLabel(this);
    texteEquipeJ2 = new QLabel(this);
    scoreEquipeJ1 = new QLabel("0", this);
    scoreEquipeJ2 = new QLabel("0", this);
    texteRelancesJ1 = new QLabel("Relances :", this);
    nbRelancesJ1 = new QLabel("0", this);
    texteRelancesJ2 = new QLabel(": Relances", this);
    nbRelancesJ2 = new QLabel("0", this);
    texteTourJ1 = new QLabel("Tour :", this);
    nbTourJ1 = new QLabel("0", this);
    texteTourJ2 = new QLabel(": Tour", this);
    nbTourJ2 = new QLabel("0", this);
    iconEquipeJ1 = new QLabel(this);
    iconEquipeJ2 = new QLabel(this);
    finDeTourC1 = new QPushButton("Fin de Tour", this);
    finDeTourC2 = new QPushButton("Fin de Tour", this);

    //Instanciation contenu BoxJoueurJ1
    mouvementJ1 = new QLabel("Mouvement :", this);
    agiliteJ1 = new QLabel("Agilité :", this);
    forceJ1 = new QLabel("Force :", this);
    armureJ1 = new QLabel("Armure :", this);
    nomJ1 = new QLabel("Nom : ", this);
    posteJ1 = new QLabel("Poste : ", this);
    mouvementJ1Chiffre = new QLabel("0",this);
    agiliteJ1Chiffre = new QLabel("0",this);
    forceJ1Chiffre = new QLabel("0",this);
    armureJ1Chiffre = new QLabel("0",this);
    nomJ1Texte = new QLabel("",this);
    posteJ1Texte = new QLabel("",this);

    //Instanciation contenu BoxJoueurJ2
    mouvementJ2 = new QLabel(": Mouvement", this);
    agiliteJ2 = new QLabel(": Agilité", this);
    forceJ2 = new QLabel(": Force", this);
    armureJ2 = new QLabel(": Armure", this);
    nomJ2 = new QLabel(": Nom", this);
    posteJ2 = new QLabel(": Poste", this);
    mouvementJ2Chiffre = new QLabel("0",this);
    agiliteJ2Chiffre = new QLabel("0",this);
    forceJ2Chiffre = new QLabel("0",this);
    armureJ2Chiffre = new QLabel("0",this);
    nomJ2Texte = new QLabel("",this);
    posteJ2Texte = new QLabel("",this);

    //
    //Initialisation de la barre superieure
    //
    texteEquipeJ2->setAlignment(Qt::AlignRight);
    scoreEquipeJ1->setAlignment(Qt::AlignRight);

    if (raceEquipeJ1 == humains)
    {
        switch (indexEquipeJ1)
        {
        case 0:
            texteEquipeJ1->setText("Mittledorf Smashers");
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/mittledorfsmashersicon.png"));
            break;
        case 1:
            texteEquipeJ1->setText("Holy Revengers");
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/holyrevengersicon.png"));
            break;
        case 2:
            texteEquipeJ1->setText("Reikland Reavers");
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/reiklandreaversicon.png"));
            break;
        }
    }
    if (raceEquipeJ1 == orques)
    {
        switch (indexEquipeJ1)
        {
        case 0:
            texteEquipeJ1->setText("Da Severed 'Eads");
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/daseveredeadsicon.png"));
            break;
        case 1:
            texteEquipeJ1->setText("Greenskin Gutrippers");
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/greenskingutrippersicon.png"));
            break;
        case 2:
            texteEquipeJ1->setText("Ironcrag Decimators");
            iconEquipeJ1->setPixmap(QPixmap("images/equipeicon/ironcragdecimatorsicon.png"));
            break;
        }
    }
    if (raceEquipeJ2 == humains)
    {
        switch (indexEquipeJ2)
        {
        case 0:
            texteEquipeJ2->setText("Mittledorf Smashers");
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/mittledorfsmashersicon.png"));
            break;
        case 1:
            texteEquipeJ2->setText("Holy Revengers");
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/holyrevengersicon.png"));
            break;
        case 2:
            texteEquipeJ2->setText("Reikland Reavers");
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/reiklandreaversicon.png"));
            break;
        }
    }
    if (raceEquipeJ2 == orques)
    {
        switch (indexEquipeJ2)
        {
        case 0:
            texteEquipeJ2->setText("Da Severed 'Eads");
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/daseveredeadsicon.png"));
            break;
        case 1:
            texteEquipeJ2->setText("Greenskin Gutrippers");
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/greenskingutrippersicon.png"));
            break;
        case 2:
            texteEquipeJ2->setText("Ironcrag Decimators");
            iconEquipeJ2->setPixmap(QPixmap("images/equipeicon/ironcragdecimatorsicon.png"));
            break;
        }
    }

    barreSuperieure->addWidget(texteEquipeJ1);
    barreSuperieure->addWidget(scoreEquipeJ1);
    barreSuperieure->addWidget(scoreEquipeJ2);
    barreSuperieure->addWidget(texteEquipeJ2);

    //
    //Initialisation du panneau du joueur 1
    //
    boxJoueurJ1Layout->addWidget(nomJ1,0,0);
    boxJoueurJ1Layout->addWidget(nomJ1Texte,0,1);
    boxJoueurJ1Layout->addWidget(posteJ1,1,0);
    boxJoueurJ1Layout->addWidget(posteJ1Texte,1,1);
    boxJoueurJ1Layout->addWidget(mouvementJ1,3,0);
    boxJoueurJ1Layout->addWidget(mouvementJ1Chiffre,3,1);
    boxJoueurJ1Layout->addWidget(agiliteJ1,4,0);
    boxJoueurJ1Layout->addWidget(agiliteJ1Chiffre,4,1);
    boxJoueurJ1Layout->addWidget(forceJ1,5,0);
    boxJoueurJ1Layout->addWidget(forceJ1Chiffre,5,1);
    boxJoueurJ1Layout->addWidget(armureJ1,6,0);
    boxJoueurJ1Layout->addWidget(armureJ1Chiffre,6,1);

    panneauJ1->addWidget(iconEquipeJ1,0,0,4,3);
    panneauJ1->addWidget(texteRelancesJ1,4,0,2,1);
    panneauJ1->addWidget(nbRelancesJ1,4,2,1,1);
    panneauJ1->addWidget(texteTourJ1,5,0,2,1);
    panneauJ1->addWidget(nbTourJ1,5,2,1,1);
    panneauJ1->addWidget(boxJoueurJ1,6,0,7,3);
    panneauJ1->addWidget(finDeTourC1,14,0,3,3);

    nomJ1->setAlignment(Qt::AlignLeft);
    posteJ1->setAlignment(Qt::AlignLeft);
    mouvementJ1->setAlignment(Qt::AlignLeft);
    mouvementJ1Chiffre->setAlignment(Qt::AlignRight);
    agiliteJ1->setAlignment(Qt::AlignLeft);
    agiliteJ1Chiffre->setAlignment(Qt::AlignRight);
    forceJ1->setAlignment(Qt::AlignLeft);
    forceJ1Chiffre->setAlignment(Qt::AlignRight);
    armureJ1->setAlignment(Qt::AlignLeft);
    armureJ1Chiffre->setAlignment(Qt::AlignRight);
    texteRelancesJ1->setAlignment(Qt::AlignLeft);
    nbRelancesJ1->setAlignment(Qt::AlignRight);
    texteTourJ1->setAlignment(Qt::AlignLeft);
    nbTourJ1->setAlignment(Qt::AlignRight);

    //
    //Initialisation du panneau du joueur 2
    //
    boxJoueurJ2Layout->addWidget(nomJ2,0,1);
    boxJoueurJ2Layout->addWidget(nomJ2Texte,0,0);
    boxJoueurJ2Layout->addWidget(posteJ2,1,1);
    boxJoueurJ2Layout->addWidget(posteJ2Texte,1,0);
    boxJoueurJ2Layout->addWidget(mouvementJ2,3,1);
    boxJoueurJ2Layout->addWidget(mouvementJ2Chiffre,3,0);
    boxJoueurJ2Layout->addWidget(agiliteJ2,4,1);
    boxJoueurJ2Layout->addWidget(agiliteJ2Chiffre,4,0);
    boxJoueurJ2Layout->addWidget(forceJ2,5,1);
    boxJoueurJ2Layout->addWidget(forceJ2Chiffre,5,0);
    boxJoueurJ2Layout->addWidget(armureJ2,6,1);
    boxJoueurJ2Layout->addWidget(armureJ2Chiffre,6,0);

    panneauJ2->addWidget(iconEquipeJ2,0,0,4,3);
    panneauJ2->addWidget(texteRelancesJ2,4,1,1,2);
    panneauJ2->addWidget(nbRelancesJ2,4,0,1,1);
    panneauJ2->addWidget(texteTourJ2,5,1,1,2);
    panneauJ2->addWidget(nbTourJ2,5,0,1,1);
    panneauJ2->addWidget(boxJoueurJ2,6,0,7,3);
    panneauJ2->addWidget(finDeTourC2,14,0,3,3);

    nomJ2->setAlignment(Qt::AlignRight);
    posteJ2->setAlignment(Qt::AlignRight);
    mouvementJ2->setAlignment(Qt::AlignRight);
    mouvementJ2Chiffre->setAlignment(Qt::AlignLeft);
    agiliteJ2->setAlignment(Qt::AlignRight);
    agiliteJ2Chiffre->setAlignment(Qt::AlignLeft);
    forceJ2->setAlignment(Qt::AlignRight);
    forceJ2Chiffre->setAlignment(Qt::AlignLeft);
    armureJ2->setAlignment(Qt::AlignRight);
    armureJ2Chiffre->setAlignment(Qt::AlignLeft);
    texteRelancesJ2->setAlignment(Qt::AlignRight);
    nbRelancesJ2->setAlignment(Qt::AlignLeft);
    texteTourJ2->setAlignment(Qt::AlignRight);
    nbTourJ2->setAlignment(Qt::AlignLeft);

    leMatch = new Match(raceEquipeJ1,indexEquipeJ1,raceEquipeJ2,indexEquipeJ2);

    sonTerrain = new SceneTerrain(15, 28, leMatch->getModel());


    layoutGrille->setSizeConstraint(QLayout::SetMinimumSize);
    QGridLayout * terrainLayout = new QGridLayout(this);
    terrainLayout->addWidget(sonTerrain);


    layoutGrille->addLayout(panneauJ1,0,0,2,1);
    layoutGrille->addLayout(panneauJ2,0,4,2,1);
    layoutGrille->addLayout(barreSuperieure,0,1);
    layoutGrille->addLayout(terrainLayout, 1, 1);
}

//void FenetrePrincipale::rechargerFenetre();
//{
//delete sonTerrain;
//on refait le terrain
// on réaffiche tout

//}



/*void FenetrePrincipale::afficheJoueurPanneau(Joueur* unJoueur)
{
    if(unJoueur->getSonCote() == true)
    {

    }
}*/
