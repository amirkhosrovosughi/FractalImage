#include "Maldelbrot.h"
#include <complex>
#include <iostream>

using namespace std;


Maldelbrot::Maldelbrot()
{
    //ctor
}

Maldelbrot::~Maldelbrot()
{
    //dtor
}


int Maldelbrot::getIterations(double x,double y){
    complex<double> z =0;
    complex<double> c(x,y);

    int iteration =0;
    while (iteration < Max_Iter){
        z = z*z +c;

        if (abs(z)> 2){
            break;
        }
        iteration++;

    }
    //cout << iteration << endl;
    return iteration;
}
