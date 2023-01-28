#include <iostream>
#include "MyLibrary.hpp"
#include "MyDataStructure.hpp"
#include "MyLibrary.cpp"

using std::cout;
using std::cin;

int main(){
    const int STUDENT_NUM = 3;
    CS2::Student students[STUDENT_NUM];
    for(int i = 0; i < STUDENT_NUM; i++){
        cout<<"Enter the information of the student #" << i+1<<" below\n";
        cout<<" ID (integer):";
        cin>>students[i].ID;
        cout<<" Name:";
        cin.ignore();
        getline(cin, students[i].Name);
        cout<<" Year in school (integer)";
        cin>>students[i].YearInSchool;
        cout<<"Year GPA (decimal or integer)";
        cin>>students[i].OveralGPA;
    }

    double avgGPA = CS2::averageGPA(students, STUDENT_NUM);
    cout<<"average GPA of "<<STUDENT_NUM<<" students is "<<avgGPA;
    return 0;
}