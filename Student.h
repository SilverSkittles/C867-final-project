#pragma once
#ifndef Student_HEADER
#define Student_HEADER
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;


class Student {
public:

	Student();
	Student(string studentID, string firstName, string lastName, string studentEmail, int age, int DaysInCourse[3], Degree degreeType);
	~Student();
		int getstudentAge();
		int *getDaysInCourse();
		string getstudentID();
		string getfirstName();
		string getlastName();
		string getstudentEmail();
		Degree getDegreeType();
		void setStudentAge(int age);
		void setDaysInCourse(int DaysInCourse[3]);
		void setStudentEmail(string studentEmail);
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setDegreeType(Degree degreeType);
		virtual void print();
		virtual Degree getDegreeProgram();
		Degree DegreeType;


private:
		
		string StudentID;
		string FirstName;
		string LastName;
		string StudentEmail;
		int StudentAge;
		int DaysInCourse[3];
		
};

#endif