/**
 * \file      sceneterrain.cpp
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Definition de la classe \b SceneTerrain
 * \details   Classe Vue-Controleur dans MVC
 *
 */

/** \class SceneTerrain sceneterrain.h "sceneterrain.h" */
#include "sceneterrain.h"

#include <QtWidgets/QHeaderView>
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

/**
 * \brief       Methode qui, a chaque selection sur le terrain, exécute les actions correspondant en fonction de l'item cliqué.
 * \details     Reimplementation de la fonction virtuelle de \e QTableView
 * \param       const QModelIndex        current : item selectionne
 * \param       const QModelIndex        previous : precedent item selectionne
 * \return      \e void
 */
void SceneTerrain::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{

    if(coupEnvoi)
    {
            sonBallon = new Ballon(sonParent->getLeMatch(), sonModele, this, current.row(), current.column());
            sonBallon->rebondir(sonModele->item(current.row(), current.column()), sonParent->getLeMatch()->lancer1D6());
            clearTerrain();
            coupEnvoi = false;
    }
    else if(current.isValid() && previous.isValid() && fClic && sonParent->getLeMatch()->getQuiJoue()==!sonModele->item(current.row(), current.column())->data(33).toBool())
    {
        if((sonParent->getLeMatch()->getQuiJoue() == 0 && sonModele->item(current.row(), current.column())->data(33).toBool()) || (sonParent->getLeMatch()->getQuiJoue() != 0 && !sonModele->item(current.row(), current.column())->data(33).toBool()))
        firstClic(current, previous);
    }
    else if(current.isValid() && previous.isValid() && !fClic && sonParent->getLeMatch()->getQuiJoue() == !sonModele->item(previous.row(), previous.column())->data(33).toBool())
    {
        secondClic(current, previous);
    }
    else if(changementJoueur || (!previous.isValid() && current.isValid() && sonParent->getLeMatch()->getQuiJoue() == !sonModele->item(current.row(), current.column())->data(33).toBool()))
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
            afficheZonesTacle(sonParent->getLeMatch()->getEquipe(!sonModele->item(current.row(), current.column())->data(33).toBool()));

            fClic = 0;
            std::cout<<"premier clic sur joueur"<<std::endl;
        }
        else
        {
        clearTerrain();
        }
    }
    else
    {
}
    changementJoueur = false;
}


/**
 * \brief       Methode qui exécute les actions correspondant à la selection d'un joueur
 * \details     en fonction du clique precedent, l'action est differente
 * \param       const QModelIndex        current : item selectionne
 * \param       const QModelIndex        previous : precedent item selectionne
 * \return      \e void
 */
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
        afficheZonesTacle(sonParent->getLeMatch()->getEquipe(!sonModele->item(current.row(), current.column())->data(33).toBool()));

        fClic = 0;
    }
        else
    {
        secondClic(current, previous);
    }
}

