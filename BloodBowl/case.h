#ifndef CASE_H
#define CASE_H

enum zone{enbut, laterale, engagement};
class Case
{
    int sonX, sonY;
    int leIdDessus;
    zone saZone;
public:
    Case(int unX, int unY);
    int getLigne();
    int getColonne();
    zone getZone();
};

#endif // CASE_H
