#ifndef student_h
#define student_h
#include "degree.h"
#include <string>

class Student
{
	public:
		std::string GetStudentID() const;

		std::string GetFirstName() const;

		std::string GetLastName() const;

		std::string GetEmailAddress() const;

		int GetAge() const; 

		void GetDaysToCompleteCourse(int array[]) const;

		std::string GetDegreeProgram() const;

		void SetStudentID(std::string initStudentID);

		void SetFirstName(std::string initFirstName);

		void SetLastName(std::string initLastName);

		void SetEmailAddress(std::string initEmailAddress);

		void SetAge(int initAge);

		void SetDaysToCompleteCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);

		void SetDegreeProgram(std::string degreeProgram);

		Student(std::string InitStudentID, std::string InitFirstName, std::string InitLastName, std::string InitEmailAddress, int InitAge, 
				int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram InitDegreeProgram);

		Student();

		void Print();

	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		int age;
		int daysToCompleteCourse[3];
		DegreeProgram degreeProgram;
};
#endif