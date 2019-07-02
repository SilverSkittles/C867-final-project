#include "pch.h"
#include <iostream>
#include "Student.h"
#include "Degree.h"
#include <string>
using namespace std;

Student::Student() 
{

}

Student::Student(string studentID, string firstName, string lastName, string studentEmail, int age, int DaysInCourse[3], Degree degreeType) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setStudentEmail(studentEmail);
	setStudentAge(age);
	setDaysInCourse(DaysInCourse);
	setDegreeType(degreeType);
}


	int Student::getstudentAge(){
		return StudentAge;
	}

	int *Student::getDaysInCourse(){
		return DaysInCourse;
	}
	
	string Student::getstudentEmail(){
		return StudentEmail;
	}

	string Student::getfirstName(){
		return FirstName;
	}

	string Student::getlastName(){
		return LastName;
	}

	string Student::getstudentID(){
		return StudentID;
	}

	Degree Student::getDegreeType(){
		return DegreeType;
	}

	void Student::setStudentAge(int studentAge){
		this->StudentAge = studentAge;
	}

	void Student::setDaysInCourse(int *daysInCourse){
		for (int i = 0; i < 3; i++) {
			this->DaysInCourse[i] = daysInCourse[i];
		}
	}

	void Student::setStudentEmail(string studentEmail){
		this->StudentEmail = studentEmail;
	}

	void Student::setFirstName(string firstName){
		this->FirstName = firstName;
	}

	void Student::setLastName(string lastName){
		this->LastName = lastName;
	}

	void Student::setStudentID(string studentID){
		this->StudentID = studentID;
	}

	void Student::setDegreeType(Degree degreeType){
		this->DegreeType = degreeType;
	}


void Student::print(){
	int *DaysInCourse = getDaysInCourse();

	cout << getstudentID() << "\t";
	cout << "First Name: " << getfirstName() << "\t";
	cout << "Last Name: " << getlastName() << "\t";
	cout << "Age: " << getstudentAge() << "\t";
	cout << "Days in course: {" << DaysInCourse[0] << "," << DaysInCourse[1] << "," << DaysInCourse[2] << "}\t";

	cout << "Degree Program: ";
	switch (getDegreeProgram()) {
	case 0: cout << "Security";
		break;
	case 1: cout << "Networking";
		break;
	case 2: cout << "Software";
		break;
	case 4: cout << "None";
		break;
	}
	cout << endl;
}


Degree Student::getDegreeProgram(){
	return Software;
}

Student::~Student(){
}