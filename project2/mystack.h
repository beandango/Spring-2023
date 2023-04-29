#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;        //index of the top element in the stack array

public:
   // Constructor
   MyStack(int size) : stackSize(size), numElem(-1) {
       stackArray = new T[stackSize];
   }

   // Copy constructor
   MyStack(const MyStack &other) : stackSize(other.stackSize), numElem(other.numElem) {
       stackArray = new T[stackSize];
       for (int i = 0; i <= numElem; i++) {
           stackArray[i] = other.stackArray[i];
       }
   }

   //operator= overloading
   MyStack& operator=(const MyStack &other) {
       if (this == &other) {
           return *this;
       }
       delete[] stackArray;
       stackSize = other.stackSize;
       numElem = other.numElem;
       stackArray = new T[stackSize];
       for (int i = 0; i <= numElem; i++) {
           stackArray[i] = other.stackArray[i];
       }
       return *this;
   }

   // Destructor
   ~MyStack() {
       delete[] stackArray;
   }

   // Stack operations
   void push(T value) {
       if (!isFull()) {
           numElem++;
           stackArray[numElem] = value;
       } else {
           cout << "Stack is full!" << endl;
       }
   }

   T pop() {
       if (!isEmpty()) {
           T value = stackArray[numElem];
           numElem--;
           return value;
       } else {
           cout << "Stack is empty!" << endl;
           return T();
       }
   }

   T top() {
       if (!isEmpty()) {
           return stackArray[numElem];
       } else {
           cout << "Stack is empty!" << endl;
           return T();
       }
   }

   bool isFull() const {
       return numElem >= stackSize - 1;
   }

   bool isEmpty() const {
       return numElem == -1;
   }

   int size() const {
       return numElem + 1;
   }
};

#endif
