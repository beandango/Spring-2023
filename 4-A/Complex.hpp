#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>

class Complex
{
public:
    Complex(double real = 0.0, double imag = 0.0) : realPart(real), imaginaryPart(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    Complex operator-(const Complex& other) const {
        return Complex(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    Complex operator*(const Complex& other) const {
        double r = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        double i = realPart * other.imaginaryPart + imaginaryPart * other.realPart;
        return Complex(r, i);
    }

    bool operator==(const Complex& other) const {
        return realPart == other.realPart && imaginaryPart == other.imaginaryPart;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    Complex& operator=(const Complex& other) {
        realPart = other.realPart;
        imaginaryPart = other.imaginaryPart;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << '(' << complex.realPart << ", " << complex.imaginaryPart << ')';
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& complex) {
        char c1, c2, c3;
        double r, i;
        if (is >> c1 && c1 == '(' && is >> r && is >> c2 && c2 == ',' &&
            is >> i && is >> c3 && c3 == ')') {
            complex = Complex(r, i);
        } else {
            is.setstate(std::ios_base::failbit);
        }
        return is;
    }

private:
    double realPart;
    double imaginaryPart;
};

#endif