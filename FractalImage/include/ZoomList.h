#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <iostream>
#include <Zoom.h>
#include <vector>
#include <utility>
using namespace std;

namespace caveofprogramming{

class ZoomList
{
    double x_Center{0};
    double y_Center{0};
    double m_scale{1.0};
    int m_width{0};
    int m_height{0};
    vector<Zoom> zooms;
    public:
        ZoomList(int width, int height);

        void add(const Zoom& zoom);

        pair<double,double> doZoom(int x, int y );



};

}
#endif // ZOOMLIST_H
