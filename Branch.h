#ifndef BRANCH_H

#define BRANCH_H

#include "Punct.h"

#define PI 3.141592

class Branch
{
protected:
    Punct currCoord;
    float lenght;
    float ang;
public:
    Branch():lenght(1),ang(PI/2){}
    Branch(Punct old, Punct curr):currCoord(curr),lenght(1),ang(PI/2)
    {}

    Branch& operator= (const Branch& b)
    {
        currCoord = b.currCoord;
        lenght = b.lenght;
        ang = b.ang;
    }

    void turnAngleLeft(float radian)
    {
        ang += radian;
    }

    void turnAngleRight(float radian)
    {
        ang -= radian;
    }

    void turn45left ()
    {
        turnAngleLeft( PI / 4);
    }

    void turn45right ()
    {
        turnAngleRight(PI / 4);
    }


};



#endif // BRANCH_H
