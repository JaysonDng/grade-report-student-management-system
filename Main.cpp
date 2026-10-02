/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "StudentList.h"
#include "InputHandler.h"
#include "OutputHandler.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const string& FILE_NAME = "student_data.txt";

void processChoice(const StudentList list, double tuitionRate)
{
	bool exit = false;
	while (!exit)
	{
		int choice = 0;
		cout << "*** MAIN MENU ***\n\n"
			<< "Select one of the following:\n\n"
			<< "\t1: Print all students\n"
			<< "\t2: Print student information\n"
			<< "\t3: Search student by last name\n"
			<< "\t4: Print students by course\n"
			<< "\t5: Print sutdents on hold\n"
			<< "\t6: Print students to file\n"
			<< "\t7: To exit\n\n"
			<< "Enter your choice: ";
		cin >> choice;
		cout << endl;
		if (choice > 0 && choice <= 7)
		{
			switch (choice)
			{
			case 1:
			{
				list.printAllStudents(tuitionRate);

				break;
			}
			case 2:
			{
				int iD = 0;

				cout << "Please enter student's ID: ";
				cin >> iD;
				cout << endl;

				list.printStudentByID(iD, tuitionRate);

				break;
			}
			case 3:
			{
				string lastName = "";

				cout << "Please enter the student's last name: ";
				cin >> lastName;
				cout << endl;

				list.printStudentByName(lastName);

				break;
			}
			case 4:
			{
				std::string prefix = "";
				int courseNo = 0;

				cout << "Please enter the course prefix: ";
				cin >> prefix;
				cout << "Please enter the course number: ";
				cin >> courseNo;
				cout << endl;

				list.printStudentsByCourse(prefix, courseNo);

				break;
			}
			case 5:
			{
				list.printStudentsOnHold(tuitionRate);

				break;
			}
			case 6:
			{
				printAllStudentsToFile(list, tuitionRate);


				break;
			}
			case 7:
				exit = true;
				cout << "Thank you for using the OCC Gradebook. Good-bye!\n";
				break;
			}
			if (choice != 7)
			{
				system("Pause");
				cout << endl;
			}
		}
		else
		{
			cout << "Sorry. That is not a selection.\n\n";

			system("Pause");
			cout << endl;
		}
	}
}

int main()
{
	ifstream infile;
	StudentList list;
	double tuitionRate = 0.0;

	infile.open(FILE_NAME);
	createStudentList(infile, list, tuitionRate);
	processChoice(list, tuitionRate);

	cout << endl;
	system("Pause");
	return 0;
}