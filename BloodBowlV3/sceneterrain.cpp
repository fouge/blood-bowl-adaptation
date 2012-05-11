#include "sceneterrain.h"
#include <QHeaderView>
#include "tablemodel.h"
#include "joueur.h"
#include <cstdio>
#include <iostream>
#include "enum.h"


SceneTerrain::SceneTerrain(int nLignes, int nColonnes, TableModel* unModele, FenetrePrincipale* parent):QTableView(),
    sonModele(unModele), joueurSelectionne(false), sonParent(parent), fClic(true), lesMouvementsPossibles(0), coupEnvoi(true)
{
    changementJoueur = false;
    setModel(sonModele);

    // init :
    for(int i=0; i<15; i++)
    {
        setRowHeight(i, 22);
    }
    for(int i=0; i<28; i++)
    {
        setColumnWidth(i, 22);
    }
    setFixedSize(618, 332);
    setCornerButtonEnabled(false);
    setSortingEnabled(false);
    this->verticalHeader()->setVisible(false);
    horizontalHeader()->setVisible(false);
    setEditTriggers(NoEditTriggers);
    setSelectionMode(QAbstractItemView::SingleSelection);
}


void SceneTerrain::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    this->update(topLeft);
    this->update(bottomRight);
}

void SceneTerrain::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{

    if(coupEnvoi)
    {
            sonBallon = new Ballon(sonParent->getLeMatch(), sonModele, current.row(), current.column());
            sonBallon->rebondir(sonModele->item(current.row(), current.column()), 3);
            clearTerrain();
            coupEnvoi = false;
    }
    else if(current.isValid() && previous.isValid() && fClic)
    {
        if((sonParent->getLeMatch()->getQuiJoue() == 0 && sonModele->item(current.row(), current.column())->data(33).toBool()) || (sonParent->getLeMatch()->getQuiJoue() != 0 && !sonModele->item(current.row(), current.column())->data(33).toBool()))
        firstClic(current, previous);
    }
    else if(current.isValid() && previous.isValid() && !fClic && sonParent->getLeMatch()->getQuiJoue() == !sonModele->item(previous.row(), previous.column())->data(33).toBool())
    {
        secondClic(current, previous);
    }
    else if(changementJoueur || (!previous.isValid() && current.isValid() && (((sonParent->getLeMatch()->getQuiJoue() == 0) && sonModele->item(current.row(), current.column())->data(33).toBool()) || ((sonParent->getLeMatch()->getQuiJoue() != 0) && !sonModele->item(current.row(), current.column())->data(33).toBool()))))
    {
        std::cout<<sonModele->item(current.row(), current.column())->data(43).toInt()<<std::endl;
        // si premier clic sur joueur :
        if(sonModele->item(current.row(), current.column())->data(45).toBool())
        {
            //on nettoie l'affichage
            clearTerrain();

            // on actualise l'affichage :
            if(sonModele->item(current.row(), current.column())->data(33).toBool() )
            {
                sonParent->updatePanneauJoueur(0,sonModele->item(current.row(), current.column()));
            }
            else
            {
                sonParent->updatePanneauJoueur(1, sonModele->item(current.row(), current.column()));
            }

            // on affiche si le joueur est debout
            if(sonModele->item(current.row(), current.column())->data(43).toBool() == true)
            {
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            }
            else
            {
                std::cout<<"Le joueur se relève pour un coût de 3 cases"<<std::endl;
                sonModele->item(current.row(), current.column())->setData(QVariant(sonModele->item(current.row(), current.column())->data(35).toInt() - 3), 35);
                sonModele->item(current.row(), current.column())->setData(QVariant(true), 43);
                lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
            }

            std::vector<QStandardItem*>::iterator leIt;
            for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
                {
                if((*leIt)!=sonModele->item(sonBallon->row(), sonBallon->column()))
                (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
                }


            // Affichage zone de tacle:
            if(sonModele->item(current.row(), current.column())->data(33).toBool())
            {
                afficheZonesTacle(sonParent->getLeMatch()->getEquipe2());
            }
            else
            {
                afficheZonesTacle(sonParent->getLeMatch()->getEquipe1());
            }

            fClic = 0;
            std::cout<<"premier clic sur joueur"<<std::endl;
        }
        else
        {
        clearTerrain();
        }
    }
    changementJoueur = false;
}



void SceneTerrain::firstClic(const QModelIndex &current, const QModelIndex &previous)
{

    if(!sonModele->item(current.row(), current.column())->data(45).toBool() && !sonModele->item(previous.row(), previous.column())->data(45).toBool())
    {
        clearTerrain();
    }

    // Affichage des mouvements :
    else if((!sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool())
            || (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && (sonModele->item(current.row(), current.column())->data(33).toBool() == sonModele->item(previous.row(), previous.column())->data(33).toBool()) ) )
    {

        //on nettoie l'affichage
        clearTerrain();


        // on actualise l'affichage :
        if(sonModele->item(current.row(), current.column())->data(33).toBool() )
        {
            sonParent->updatePanneauJoueur(0,sonModele->item(current.row(), current.column()));
        }
        else
        {
            sonParent->updatePanneauJoueur(1, sonModele->item(current.row(), current.column()));
        }

        // on affiche si le joueur est debout
        if(sonModele->item(current.row(), current.column())->data(43).toBool() == true)
        {
            lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
        }
        else
        {
            std::cout<<"Le joueur se relève pour un coût de 3 cases"<<std::endl;
            sonModele->item(current.row(), current.column())->setData(QVariant(sonModele->item(current.row(), current.column())->data(35).toInt() - 3), 35);
            sonModele->item(current.row(), current.column())->setData(QVariant(true), 43);
            lesMouvementsPossibles = afficheMouvements(sonModele->item(current.row(), current.column()));
        }

        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
        {
        if((*leIt)!=sonModele->item(sonBallon->row(), sonBallon->column()))
        (*leIt)->setData(QVariant(QBrush(QColor(120, 50, 170))), Qt::BackgroundRole);
        }

        // Affichage zone de tacle:
        if(sonModele->item(current.row(), current.column())->data(33).toBool())
        {
            afficheZonesTacle(sonParent->getLeMatch()->getEquipe2());
        }
        else
        {
            afficheZonesTacle(sonParent->getLeMatch()->getEquipe1());
        }

        fClic = 0;
    }
        else
    {
        secondClic(current, previous);
    }
}

void SceneTerrain::secondClic(const QModelIndex &current, const QModelIndex &previous)
{

    //
    //
    // DEPLACEMENT
    //
    //
    if(!(sonModele->item(previous.row(), previous.column())->data(34).toBool()) && (sonModele->item(previous.row(), previous.column())->data(45).toBool() && !sonModele->item(current.row(), current.column())->data(45).toBool()))
    {
        std::cout<<"Deplacement"<<std::endl;
        bool deplacementPossible(false);
        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = lesMouvementsPossibles->begin(); leIt != lesMouvementsPossibles->end(); leIt++)
        {
            if((*leIt) == sonModele->item(current.row(), current.column()))
            {
              deplacementPossible = true;
            }
        }

        if(deplacementPossible && esquive(previous.row(), previous.column()))
        {
        // on enleve le nombre de mouvements effectués :
        int mvts = sonModele->item(previous.row(), previous.column())->data(35).toInt();
        signed int x = previous.row() - current.row();
        signed int y = previous.column() - current.column();

        if(abs(x) >= abs(y))
        {
            sonModele->item(previous.row(),previous.column())->setData(QVariant(mvts - abs(x)), 35);
        }
        else
        {
            sonModele->item(previous.row(), previous.column())->setData(QVariant(mvts - abs(y)), 35);
        }

        sonModele->item(previous.row(), previous.column())->setData(QVariant(true), 47);

        // on deplace le ballon si le joueur a le ballon
        if(sonModele->item(previous.row(), previous.column())->data(48).toBool())
        {
            placeBallon(current.row(), current.column());
        }

        // si on deplace le joueur sans ballon sur la case avec le ballon
        if(!sonModele->item(previous.row(), previous.column())->data(48).toBool() && current.row() == sonBallon->row() && current.column()==sonBallon->column())
        {
            sonModele->item(previous.row(), previous.column())->setData(QVariant(true), 48);
        }

        // on déplace le joueur :
        sonModele->switchItems(sonModele->item(previous.row(), previous.column()), sonModele->item(current.row(), current.column()));

        }

        // on nettoie l'affichage :
        clearTerrain();
        touchdown();
    }



    //
    //
    // BLOCAGE OU BLITZ
    //
    //
    else if(!sonModele->item(previous.row(), previous.column())->data(34).toBool() && (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(current.row(), current.column())->data(45).toBool() && (sonModele->item(previous.row(), previous.column())->data(33).toBool() != sonModele->item(current.row(), current.column())->data(33).toBool())))
    {
        int resBlocage = blocage(current, previous);
        if(resBlocage<0)
            resBlocage =0;

        // on attaque
        // si joueur sur une case adjacente : BLOCAGE
        if(resBlocage < 9) // alors le joueur peut effectuer un blocage car son equipe n'a pas effectue et le joueur n'a jamais bloqué
        {
            std::cout<<"Le joueur bloque avec le soutien de "<<resBlocage<<" de ses coequipiers"<<std::endl;
            if(sonModele->item(previous.row(), previous.column())->data(47).toBool())
            { // alors le joueur effectue un blitz, ce qui lui coute une case de mouvement
                int mvts = sonModele->item(previous.row(), previous.column())->data(35).toInt();
                sonModele->item(previous.row(), previous.column())->setData(QVariant(mvts - 1), 35);
                std::cout<<"Le joueur BLITZ avec le soutien de "<<resBlocage<<" de ses coequipier(s)"<<std::endl;
            }
            else
            {
                std::cout<<"Le joueur bloque avec le soutien de "<<resBlocage<<" de ses coequipiers"<<std::endl;
            }

               // en theorie, il faut les memes force pour lancer un seul dé. Pour simplifier, on lancera qu'un seul dé a chaque fois.
//            if(sonModele->item(previous.row(), previous.column())->data(36).toInt()+soutien == sonModele->item(current.row(), current.column())->data(36).toInt())
//            {

                int de = sonParent->getLeMatch()->lancer1D6();
                sonParent->updateResultatsDes(de);

                switch(de)
                {
                case 1: {
                    std::cout<<"dé : 1 : attaquant à terre"<<std::endl;
                    sonModele->item(previous.row(), previous.column())->setData(QVariant(false), 43);
                    if(sonModele->item(previous.row(), previous.column())->data(48).toBool())
                    {
                    sonModele->item(previous.row(), previous.column())->setData(QVariant(false), 48);
                    sonBallon->rebondir(sonModele->item(previous.row(), previous.column()), 1);
                    }
                    break;}

                case 2: { // deux joueurs a terre sauf si l'un a la competence blocage
                    std::cout<<"dé : 2 : les joueurs à terre sauf si compétence BLOCAGE"<<std::endl;
                    bool aCompetence = false;
                        std::vector<competences>* sesCompetences = sonParent->getLeMatch()->getEquipe(sonModele->item(previous.row(), previous.column())->data(33).toBool())->getLeJoueur(sonModele->item(previous.row(), previous.column())->data(39).toInt())->getCompetences();
                        std::vector<competences>::iterator leIt;
                        for(leIt = sesCompetences->begin(); leIt != sesCompetences->end(); leIt++)
                        {
                            if((*leIt) == 4)
                            {
                                aCompetence = true;
                                std::cout<<"L'attaquant a la competence BLOCAGE, il ne tombe pas"<<std::endl;
                            }
                        }
                        if(!aCompetence)
                        {
                            std::cout<<"L'attaquant n'a pas la competence BLOCAGE, il tombe"<<std::endl;

                            sonModele->item(previous.row(), previous.column())->setData(QVariant(false), 43);
                            if(sonModele->item(previous.row(), previous.column())->data(48).toBool())
                            {
                            sonModele->item(previous.row(), previous.column())->setData(QVariant(false), 48);
                            sonBallon->rebondir(sonModele->item(previous.row(), previous.column()), 1);
                            }
                        }

                        // pour le second (current)
                        aCompetence = false;
                        for(leIt = sesCompetences->begin(); leIt != sesCompetences->end(); leIt++)
                        {
                            if((*leIt) == 4)
                            {
                                aCompetence = true;
                            }
                        }
                        if(!aCompetence)
                        {
                            if(sonModele->item(current.row(), current.column())->data(48).toBool())
                            {
                            sonModele->item(current.row(), current.column())->setData(QVariant(false), 48);
                            sonBallon->rebondir(sonModele->item(current.row(),current.column()), 1);
                            }
                            sonModele->item(current.row(), current.column())->setData(QVariant(false), 43);
                        }

                    break; }

                case 3:
                case 4: {
                    std::cout<<"dé : 3 ou 4 : defenseur repoussé"<<std::endl;
                    int difX = previous.row() - current.row();
                    int difY = previous.column() - current.column();
                    if(current.row()<14 && current.row()>0 && current.column()<27 && current.column()>0)
                    {
                        if(current.row() == previous.row()) //si sur la meme ligne on bouge que la ligne
                        {
                             if(!sonModele->item(current.row(), (current.column()-difY))->data(45).toBool())
                                 sonModele->switchItems(sonModele->item(current.row(), current.column()), sonModele->item(current.row(), (current.column()-difY)));
                        }
                        else if(current.column() == previous.column()) // si sur la meme colonne
                        {
                             if(!sonModele->item((current.row() - difX), (current.column()))->data(45).toBool())
                             sonModele->switchItems(sonModele->item(current.row(), current.column()), sonModele->item(current.row() - difX, current.column()));
                        }
                    }

                    break; }

                case 5: {
                    std::cout<<"dé : 5 : defenseur plaqué et repoussé s'il n'a pas la competence ESQUIVE"<<std::endl;
                    // repoussé et plaqué sauf si esquive/ attaquant peut poursuivre
                    bool aCompetence = false;
                    std::vector<competences>* sesCompetences = sonParent->getLeMatch()->getEquipe(sonModele->item(current.row(), current.column())->data(33).toBool())->getLeJoueur(sonModele->item(current.row(), current.column())->data(39).toInt())->getCompetences();
                    std::vector<competences>::iterator leIt;
                    for(leIt = sesCompetences->begin(); leIt != sesCompetences->end(); leIt++)
                    {
                        if((*leIt) == 0)
                        {
                            aCompetence = true;
                        }
                    }
                    if(!aCompetence)
                    {
                        int difX = previous.row() - current.row();
                        int difY = previous.column() - current.column();
                        if(current.row()<14 && current.row()>0 && current.column()<27 && current.column()>0)
                        {
                            if(current.row() == previous.row()) //si sur la meme ligne on bouge que la ligne
                            {
                                std::cout<<"Les deux joueurs sont sur la meme ligne"<<std::endl;
                                 if(!sonModele->item(current.row(), (current.column()-difY))->data(45).toBool())
                                 {
                                     sonModele->switchItems(sonModele->item(current.row(), current.column()), sonModele->item(current.row(), (current.column()-difY)));
                                 }
                            }
                            else if(current.column() == previous.column()) // si sur la meme colonne
                            {
                                std::cout<<"Les deux joueurs sont sur la meme colonne"<<std::endl;
                                 if(!sonModele->item((current.row() - difX), (current.column()))->data(45).toBool())
                                 {
                                 sonModele->switchItems(sonModele->item(current.row(), current.column()), sonModele->item((current.row() - difX), current.column()));
                                 }
                            }
                        }
                    }
                    if(sonModele->item(current.row(), current.column())->data(48).toBool())
                    {
                    sonModele->item(current.row(), current.column())->setData(QVariant(false), 48);
                    sonBallon->rebondir(sonModele->item(current.row(), current.column()), 1);
                    }
                    sonModele->item(current.row(), current.column())->setData(QVariant(false), 43);

                    break;  }

                case 6: {
                    std::cout<<"dé : 6 : defenseur repoussé et plaqué dans la case ou il a été deplacé"<<std::endl;

                    // defenseur repoussé et plaqué dans la case ou il a été deplacé / attaquant peut poursuivre
                    sonModele->item(current.row(), current.column())->setData(QVariant(false), 43);
                    if(sonModele->item(current.row(), current.column())->data(48).toBool())
                    {
                    sonModele->item(current.row(), current.column())->setData(QVariant(false), 48);
                    sonBallon->rebondir(sonModele->item(current.row(), current.column()), 1);
                    }
                    int difX = previous.row() - current.row();
                    int difY = previous.column() - current.column();
                    if(current.row()<14 && current.row()>0 && current.column()<27 && current.column()>0)
                    {
                        if(current.row() == previous.row()) //si sur la meme ligne on bouge que la ligne
                        {
                            std::cout<<"Les deux joueurs sont sur la meme ligne"<<std::endl;
                             if(!sonModele->item(current.row(), (current.column()-difY))->data(45).toBool())
                                 sonModele->switchItems(sonModele->item(current.row(), current.column()), sonModele->item(current.row(), current.column()-difY));
                        }
                        else if(current.column() == previous.column()) // si sur la meme colonne
                        {
                            std::cout<<"Les deux joueurs sont sur la meme colonne"<<std::endl;
                             if(!sonModele->item((current.row() - difX), (current.column()))->data(45).toBool())
                             sonModele->switchItems(sonModele->item(current.row(), current.column()), sonModele->item(current.row() - difX, current.column()));
                        }
                    }
                    break;}
                default: std::cout<<"/!\ le dé n'a pas retourné de chiffre entre 1 et 6..."<<std::endl;
                }

//            }
        }

        else if(resBlocage == 9)
        {
            std::cout<<"Ce joueur a déjà bloqué ou le blitz a déjà été effectué !"<<std::endl;
        }
        else if(resBlocage == 10)
        {
            std::cout<<"Les joueurs ne remplissent pas les conditions d'un blocage..."<<std::endl;
        }


        clearTerrain();
        // action effectué; si blitz : l'équipe a effectué son blitz
        blitzEffectue(sonModele->item(previous.row(), previous.column()));
        sonModele->item(previous.row(), previous.column())->setData(QVariant(true), 34);
    }



    //
    //
    // TRANSMISSION OU PASSE :
    //
    //
    else if(!sonModele->item(previous.row(), previous.column())->data(34).toBool() && (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(previous.row(), previous.column())->data(33).toBool() == sonModele->item(current.row(), current.column())->data(33).toBool()))
    {
        //
        // PASSE ou TRANSMISSION
       // on effectue une passe ou transmission si le joueur a le ballon :
        if(sonBallon->row() == previous.row() && sonBallon->column() == previous.column())
        {

            sonModele->item(previous.row(), previous.column())->setData(QVariant(false), 48);
            sonModele->item(current.row(), current.column())->setData(QVariant(true), 48);
            placeBallon(current.row(), current.column());
            clearTerrain();
            // action effectue :
            sonModele->item(previous.row(), previous.column())->setData(QVariant(true), 34);
        }
        else
        firstClic(current, previous);

        touchdown();
    }

}


