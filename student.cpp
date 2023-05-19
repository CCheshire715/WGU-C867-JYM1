#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int numDays[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->numDays[0] = numDays[0];
	this->numDays[1] = numDays[1];
	this->numDays[2] = numDays[2];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmailAddress() {
	return this->emailAddress;
}
int Student::getStudentAge() {
	return this->studentAge;
}
const int* Student::getNumDays() {
	return this->numDays;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setStudentAge(int studentAge) {
	this->studentAge = studentAge;
}
void Student::setNumDays(const int numDays[]) {
	this->numDays[0] = numDays[0];
	this->numDays[1] = numDays[1];
	this->numDays[2] = numDays[2];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << studentID << "\t";
	cout << firstName << "\t";
	cout << lastName << "\t";
	cout << studentAge << "\t";
	cout << "{" << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "}\t";
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}