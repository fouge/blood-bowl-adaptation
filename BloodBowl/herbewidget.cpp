#include "herbewidget.h"

HerbeWidget::HerbeWidget(Case* uneCase):QLabel(), saCase(uneCase)
{
}


void HerbeWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    emit cliqueCase(this);
}
