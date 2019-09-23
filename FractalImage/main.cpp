#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "C:\Users\Amir\Desktop\Gtt\FractalImage\FractalImage\include\Bitmap.h"


using namespace std;
using namespace caveofprogramming;

int main()
{
    //Bitmap mtmp1(800,800);
    Bitmap btmp1(700,700);
    btmp1.write("test1.bmp");
    cout << "Hello world!" << endl;
    return 0;
}
