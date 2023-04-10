/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 9
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 04.10.2023
   Purpose: This program is the test cases for the assignment
*/
#include <iostream>
#include <iomanip>

using std::cout, std::endl;

// prototypes
void unpackCharacters(char[], unsigned);
void displayBits(unsigned);

int main() {
   char characters[4];
   unsigned packed{1633903975}; // a, c, e, g

   cout << "The packed character representation is:\n";
   displayBits(packed);

   // demonstrate unpacking of characters
   unpackCharacters(characters, packed);
   cout << "\nThe unpacked characters are: ";
   for (size_t i{0}; i < 4; ++i) {
      cout << characters[i] << " ";
   }
   cout << endl;

   cout << "\nThe unpacked characters in bits are:" << endl;
   for (size_t i{0}; i < 4; ++i) {
      displayBits(characters[i]);
   }
}

// take apart the characters
void unpackCharacters(char characters[], unsigned pack)
{
   const unsigned mask1 = 4278190080;
   const unsigned mask2 = 16711680;
   const unsigned mask3 = 65280;
   const unsigned mask4 = 255;

   characters[0] = (pack & mask1) >> 24;
   characters[1] = (pack & mask2) >> 16;
   characters[2] = (pack & mask3) >> 8;
   characters[3] = (pack & mask4);
}

// display the bits of value
void displayBits(unsigned value)
{
   const int SHIFT{8 * sizeof(unsigned) - 1};
   const unsigned MASK{1u << SHIFT};

   for (int i{1}; i <= SHIFT + 1; ++i) {
      cout << (value & MASK ? '1' : '0');
      value <<= 1;

      if (i % 8 == 0) {
         cout << ' ';
      }
   }

   cout << endl;
}
