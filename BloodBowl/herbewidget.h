#ifndef HERBEWIDGET_H
#define HERBEWIDGET_H
#include "case.h"

class Case;

class HerbeWidget : public QLabel
{
    Q_OBJECT
    Case* saCase;
public:
    HerbeWidget(Case *);
protected:
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void cliqueCase(HerbeWidget*);
};


#endif // HERBEWIDGET_H
