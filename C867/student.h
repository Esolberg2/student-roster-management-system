#include <string>
#include "degree.h"
#pragma once

using std::string;

class Student
{
    public:
        const static int arraySize = 3;
        Student();
        Student(
                string studentID,
                string firstName,
                string lastName,
                string emailAddress,
                int age,
                int daysInCourse[]
                );
        
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int* getDaysInCourse();
        virtual DegreeType getDegreeType() = 0;
        
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDaysInCourse(int daysInCourse[]);
        
        virtual void print() = 0;
        
        virtual ~Student() = 0;
//        ~Student();

        
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysInCourse[arraySize];        
};