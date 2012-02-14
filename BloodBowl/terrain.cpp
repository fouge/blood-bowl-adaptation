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
    if(!clique && unJoueur->getCase()->sonJoueurDessus != 0 && unJoueur->getCase()->sonJoueurDessus->getMouvements() > 0)
    {
        //on modifie l'affichage de la case :
        std::vector<Case*>::iterator leIt;
        std::vector<Case*>* lesCases = sonMatch->voirMouvementsPossibles(unJoueur->getCase());
        for(leIt = lesCases->begin(); leIt != lesCases->end(); leIt++)
        {
            (*leIt)->getHerbe()->setGraphicsEffect(new QGraphicsColorizeEffect());
        }
        unJoueur->setGraphicsEffect(new QGraphicsColorizeEffect());


        sonMatch->firstClic(unJoueur->getCase()->sonJoueurDessus);


        // on enregistre le joueur cliqué:
        sonJoueurClique = unJoueur;

        clique = true;
    }
    else if(!clique && unJoueur->getCase()->sonJoueurDessus != 0 && unJoueur->getCase()->sonJoueurDessus->getMouvements() == 0)
    {
        unJoueur->getCase()->getHerbe()->setGraphicsEffect(new QGraphicsColorizeEffect());
        unJoueur->setGraphicsEffect(new QGraphicsColorizeEffect());
        // on change pas la valeur de clique puisque le joueur ne peut rien faire, on attend un nouvel element cliquable
    }

    //si un clique deja effectué :
        //on reclique sur le meme joueur :
    else if(clique && unJoueur == sonJoueurClique)
    {
            std::vector<Case*>::iterator leIt;
            std::vector<Case*>* lesCases = sonMatch->voirMouvementsPossibles(unJoueur->getCase());
            for(leIt = lesCases->begin(); leIt != lesCases->end(); leIt++)
            {
                (*leIt)->getHerbe()->setGraphicsEffect(0);
            }
            unJoueur->setGraphicsEffect(0);

            //on enleve le joueur clique :
            sonJoueurClique = 0;
            clique = false;
    }

        //on clique sur une case voisine :
    else if( unJoueur != sonJoueurClique )
    {
        //on deplace le joueur sur la nouvelle case :

        // on modifie l'affichage :

        // puis on modifie le jeu
    }

}





    //si clique = true ...



