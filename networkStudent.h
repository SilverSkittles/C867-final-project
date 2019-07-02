#pragma once
#ifndef Network_HEADER
#define Network_HEADER
#include "Student.h"

class networkStudent : public Student {

public:
	virtual Degree getDegreeProgram();
	networkStudent(string studentID, string firstName, string lastName, string studentEmail, int age, int[3], Degree degreeType);

private:
	Degree DegreeType = Networking;
};

#endif
