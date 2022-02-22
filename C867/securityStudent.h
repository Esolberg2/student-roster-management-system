#include <string>
#include "student.h"

class SecurityStudent : public Student
{
    private:
        DegreeType dtype;

    public:
        SecurityStudent();
        SecurityStudent(
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
        ~SecurityStudent();
};