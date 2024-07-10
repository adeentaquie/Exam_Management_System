#pragma once
#include <list>
#include <string>
#include"Printt.h"
using namespace std;

class Course;

class Instructor: public Printable
{
    int instructor_id;
    string instructor_name;
    list<Course> Courselist;
public:
    Instructor();
    Instructor(int itid, string itn, list<Course> cl);
    int getcourse_list();
    void AddCourseList(Course clist);
    void ViewCourse();
    void Print2();
    int GetInstructorId();
    string GetInstructorName();
    void SetInstructorId(int itid);
    void SetInstructorName(string itn);
    friend void operator <<(ostream& out, const Instructor& it);
    friend void operator >>(istream& in, Instructor& it);
    string Print() override
    {
        ostringstream oss;

           oss << "Intructor Id: " << GetInstructorId() << endl;
           oss << "Intructor Name: " << GetInstructorName() << endl;
        return oss.str();
    }
};