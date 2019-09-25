#include "FractalCreator.h"

namespace caveofprogramming{

FractalCreator::FractalCreator(int Width, int Height): Width(Width), Height(Height),
histogram2(new int[Maldelbrot::Max_Iter]{0}), fractal2(new int [Width*Height]{0}),
btmp1(Width,Height), zoolist(Width,Height)
{
    //ctor
}

FractalCreator::~FractalCreator()
{
    //dtor
}


void FractalCreator::run(string name){
    addZoom(Zoom(Width/2,Height/2,4.0/Width));
    addZoom(Zoom(280,Height-200,0.1));
    addZoom(Zoom(444,Height-327,0.25));
    CalculateIteration();
    CalculateRangeTotal();
    drawFractal();
    writeBitmap(name);

}


void FractalCreator::CalculateIteration(){
    for (int i=0; i<Width; i++){
        for (int j=0;j<Height;j++){

                /*xFractal = Scaling(i-200,Height);
                yFractal = Scaling(j,Height);*/

        pair<double,double> Frc =zoolist.doZoom(i,j);

        int iteration = Maldelbrot::getIterations(Frc.first,Frc.second);

        fractal2[j*Width+i]=iteration;

        if (iteration != Maldelbrot::Max_Iter){
                histogram2[iteration]++;
                }
        }
    }
}




void FractalCreator::drawFractal(){
    //RGB StartColor(50,10,20);
    //RGB EndColor(180,150,200);



    int total = 0;
    for (int i=0;i<Maldelbrot::Max_Iter;i++){
        total += histogram2[i];
    }

    //cout << "Overall total: " <<  total << endl;


    for (int i=0; i<Width; i++){
            for (int j=0;j<Height;j++){

                int iteration = fractal2[j*Width+i];
                int range = getRange(iteration);

                int rangeTotal = m_rangeTotal[range];
                int rangeStart = ranges[range];



                RGB& StartColor = colors[range];
                RGB& EndColor = colors[range+1];

                RGB DiffColor = EndColor - StartColor;

                uint8_t red=0;
                uint8_t green = 0;
                uint8_t blue = 0;

                //uint8_t color = (uint8_t)(256*(double)iteration/ Maldelbrot::Max_Iter);
                if (iteration != Maldelbrot::Max_Iter){

                int TotalPixels=0;
                for (int k=rangeStart; k <=iteration;k++){
                    //hue += ((double)histogram2[k])/total;
                    TotalPixels += histogram2[k];
                }

                double hue;
                hue = (double)TotalPixels/rangeTotal;

                red = StartColor.r +DiffColor.r*hue;
                green = StartColor.g - DiffColor.g*hue;
                blue = StartColor.b - DiffColor.b*hue;
                }

                btmp1.setPixel(i,j,red,green,blue);
            }
        }
}

void FractalCreator::writeBitmap(string name){
    btmp1.write(name);
    cout << "Done!" << endl;
}



void FractalCreator::addZoom(const Zoom& zoom){
    zoolist.add(zoom);
}


void FractalCreator::addRange(double EndRange, const RGB rgb){
    ranges.push_back(EndRange*Maldelbrot::Max_Iter);
    colors.push_back(rgb);

    if(m_bGotFirstRagne){
        m_rangeTotal.push_back(0);
    }

    m_bGotFirstRagne = true;

}


void FractalCreator::CalculateRangeTotal(){
    int rangeInx = 0;

    for(int i=0;i <Maldelbrot::Max_Iter;i++){
        int pixels = histogram2[i];

        if (i>=ranges[rangeInx+1]){
            rangeInx++;
        }

        m_rangeTotal[rangeInx] += pixels;
    }
}

int FractalCreator::getRange(int iterations) const{
    int range=0;

    for(int i=1; i<ranges.size();i++){
        range = i;

        if (ranges[i]>iterations){
            break;
        }
    }

    range--;
    assert(range >-1);
    assert(range <ranges.size());

    return range;
}




}
