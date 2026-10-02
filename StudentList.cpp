/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "StudentList.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Node Class

Node* Node::getNext() const
{
    return next;
}
Student Node::getStudent() const
{
    return student;
}

void Node::setNext(Node* newNext)
{
    next = newNext;
}
void Node::setStudent(Student newStudent)
{
    student = newStudent;
}

// StudentList Class
void StudentList::addStudent(const Student& aStudent)
{
    Node* studentToAdd = new Node(aStudent, nullptr);

    if (first == nullptr)
    {
        first = studentToAdd;
        last = studentToAdd;
    }
    else
    {
        last->setNext(studentToAdd);
        last = last->getNext();
    }
	++count;
}

int StudentList::getNoOfStudents() const
{
	return count;
}

void StudentList::printStudentByID(int ID, double tuitionRate) const
{
    if (first == nullptr)
        cerr << "List is empty.";
    else
    {
        bool found = false;
        Node* current = first;

        while (current != nullptr && !found)
        {
            if (current->getStudent().getID() == ID)
            {
                current->getStudent().printStudentInfo(tuitionRate);
                found = true;
            }
            current = current->getNext();
        }

        if (!found)
            cerr << "No students with ID " << ID 
                << " found in the list.\n\n";
    }
}

void StudentList::printStudentByName(const string& lastName) const
{
    if (first == nullptr)
        cerr << "List is empty.";
    else
    {
        bool found = false;
        Node* current = first;

        while (current != nullptr)
        {
            if (current->getStudent().getLastName() == lastName)
            {
                current->getStudent().printStudent();
                found = true;
            }
            current = current->getNext();
        }

        if (!found)
            cerr << "No student with last name " << lastName 
                << " is on the list.";
        cout << endl;
    }
}

void StudentList::printStudentsByCourse(const string& prefix, int courseNumber) const
{
    if (first == nullptr)
        cerr << "List is empty.";
    else
    {
        bool found = false;
        Node* current = first;
        while (current != nullptr)
        {
            bool foundCourse = false;

            for (const auto& i : current->getStudent().getCoursesCompleted())
            {
                if (i.first.getCoursePrefix() == prefix &&
                    i.first.getCourseNumber() == courseNumber)
                {
                    current->getStudent().printStudent();
                    foundCourse = true;
                    found = true;
                    break;
                }
            }
            current = current->getNext();
        }
        if (!found)
            cerr << "No students enrolled in " << prefix << " " << courseNumber << endl;
        cout << endl;
    }
}

void StudentList::printAllStudents(double tuitionRate) const
{
    if (first != nullptr)
    {
        Node* current = first;

        while (current != nullptr)
        {
            current->getStudent().printStudentInfo(tuitionRate);
            current = current->getNext();
        }
    }
}

void StudentList::printStudentsOnHold(double tuitionRate) const
{
    bool studentsOnHold = false;
    if (first != nullptr)
    {
        Node* current = first;
        while (current != nullptr)
        {
            if (!current->getStudent().isTuitionPaid())
            {
                studentsOnHold = true;
                double amountDue = current->getStudent().getNumberOfCourses() * tuitionRate;
                current->getStudent().printStudent();
                cout << "Amount Due: $" << fixed << setprecision(2) << amountDue << endl;
            }
            current = current->getNext();
        }
    }

    if (!studentsOnHold)
        cout << "There are no students on hold.\n";
    cout << endl;
}

void StudentList::printStudentsToFile(std::ofstream& out, double tuitionRate) const
{
    Node* current = first;
    while (current != nullptr)
    {
        out << "Student Name: " << current->getStudent().getLastName() << ", " 
            << current->getStudent().getFirstName() << "\n"
            << "Student ID: " << current->getStudent().getID() << "\n"
            << "Number of courses completed: " 
            << current->getStudent().getNumberOfCourses()
            << "\n\n" << "CourseNo  Units  Grade\n";

        for (const auto& i : current->getStudent().getCoursesCompleted())
        {
            out << left << setw(5) << i.first.getCoursePrefix()
                << i.first.getCourseNumber() << right << setw(5)
                << i.first.getCourseUnits() << setw(7) << i.second << "\n";
        }

        out << "Total number of credit hours: " 
            << current->getStudent().getUnitsCompleted() << endl;

        if (current->getStudent().isTuitionPaid())
            out << "Current Term GPA: " << fixed << setprecision(2) 
            << current->getStudent().calculateGPA();
        else
            out << "Tuition not paid. GPA not available.";
        out << "\n\n" << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";

        current = current->getNext();
    }
    cout << endl;
}

void StudentList::clearStudentList()
{
    if (first != nullptr)
    {
        Node* current = first;

        while (current != nullptr)
        {
            Node* temp = current->getNext();
            delete current;
            current = temp;
        }

        first = nullptr;
        last = nullptr;
    }
    count = 0;
}

StudentList::~StudentList()
{
    if (count > 0)
        clearStudentList();
}