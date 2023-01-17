/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 1-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 01.16.2022
Purpose: The purpose of this assignment is to make sure that you know how
 to write a program that uses unnamed namespace, separate compilation, 
 external linkage, dynamic memory and smart pointers.
*/

#include "PROTOTYPES.hpp"
#include "DELETE_REPEATS.cpp"
#include <memory>
#include <iostream>

//Size as a global constant that I can access in other files


extern const int SIZE = 10;


int main()
{
    char originalArray[SIZE];

    originalArray [0] = 'a';

    originalArray [1] = 'b';

    originalArray [2] = 'b';

    originalArray [3] = 'c';

    originalArray [4] = 'a';

    originalArray [5] = 'c';

    originalArray [6] = 'a';

    originalArray [7] = 'c';

    originalArray [8] = 'b';

    originalArray [9] = 'c';

    //Passing this int into the function call below so i can keep track of how many characters were removed
    int removed = SIZE;
    std::unique_ptr<char[]>noRepeats = deleteRepeats(originalArray, removed);

    //Final printing loop :)
    for (int i = 0; i < SIZE-removed; i++) {
        std::cout << noRepeats[i] << "\n";
    }

    return 0;
}