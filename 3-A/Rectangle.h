#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
    
    private:
        Point topLeft, topRight, bottomLeft, bottomRight;
        double l, w;
    public:
        Rectangle(Point, Point, Point, Point);
        void setLenWid();
        double area();
        bool square();
        double perimeter();

        void setW(double n)
        { w = n; }
        void setL(double n)
        { l = n; }
        double length()
        { return l; }
        double width()
        { return w; }

        Point getBottomLeft();
        Point getBottomRight();
        Point getTopLeft();
        Point getTopRight();

};

#endif //RECTANGLE_H