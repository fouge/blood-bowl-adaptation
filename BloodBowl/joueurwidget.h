#ifndef JOUEURWIDGET_H
#define JOUEURWIDGET_H

#include <QtGui>
#include "case.h"
#include <QLabel>

class Case;

class JoueurWidget : public QLabel
{
    Q_OBJECT
    Case* saCase;
public:
    JoueurWidget(Case*);
protected:
    void mouseReleaseEvent(QMouseEvent* ev);
signals:
    void cliqueJoueur(JoueurWidget*);
};

#endif // JOUEURWIDGET_H
