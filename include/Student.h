#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    std::string name;           // Name of the student
    int numCourses;             // Number of courses the student is currently enrolled in
    std::string *courseList;    // Dynamically allocated array of course names

public:

    Student();


    explicit Student(std::string studentName);


    Student(const Student &other);


    Student &operator=(const Student &other);


    ~Student();


    std::string getName() const;


    void setName(const std::string &studentName);


    void addCourse(const std::string &courseName);


    void print() const;


    friend std::ostream &operator<<(std::ostream &os, const Student &student);


    void resetCourses();


    int getNumCourses() const;
};

#endif  // STUDENT_H
