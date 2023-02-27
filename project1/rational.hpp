// COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
//
// rational.hpp: Definition of rational class and its interace.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>


// Mathematical helper functions.
//
// NOTE: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational {
public:
    Rational() : numerator_(0), denominator_(1) {}
    Rational(int n) : numerator_(n), denominator_(1) {}
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        int gcd_ = gcd(numerator, denominator);
        numerator_ = numerator / gcd_;
        denominator_ = denominator / gcd_;
        if (denominator_ < 0) {
            numerator_ *= -1;
            denominator_ *= -1;
        }
    }

    int num() const { return numerator_; }
    int den() const { return denominator_; }

    bool operator==(const Rational& other) const {
        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        // Compare numerators multiplied by other's denominator and vice versa
        return numerator_ * other.denominator_ < other.numerator_ * denominator_;
    }

    bool operator<=(const Rational& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Rational& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

    Rational operator+(const Rational& other) const {
        int lcm_ = lcm(denominator_, other.denominator_);
        int numerator_sum_ = numerator_ * (lcm_ / denominator_) + other.numerator_ * (lcm_ / other.denominator_);
        return Rational(numerator_sum_, lcm_);
    }

    Rational operator-(const Rational& other) const {
        return *this + Rational(-1 * other.numerator_, other.denominator_);
    }

    Rational operator*(const Rational& other) const {
        int numerator_ = numerator_ * other.numerator_;
        int denominator_ = denominator_ * other.denominator_;
        int gcd_ = gcd(numerator_, denominator_);
        numerator_ /= gcd_;
        denominator_ /= gcd_;
        if (denominator_ < 0) {
            numerator_ *= -1;
            denominator_ *= -1;
        }
        return Rational(numerator_, denominator_);
    }

    Rational operator/(const Rational& other) const {
        return *this * Rational(other.denominator_, other.numerator_);
    }

private:
    int numerator_;
    int denominator_;

    int gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) const {
        return (a * b) / gcd(a, b);
    }

};

// These are provided for you.
//
// NOTE: They are defined in rational.cpp.
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
