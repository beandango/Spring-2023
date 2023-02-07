/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 3-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 02.06.2023
Purpose: The purpose of this assignment is to make sure that 
you know how to write a program that uses classes, 
friend functions, and operator overloading
*/

#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Point.h"
#include "Point.cpp"
#include <iostream>

int main()
{
    /* 
    My own driver code before i noticed I was supposed to use the code on brightspace
    My version allows for user input

    double n1, n2, n3, n4, n5, n6, n7, n8;
    std::cout<<"\nEnter four coordinate pairs, one at a time, for a square or rectangle\n"
             <<"Start from the bottom left, and go counter-clockwise\n";
    std::cin>>n1>>n2>>n3>>n4>>n5>>n6>>n7>>n8;

    Point p1(n1, n2);
    Point p2(n3, n4);
    Point p3(n5, n6);
    Point p4(n7, n8);

    
    Rectangle r(p1, p2, p3, p4);

    r.setLenWid();
    
    std::cout<<"\nLength: "<<r.length();
    std::cout<<"\nWidth: "<<r.width();
    std::cout<<"\nIs it a square? 1 = true, 0 = false: "<<r.square();
    std::cout<<"\nArea: "<<r.area();
    std::cout<<"\nPerimeter: "<<r.perimeter();
    */

   Point w{1.0, 1.0};
   Point x{5.0, 1.0};
   Point y{5.0, 3.0};
   Point z{1.0, 3.0};
   Point j{0.0, 0.0};
   Point k{1.0, 0.0};
   Point m{1.0, 1.0};
   Point n{0.0, 1.0};

   Rectangle r1{z, y, x, w};
   r1.setLenWid();
   std::cout << "Rectangle 1:\n";
   std::cout << "length = " << r1.length();
   std::cout << "\nwidth = " << r1.width();
   r1.perimeter();
   r1.area();
   std::cout << "\nThe rectangle "
      << (r1.square() ? "is" : "is not")
      << " a square.\n";

   Rectangle r2{j, k, m, n};
   r2.setLenWid();
   std::cout << "\nRectangle 2:\n";
   std::cout << "length = " << r2.length();
   std::cout << "\nwidth = " << r2.width();
   r2.perimeter();
   r2.area();
   std::cout << "\nThe rectangle "
      << (r2.square() ? "is" : "is not")
      << " a square.\n";

}