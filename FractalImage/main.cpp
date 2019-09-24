#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "C:\Users\Amir\Desktop\Gtt\FractalImage\FractalImage\include\Bitmap.h"
#include "Maldelbrot.h"
#include <memory>
#include "ZoomList.h"
#include "FractalCreator.h"


using namespace std;
using namespace caveofprogramming;


double Scaling(int input, int range){
    return (2.0*input/range - 1);
}

int main()
{
    int const Width=800;
    int const Height = 600;
    //int wdt = 800;
    //Bitmap mtmp1(800,800);
    Bitmap btmp1(Width,Height);


    ZoomList zoolist(Width,Height);
    zoolist.add(Zoom(Width/2,Height/2,4.0/Width));
    zoolist.add(Zoom(280,Height-200,0.1));
    zoolist.add(Zoom(444,Height-327,0.25));

    unique_ptr<int[]> histogram(new int[Maldelbrot::Max_Iter]{0});
    unique_ptr<int[]> fractal(new int [Width*Height]{0});


    //int x[3] = {1,2,3};
    //int x{5};
    FractalCreator fractalcreator(Width,Height);
    //fractalcreator.Test(histogram.get());
    //cout << "This is my Test result:" << histogram[0]  <<endl;
    fractalcreator.CalculateIteration(histogram.get(),fractal.get(),zoolist);

    /*for (int i=0;i<Maldelbrot::Max_Iter;i++){
        cout << histogram[i] << ", ";
    }*/


  /*  for (int i=0; i<Width; i++){
            for (int j=0;j<Height;j++){

                pair<double,double> Frc =zoolist.doZoom(i,j);

                int iteration = Maldelbrot::getIterations(Frc.first,Frc.second);

                fractal[j*Width+i]=iteration;

                if (iteration != Maldelbrot::Max_Iter){
                histogram[iteration]++;
                }
            }
    }*/

    fractalcreator.drawFractal(histogram.get(),fractal.get(),btmp1);

    /*int total = 0;
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
                blue = pow(255,hue);
                }

                btmp1.setPixel(i,j,red,green,blue);
            }
        } */


        fractalcreator.writeBitmap(btmp1 ,"test7.bmp");
        /*btmp1.write("test7.bmp");
        cout << "Done!" << endl;*/


    return 0;
}
