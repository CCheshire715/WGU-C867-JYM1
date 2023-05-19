#pragma once
#include <string>
#include "student.h"
using namespace std;

class Roster {

public:
	const static int rosterSize = 5;
	Student* classRosterArray[rosterSize] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	void parseData(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();

private:
	int index = -1;
};
