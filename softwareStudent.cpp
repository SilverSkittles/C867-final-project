#include "pch.h"
#include "softwareStudent.h"
#include "degree.h"


Degree softwareStudent::getDegreeProgram() {

	return DegreeType;
}

softwareStudent::softwareStudent(string studentID, string firstName, string lastName, string studentEmail, int age, int daysInCourse[3], Degree degreeType) : Student(studentID, firstName, lastName, studentEmail, age, daysInCourse, degreeType)
{

}