void SceneTerrain::clearTerrain()
{
    sonParent->clearPanneauxJoueurs();
    for(int i(0); i<15; i++)
    {
        for(int j(0); j<28; j++)
        {
            if(sonModele->item(i, j)->data(45).toBool() && !sonModele->item(i, j)->data(43).toBool())
            {
                sonModele->item(i,j)->setData(QVariant(QBrush(QColor(177,0,0))), Qt::BackgroundRole);
            }
            else
            sonModele->item(i,j)->setData(QVariant(QBrush(QColor(110,210,50))), Qt::BackgroundRole);
        }
    }

    placeBallon(sonBallon->row(), sonBallon->column());
    fClic = 1;
}


void SceneTerrain::mouseReleaseEvent(QMouseEvent *event)
{
    int action(2);
    if(sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(33).toBool() && sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(45).toBool())
        {
        action = 0;
        std::cout<<"Joueur bleu cliqué"<<std::endl;
        }
    else if(!sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(33).toBool() && sonModele->item(rowAt(event->y()),columnAt(event->x()))->data(45).toBool())
        {
        action = 1;
        std::cout<<"Joueur rouge cliqué releaseEvent"<<std::endl;
        }
    else
        {action = 2;}

    emit cliqueTerrain(action, sonModele->item(rowAt(event->y()), columnAt(event->x())));
}


