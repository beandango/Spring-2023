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
        public:
            Course();
            Course(std::string courseName, std::string department, int credit);
            ~Course();
            std::string getCourseName() const
            {
                return courseName;
            }

            inline std::string getDepartment() const
            {
                return department;
            }
            int getCredit() const;
            void setCourseName(std::string courseName);
            void setDepartment(std::string department);
            void setCredit(int credit);
    };
}

#endif //COURSE_H