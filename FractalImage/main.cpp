#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "C:\Users\Amir\Desktop\Gtt\FractalImage\FractalImage\include\Bitmap.h"


using namespace std;
using namespace caveofprogramming;

int main()
{
    int const Width=800;
    int const Height = 600;
    //Bitmap mtmp1(800,800);
    Bitmap btmp1(Width,Height);

    for (int i=0; i<Width; i++){
            for (int j=0;j<Height;j++){
                btmp1.setPixel(i,j,200,5,5);
            }
    }

    btmp1.write("test1.bmp");
    cout << "Hello world!" << endl;
    return 0;
}
