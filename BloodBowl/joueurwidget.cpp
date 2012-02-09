#include "joueurwidget.h"
#include <QLabel>
#include <QObject>

JoueurWidget::JoueurWidget(Case* uneCase):saCase(uneCase)
{
}

void JoueurWidget::mouseReleaseEvent(QMouseEvent *ev)
{
        emit cliqueJoueur(this);
}
