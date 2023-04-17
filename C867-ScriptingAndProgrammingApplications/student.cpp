#include <iostream>
#include "student.h"
using namespace std;

	std::string Student::GetStudentID() const
	{
		return studentID;
	};

	std::string Student::GetFirstName() const
	{
		return firstName;
	};

	std::string Student::GetLastName() const
	{
		return lastName;
	};

	std::string Student::GetEmailAddress() const
	{
		return emailAddress;
	};

	int Student::GetAge() const
	{
		return age;
	};

	void Student::GetDaysToCompleteCourse(int array[]) const
	{
		for (int i = 0; i < 3; ++i)
		{
			array[i] = daysToCompleteCourse[i];
		}
	};

	std::string Student::GetDegreeProgram() const
	{
		std::string initDegreeProgram;

		if (degreeProgram == SECURITY)
		{
			initDegreeProgram = "SECURITY";
		}
		else if (degreeProgram == NETWORK)
		{
			initDegreeProgram = "NETWORK";
		}
		else if (degreeProgram == SOFTWARE)
		{
			initDegreeProgram = "SOFTWARE";
		}

		return initDegreeProgram;
	};

	void Student::SetStudentID(std::string initStudentID)
	{
		studentID = initStudentID;
	};

	void Student::SetFirstName(std::string initFirstName)
	{
		firstName = initFirstName;
	};

	void Student::SetLastName(std::string initLastName)
	{
		lastName = initLastName;
	};

	void Student::SetEmailAddress(std::string initEmailAddress)
	{
		emailAddress = initEmailAddress;
	};

	void Student::SetAge(int initAge)
	{
		age = initAge;
	};

	void Student::SetDaysToCompleteCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
	{
		daysToCompleteCourse[0] = daysInCourse1;
		daysToCompleteCourse[1] = daysInCourse2;
		daysToCompleteCourse[2] = daysInCourse3;
	};

	void Student::SetDegreeProgram(std::string initDegreeProgram)
	{
		if (initDegreeProgram == "SECURITY")
		{
			degreeProgram = SECURITY;
		}
		else if (initDegreeProgram == "NETWORK")
		{
			degreeProgram = NETWORK;
		}
		else if (initDegreeProgram == "SOFTWARE")
		{
			degreeProgram = SOFTWARE;
		}
	};

	Student::Student(std::string InitStudentID, std::string InitFirstName, std::string InitLastName, std::string InitEmailAddress, int InitAge, 
					 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram InitDegreeProgram)
	{
		studentID = InitStudentID;
		firstName = InitFirstName;
		lastName = InitLastName;
		emailAddress = InitEmailAddress;
		age = InitAge;
		daysToCompleteCourse[0] = daysInCourse1;
		daysToCompleteCourse[1] = daysInCourse2;
		daysToCompleteCourse[2] = daysInCourse3;
		degreeProgram = InitDegreeProgram;
	};

	Student::Student()
	{
		int i;
		studentID = "";
		firstName = "";
		lastName = "";
		emailAddress = "";
		age = 0;

		for (i = 0; i < 3; ++i)
		{
			daysToCompleteCourse[i] = daysToCompleteCourse[0];
		};
		degreeProgram = SOFTWARE;
	};

	void Student::Print()
	{
		std::string initDegreeProgram;

		if (degreeProgram == SECURITY)
		{
			initDegreeProgram = "SECURITY";
		}
		else if (degreeProgram == NETWORK)
		{
			initDegreeProgram = "NETWORK";
		}
		else if (degreeProgram == SOFTWARE)
		{
			initDegreeProgram = "SOFTWARE";
		}
		cout << studentID << "\t" << firstName << "\t" << lastName << "\t" << age << "\t" << "{" << daysToCompleteCourse[0] << ","
			 << daysToCompleteCourse[1] << "," << daysToCompleteCourse[2] << "}" << "\t" << initDegreeProgram << endl;
	};