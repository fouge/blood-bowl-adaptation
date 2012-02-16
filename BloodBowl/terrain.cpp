#include "terrain.h"

Terrain::Terrain(std::vector<std::vector<Case*>*> * unTerrain, Match* unMatch): sonTerrain(unTerrain), sonMatch(unMatch), clique(false)
{
    grilleTerrain = new QGridLayout;
    int i(0), j(0);
    std::vector<std::vector<Case*>*>::iterator itLigne;
    std::vector<Case*>::iterator itColonne;
    for(itLigne = unTerrain->begin(); itLigne != unTerrain->end(); itLigne++, i++)
    {
        for(itColonne = (*itLigne)->begin(), j=0; itColonne != (*itLigne)->end(); itColonne++, j++)
        {
            //on affiche les QLabel (les images) de chaque case.
            grilleTerrain->addWidget((*itColonne)->getHerbe(), j, i);
            grilleTerrain->addWidget((*itColonne)->getJoueurWidget(), j, i);

            // JoueurWidget toujours au dessus donc on ne peut cliquer que sur un JoueurWidget
            QObject::connect( (*itColonne)->getJoueurWidget(), SIGNAL (cliqueJoueur(JoueurWidget*)), this, SLOT (joueurOnReleaseEvent(JoueurWidget*)) );
        }
    }
    grilleTerrain->setSpacing(1);
    setLayout(grilleTerrain);
}

void Terrain::joueurOnReleaseEvent(JoueurWidget* unJoueur)
{
    // si premier clic :
    if(!clique)
    {
        sonMatch->firstClic(unJoueur->getCase()->getJoueurDessus());
        clique = true;
    }

    //si un clique deja effectué :
    else if(clique)
    {
        sonMatch->secondClic(unJoueur->getCase()->getJoueurDessus());
        clique = false;
    }

}




