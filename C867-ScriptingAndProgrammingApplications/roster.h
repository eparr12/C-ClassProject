#ifndef roster_h
#define roster_h
#include "student.h"
#include <string>

class Roster
{
	public:
		Student* classRosterArray[5];

		void parse(std::string studentList, int index);

		void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,int age, int daysInCourse1, 
			     int daysInCourse2, int daysInCourse3, std::string initDegreeProgram, int index = 5);

		void remove(std::string studentID);

		void printAll();

		void printAverageDaysInCourse(std::string studentID);

		void printInvalidEmails();

		void printByDegreeProgram(std::string initProgram);

		~Roster()
		{

		}

	private:
		Student student;
};
#endif