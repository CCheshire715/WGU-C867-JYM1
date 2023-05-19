#pragma once
#include <iostream>
#include "degree.h"
using namespace std;

class Student {

public:
	const static int courseDays = 3;

	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int numDays[], DegreeProgram degreeProgram);
	
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	const int* getNumDays();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setStudentAge(int studentAge);
	void setNumDays(const int numDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int numDays[courseDays];
	DegreeProgram degreeProgram;
};
