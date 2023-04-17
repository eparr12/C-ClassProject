#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main()
{
	Roster classRoster;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ethan,Parrish,eparr12@wgu.edu,32,25,33,35,SOFTWARE"
	};

	for (int i = 0; i < 5; i++)
	{
		classRoster.parse(studentData[i], i);
	}

	cout << "C867-Scripting & Programming: Applications" << endl << "Language: C++" << endl
		 << "Student ID: 001319612" << endl << "Name: Ethan Parrish" << endl << endl;

	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++)
	{
		string student = classRoster.classRosterArray[i]->GetStudentID();
		classRoster.printAverageDaysInCourse(student);
	}

	cout << endl;

	classRoster.printByDegreeProgram("SOFTWARE");

	classRoster.remove("A3");

	classRoster.remove("A3");

	classRoster.~Roster();

	return 0;
 }