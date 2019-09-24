#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <iostream>
#include <string>
#include "ZoomList.h"
#include "Zoom.h"
#include <utility>
#include "Maldelbrot.h"
#include "Bitmap.h"
#include <cstdint>
#include <math.h>

using namespace std;


namespace caveofprogramming{



class FractalCreator
{
    int Width{0};
    int Height{0};

    public:
        FractalCreator(int Width, int Height);
        virtual ~FractalCreator();

        void CalculateIteration( int histogram[], int fractal[],  ZoomList &zoolist);
        void drawFractal(int histogram[], int fractal[],  Bitmap &btmp1);
        void addZoom(const Zoom& zoom);
        void writeBitmap(Bitmap &btmp1 ,string name);

        /*void Test(int x[]){
            //(*x)[0] = 10;
            x[0]=6;
            x[1]=7;
            x[2]=8;
        }*/
};


}

#endif // FRACTALCREATOR_H
