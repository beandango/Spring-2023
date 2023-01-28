#ifndef MYDATASTRUCTURE_HPP
#define MYDATASTRUCTURE_HPP

#include <string>

namespace CS2
{
    using std::string;
    struct Student
    {
        int ID;
        string Name;
        int YearInSchool;
        double OveralGPA;
    };
}

#endif