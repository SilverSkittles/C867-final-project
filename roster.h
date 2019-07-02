#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"

using namespace std;

class Roster {

public:
	void add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void printAll();
	void printByDegreeProgram(Degree degreeProgram);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void remove(string studentID);
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	~Roster();

};

