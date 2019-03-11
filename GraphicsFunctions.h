#ifndef GraphicsFunctions

#define GraphicsFunctions

#include <graphics.h>
#include "Punct.h"

void onPressReset()
{
getch();
cleardevice();
}

void drawDot (Punct P, int color = WHITE)
{
    putpixel(P.getGhX(), P.getGhY(), color);
}

void drawPoint (Punct P, int color = WHITE, int radius = 1)
{
    circle(P.getGhX(),P.getGhY(),radius);
    floodfill(P.getGhX(),P.getGhY(),color);

}

void drawLine (Punct startP, Punct endP, int color = WHITE)
{
    int lastColor = getcolor();
    setcolor(color);
    line(startP.getGhX(),startP.getGhY(),endP.getGhX(),endP.getGhY());
    setcolor(lastColor);
}

void undoLine (Punct startP, Punct endP)
{
    drawLine(startP,endP,BLACK);
}


void drawLineMultiple (const vector<Punct>& vct, int startPoz, int endPoz, int color = WHITE)
{
    int lastCol = getcolor();
    setcolor(color);

    for(int i=startPoz; i < endPoz; i++)
        drawLine(vct[i],vct[i+1],color);

    setcolor(lastCol);
}

void undoLineMultiple (const vector<Punct>& vct, int startPoz, int endPoz)
{
    drawLineMultiple(vct, startPoz, endPoz,BLACK);
}

void drawForm (const vector<Punct>& vct, int color = WHITE)
{
    drawLine (vct[ vct.size()-1 ], vct[0],color);
    drawLineMultiple(vct, 0, vct.size(),color);
}

void drawPoints(const vector <Punct>& aVect, unsigned int waitDelay = 0, bool clearAfterDelay = FALSE)
{
    for(int i = 0; i< aVect.size(); i++)
    {
        drawPoint(aVect[i],waitDelay);
    }

    if(waitDelay > 0)
    {
        delay(2000);
        if(clearAfterDelay) cleardevice();
    }
}

#endif // GraphicsFunctions
