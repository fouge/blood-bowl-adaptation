#ifndef BALLON_H
#define BALLON_H

#include "match.h"

class Match;

class Ballon
{
    Match* sonMatch;
public:
    Ballon(Match*);
};

#endif // BALLON_H
