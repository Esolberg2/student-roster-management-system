
#include "roster.h"
using namespace std;

Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student*[capacity];
}

Student * Roster::getStudentAtIndex(int index)
{
    return classRosterArray[index];
}

void Roster::loadStudents(string row)
{
    int numDegrees = sizeof(degreeTypeString) / sizeof(degreeTypeString[0]);
    int lastFieldIndex = row.rfind(',');
    string degType = row.substr(lastFieldIndex+1);
    if (lastIndex < capacity) {
        lastIndex++;
        DegreeType degreeType;
        for( int a = 0; a < numDegrees -1; a++ ){
                
            if (degType == "SECURITY") {
                degreeType = SECURITY;
            }
            else if (degType == "NETWORK") {
                degreeType = NETWORK;
            }
            else if (degType == "SOFTWARE") {
                degreeType = SOFTWARE;
            }
            else if(a == numDegrees) {
                cerr << "Invalid Degree Type: " << degType << " Entered.  Quitting program." << endl;
                exit(-1);
            }
            
            int rightDelimiter = row.find(",");
            string studentID = row.substr(0, rightDelimiter);
            
            int leftDelimiter = rightDelimiter + 1;
            rightDelimiter = row.find(",", leftDelimiter);
            string firstName = row.substr(leftDelimiter, rightDelimiter - leftDelimiter);
            
            leftDelimiter = rightDelimiter + 1;
            rightDelimiter = row.find(",", leftDelimiter);
            string lastName = row.substr(leftDelimiter, rightDelimiter - leftDelimiter);
            
            leftDelimiter = rightDelimiter + 1;
            rightDelimiter = row.find(",", leftDelimiter);
            string email = row.substr(leftDelimiter, rightDelimiter - leftDelimiter);

            leftDelimiter = rightDelimiter + 1;
            rightDelimiter = row.find(",", leftDelimiter);
            int age = stoi(row.substr(leftDelimiter, rightDelimiter - leftDelimiter));

            leftDelimiter = rightDelimiter + 1;
            rightDelimiter = row.find(",", leftDelimiter);
            int dInCourse1 = stoi(row.substr(leftDelimiter, rightDelimiter - leftDelimiter));
            
            leftDelimiter = rightDelimiter + 1;
            rightDelimiter = row.find(",", leftDelimiter);
            int dInCourse2 = stoi(row.substr(leftDelimiter, rightDelimiter - leftDelimiter));
            
            leftDelimiter = rightDelimiter + 1;
            rightDelimiter = row.find(",", leftDelimiter);
            int dInCourse3 = stoi(row.substr(leftDelimiter, rightDelimiter - leftDelimiter));
            
            add(studentID, firstName, lastName, email, age, dInCourse1, dInCourse2, dInCourse3, degreeType);
        }
    }
}
   

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType dt)
{
    int daysInCourse[Student::arraySize];
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
        
    if (dt == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, dt);
    else if (dt == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, dt);
    else if (dt == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, dt);

}


void Roster::remove(string studentID)
{
    int numFound = 0;
    for (int a = 0; a <= lastIndex; a++) {
         if (this->classRosterArray[a] != nullptr){
             if (this->classRosterArray[a]->getStudentID() == studentID) {
//                delete classRosterArray[a]; //
//                classRosterArray[a] = classRosterArray[lastIndex];  //
//                lastIndex--; //
                this->classRosterArray[a] = nullptr;
                cout << "studentID: " << studentID << " has been removed" << endl;
                numFound = numFound + 1;
             }
        }
    }
    if (numFound == 0){
            cout << "No student with ID: " << studentID << " was found" << endl;
        }
    
}

void Roster::printAll()
{
    for (int a = 0; a <= this->lastIndex; a++) {
        if (this->classRosterArray[a] != nullptr) {
             (this->classRosterArray)[a]->print();
        cout << "" << endl;
        }
    }
}
 
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int a = 0; a <= this->lastIndex; a++) {
        if (this->classRosterArray[a]->getStudentID() == studentID){

            int* days = this->classRosterArray[a]->getDaysInCourse();
            int totalDays = 0;
            for (int day = 0; day < 3; day++){
                totalDays = totalDays + days[day];
            }
            double average = totalDays / 3.0;
            cout << "Student with ID " << studentID << " has an average of: " << average << " days in course" << endl;
            cout << "" << endl;
            break;
        }
        else if (a == this->lastIndex ){
            cout << a << endl;
            cout << this->lastIndex << endl;
            cout << "No student with ID: " << studentID << " was found" << endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    bool hasInvalidEmail = false;
    for (int a = 0; a <= this->lastIndex; a++) {
        string email = this->classRosterArray[a]->getEmailAddress();
        bool hasAt = false;
        bool hasDot = false;
        bool hasSpace = false;
        
//        for (int l = 0; l <= (sizeof(email) / sizeof(email[0])); l++){
          for (int l = 0; l < email.size(); l++){

            if (email[l] == '@') {
                hasAt = true;
            }
            if (email[l] == '.') {
                hasDot = true;
            }
            if (email[l] == ' ') {
                hasSpace = true;
            }
        }
        if (!((hasDot == true && hasAt == true) && hasSpace == false)){
            cout << "Email " << email << " is invalid" << endl;
            hasInvalidEmail = true;
        }
    }
    if (hasInvalidEmail == false) {
        cout << "No incorrect emails were found." << endl;
    }
}

void Roster::printByDegreeProgram(int degreeProgram)
{
    cout << "Printing Student Data for Degree Type: " << degreeTypeString[degreeProgram] << endl;
    for (int i = 0; i <= this->lastIndex; i++){
        if (this->classRosterArray[i]->getDegreeType() == degreeProgram){
            this->classRosterArray[i]->print();
            cout << "" << endl;
        }
    }
}

Roster::~Roster(){
     for (int i = 0; i <= this->lastIndex; i++){
         delete this->classRosterArray[i];
     }
     delete classRosterArray;
}


int main() {
    
    cout << "Course Title: Scripting and Programming - Applications – C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: #001019773" << endl;
    cout << "Student Name: Eric Solberg" << endl;
    cout << "" << endl;
    
    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Eric,Solberg,esolbe3@wgu.edu,29,5,10,15,SOFTWARE"
    };
    
    const int numEntries = sizeof(studentData)/(sizeof(studentData[0]));
   
    Roster* classRoster = new Roster(numEntries);
    
    for (int i = 0; i <= numEntries-1; i++){
        classRoster->loadStudents(studentData[i]);
    }
    cout << "---Student Data Load Complete---" << endl;
    cout << "" << endl;
    
    cout << "---Printing Student Roster---" << endl;
    classRoster->printAll();
    cout << "" << endl;
    
    cout << "---Checking for invalid emails---" << endl;
    classRoster->printInvalidEmails();
    cout << "" << endl;

        
    cout << "---Printing Average Days in Courses---" << endl;
    for (int i = 0; i <= numEntries -1; i++){
        classRoster->printAverageDaysInCourse(classRoster->getStudentAtIndex(i)->getStudentID());
    }
    
    classRoster->printByDegreeProgram(2);
    cout << "" << endl;
    classRoster->remove("A3");
    classRoster->remove("A3");
    classRoster->~Roster();
}