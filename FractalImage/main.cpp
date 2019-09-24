#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "C:\Users\Amir\Desktop\Gtt\FractalImage\FractalImage\include\Bitmap.h"
#include "Maldelbrot.h"
#include <memory>
#include <math.h>
#include "ZoomList.h"

#include <cstdint>

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

    double xFractal;
    double yFractal;


    ZoomList zoolist(Width,Height);
    zoolist.add(Zoom(Width/2,Height/2,4.0/Width));
    zoolist.add(Zoom(280,Height-200,0.1));
    zoolist.add(Zoom(444,Height-327,0.25));

    unique_ptr<int[]> histogram(new int[Maldelbrot::Max_Iter]{0});
    unique_ptr<int[]> fractal(new int [Width*Height]{0});

    for (int i=0; i<Width; i++){
            for (int j=0;j<Height;j++){

                /*xFractal = Scaling(i-200,Height);
                yFractal = Scaling(j,Height);*/

                pair<double,double> Frc =zoolist.doZoom(i,j);
                xFractal = Frc.first;
                yFractal = Frc.second;


                int iteration = Maldelbrot::getIterations(xFractal,yFractal);

                fractal[j*Width+i]=iteration;

                if (iteration != Maldelbrot::Max_Iter){
                histogram[iteration]++;
                }


            }
    }

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



    btmp1.write("test6.bmp");
    cout << "Done!" << endl;
    return 0;
}
