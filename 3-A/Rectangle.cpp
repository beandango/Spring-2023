#include "Rectangle.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4)
{
    setCoords();

    bool rec = false;

    line1Len = sqrt((pow(abs(x2-x1), 2))+(pow(abs(y2-y1), 2)));
    line2Len = sqrt((pow(abs(x3-x2), 2))+(pow(abs(y3-y2), 2)));
    line3Len = sqrt((pow(abs(x4-x3), 2))+(pow(abs(y4-y3), 2)));
    line4Len = sqrt((pow(abs(x1-x4), 2))+(pow(abs(y1-y4), 2)));

    if(line1Len == line3Len && line2Len == line4Len)
    {
        rec = true;
        std::cout<<"\n Created Rectangle\n";
    }
    else
    {
        throw "\nCoordinates entered are not of a rectangle\n";
    }
}

void Rectangle::setCoords()
{
    std::cout<<"\nEnter the coordinates of the rectangle, one coordinate a time,"
             <<"\nrepresenting the rectangle as follows:\n\n"
             <<"p4...........p3\n"
             <<".             .\n"
             <<".             .\n"
             <<"p1...........p2\n\n";
    std::cin>>a.x1>>a.y1>>a.x2>>a.y2>>a.x3>>a.y3>>a.x4>>a.y4;
}

