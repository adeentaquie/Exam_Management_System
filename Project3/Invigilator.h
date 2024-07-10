#pragma once
#include <list>
#include <string>
#include "Exam.h" 
#include"Printt.h"
using namespace std;

class Invigilator: public Printable
{
    int invigilator_id;
    string invigilator_name;
    list<Exam> exam;
public:
    Invigilator();
    Invigilator(int id, string name, list<Exam>ex);
    void add_exam(Exam ex);
    // void remove_exam(Exam ex);
    void print();
    void getexams();
    void setid(int id);
    void setname(string name);
    int getid();
    string getname();
    friend void operator <<(ostream& out, const Invigilator& i);
    friend void operator >>(istream& in, Invigilator& i);
    void addInvigilator();
    void markAttendance();
    string Print() override
    {
        ostringstream oss;
            oss << "\nInvigilator ID: " << invigilator_id;
            oss << "\nInvigilator Name: " << invigilator_name;
            oss << "\nExams: ";
            getexams();
            return oss.str();
    }
};