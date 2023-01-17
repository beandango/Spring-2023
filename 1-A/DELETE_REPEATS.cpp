#include "PROTOTYPES.hpp"
#include <iostream>

//global constant accessed :)
extern const int SIZE;

//Precondition: Array of char's declared in main, "removed" set equal to the size constant
//Postcondition: returns a new dynamic array with duplicate characters removed
std::unique_ptr<char[]> deleteRepeats(char arr[], int& removed) {
    int n = SIZE;

    //array of booleans that store if a particular character has been seen in the below loop, false by default
    bool seen[256] = {false};
    int j = 0;
    std::unique_ptr<char[]> newArr(new char[n]);

    //loop to find dupes
    for (int i = 0; i < n; i++) {
        if (!seen[arr[i]]) {            //if character at current index has not been seen:
            seen[arr[i]] = true;        //it is marked as seen,
            newArr[j++] = arr[i];       //then the character is added to the newArr
            removed--;                  //number of characters remaining in the arr decreases
        }
    }
    return newArr;
}