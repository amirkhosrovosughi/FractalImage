#include "FractalCreator.h"

namespace caveofprogramming{

FractalCreator::FractalCreator(int Width, int Height): Width(Width), Height(Height)
{
    //ctor
}

FractalCreator::~FractalCreator()
{
    //dtor
}

void FractalCreator::CalculateIteration(int *histogram, int *fractal, ZoomList &zoolist){
    for (int i=0; i<Width; i++){
        for (int j=0;j<Height;j++){

                /*xFractal = Scaling(i-200,Height);
                yFractal = Scaling(j,Height);*/

        pair<double,double> Frc =zoolist.doZoom(i,j);

        int iteration = Maldelbrot::getIterations(Frc.first,Frc.second);

        fractal[j*Width+i]=iteration;

        if (iteration != Maldelbrot::Max_Iter){
                histogram[iteration]++;
                }
            }
    }

}




void FractalCreator::drawFractal(int *histogram, int *fractal, Bitmap &btmp1){
    int total = 0;
    for (int i=0;i<Maldelbrot::Max_Iter;i++){
        total += histogram[i];
    }

    for (int i=0; i<Width; i++){
            for (int j=0;j<Height;j++){

                uint8_t red=0;
                uint8_t green = 0;
                uint8_t blue = 0;

                int iteration = fractal[j*Width+i];
                //uint8_t color = (uint8_t)(256*(double)iteration/ Maldelbrot::Max_Iter);
                if (iteration != Maldelbrot::Max_Iter){
                double hue = 0;

                for (int i=0; i <=iteration;i++){
                    hue += ((double)histogram[i])/total;
                }
                red = pow(255,hue);
                }

                btmp1.setPixel(i,j,red,green,blue);
            }
        }
}




void FractalCreator::writeBitmap(Bitmap &btmp1 ,string name){
    btmp1.write(name);
    cout << "Done!" << endl;
}

}
