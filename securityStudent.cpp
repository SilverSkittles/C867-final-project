#include "pch.h"
#include "securityStudent.h"
#include "degree.h"


Degree securityStudent::getDegreeProgram() {
	return DegreeType;
}

securityStudent::securityStudent(string studentID, string firstName, string lastName, string studentEmail, int age, int daysInCourse[3], Degree degreeType) : Student(studentID, firstName, lastName, studentEmail, age, daysInCourse, degreeType)
{

}