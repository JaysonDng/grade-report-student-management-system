# Grade Report Student Management System

A console-based student record management system developed in C++.

## Overview

This program loads student and course information from a text file and allows users to view, search, and generate reports for student records.

## Features

- Display all student records
- Search for students by ID
- Search for students by last name
- Search for students enrolled in a specific course
- Calculate GPA and completed credit hours
- Track tuition payment status
- Display students with unpaid tuition
- Generate unofficial transcript reports
- Export student reports to a text file

## Technologies and Concepts

- C++
- Object-oriented programming
- Classes and encapsulation
- Linked lists
- Multimaps
- File input and output
- Dynamic memory management
- Copy constructors
- Overloaded assignment operators
- Modular program design

## Project Structure

- `Main.cpp` - Contains the main menu and program execution
- `Course.cpp / Course.h` - Defines course information and course comparison
- `Student.cpp / Student.h` - Manages student data, GPA, tuition, and course records
- `StudentList.cpp / StudentList.h` - Stores and searches student records using a linked list
- `StudentListCopyFunctions.cpp` - Implements copying and assignment operations for `StudentList`
- `InputHandler.cpp / InputHandler.h` - Reads student data from an input file
- `OutputHandler.cpp / OutputHandler.h` - Exports student reports to a text file
- `student_data.txt` - Stores sample student and course information

## How to Run

### Visual Studio

1. Open the Visual Studio solution file.
2. Build the project.
3. Make sure `student_data.txt` is located in the program's working directory.
4. Run the program.
5. Select an option from the menu.

### Program Input

The program reads student information from `student_data.txt`. Each record includes the student's ID, name, tuition status, courses, units, and grades.

## My Contributions

This was a team project. My contributions included:

- [Describe the components or features you personally implemented.]
- [Describe any debugging, testing, or documentation work you completed.]
- [Describe how you collaborated with the team.]

## Team Project

This project was completed collaboratively as part of a C++ programming course.
