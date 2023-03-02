#include "Course.cpp"
#include "Course.h"
#include <iostream>

using namespace std;

void printCourse(const ComputerScience::Course& a);

int main(){
    using ComputerScience::Course;
    string name = "Computer Science II";
    string depart = "Computer Science";
    {
        Course cs2;
        printCourse(cs2);
        cout<<endl;cout<<endl;
        cs2.setCourseName(name);
        cs2.setDepartment(depart);
        cs2.setCredit(4);
        cs2.setNumberOfScores(3); //set three scores
        cs2.setScore(0, 95);
        cs2.setScore(1, 97);
        cs2.setScore(2, 100);
        printCourse(cs2);
        cout<<endl;cout<<endl;
        cs2.setNumberOfScores(2); //reset scores
        cs2.setScore(0, 60);
        cs2.setScore(1, 70);
        cout<<"After reset scores:\n";
        printCourse(cs2);

        Course previousCS2(cs2);
        Course nextCS2;
        nextCS2 = cs2;
        cout<<"\npreviousCS2 after declared:\n";
        printCourse(previousCS2);
        cout<<"\nnextCS2 after assigned:\n";
        printCourse(nextCS2);
        //change a score in cs2
        cs2.setScore(0, 100);
        cout<<"\ncs2 after score at pos 0 is changed:\n";
        printCourse(cs2);
        cout<<"\npreviousCS2 after score at pos 0 of cs2 is changed:\n";
        printCourse(previousCS2);
        cout<<"\nnextCS2 after score at pos 0 is changed:\n";
        printCourse(nextCS2);
    }
    cout<<"\n\nEnter RETURN key tp finish the program";
    cin.get();
    return 0;
}

void printCourse(const ComputerScience::Course& a){
    //display the course info
    cout<<"\""<<a.getCourseName()<<"\" of "
        <<a.getDepartment()<<" Department has "
        <<a.getCredit()<<" credits\n"
        <<"It contains "<<a.getNumberOfScores()<<" scores with average "<<a.getAverageScore();
}
