#include "Course.h"
#include <iostream>

namespace ComputerScience
{
    Course::Course() //default constructor
    {
        scoreNumber = 0;
        scores = nullptr;
        std::cout<<"\n default constuctor is called \n";
    }

    Course::Course(std::string courseName, std::string department, int credit)
    {
        scoreNumber = 0;
        scores = nullptr;
        this->courseName = courseName;
        this->department = department;
        this->credit = credit;
        std::cout<<"\n constructor with 3 parameters is called \n";
    }

    Course::Course(const Course& a) //copy constructor
    {
        contentCopy(a);
        std::cout<<"copy constructor is called";
    }

    Course& Course::operator=(const Course& a)
    {
        if(this == &a){ //this is the pointer to itself
        //the address of itself is the saem as the address of abject a
        //it is doing a=a. So do nothing
            return *this; //return this object
        }
        freeMemory(); //clean current scores
        contentCopy(a); //copy all 
        std::cout<<"overloaded assignment is called";
        return *this; //return the ref of the obj
    }

    void Course::contentCopy(const Course& a){
        //assign non-pointer members 
        courseName = a.courseName;
        department = a.department;
        credit = a.credit;
        //handle array
        if(a.scoreNumber == 0){
            scoreNumber = 0;
            scores = nullptr;
        }else{
            //only allocate mem and copy arr with a.scorenumber is not 0
            scoreNumber = a.scoreNumber;
            scores = new int[scoreNumber];
            for(int i=0; i < scoreNumber; i++)
            {
                scores[i] = a.scores[i]; //copy arr elements
            }
        }

    }

    Course::~Course() //destructor 
    {
        freeMemory(); //free memory and set scores to null
        std::cout << "\n destructor is automatically called. The object is destroyed \n";
    }
    
    void Course::freeMemory()
    {
        if(scores != nullptr){
            delete[] scores;
            scores = nullptr;
            scoreNumber = 0;
        }
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

    void Course::setNumberOfScores(int number)
    {
        if(number < 0){
            std::cout<<"number of scores can not be negative";
        }
        else if(number == 0){
            freeMemory();
        }
        else{
            freeMemory();
            scores = new int[number];
            scoreNumber = number;
        }
    }

    int Course::getNumberOfScores() const{
        return scoreNumber;
    }

    void Course::setScore(int index, int aScore){
        if(index < 0 || index >= scoreNumber){
            std::cout<<"the index is out of range";
        }
        else{
            scores[index] = aScore;
        }
    }

    int Course::getScore(int index) const{
        if(index < 0 || index >= scoreNumber){
            std::cout<<"the index is out of range";
            return -1;
        }
        else{
            return scores[index];
        }
    }

    double Course::getAverageScore() const{
        if(scoreNumber == 0) return -1;
        double total = 0;
        for(int i=0; i<scoreNumber; i++){
            total += scores[i];
        }
        return total/scoreNumber;
    }

}