#include <iostream>
#include "networkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent(): Student()
{
    dtype = NETWORK;
}

NetworkStudent::NetworkStudent(
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

DegreeType NetworkStudent:: getDegreeType(){
    return dtype;
}

void NetworkStudent:: print(){
    cout << getStudentID();
    cout << "\tfirstName: " << getFirstName();
    cout << "\tlastName: " << getLastName();
    cout << "\tage: " << getAge();
    cout << "\tdaysInCourse: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2];
    cout << "} Degree Program: NETWORK" << endl;
}

NetworkStudent:: ~NetworkStudent(){
    Student:: ~Student();
}