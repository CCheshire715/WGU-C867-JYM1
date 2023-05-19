#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {

	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Programming language: C++" << endl;
	cout << "WGU student ID: 010713063" << endl;
	cout << "Name: Curtis Cheshire" << endl << endl;
	
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Curtis,Cheshire,cchesh3@wgu.edu,31,4,6,8,SOFTWARE"
	};

	const int students = 5;

	Roster classRoster;

	for (int i = 0; i < students; i++) {
		classRoster.parseData(studentData[i]);
	}

	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Displaying invalid emails: " << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	for (int i = 0; i < students; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	
	cout << endl << "Showing students in degree program: SOFTWARE" << endl << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	classRoster.printAll();
	cout << endl << "Removing A3 again" << endl << endl;

	classRoster.remove("A3");
	cout << "DONE.";


	return 0;
}