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
#include "RGB.h"
#include <vector>
#include <assert.h>

using namespace std;


namespace caveofprogramming{



class FractalCreator
{
    int Width{0};
    int Height{0};

    unique_ptr<int[]> histogram2;
    unique_ptr<int[]> fractal2;

    Bitmap btmp1;

    ZoomList zoolist;
    vector<int> ranges;
    vector<RGB> colors;

    vector<int> m_rangeTotal;

    bool m_bGotFirstRagne{false};

    public:
        FractalCreator(int Width, int Height);
        virtual ~FractalCreator();
        void run(string name);
        void CalculateIteration();
        void drawFractal();
        void addZoom(const Zoom& zoom);
        void writeBitmap(string name);
        void addRange(double EndRange, const RGB rgb);
        void CalculateRangeTotal();
        int getRange(int iterations) const;

};


}

#endif // FRACTALCREATOR_H
