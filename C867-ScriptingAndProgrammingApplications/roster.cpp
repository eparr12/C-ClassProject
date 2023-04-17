#include <iostream>
#include "roster.h"
using namespace std;

	void Roster::parse(string studentList, int index)
	{
		size_t rhs = studentList.find(",");
		string initStudentID = studentList.substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		string initFirstName = studentList.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		string initLastName = studentList.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		string initEmailAddress = studentList.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		int initAge = stoi(studentList.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		int initDaysInCourse1 = stoi(studentList.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		int initDaysInCourse2 = stoi(studentList.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		int initDaysInCourse3 = stoi(studentList.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentList.find(",", lhs);
		string initDegreeProgram = studentList.substr(lhs, rhs - lhs);

		add(initStudentID, initFirstName, initLastName, initEmailAddress, initAge, initDaysInCourse1, initDaysInCourse2, initDaysInCourse3, 
			initDegreeProgram, index);
	};

	void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
					 int daysInCourse3, string initDegreeProgram, int index)
	{
		if (index == 5)
		{
			string student;
			for (int i = 0; i < 5; i++)
			{
				student = classRosterArray[i]->GetStudentID();
				if (student == "")
				{
					index = i;
				}
			}
		}

		if (index == 5)
		{
			cout << "The class roster is full. Please remove an entry." << endl;
			return;
		}

		student.SetStudentID(studentID);
		student.SetFirstName(firstName);
		student.SetLastName(lastName);
		student.SetEmailAddress(emailAddress);
		student.SetAge(age);
		student.SetDaysToCompleteCourse(daysInCourse1, daysInCourse2, daysInCourse3);
		student.SetDegreeProgram(initDegreeProgram);
		DegreeProgram program = DegreeProgram::NETWORK;

		if (initDegreeProgram == "SECURITY")
		{
			program = SECURITY;
		}
		else if (initDegreeProgram == "NETWORK")
		{
			program = NETWORK;
		}
		else if (initDegreeProgram == "SOFTWARE")
		{
			program = SOFTWARE;
		}

		classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, 
											  program);
	};

	void Roster::remove(string studentID)
	{
		cout << "Removing " << studentID << ":" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			string student = classRosterArray[i]->GetStudentID();

			if (student == studentID)
			{
				for (int j = i; j < 4; ++j)
				{
					classRosterArray[j] = classRosterArray[j + 1];
				}
				classRosterArray[4] = new Student();
				printAll();
				return;
			}

			if (i == 4 && student != studentID)
			{
				cout << "The student with the ID: " << studentID << " was not found." << endl;
			}
		};
	};

	void Roster::printAll()
	{
		cout << "Displaying all students:" << endl;

		string studentID;

		for (int i = 0; i < 5; i++)
		{
			studentID = classRosterArray[i]->GetStudentID();
			if (studentID != "")
			{
				classRosterArray[i]->Print();
			}
		};

		cout << endl;
	};

	void Roster::printAverageDaysInCourse(string studentID)
	{
		string student;
		int daysToCompleteCourse[3];
		int averageDaysToCompleteCourse;

		for (int i = 0; i < 5; i++)
		{
			student = classRosterArray[i]->GetStudentID();

			if (student == studentID)
			{
				classRosterArray[i]->GetDaysToCompleteCourse(daysToCompleteCourse);
				averageDaysToCompleteCourse = (daysToCompleteCourse[0] + daysToCompleteCourse[1] + daysToCompleteCourse[2]) / 3;
				cout << "Student ID: " << studentID << ", average days in course is: " << averageDaysToCompleteCourse << endl;
			}
		}
	};

	void Roster::printInvalidEmails()
	{
		cout << "Displaying invalid emails:" << endl << endl;
		string email;
		char period = '.';
		char symbol = '@';
		char space = ' ';

		for (int i = 0; i < 5; i++)
		{
			bool foundSymbol = false;
			bool foundPeriod = false;
			bool foundSpace = false;
			bool goodEmail = false;
			int j = 0;
			int k = 0;
			int l = 0;
			email = classRosterArray[i]->GetEmailAddress();

			while ((foundPeriod == false) && (j < email.length()))
			{
				if (email[j] == period)
				{
					foundPeriod = true;
				}
				j++;
			}

			while ((foundSymbol == false) && (k < email.length()))
			{
				if (email[k] == symbol)
				{
					foundSymbol = true;
				}
				k++;
			}

			while ((foundSpace == false) && (l < email.length()))
			{
				if (email[l] == space)
				{
					foundSpace = true;
				}
				l++;
			}

			if (foundSymbol == true && foundPeriod == true && foundSpace == false)
			{
				goodEmail = true;
			}
			else
			{
				goodEmail = false;
			}

			if (goodEmail == false)
			{
				cout << classRosterArray[i]->GetEmailAddress() << " - is invalid." << endl;
			}
		}

		cout << endl;
	};

	void Roster::printByDegreeProgram(string initProgram)
	{
		cout << "Showing students in degree program: " << initProgram << endl << endl;

		string program;

		for (int i = 0; i < 5; i++)
		{
			program = classRosterArray[i]->GetDegreeProgram();
			if (program == initProgram)
			{
				classRosterArray[i]->Print();
			}
		}

		cout << endl;
	};