std::vector<QStandardItem*>* SceneTerrain::afficheMouvements(QStandardItem *unItem)
{
    int rayon = unItem->data(35).toInt();
    int x = unItem->row();
    int y = unItem->column();
    std::vector<QStandardItem*>* lesItems = new std::vector<QStandardItem*>();
    for(int i(0); i<15; i++)
    {
        for(int j(0); j<28; j++)
        {
            if(i >= x-rayon && i<= x+rayon && j>= y-rayon && j <= y+rayon)
            {
                lesItems->push_back(sonModele->item(i,j));
            }
        }
    }
    return lesItems;
}


void SceneTerrain::afficheZonesTacle(Equipe * uneEquipe)
{
    std::map<int, std::vector<QStandardItem* >* >::iterator itMap;
    lesZonesTacle = uneEquipe->zonesTacle();
    for(itMap = lesZonesTacle->begin(); itMap != lesZonesTacle->end(); itMap++)
    {
        std::vector<QStandardItem* >::iterator itVect;
        for(itVect = itMap->second->begin(); itVect != itMap->second->end(); itVect++)
        {
            if((*itVect) != sonModele->item(sonBallon->row(), sonBallon->column()))
            (*itVect)->setData(QVariant(QBrush(QColor(241,132,22))), Qt::BackgroundRole);
        }
    }

}

