#ifndef SCENETERRAIN_H
#define SCENETERRAIN_H

#include <QGraphicsScene>
#include <QTableView>
#include "tablemodel.h"
#include "fenetreprincipale.h"
#include "ballon.h"

class FenetrePrincipale;
class Ballon;

class SceneTerrain : public QTableView
{
    Q_OBJECT
    TableModel* sonModele;
    bool joueurSelectionne;
    FenetrePrincipale* sonParent;
    bool fClic;
    std::vector<QStandardItem*>* lesMouvementsPossibles;
    std::map<int, std::vector<QStandardItem* >* > * lesZonesTacle;
    bool changementJoueur;
    bool coupEnvoi;
    Ballon* sonBallon;
public:
    SceneTerrain(int nLignes, int nColonnes, TableModel* unModele, FenetrePrincipale* parent);
    std::vector<QStandardItem*>* afficheMouvements(QStandardItem* unItem);
    void afficheZonesTacle(Equipe*);
    void firstClic(const QModelIndex &current, const QModelIndex &previous);
    void secondClic(const QModelIndex &current, const QModelIndex &previous);
    void clearTerrain();
    bool esquive(int, int);
    int blocage(const QModelIndex &current, const QModelIndex &previous);
    void setChangementJoueur(bool aChangeJoueur);
    void blitzEffectue(QStandardItem*);
    void placeBallon(int row, int column);

protected:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void cliqueTerrain(int, QStandardItem*);
};

#endif // SCENETERRAIN_H
