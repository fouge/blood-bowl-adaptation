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
            grilleTerrain->addWidget((*itColonne)->getJoueur(), j, i);

            // JoueurWidget toujours au dessus donc on ne peut cliquer que sur un JoueurWidget
            QObject::connect( (*itColonne)->getJoueur(), SIGNAL (cliqueJoueur(JoueurWidget*)), this, SLOT (afficheMvts(JoueurWidget*)) );
        }
    }
    grilleTerrain->setSpacing(1);
    setLayout(grilleTerrain);
}

void Terrain::afficheMvts(JoueurWidget* unJoueur)
{
    // si clique = false :
    if(!clique && unJoueur->getCase()->sonJoueurDessus != 0)
    {
        std::vector<Case*>::iterator leIt;
        std::vector<Case*>* lesCases = sonMatch->voirMouvementsPossibles(unJoueur->getCase());
        for(leIt = lesCases->begin(); leIt != lesCases->end(); leIt++)
        {
            (*leIt)->getHerbe()->setGraphicsEffect(new QGraphicsColorizeEffect());
        }
        unJoueur->setGraphicsEffect(new QGraphicsColorizeEffect());

        //envoyer les caractéristiques du joueur pour l'affichage :


        // aller dans une fonction pour attente d'un nouveau clique pour deplacement... :


        // on enregistre le joueur cliqué:
        sonJoueurClique = unJoueur;

        clique = true;
    }

    else if(clique)
    {
        if(unJoueur == sonJoueurClique)
        {
            std::vector<Case*>::iterator leIt;
            std::vector<Case*>* lesCases = sonMatch->voirMouvementsPossibles(unJoueur->getCase());
            for(leIt = lesCases->begin(); leIt != lesCases->end(); leIt++)
            {
                (*leIt)->getHerbe()->setGraphicsEffect(0);
            }
            unJoueur->setGraphicsEffect(0);


            // il faut modifier l'affichage :

        }




        sonJoueurClique = 0;
        clique = false;
    }





    //si clique = true ...
}


