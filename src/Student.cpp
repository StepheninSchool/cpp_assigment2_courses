// Student.cpp
#include "Student.h"
#include <utility>  // For std::move


Student::Student() : numCourses(0), courseList(nullptr) {
    std::cout << "Default constructor called." << std::endl;
}

//SOURCE: https://en.cppreference.com/w/cpp/utility/move
Student::Student(std::string studentName) : name(std::move(studentName)), numCourses(0), courseList(nullptr) {
    std::cout << "String constructor called." << std::endl;
}

// SOURCE: https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/
Student::~Student() {
    if (courseList != nullptr) {
        delete[] courseList;
        courseList = nullptr;
    }
    std::cout << "Destructor called." << std::endl;
}


std::string Student::getName() const {
    return name;
}


void Student::setName(const std::string &studentName) {
    name = studentName;
}


void Student::print() const {
    std::cout << "Student Name: " << getName() << std::endl;
    std::cout << "Number of Courses: " << getNumCourses() << std::endl;
    for (int i = 0; i < getNumCourses(); ++i) {
        std::cout << "Course " << (i + 1) << ": " << courseList[i] << std::endl;
    }
}

//SOURCE: https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
//
std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << "Student Name: " << student.getName() << "\n";
    os << "Number of Courses: " << student.getNumCourses() << "\n";
    for (int i = 0; i < student.getNumCourses(); ++i) {
        os << "Course " << (i + 1) << ": " << student.courseList[i] << "\n";
    }
    return os;
}


void Student::resetCourses() {
    if (courseList != nullptr) {
        delete[] courseList;
        courseList = nullptr;
    }
    numCourses = 0;
    std::cout << "Courses have been reset for " << getName() << std::endl;
}


Student::Student(const Student &other) : name(other.getName()), numCourses(other.getNumCourses()) {
    std::cout << "Copy constructor called." << std::endl;
    if (other.courseList) {
        courseList = new std::string[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            courseList[i] = other.courseList[i];
        }
    } else {
        courseList = nullptr;
    }
}


Student &Student::operator=(const Student &other) {
    if (this == &other) return *this;

    std::cout << "Assignment operator called." << std::endl;

    if (courseList) {
        delete[] courseList;
    }

    name = other.getName();
    numCourses = other.getNumCourses();

    if (other.courseList) {
        courseList = new std::string[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            courseList[i] = other.courseList[i];
        }
    } else {
        courseList = nullptr;
    }

    return *this;
}

//SOURCE: https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/

void Student::addCourse(const std::string &courseName) {
    std::cout << "Add course function called for " << getName() << std::endl;

    auto *newCourseList = new std::string[getNumCourses() + 1];

    for (int i = 0; i < getNumCourses(); ++i) {
        newCourseList[i] = courseList[i];
    }

    newCourseList[getNumCourses()] = courseName;

    delete[] courseList;
    courseList = newCourseList;
    numCourses++;
}

int Student::getNumCourses() const {
    return numCourses;
}
