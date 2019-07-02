#pragma once
#ifndef Security_HEADER
#define Security_HEADER
#include "Student.h"
#include "degree.h"

class securityStudent : public Student {

public:
	virtual Degree getDegreeProgram();
	securityStudent(string studentID, string firstName, string lastName, string studentEmail, int age, int[3], Degree degreeType);
	Degree DegreeType = Security;
};

#endif

