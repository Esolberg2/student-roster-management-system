#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

class Roster {
    private:
    int lastIndex;
    int capacity;
    Student** classRosterArray;
    
    public:
        Roster();
        Roster(int capacity);
        
        Student* getStudentAtIndex(int index);
        void loadStudents(string datarow);
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType dtype);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(int degreeProgram);
        ~Roster();
};