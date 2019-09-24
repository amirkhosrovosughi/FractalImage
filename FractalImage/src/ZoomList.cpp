#include "ZoomList.h"



namespace caveofprogramming{
ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height){
    //ctor
}

void ZoomList::add(const Zoom& zoom){
    zooms.push_back(zoom);

    x_Center += (zoom.x - m_width/2)*m_scale;
    y_Center += (zoom.y - m_height/2)*m_scale;

    m_scale  *= zoom.scale;

    //cout << x_Center << ", " << y_Center << ", " << m_scale << endl;
}


pair<double,double> ZoomList::doZoom(int x, int y){
    double xFractal = (x-m_width/2)*m_scale + x_Center;
    double yFractal = (y-m_height/2)*m_scale + y_Center;
    return pair<double,double>(xFractal,yFractal);
}

}


