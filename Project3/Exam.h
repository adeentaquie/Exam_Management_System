#pragma once
#include<iostream>
#include <list>
#include <string>
#include<sstream>
#include "Course.h" // Include course.h here
#include "Invigilator.h"
#include"Printt.h"
#include"AddExam.h"
using namespace std;

class Invigilator; // Forward declaration


class Exam : public Printable, public AddExam
{
    int Exam_id;
    string Date;
    string time;
    int room_no;
    Course* cr;
    Invigilator* inv;
public:
    Exam();
    Exam(int exi, string dt, string t, Course* c, Invigilator* i);
    void SetExamid(int exi);
    void SetExamDate(string dt);
    void SetExamTime(string t);
    void SetRoomNo(int rno);
    void viewExamOnDate();
    void addExam();
    int GetExamId();
    string GetExamTime();
    void SetExam(Course c);
    void SetInvigilator(Invigilator i);
    string GetExamDate() override;
    //void Print();
    //void Print();
    friend void operator <<(ostream& out, const Exam& e);
    friend void operator >>(istream& in, AddExam* e);
    string Print()  override {
        ostringstream oss;
        oss << "\nExam ID: " << GetExamId();
        oss << "\nExam Date: " << GetExamDate();
        oss << "\nExam Time: " << GetExamTime() << endl;
        oss <<  "Course_id: " <<  cr->GetCourseId() << endl;
        oss <<  "Course_name: "<< cr->GetCourseName();

        oss << "\nRoom NO: " << room_no;

        return oss.str();
    }
};