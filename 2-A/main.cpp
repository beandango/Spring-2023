/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 2-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 01.19.2022
Purpose: The purpose of this assignment is to make sure that you 
know how to write a program that uses classes or structs.
*/

#include "Tax.hpp"
#include "Tax.cpp"
#include "TaxDataType.hpp"
#include <iostream>
#include <vector>

int main()
{
    // created a vector to store tax payer info
    std::vector<taxInfo> payers;
    taxInfo tax;

    //function calls to collect info and then print infos
    taxTake(payers, tax);
    printTax(payers, tax);

    return 0;
}
