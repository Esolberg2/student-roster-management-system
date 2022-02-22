#include <iostream>
#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent(): Student()
{
    dtype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(
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

DegreeType SoftwareStudent:: getDegreeType(){
    return dtype;
}

void SoftwareStudent:: print(){
    cout << getStudentID();
    cout << "\tfirstName: " << getFirstName();
    cout << "\tlastName: " << getLastName();
    cout << "\tage: " << getAge();
    cout << "\tdaysInCourse: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2];
    cout << "} Degree Program: SOFTWARE" << endl;
}

SoftwareStudent:: ~SoftwareStudent(){
    Student:: ~Student();
}