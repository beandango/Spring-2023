#ifndef INTARRAY_H
#define INTARRAY_H

namespace ComputerScience
{
    class IntArray {
        private:
            int length;         //hold the array size i.e. the number of nodes
            struct ListNode 
            {
                int value;      //hold the value
                ListNode *previous, *next;
                //previous: pointing to the prev node
                //next: pointing to the next node

            };
            ListNode *first;    //hold the address of the first node
            ListNode *last;     //hold the address of the last node
            ListNode *current;  //hold the address of the current node. Think as a cursor
            int currentIndex;   //hold the array index value of the node that current points to
            //implementation code must maintain the consistency of currentIndex and current
        public:
            IntArray(int length = 0); //constructor. length is the array size. default to 0 
            IntArray(const IntArray & r); //copy constructor to initiate the instance from existing instance 
            ~IntArray(); //destructor. Allocated array must be deleted in this function 
            int size() const; //getter function to return the size of the array
            int& operator[](int i); //subscript operator overloading. The return value must be the reference of the element of the array 
            IntArray& operator= (const IntArray& r); //overloading operator=
            IntArray operator+ (const IntArray& r) const; //overloading operator + to merge two IntArrays
            IntArray operator+ (int) const; //overloading operator to add an int element at the end of the array
            IntArray& operator+= (const IntArray& r); //overloading operator += to append an array
            IntArray& operator+= (int); //overloading operator += to append an int to the end of the array
            void Resize (int newSize); //resize the array to the length of newSize, Irt preserves the existing values
            friend std::ostream& operator<< (std::ostream & out, const IntArray& r); //friend function to overload operator << for output 
            friend std::istream& operator>> (std::istream & in, IntArray& r); //friend function to overload operator >> for input
            friend IntArray operator+ (int, const IntArray&); //commutative + of IntArray operator+(int)
        private:
            void copyContent(const IntArray& r); //copy the content from another obj
            void addNodes(int num); //add num nodes (placeholder) to the end of the list
            void removeNodes(int num); //remove num nodes from the end of the list
    };
}

#endif //INTARRAY_H