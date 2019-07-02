#pragma once
#ifndef Software_HEADER
#define Software_HEADER
#include "Student.h"


class softwareStudent : public Student {

public:
	virtual Degree getDegreeProgram();
	softwareStudent(string studentID, string firstName, string lastName, string studentEmail, int age, int[3], Degree degreeType);
	Degree DegreeType = Software;
};

#endif