bool SceneTerrain::esquive(int row, int column)
{
    bool enZone = false;
    int penalite = 0;
    // on parcours les items de zone de tacle pour savoir si le joueur deplacé est en zone de tacle
    std::map<int, std::vector<QStandardItem* >* >::iterator itMap;
    for(itMap = lesZonesTacle->begin(); itMap != lesZonesTacle->end(); itMap++)
    {
        std::vector<QStandardItem* >::iterator itVect;
        for(itVect = itMap->second->begin(); itVect != itMap->second->end(); itVect++)
        {
            if(sonModele->item(row, column)==(*itVect))
            {
                penalite++;
                enZone = true;
            }
        }
    }

    // si joueur a deplacé en zone de tacle on joue un dé pour voir s'il tombe ou pas, sinon le joueur peut se deplacer: on retourne TRUE.
    if(enZone)
    {
        // on lance un dé et selon le resultat, le joueur tombe ou ne tombe pas, si il ne tombe pas il esquive, la methode retourne TRUE, sinon le joueur tombe et TURNOVER
        int de = sonParent->getLeMatch()->lancer1D6();
        sonParent->updateResultatsDes(de);
        if((de + sonModele->item(row, column)->data(37).toInt() - penalite) >= 7)
        {
            return true;
        }
        else
        {
            sonModele->item(row, column)->setData(QVariant(false), 43);
            sonModele->item(row,  column)->setData(QVariant(true), 34);
            if(sonModele->item(row,column)->data(48).toBool())
            {
            sonModele->item(row,column)->setData(QVariant(false), 48);
            sonBallon->rebondir(sonModele->item(row, column), 1);
            }
            sonParent->getLeMatch()->turnover(0);
            return false;
        }
    }
    else
    {
        return true;
    }
}

