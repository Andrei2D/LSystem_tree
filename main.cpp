#include <iostream>
#include "LSystem.h"
#include "GraphicsFunctions.h"

#define HEIGHT_W 600
#define WIDTH_W
using namespace std;
///TO DO:
    /// METODA CARE SA CEARA FUNCTIE DE INTERPRETARE
    /// MODALITATE DE A UMPLE OBIECTUL GENERATOR INDIRECT

int main()
{
srand(time(NULL));

    initwindow(600,600,"L System");
    Punct::setRelativeOrigin(300,600);
    Punct::setScale( 40 );

    char cara = 32;

    LSystem Tree;
    Tree.drawFormula();
    Tree.addAngleShift(45);
    //Tree.addAngleShift(30);
    //Tree.addAngleShift(15);
    cara = getch();

    while(cara != '0')
    {
        switch(cara)
        {
     case('+'):
        Punct::setScale(Punct::getScale() * 1.2);
        break;

     case('-'):
        Punct::setScale(Punct::getScale() * 0.8);
        break;

     case ('2'):
         Punct::addAtOrigin(0,10);
        break;

     case ('8'):
         Punct::addAtOrigin(0,-10);
        break;

     case ('4'):
         Punct::addAtOrigin(-10,0);
        break;

     case ('6'):
         Punct::addAtOrigin(10,0);
        break;

     case ('5'):
        cout<<"The axiom is :\n"<<Tree.getAxiom()<<"\n\n";
        break;

     default:
        Tree.nextItteration();
        break;
        }
        cleardevice();
        Tree.drawFormula();

        cara = getch();
    }

    getch();
    closegraph();


    return 0;
}
