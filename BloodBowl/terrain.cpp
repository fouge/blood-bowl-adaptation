#include "terrain.h"

Terrain::Terrain(std::vector<std::vector<Case*>*> * unTerrain)
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
        }
    }
    grilleTerrain->setSpacing(1);
    setLayout(grilleTerrain);

}
