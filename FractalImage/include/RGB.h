#ifndef RGB_H
#define RGB_H

namespace caveofprogramming {

struct RGB
{
    double r;
    double g;
    double b;
    public:
        RGB(double r, double g, double b);

};


RGB operator-(const RGB& first, const RGB& second);
}




#endif // RGB_H
