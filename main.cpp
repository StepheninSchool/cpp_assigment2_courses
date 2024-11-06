// main.cpp
#include <iostream>
#include "Student.h"
#include <limits>

int main() {
    char choice;

    do {
        std::string studentName1;
        do {
            std::cout << "Enter the name of the first student: ";
            std::getline(std::cin, studentName1);
            if (studentName1.empty()) {
                std::cout << "(Error: Student name cannot be empty.)\n";
            }
        } while (studentName1.empty());

        Student student1(studentName1);

        std::string courseName;
        while (true) {
            std::cout << "Enter a course (or 'done' to finish): ";
            std::getline(std::cin, courseName);
            if (courseName == "done") break;
            if (courseName.empty()) {
                std::cout << "(Error: Course name cannot be empty.)\n";
                continue;
            }
            student1.addCourse(courseName);
        }

        std::cout << "\nFirst Student Information:\n";
        student1.print();

        std::string studentName2;
        do {
            std::cout << "\nEnter the name of the second student: ";
            std::getline(std::cin, studentName2);
            if (studentName2.empty()) {
                std::cout << "(Error: Student name cannot be empty.)\n";
            }
        } while (studentName2.empty());

        Student student2 = student1;
        student2.setName(studentName2);

        std::cout << "\nSecond Student Information (after copying and renaming):\n";
        std::cout << student2;

        student1.resetCourses();
        std::cout << "\nFirst Student Information (after reset):\n";
        std::cout << student1;

        std::cout << "\nSecond Student Information (after first student reset):\n";
        std::cout << student2;

        Student student3;
        student3 = student2;
        std::cout << "\nThird Student Information (after assignment from second student):\n";
        std::cout << student3;


        std::cout << "\n1st student is " << student1.getName() << " and has "
        << student1.getNumCourses() << " course(s).";
        std::cout << "\n2nd student is " << student2.getName() << " and has "
        << student2.getNumCourses() << " course(s).";
        std::cout << "\n3rd student is a copy of " << student3.getName() << " and has "
        << student3.getNumCourses() << " course(s).\n";

        std::cout << "\nDo you want to start again? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
