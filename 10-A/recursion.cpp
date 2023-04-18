/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 10
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 04.17.2023
   Purpose: The purpose of this assignment is to make sure that you know how to write 
   a program that uses user written recursion functions.
*/
#include <iostream>

// prototypes
template <class T>
void printarray(const T[], int);
template <class T>
int partition(T ar[], int first, int last);
void chew_system_stack();

/*
 * Recursive version of fibonacci
 */
int fibrecurse(int n) {
    if (n <= 1)
        return n;
    else
        return fibrecurse(n - 1) + fibrecurse(n - 2);
}

/*
 * Iterative (loop) version of fibonacci
 */
int fibiterate(int n) {
    int a = 0, b = 1, c;

    if (n <= 1)
        return n;

    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

/*
 * Recursive quicksort
 */
template <class T>
void quicksort(T ar[], int first, int last) {
    if (first < last) {
        int pivotIndex = partition(ar, first, last);
        quicksort(ar, first, pivotIndex - 1);
        quicksort(ar, pivotIndex + 1, last);
    }
}

/*
* Helper Function for Quicksort
*/
template <class T>
int partition(T ar[], int first, int last) {
    T pivot = ar[last];
    int i = first - 1;

    for (int j = first; j < last; ++j) {
        if (ar[j] <= pivot) {
            ++i;
            std::swap(ar[i], ar[j]);
        }
    }
    std::swap(ar[i + 1], ar[last]);
    return i + 1;
}

int main() {
    const int FIBLOOPS = 10;
    const int ARSIZ = 16;
    int ar[ARSIZ];

    std::cout << "Recursive fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibrecurse(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Iterative fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibiterate(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Quicksort:" << std::endl;
    // populate random array
    for(int i = 0; i < ARSIZ; ++i)
    {
        ar[i] = (i * 3037) % 2099;  // prime numbers! again!
    }
    printarray(ar, ARSIZ);
    quicksort(ar, 0, ARSIZ-1);
    printarray(ar, ARSIZ);

    //std::cout << "Chewing system stack:" << std::endl;
    //chew_system_stack();

    return 0;
}

/*  utility functions, do not modify  */
template <class T>
void printarray(const T ar[], int s)
{
    for(int i = 0; i < s; ++i)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

//following code is assembly code, commented for now. 
//It works in GCC compiler (Code Blocks) while not working in Visual Studio
//void printstackpointer()
//{
//    void * stack_pointer;
//    // inline assembly language to get stack pointer
//    __asm__ __volatile__("movl  %%esp,%%eax"
//                             :"=a"(stack_pointer)
//                             );
//    std::cout << stack_pointer << std::endl;
//}
//
//void chew_system_stack()
//{
//    // Feel free to play with this, but please
//    // do NOT enable this for your final commit!
//    printstackpointer();
//    chew_system_stack();
//}
/* end utilities */
