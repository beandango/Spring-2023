// towerofhanoi.cpp : Defines the entry point for the console application.
//DO NOT MODIFY THIS FILE

#include <iostream>
#include "towers.h"
#include "towers.cpp"

using namespace std;

int main()
{
	int numDisk = 4;
	Towers t(numDisk);
	t.start();
	return 0;
}

