#include "pch.h"
#include "networkStudent.h"
#include "degree.h"


Degree networkStudent::getDegreeProgram() {
	return DegreeType;
}

networkStudent::networkStudent(string studentID, string firstName, string lastName, string studentEmail, int age, int daysInCourse[3], Degree degreeType) : Student(studentID, firstName, lastName, studentEmail, age, daysInCourse, degreeType)
{

}