#include <iostream>
#include "Course.h"
#include "Course.cpp"

void printCourse(const ComputerScience::Course& a);

using namespace std;

int main()
{
    using ComputerScience::Course;
    string name = "Computer Science II";
    string depart = "Computer Science";
    {
        Course cs2("System Programming", "Computer Science", 3);
        printCourse(cs2);
        cout << endl;
        cs2.setCourseName(name);
        cs2.setDepartment(depart);
        cs2.setCredit(4);
        printCourse(cs2);
    }
    cout << "\n\nEnter RETURN key to finish the program";
    cin.get();
    return 0;
}

void printCourse(const ComputerScience::Course& a)
{
    cout << "\"" << a.getCourseName() << "\" of "
         << a.getDepartment() << " Department has "
         <<a.getCredit() << " credits";
    
}