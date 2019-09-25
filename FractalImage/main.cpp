//#include <iostream>
//#include "BitmapFileHeader.h"
//#include "BitmapInfoHeader.h"
//#include "C:\Users\Amir\Desktop\Gtt\FractalImage\FractalImage\include\Bitmap.h"
//#include "Maldelbrot.h"
//#include <memory>
//#include "ZoomList.h"
#include "FractalCreator.h"
#include "RGB.h"


using namespace std;
using namespace caveofprogramming;


double Scaling(int input, int range){
    return (2.0*input/range - 1);
}

int main(){

    RGB color1(3,5,6);
    RGB color2(5,7,1);

    RGB color3 =  color2 - color1;
    cout << color3.r << "," << color3.b << endl;

    int const Width=800;
    int const Height = 600;

    FractalCreator fractalcreator(Width,Height);

    fractalcreator.addRange(0.0,RGB(0,0,0));
    fractalcreator.addRange(0.3,RGB(255,0,0));
    fractalcreator.addRange(0.5,RGB(0,255,0));
    fractalcreator.addRange(1.0,RGB(255,255,255));

    //cout << "Range is: " << fractalcreator.getRange(200)<< endl;

    fractalcreator.run("test10.bmp");



    return 0;
}
