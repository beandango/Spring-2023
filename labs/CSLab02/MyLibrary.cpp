#include "MyLibrary.hpp"

namespace CS2
{
    double averageGPA(Student students[], int studentNumber)
    {
        double totalGPA = 0;
        for(int i = 0; i < studentNumber; i++){
            totalGPA += students[i].OveralGPA;
        }
        return totalGPA/static_cast<double>(studentNumber);
    }
}