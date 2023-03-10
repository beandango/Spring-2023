#ifndef INTARRAY_H
#define INTARRAY_H
#include <iostream>

namespace ComputerScience
{
    class IntArray
    {
        private:
            int length; //hold the array size 
            int *myArray; //a pointer pointing to a dynamically allocated array.
        public:
            IntArray(int length = 0); //constructor. length is the array size. default to 0 
            IntArray(const IntArray & r); //copy constructor to initiate the instance from existing instance 
            ~IntArray(); //destructor. Allocated array must be deleted in this function 
            int size() const; //getter function to return the size of the array
            int& operator[] (int i); //subscript operator overloading. The return value must be the reference of the element of the array 
            IntArray& operator= (const IntArray& r); //overloading operator=
            IntArray operator+ (const IntArray& r) const; //overloading operator + to merge two IntArrays
            IntArray operator+ (int) const; //overloading operator to add an int element at the end of the array
            IntArray& operator += (const IntArray& r); //overloading operator += to append an array
            IntArray& operator+= (int); //overloading operator += to append an int to the end of the array
            friend std::ostream& operator<< (std::ostream & out, const IntArray& r); //friend function to overload operator << for output 
            friend std::istream& operator >> (std::istream & in, IntArray& r); //friend function to overload operator >> for input
            friend IntArray operator+ (int, const IntArray&); //commutative + of IntArray operator+(int)
        private:
            void freeMemory(); //free allocated memory for myArray
            void copyContent(const IntArray& r); //copy content from another obj
    };
}

#endif //INTARRAY_H