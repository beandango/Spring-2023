#ifndef INTARRAY_H
#define INTARRAY_H
#include <iostream>

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
            class iterator {
                private:
                    ListNode *p; //pointing to a node
                    ListNode* noWhere(); //generate a ListNdoe* pointing to nowhere
                                        //so it can be used in container.end()
                public:
                    using iterator_category = std::forward_iterator_tag; //specify it is a forward iterator
                    using difference_type = std::ptrdiff_t; //a signed int type that can be used to identify
                                                            //distance between iterator steps. Out iterator is 
                                                            //basically a wrapper around a pointer and leverages
                                                            //pointer arithmetic, so the default std::ptrdiff_t
                                                            //is a good choice
                    using value_type       = int; //the type the iterator iterates over. int in our case
                    using pointer           = int*; //defines a pointer to the type iterated over
                    using reference         = int&; //defines a reference to the type iterated over

                    iterator(ListNode* ln = nullptr); //default constructor and 
                                                    //constructor with a pointer of list node passed in
                    bool operator != (const iterator &right); //overloading !=
                    bool operator == (const iterator &right); //overloading ==
                    int & operator*(); //dereference operator
                    iterator& operator ++(); //prefix ++, advnacing iterator
                    iterator operator++(int); //postfix ++, parameter is a dummy parameter
                    iterator operator+(int steps); //overloading +. Advancing iterator
                                                //for that many steps specified by the parameter
            };
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
            iterator begin(); //return the iterator pointing to the first node
            iterator end(); //return the iterator pointing to an address a little more than the last node
        private:
            void copyContent(const IntArray& r); //copy the content from another obj
            void addNodes(int num); //add num nodes (placeholder) to the end of the list
            void removeNodes(int num); //remove num nodes from the end of the list
    };
}

#endif //INTARRAY_H