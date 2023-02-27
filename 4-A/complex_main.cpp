/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 4
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 09.09.2017
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

     std::cout << "Enter a complex number in the form: (a, b)\n? ";
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

}

Complex::Complex( double realPart, double imaginaryPart ): real( realPart ), imaginary( imaginaryPart )
{}

// addition
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real,
   imaginary + operand2.imaginary );
} 

Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real,
   imaginary - operand2.imaginary );
}


Complex Complex::operator*(const Complex & operand2) const
{
	 return Complex(real * operand2.real, imaginary * operand2.imaginary );
}

Complex Complex::operator!=(const Complex & operand2)
{
   if(real != operand2.real)
   {
      real = operand2.real;
      return real;
   }
}

Complex Complex::operator==(const Complex & operand2) 
{
   if(real == operand2.real)
   {
      real = operand2.real;
      return real;
   }
}

void Complex::setReal(double realPart)
{
   real = realPart;
}

void Complex::setImag(double imaginaryPart)
{
   imaginary = imaginaryPart;
}

double Complex::getReal() const
{
   return real;
}

double Complex::getImag() const
{
   return imaginary;
}

// display a Complex object in the form: (a, b)
std::ostream & operator << (std::ostream & output, const Complex &temp)
{
   output << "" << temp.getReal() << std::endl;
   output << "" << temp.getImag() << std::endl;
   return output;
}

std::istream & operator >> (std::istream &input, const Complex &temp)
{
   std::cout << "";
   double imag;
   input >> imag;
   temp.setImag(imag);

   std::cout <<"";
   double real;
   input >> real;
   temp.setImag(real);
}
