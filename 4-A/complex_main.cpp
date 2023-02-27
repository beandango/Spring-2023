/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 4
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 02.27.2023
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include "Complex.hpp"

int main()
{
   for (double i = 1; i < 10; ++ i)
   {
     Complex y{i * 2.7, i + 3.2};
     Complex z{i * 6, i + 8.3};

     Complex x;
     Complex k;

     std::cout << "Enter a complex number in the form: (a, b)?\n";
     std::cin >> k; // demonstrating overloaded >>
     std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
               << k << '\n'; // demonstrating overloaded <<
     x = y + z; // demonstrating overloaded + and =
     std::cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
     x = y - z; // demonstrating overloaded - and =
     std::cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
     x = y * z; // demonstrating overloaded * and =
     std::cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

     if (x != k) { // demonstrating overloaded !=
        std::cout << x << " != " << k << '\n';
     }

     std::cout << '\n';
     x = k;

     if (x == k) { // demonstrating overloaded ==
        std::cout << x << " == " << k << '\n';
     }
       std::cout << std::endl;
     }

   return 0;
}