/**
 * \brief       Methode qui exécute les actions correspondant à l'action d'un joueur selectionné auparavant
 * \details     en fonction de la selection l'action est differente <br/>Il y a trois actions differentes en fonction du precedent et du actuel <br/>-> Deplacement<br/>-> Blocage ou blitz <br/>-> Passe
 * \param       const QModelIndex        current : item selectionne
 * \param       const QModelIndex        previous : precedent item selectionne
 * \return      \e void
 */
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
                        sesCompetences = sonParent->getLeMatch()->getEquipe(sonModele->item(previous.row(), previous.column())->data(33).toBool())->getLeJoueur(sonModele->item(current.row(), current.column())->data(39).toInt())->getCompetences();
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
    // si la passe n'est pas déjà effectuée et si l'action du joueur n'est pas déjà effectuée et si les deux joueurs sont dans le même camps
    else if(!sonParent->getLeMatch()->getEquipe(sonModele->item(previous.row(), previous.column())->data(33).toBool())->getPasseEffectuee() && !sonModele->item(previous.row(), previous.column())->data(34).toBool() && (sonModele->item(previous.row(), previous.column())->data(45).toBool() && sonModele->item(previous.row(), previous.column())->data(33).toBool() == sonModele->item(current.row(), current.column())->data(33).toBool()))
    {
        //
        // PASSE ou TRANSMISSION
       // on effectue une passe ou transmission si le joueur a le ballon :
        if(sonModele->item(previous.row(), previous.column())->data(48).toBool())
        {
            sonModele->item(previous.row(), previous.column())->setData(QVariant(false), 48);
            recevoirBallon(current.row(), current.column());
            clearTerrain();
            // action effectue :
            sonModele->item(previous.row(), previous.column())->setData(QVariant(true), 34);
            sonParent->getLeMatch()->getEquipe(sonModele->item(previous.row(), previous.column())->data(33).toBool())->setPasseEffectuee(true);
        }
        else // sinon cela revient à choisir un autre joueur => firstClic.
        firstClic(current, previous);

        // Enfin, on vérifie si un touchdown est effectué sur la passe.
        touchdown();
    }

}



/**
 * \brief       Actualise l'affichage en background
 * \details     Permet d'enlever les zones tacles ou mouvements possibles.
 * \return      \e void
 */
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

/**
 * \brief       Reimplementation de la méthode executee lors d'un evenement de souris : permet l'affichage dans le panneau des caractéristiques du joueur.
 * \details     en fonction du clique, une action differente est affectee et un SIGNAL est emis : \e cliqueTerrain()
 * \param       QMouseEvent*     event
 * \return      \e void
 */
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

/**
 * \brief       Methode qui renvoie les items des cases ou le deplacement est possible.
 * \details     Enregistre les items dans un tableau de \e QStandardItem*
 * \todo        Mettre a jour l'affichage directement mais retourner les cases pour savoir si deplacement possible ensuite.
 * \param       QStandardItem*     unItem : joueur clique.
 * \return      \e std::vector<QStandardItem*>*
 */
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

/**
 * \brief       Affiche sur le terrain les zones de tacles des joueurs adverses
 * \details
 * \param       Equipe*     l'Equipe adverse
 * \return      \e std::vector<QStandardItem*>*
 */
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


/**
 * \brief       Methode qui renvoie si le joueur esquive le tacle ou non.
 * \details     Si le joueur n'a pas esquive, il tombe. <br/>Si le joueur esquive, alors \e return \e true
 * \param       int     row : ligne de la case d'ou le joueur sort
 * \param       int     column : colonne de la case d'ou le joueur sort
 * \return      \e bool
 */
bool SceneTerrain::esquive(int row, int column)
{
    if(sonModele->item(row, column)->data(33).toBool() == sonParent->getLeMatch()->getQuiJoue())
    {
        return false;
    }
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
}


/**
 * \brief       Methode qui renvoie l'option de blocage
 * \details     Si nombre (x) renvoye entre 0 et 7, blocage effectue avec le soutien de x coequipiers<br/>Si blocage impossible, la methode retourne 10.
 * \param       const QModelIndex     current
 * \param       const QModelIndex     previous
 * \return      \e int
 */
