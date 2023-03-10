#include "IntArray.h"
#include <iostream>
using namespace std;

namespace ComputerScience
{
    IntArray::IntArray(int size)
    {
        //constructor 
        if (size < 0)
        {
            //not allowed. length = 0;
            myArray = nullptr;
            std::cout << "size of the array must be greater than 0";
        }
        
        else if (size == 0)
        {
            length = 0;
        }
        else
        {
            myArray = nullptr;
            length = size;
            myArray = new int[size];
        }
    }
        
    IntArray::~IntArray()
    {
        //myArray always holds a memory, so safe to free
        freeMemory();
    }
    void IntArray::freeMemory()
    {
        //free the allocated memory for myArray
        if(myArray != nullptr) {
            delete []myArray;
            myArray = nullptr; 
            length = 0;  
        }
    }    
    IntArray::IntArray(const IntArray &r){
        //copy constructor to init the instance from existing instance
        copyContent(r);
    }

    IntArray& IntArray::operator=(const IntArray& r){
        if(this == &r){ //this is the pointer to itself
        //the address of itself is the same as the address of obj a
        //it is doing a=a. so do nothing
        return *this;
        }
        //not the right side IntArray r is not the saem obj
        freeMemory(); //clean current array
        copyContent(r); //copy all
        return *this; //return the ref of the obj
    }
    void IntArray::copyContent(const IntArray& r){
        //copy the content from another obj
        //handle array
        if(r.length == 0){
            //r is empty array
            length = 0;
            myArray = nullptr;
        }else{
            //only allocate mem and copy array when r.length is not 0
            length = r.length;
            myArray = new int[length];
            for(int i = 0; i<length; i++){
                myArray[i] = r.myArray[i]; //copy aray elements
            }
        }
    }

    int IntArray::size() const{
        //getter function to return size of array
        return length;
    }

    int& IntArray::operator[](int i){
        //suscript overloading, return the ref of ith elem
        if(i < 0 || i >= length){
            //out of range
            std::cout<<"the index is out of range";
        }
        return myArray[i];
    }
    IntArray IntArray::operator+(const IntArray& r) const{
        //overloading operator+ to merge to IntArrays
        //create an instance
        IntArray merged(length + r.length);

        //copy content from this obj first
        for(int i=0; i<r.length; i++){
            merged.myArray[i] = myArray[i];
        }

        //copy content from r
        for(int i=0; i<r.length; i++){
            merged.myArray[length + i] = r.myArray[i];
        }
        return merged;
    }
    IntArray IntArray::operator+(int val) const{
        //overloading operator + to merge intarrays and an int
        IntArray merged (length + 1); //create an array one element more than this array
        //copy content from this object first
        for (int i=0; i<length; i++) {
            merged.myArray[i] = myArray[i];
        }
        //put val to the last element
        merged.myArray[length] = val; 
        return merged; 
    }
    IntArray& IntArray::operator+=(const IntArray& r) {
        //overloading operator += to append r to this array
        if (r.length == 0) {
            //appended array is empty. return the reference of this object directly 
            return *this;
        }
        //following code works for both a += a; and a += b; 
        //create a new combined array to hold merged arrays
        int newlength = length + r.length;
        int *tmpArray = new int[newlength];
        //copy contents from this object into Array 
        for(int i=0; i<length; i++) {
            tmpArray[i] = myArray[i];
        }
        //copy content from r
        for (int i=0; i<r.length; i++) {
            tmpArray[length + i] = r.myArray[i];
        }
        //free current array of this object
        freeMemory();
        //swap Array to myArray
        myArray = tmpArray;
        length = newlength;
        return *this; 
    }

    IntArray& IntArray::operator+= (int val) {
        //overloading operator += to append an int to this array 
        //create a new array one element larger
        int newlength = length + 1;
        int *tmpArray = new int[newlength];
        //copy contents from this object into Array 
        for (int i=0; i<length; i++) {
            tmpArray[i] = myArray[i];
        }
        //put val to the last element of tmpArray 
        tmpArray[length] = val;
        //free current array of this object 
        freeMemory();
        //swap tmpArray to myArray
        myArray = tmpArray;
        length = newlength;
        return *this; 
    }

    IntArray operator+(int val, const IntArray& r){
        //commutative + of IntArray operator+(int)
        IntArray merged(r.length + 1); //create an array one element more than this array
        //put val to the first elem
        merged.myArray[0] = val;
        //copy content from this obj
        for (int i=0; i<r.length; i++) {
            merged.myArray[1 + i] = r.myArray[i];
        }
        return merged;
    }

    std::ostream& operator<< (std::ostream & out, const IntArray& r){
        for(int i=0; i<r.length;i++)
        {
            out << r.myArray[i] <<' ';
        }
        return out;
    }

    std::istream& operator>> (std::istream & in, IntArray& r){
        for(int i=0; i<r.length;i++)
        {
            in >> r.myArray[i];
        }
        return in;
    }

}