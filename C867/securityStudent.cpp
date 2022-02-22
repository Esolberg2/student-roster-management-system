#include <iostream>
#include "securityStudent.h"

// attributes vs parameters

using namespace std;

SecurityStudent::SecurityStudent(): Student()
{
    dtype = SECURITY;
}

SecurityStudent::SecurityStudent(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse[],
    DegreeType degreetype)
    :Student(
        studentID,
        firstName,
        lastName,
        emailAddress,
        age,
        daysInCourse
        )
{
    dtype = degreetype;
}

DegreeType SecurityStudent:: getDegreeType(){
    return dtype;
}

void SecurityStudent:: print(){
    cout << getStudentID();
    cout << "\tfirstName: " << getFirstName();
    cout << "\tlastName: " << getLastName();
    cout << "\tage: " << getAge();
    cout << "\tdaysInCourse: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2];
    cout << "} Degree Program: SECURITY" << endl;
}

SecurityStudent:: ~SecurityStudent(){
    Student:: ~Student();
}