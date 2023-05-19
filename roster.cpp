#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

void Roster::parseData(string students) {
	int rhs = students.find(",");
	string studentID = students.substr(0, rhs);
	int lhs = rhs + 1;

	rhs = students.find(",", lhs);
	string firstName = students.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = students.find(",", lhs);
	string lastName = students.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = students.find(",", lhs);
	string emailAddress = students.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = students.find(",", lhs);
	int age = stoi(students.substr(lhs, rhs - lhs));
	lhs = rhs + 1;

	rhs = students.find(",", lhs);
	int daysInCourse1 = stoi(students.substr(lhs, rhs - lhs));
	lhs = rhs + 1;

	rhs = students.find(",", lhs);
	int daysInCourse2 = stoi(students.substr(lhs, rhs - lhs));
	lhs = rhs + 1;

	rhs = students.find(",", lhs);
	int daysInCourse3 = stoi(students.substr(lhs, rhs - lhs));
	lhs = rhs + 1;

	rhs = students.find(",", lhs);
	DegreeProgram degreeProgram{};
	string degree = students.substr(lhs, rhs - lhs);
	if (degree == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degree == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degree == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void Roster::remove(string studentID) {
	bool bookFound = false;
	for (int i = 0; i < Roster::index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			bookFound = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[rosterSize - 1];
			classRosterArray[rosterSize - 1] = temp;
			Roster::index--;
		}
	}
	if (bookFound) {
		cout << "Removing " << studentID << ":" << endl << endl;
	}
	else {
		cout << "The student with the ID: " << studentID << " was not found" << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i <= Roster::index; i++) {
		Roster::classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << "Student ID: " << studentID << ", average days in course is: ";
			cout << ((classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2]) / 3) << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= Roster::index; i++) {
		string emailAddress = classRosterArray[i]->getEmailAddress();
		string studentID = classRosterArray[i]->getStudentID();
		if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(" ") != string::npos) {
			cout << emailAddress << " - is invalid" << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::index; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < rosterSize; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}