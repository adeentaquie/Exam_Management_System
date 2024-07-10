#pragma once
#include <list>
#include <string>
#include<sstream>
#include"Printt.h"
using namespace std;

class Course;

class Student: public Printable
{
    int student_id;
    string student_name;
    string student_address;
    int Age;
    string DOB;
    list <Course> i;
public:
    Student();
    Student(int id, string name, string add, int age, string db, list<Course> li);
    void add_course(Course li);
    void getcourse_list();
    int getstd_id();
    string getstd_name();
    string getstd_add();
    string getDOB();
    int getAge();
    void setage(int age);
    void setDOB(string db);
    void setstd_id(int id);
    void setstd_name(string name);
    void setstd_add(string add);
    void print2();
    friend void operator <<(ostream& out, const Student& s);
    friend void operator >>(istream& in, Student& s);
    void AddStudent();
    string Print() {
        ostringstream oss;
        oss << "\nStudent ID: " << getstd_id();
        oss << "\nStudent Name: " << getstd_name();
        oss << "\nStudent Address: " << getstd_add();
        oss << "\nStudent age: " << getAge();
        oss << "\nStudent  Date of Birth: " << getDOB() << endl;
  
        return oss.str();
    }
    void viewExamInfo();
    void viewStudentRecord();
};