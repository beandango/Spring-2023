#include "Course.h"
#include <iostream>

namespace ComputerScience
{
    Course::Course()
    {
        std::cout<<"\n default constuctor is called \n";
    }
    Course::Course(std::string courseName, std::string department, int credit)
    {
        this->courseName = courseName;
        this->department = department;
        this->credit = credit;
        std::cout<<"\n constructor with 3 parameters is called \n";
    }
    Course::~Course()
    {
        std::cout << "\n destructor is automatically called. The object is destroyed \n";
    }
    int Course::getCredit() const
    {
        return credit;
    }
    void Course::setCourseName(std::string courseName)
    {
        this->courseName = courseName;
    }
    void Course::setDepartment(std::string department)
    {
        this->department = department;
    }
    void Course::setCredit(int cdt)
    {
        credit = cdt;
    }
}