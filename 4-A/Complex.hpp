#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>

class Complex
{
   public:
      Complex(double = 0.0, double = 0.0); // default constructor

      void setReal(double real);
      void setImag(double imaginary);
      double getReal() const;
      double getImag() const;

      Complex operator+( const Complex & ) const;
      Complex operator-( const Complex & ) const;
      Complex operator ==(const Complex &);
      Complex operator !=(const Complex &); 
      Complex operator *(const Complex &) const;

      friend std::ostream & operator << (std::ostream &output, const Complex &temp);
      friend std::istream & operator >> (std::istream &input, Complex &temp);

   private:
      double real;
      double imaginary;
};

#endif

