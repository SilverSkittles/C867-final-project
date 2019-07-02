#include "pch.h"
#include "roster.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"

using namespace std;



void Roster::add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] == nullptr) {
			if (degreeProgram == Networking) {
				classRosterArray[i] = new networkStudent(studentID, firstName, lastName, studentEmail, studentAge, daysInCourse, degreeProgram);
			}
			else if (degreeProgram == Security) {
				classRosterArray[i] = new securityStudent(studentID, firstName, lastName, studentEmail, studentAge, daysInCourse, degreeProgram);
			}
			else if (degreeProgram == Software) {
				classRosterArray[i] = new softwareStudent(studentID, firstName, lastName, studentEmail, studentAge, daysInCourse, degreeProgram);
			}

			break;
		}
	}
}

void Roster::printAll() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
			classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	float avg = 0;
	int max = 3;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID) {
			int *DaysInCourse = classRosterArray[i]->getDaysInCourse();
			for (int x = 0; x < max; x++) {
				avg += DaysInCourse[x];
			}

			cout << "Student " << classRosterArray[i]->getstudentID() << "'s average number of days in the three courses is " << (avg / max) << endl;
			break;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram)
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}


void Roster::printInvalidEmails()
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		string email = classRosterArray[i]->getstudentEmail();
		bool isValid = false;
		size_t found = email.find("@");
		if (found != string::npos) {
			found = email.find(".");
			if (found != string::npos) {
				found = email.find(" ");
				if (found == string::npos) {
					isValid = true;
				}
			}
		}

		if (!isValid) {
			cout << email << " is not a valid email address \n";
		}
	}
}

void Roster::remove(string studentID)
{
	bool studentRemoved = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID) {
			classRosterArray[i] = nullptr;
			studentRemoved = true;
			break;
		}
	}

	if (studentRemoved == false) {
		cout << "ERROR: Student ID '" << studentID << "' does not exist \n";
	}
}


Roster::~Roster()
{
}

void main() {
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "C++" << endl;
	cout << " 000874972" << endl;
	cout << "Angela Cook" << endl;

	Roster classRoster;

	const string studentData[] = {
	"A1,John,Smith,John1989@g mail.com,20,30,35,40,Security",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,Network",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,Software",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,Security",
	"A5,Angela,Cook,acoo125@wgu.edu,34,55,32,28,Software"
	};


	for (int i = 0; i < 5; i++) {

		string data = studentData[i];
		istringstream studentInfo(data);
		string item;
		string tempData[9];

		int x = 0;
		while (getline(studentInfo, item, ',')) {
			tempData[x] = item;
			x++;
		}

		Degree studentDegree;
		if (tempData[8] == "Network") {
			studentDegree = Networking;
		}
		else if (tempData[8] == "Security") {
			studentDegree = Security;
		}
		else if (tempData[8] == "Software") {
			studentDegree = Software;
		}
		else {
			studentDegree = None;
		}
		classRoster.add(tempData[0], tempData[1], tempData[2], tempData[3], stoi(tempData[4]), stoi(tempData[5]), stoi(tempData[6]), stoi(tempData[7]), studentDegree);

	}

	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getstudentID());
	}
	cout << endl;
	classRoster.printByDegreeProgram(Software);
	cout << endl;
	classRoster.remove("A3");
	classRoster.remove("A3");
}

