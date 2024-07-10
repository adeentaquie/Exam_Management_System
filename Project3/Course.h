#pragma once
#include <list>
#include <string>
#include<sstream>
#include"Printt.h"
using namespace std;

class Instructor;
class Student;
class Course : public Printable {
    int course_id;
    string course_name;
    list <Instructor> i;
    list <Student> s;
public:
    Course();
    Course(int ci, string cn, list<Instructor> ilist, list<Student> std);
    void ViewInstructorlist();
    void SetInstructor(Instructor it);
    void SetStudent(Student std);
    void ViewStudentlist();
    void print_std();
    int GetCourseId();
    string GetCourseName();
    void SetCourseId(int courseid);
    void SetCourseName(string coursename);

    string Print() override {
        ostringstream oss;
        oss << "Course_id: " << GetCourseId() << endl;
        oss << "Course_name: " << GetCourseName() << endl;
        oss << "Instructors teaching this course: " << endl;
        return oss.str();
    }
    friend void operator <<(ostream& out, const Course& c);
    friend void operator >>(istream&, Course&);
    void addCourse();
};

