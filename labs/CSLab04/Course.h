#ifndef COURSE_H
#define COURSE_H

#include <string>
namespace ComputerScience
{
    class Course
    {
        private:
            std::string courseName;
            std::string department;
            int credit;
            int scoreNumber; //store the size of array scores
            int *scores; //store the address of dynamically allocated array for scores
        public:
            Course(); //default constructor
            Course(std::string courseName, std::string department, int credit); //constructor
            Course(const Course& a); //must use ref parameter to avoid copying object
            ~Course(); //destructor
            Course& operator=(const Course& a);
            //return type must be the reference
            //of itself to support consecutive assignment such as a=b=c
            std::string getCourseName() const
            {
                return courseName;//inline function
            }

            //you can add keyword inline for inline functions
            inline std::string getDepartment() const
            {
                return department;
            }
            int getCredit() const;
            void setCourseName(std::string courseName);
            void setDepartment(std::string department);
            void setCredit(int credit);

            void setNumberOfScores(int number);//set numbe of scores and dynamically allocate the array
            int getNumberOfScores() const;//get number of scores
            void setScore(int index, int aScore);//set score at the array pos index
            int getScore(int index) const;
            double getAverageScore() const;//get the average (retain decimals)
        private: //helper functions
            void freeMemory();//clear memory allocated
            void contentCopy(const Course& a); //copy content from variable a

    };
}

#endif //COURSE_H