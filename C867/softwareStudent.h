#include <string>
#include "student.h"

class SoftwareStudent : public Student
{
    private:
        DegreeType dtype;
        
    public:
        SoftwareStudent();
        SoftwareStudent(
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
        
        ~SoftwareStudent();
};