int SceneTerrain::blocage(const QModelIndex &current, const QModelIndex &previous)
{
    std::vector<QStandardItem*>* zoneBlocage = new std::vector<QStandardItem*>;

    if(sonModele->item(previous.row(), previous.column())->data(46).toBool() || (sonModele->item(previous.row(), previous.column())->data(47).toBool() && ((sonModele->item(previous.row(), previous.column())->data(33).toBool() && sonParent->getLeMatch()->getEquipe1()->getBlitzEffectue()) || (!sonModele->item(previous.row(), previous.column())->data(33).toBool() && sonParent->getLeMatch()->getEquipe2()->getBlitzEffectue() ))))
        return 9;

    int x = current.row();
    int y = current.column();

    if(x-1>=0 && y-1>=0)
    zoneBlocage->push_back(sonModele->item(x-1, y-1));
    if(x-1>=0)
    zoneBlocage->push_back(sonModele->item(x-1, y));
    if(x-1>=0 && y+1<28)
    zoneBlocage->push_back(sonModele->item(x-1, y+1));
    if(y-1>=0)
    zoneBlocage->push_back(sonModele->item(x, y-1));
    if(y+1<28)
    zoneBlocage->push_back(sonModele->item(x, y+1));
    if(x+1<15 && y-1>=0)
    zoneBlocage->push_back(sonModele->item(x+1, y-1));
    if(x+1<15)
    zoneBlocage->push_back(sonModele->item(x+1, y));
    if(x+1<15 && y+1<28)
    zoneBlocage->push_back(sonModele->item(x+1, y+1));


    bool res = false;
    int soutien(0);

    // si les deux joueurs sont debouts et que le joueur qui attaque a au moins un mouvement dispo
    if(sonModele->item(current.row(), current.column())->data(43).toBool() && sonModele->item(previous.row(), previous.column())->data(43).toBool() && sonModele->item(previous.row(), previous.column())->data(35).toInt()>0)
    {
        std::vector<QStandardItem*>::iterator leIt;
        for(leIt = zoneBlocage->begin(); leIt != zoneBlocage->end(); leIt++)
        {
            std::cout<<(*leIt)->data(39).toInt()<<std::endl;
        }

        for(leIt = zoneBlocage->begin(); leIt != zoneBlocage->end(); leIt++)
        {

            // si le joueur adverse appartient aux cases adjacentes :
            if((*leIt) == sonModele->item(previous.row(), previous.column()))
            {
                res = true;
            }


            // si il y a un joueur de la meme equipe que le joueur qui attaque a coté du joueur a attaquer :
            // le joueur doit etre debout
            if((*leIt)->data(43).toBool() && (*leIt)->data(45).toBool() && ((*leIt)->data(33).toBool() == sonModele->item(previous.row(), previous.column())->data(33).toBool()))
            {
                // alors on vérifie qu'il n'est pas dans une zone de tacle
                std::map<int, std::vector<QStandardItem* >* >::iterator itMap;
                if(sonModele->item(previous.row(), previous.column())->data(33).toBool())
                {
                    lesZonesTacle = sonParent->getLeMatch()->getEquipe2()->zonesTacle();
                }
                else
                {
                    lesZonesTacle = sonParent->getLeMatch()->getEquipe1()->zonesTacle();
                }


                bool estDansZoneTacle(false);

                for(itMap = lesZonesTacle->begin(); itMap != lesZonesTacle->end() && !estDansZoneTacle; itMap++)
                {
                    if(itMap->first != sonModele->item(current.row(), current.column())->data(39).toInt())
                    {
                    std::vector<QStandardItem* >::iterator itVect;
                        for(itVect = itMap->second->begin(); itVect != itMap->second->end() && !estDansZoneTacle; itVect++)
                        {
                            // si le coequipier est dans la zone de tacle
                            if((*itVect) == (*leIt))
                            {
                                estDansZoneTacle = true;
                            }
                        }
                    }

                }
                // si le coequipier n'est pas en zone de tacle et le coequipier est debout, on l'ajoute au soutien
                if(!estDansZoneTacle)
                {
                    std::cout<<"le joueur "<<(*leIt)->data(39).toInt()<<" est en soutien"<<std::endl;
                    soutien++;
                }
                else
                     std::cout<<"le joueur "<<(*leIt)->data(39).toInt()<<" n'est pas en soutien"<<std::endl;
            }
        }
    }

    if(!res)
        return 10;
    else
    {
        // on enleve le joueur qui attaque du soutien
        return --soutien;
    }
}

