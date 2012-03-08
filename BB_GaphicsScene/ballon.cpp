#include "ballon.h"

Ballon::Ballon(Case* uneCase, Match* unMatch): saCase(uneCase), sonMatch(unMatch)
{
}

void Ballon::rebondirBallon()
{
    int nAleatoire = rand() % 8 + 1;
    std::vector<Case*>* lesMvtsPossibles = sonMatch->voirMouvementsPossibles(saCase);
    std::vector<Case*>::iterator leIt;
    leIt = lesMvtsPossibles->begin();
    leIt += nAleatoire - 1;
    saCase = (*leIt);
}

void Ballon::setCase(Case *uneCase)
{
    saCase = uneCase;
}