int SceneTerrain::blocage(const QModelIndex &current, const QModelIndex &previous)
{
    std::vector<QStandardItem*>* zoneBlocage = new std::vector<QStandardItem*>;

    if(sonModele->item(previous.row(), previous.column())->data(46).toBool() || (sonModele->item(previous.row(), previous.column())->data(47).toBool() && ((sonModele->item(previous.row(), previous.column())->data(33).toBool() && sonParent->getLeMatch()->getEquipe(1)->getBlitzEffectue()) || (!sonModele->item(previous.row(), previous.column())->data(33).toBool() && sonParent->getLeMatch()->getEquipe(0)->getBlitzEffectue() ))))
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
                lesZonesTacle = sonParent->getLeMatch()->getEquipe(!sonModele->item(previous.row(), previous.column())->data(33).toBool())->zonesTacle();

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

/**
 * \brief       Methode qui fixe le changement du joueur
 * \details     /!\ pour le firstClic apres fin de tour, faire passer à \e true sinon bug
 * \param       const QModelIndex     current
 * \param       const QModelIndex     previous
 * \return      \e int
 */
void SceneTerrain::setChangementJoueur(bool aChangeJoueur)
{
    changementJoueur = aChangeJoueur;
}

/**
 * \brief       Methode qui fixe le blitz effectue ou non. Methode a utiliser apres chaque mouvement de joueur ou chaque blocage.
 * \details     un seul blitz possible par tour
 * \param       QStandardItem*     item du joueur ayant effectue une action
 * \return      \e void
 */
void SceneTerrain::blitzEffectue(QStandardItem * unItem)
{
    if(unItem->data(47).toBool() && unItem->data(46).toBool())
    {
            sonParent->getLeMatch()->getEquipe(unItem->data(33).toBool())->setBlitzEffectue(true);
    }
}


/**
 * \brief       Methode qui place le ballon sur le terrain à la position \e (row,column)
 * \details     si sur la même case, un joueur avec ballon, alors le ballon est possede par un joueur : image differente
 * \param       int         row (ligne)
 * \param       int         column (column)
 * \return      \e void
 */
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


/**
 * \brief       Methode qui test si le Joueur bloque le Ballon ou n'arrive pas à le prendre et modifie le joueur
 * \details     en paramètre : la case où le ballon est lancé <br/> - soit le joueur attrape le ballon, alors il le possede et le ballon est placé <br/> - soit le joueur n'attrape pas le ballon et le ballon rebondi
 * \param       int     row
 * \param       int     column
 * \return      \e void
 */
void SceneTerrain::recevoirBallon(int row, int column)
{
    // si il y a un joueur debout à cette position :

    // soit le joueur attrape le ballon, alors il le possede et le ballon est placé
    // soit le joueur n'attrape pas le ballon et le ballon rebondi
    if(sonModele->item(row, column)->data(45).toBool() && sonModele->item(row, column)->data(43).toBool())
    {
        std::cout<<"Jet de reception du ballon"<<std::endl;
    if(sonParent->getLeMatch()->lancer1D6() + sonModele->item(row, column)->data(37).toInt() >= 7 )
    {
        std::cout<<"Le joueur receptionne le ballon"<<std::endl;
        sonModele->item(row, column)->setData(QVariant(true), 48);
        placeBallon(row, column);
    }
    else
    {
        std::cout<<"Le joueur ne receptionne pas le ballon, il rebondit"<<std::endl;
        sonBallon->rebondir(sonModele->item(row, column), sonParent->getLeMatch()->lancer1D6());
    }

    }

}

/**
 * \brief       Methode qui test si un touchdown est marque
 * \details     Si touchdown alors turnover avec la bonne option pour savoir qui a marque.
 * \return      \e void
 */
void SceneTerrain::touchdown()
{
    for(int i(0); i<15; i++)
    {
        //si rouge dans la colonne 0 avec le ballon alors touchdown : turnover avec option 2
        if(sonModele->item(i, 0)->data(45).toBool() && !sonModele->item(i, 0)->data(33).toBool() && sonModele->item(i, 0)->data(48).toBool())
        {
            sonParent->getLeMatch()->turnover(2);
        }
        // sinon si bleu dans la colonne 27 avec le ballon, alors touchdown pour les bleus: turnover avec option 1
        else if(sonModele->item(i, 27)->data(45).toBool() && sonModele->item(i, 27)->data(33).toBool() && sonModele->item(i, 27)->data(48).toBool())
        {
            sonParent->getLeMatch()->turnover(1);
        }
    }
    clearTerrain();
}
