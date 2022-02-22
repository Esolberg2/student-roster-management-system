#include <string>
#include "student.h"

class NetworkStudent : public Student
{
    private:
        DegreeType dtype;
        
    public:
        NetworkStudent();
        NetworkStudent(
                string studentID,
                string firstName,
                string lastName,
                string emailAddress,
                int age,
                int daysInCourse[],
                DegreeType degreetype
                );
        DegreeType getDegreeType();
        void print();
        
        ~NetworkStudent();
};