// pour le first clic apres changement de joueur sinon bug
void SceneTerrain::setChangementJoueur(bool aChangeJoueur)
{
    changementJoueur = aChangeJoueur;
}

void SceneTerrain::blitzEffectue(QStandardItem * unItem)
{
    if(unItem->data(47).toBool() && unItem->data(46).toBool())
    {
        if(unItem->data(33).toBool())
        {
            sonParent->getLeMatch()->getEquipe1()->setBlitzEffectue(true);
        }
        else
            sonParent->getLeMatch()->getEquipe2()->setBlitzEffectue(true);
    }
}

void SceneTerrain::placeBallon(int row, int column)
{
    if(sonModele->item(sonBallon->row(), sonBallon->column())->data(48).toBool() && sonModele->item(sonBallon->row(), sonBallon->column())->data(45).toBool())
    {
           sonModele->item(row, column)->setBackground(QBrush(QPixmap("images/ballonJoueur.png")));

    }
    else
    {
            sonModele->item(row, column)->setBackground(QBrush(QPixmap("images/ballon.png")));
    }

    sonBallon->setRow(row);
    sonBallon->setColumn(column);
}

void SceneTerrain::touchdown()
{
    for(int i(0); i<15; i++)
    {
        //si rouge dans la colonne 0 avec le ballon alors turnover
        if(sonModele->item(i, 0)->data(45).toBool() && !sonModele->item(i, 0)->data(33).toBool() && sonModele->item(i, 0)->data(48).toBool())
        {
            sonParent->getLeMatch()->turnover(2);
        }
        else if(sonModele->item(i, 27)->data(45).toBool() && sonModele->item(i, 27)->data(33).toBool() && sonModele->item(i, 27)->data(48).toBool())
        {
            sonParent->getLeMatch()->turnover(1);
        }
    }
}
