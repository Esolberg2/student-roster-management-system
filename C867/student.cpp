#include <iostream>
#include "student.h"
using namespace std;

// defaults if class is created without any arguments
Student::Student(){
    this->studentID = -1;
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    for (int n = 0; n < arraySize; n++) this->daysInCourse[n] = 0;
}

Student::Student(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse[]
    ){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int n = 0; n < arraySize; n++) this->daysInCourse[n] = daysInCourse[n];
}

//getters
string Student::getStudentID(){
    return studentID;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName(){
    return lastName;
}
string Student::getEmailAddress(){
    return emailAddress;
}
int Student::getAge(){
    return age;
}
int* Student::getDaysInCourse(){
    return daysInCourse;
}

//setters
void Student::setStudentID(string studentID){
    this->studentID = studentID;
}
void Student::setFirstName(string firstName){
    this->firstName = firstName;
}
void Student::setLastName(string lastName){
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress){
    this->emailAddress = emailAddress;
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setDaysInCourse(int daysInCourse[]){
    for (int n = 0; n < arraySize; n++)
    this->daysInCourse[n] = daysInCourse[n];
}


Student::~Student(){};