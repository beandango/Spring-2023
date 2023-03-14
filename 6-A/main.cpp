/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 6 A
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 03.13.2023

*/

#include <iostream>
#include "DynStringStack.hpp"
#include "DynStringStack.cpp"
#include <iostream>

int main()
{
	// Create a DynamicStringStack object.
	DynStringStack myStack;

	// Push the strings "one", "two", and
	// "three" onto the stack.
    std::cout << "Pushing one\n";
    myStack.push("one");
    std::cout << "Pushing two\n";
    myStack.push("two");
    std::cout << "Pushing three\n";
    myStack.push("three");

    // Pop the first string from the stack and display it.
    std::cout << "Popping...\n";
    if (!myStack.isEmpty()) {
        std::cout << myStack.getTop()->string;
        myStack.pop();
    } else {
        std::cout << "Stack is empty!\n";
    }

	// Pop the second string from the stack
	// and display it.
	std::cout << "\nAttempting to pop again... \n";
    if (!myStack.isEmpty()) {
        std::cout << myStack.getTop()->string;
        myStack.pop();
    } else {
        std::cout << "Stack is empty!\n";
    }

	// Pop the third string from the stack
	// and display it.
	std::cout << "\nAttempting to pop again... \n";
    if (!myStack.isEmpty()) {
        std::cout << myStack.getTop()->string;
        myStack.pop();
    } else {
        std::cout << "Stack is empty!\n";
    }

	// The stack is empty, but try to pop again.
	std::cout << "\nAttempting to pop again... \n";
    if (!myStack.isEmpty()) {
        std::cout << myStack.getTop()->string;
        myStack.pop();
    } else {
        std::cout << "Stack is empty!\n";
    }

	return 0;
}
