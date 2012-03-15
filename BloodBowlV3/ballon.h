#ifndef BALLON_H
#define BALLON_H

#include "match.h"

class Case;
class Match;

class Ballon
{
    Case* saCase;
    Match* sonMatch;
public:
    Ballon(Case*, Match*);
    void rebondirBallon();
    void setCase(Case* uneCase);
};

#endif // BALLON_H
