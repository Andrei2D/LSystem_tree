#ifndef LSYSTEM_H

#define LSYSTEM_H
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "GraphicsFunctions.h"
#include "Branch.h"
#include "Fractal.h"

/// CLASA AR TREBUI FORMATA DIN 2 ENTITATI:
///UNA CARE REPREZINTA VARIABILELE NECESARE DESENATULUI
///UNA CARE REPREZINTA GENERAREA FORMULEI SI INTERPRETAREA
class LSystem : public Branch, public Fractal
{
    ///VECTOR DE VARIANTE DE UNGHIURI IN CARE SE POT SCHIMBA
    ///DIRECTIILE CRENGILOR
    vector<float> angShifts;
    ///GRAMATICELE GENERATOARE
    ///IN CAZ DE PUSH SI POP
    vector<Branch> saved;

public:
    LSystem()
    {
        setSymbols("10","[]");
        addRule('1',"11");
        addRule('0',"1[0]0");
        setAxiom("0");

        /*
        setSymbols("1","[]+-");
        addRule('1',"11+[+1-1-1]-[-1+1+1]");
        setAxiom("1");
        */
        }
    ~LSystem()
    {
        saved.clear();
    }

    ///GETTER PUNCT P
    Punct curr()
    {
        return currCoord;
    }

    ///SCHIMBARE UNGHI
    void changeAngle (float newAngle)
    {
        ang = newAngle;
    }

    float getAngleRandom ()
    {
        int sizee = angShifts.size();
        if(sizee <= 0 )
            return PI/4;

        return angShifts[rand()%sizee];


    }

    bool addAngleShift (int degreeAngle)
    {
        angShifts.push_back(degreeAngle/180.0 * PI);
    }

    Punct genP ()
    {
        float x = currCoord.getx() + lenght * cos(ang);
        float y = currCoord.gety() + lenght * sin(ang);
        Punct newP(x,y);

        return newP;
    }

    void growP ()
    {
        currCoord = genP();
    }

    void saveCurrent()
    {
        saved.push_back(*(Branch*)this);
    }

    bool revertPrev()
    {
        int sizee = saved.size();
        if(sizee < 1)
            return 0;

        *(Branch*)this = saved[ sizee -1 ];

        saved.pop_back();
        return 1;
    }

    void drawFormula ()
    {
        saveCurrent();
        for(int i=0; i<Axiom.size(); i++)
        {
            switch(Axiom[i])
            {
            case('1'):
                drawLine(currCoord,genP());
                growP();
                break;

            case ('0'):
                drawLine(currCoord,genP());
                growP();
                break;

            case ('['):
                saveCurrent();
                turnAngleLeft(getAngleRandom());
                break;

            case (']'):
                revertPrev();
                turnAngleRight(getAngleRandom());
                break;

            default:
                break;
            }
        }
        revertPrev();
    }

    void nextItteration ()
    {
        evolve();
        lenght *= 0.67;
        ang = PI / 2;
        currCoord.set(0,0);
    }



};

#endif // LSYSTEM_H
