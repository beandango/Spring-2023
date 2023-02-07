#include "Rectangle.h"
#include "Point.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle(Point bl, Point br, Point tr, Point tl)
{
    if(bl.getX() < 20 && bl.getY()<20 
    && br.getX() < 20 && br.getY() < 20
    && tr.getX() < 20 && tr.getY() < 20
    && tl.getX() < 20 && tl.getY() < 20)
    {
        bottomLeft = bl;
        bottomRight = br;
        topRight = tr;
        topLeft = tl;
    }
    else
    {
        std::cout<<"\nError: Invalid Coordinates\nValues must be less than 20.\n";
        exit(EXIT_FAILURE);
    }

    if(bl.getX() != tl.getX())
    {
        std::cout<<"\nError: Top and bottom left must have same X value";
        exit(EXIT_FAILURE);
    }
    if(br.getX() != tr.getX())
    {
        std::cout<<"\nError: Top and bottom right must have same X value";
        exit(EXIT_FAILURE);
    }
    
    std::cout<<"\nCreated Rectangle\n";
}

Point Rectangle::getBottomLeft()
{
    return bottomLeft;
}

Point Rectangle::getBottomRight()
{
    return bottomRight;
}
Point Rectangle::getTopLeft()
{
    return topLeft;
}
Point Rectangle::getTopRight()
{
    return topRight;
}


void Rectangle::setLenWid()
{
    Point p1 = this->getBottomLeft();
    Point p2 = this->getBottomRight();
    Point p3 = this->getTopRight();
    Point p4 = this->getTopLeft();

    double side1 = sqrt(pow((p2.getX()-p1.getX()), 2)+pow((p2.getY()-p1.getY()), 2));
    double side2 = sqrt(pow((p3.getX()-p2.getX()), 2)+pow((p3.getY()-p2.getY()), 2));

    //std::cout<<"side1: "<<side1;

    if(side1 >= side2)
    {
        setL(side1);
        setW(side2);
    }
    else
    {
        setW(side1);
        setL(side2);
    }
}

double Rectangle::area()
{
    return l*w;
}

bool Rectangle::square()
{
    if(l==w)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Rectangle::perimeter()
{
    return 2*(l+w);
}

