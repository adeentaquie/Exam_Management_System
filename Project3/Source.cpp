#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <list>
#include <string>
#include<cstring>
#include<sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Course.h"
#include "instructor.h"
#include "Student.h"
#include "Invigilator.h"
#include "Exam.h"
#include "Room.h"
#include "AddExam.h"
#include"System.h"
#include"AcademicOfficer.h"
using namespace std;

sf::Color yaleBlue(13, 77, 146);
sf::Color offWhiteColor(240, 240, 240);  
sf::Color lightGray(211, 211, 211);

sf::Color darkerYaleBlue(8, 40, 79);
void handleAcademicOfficerAction(sf::RenderWindow& window, int& input);
void handleStudentAction(sf::RenderWindow& window, int& input);
Course::Course()
{
    course_id = 0;
    course_name = "/0";
}
Course::Course(int ci, string cn, list<Instructor> ilist, list<Student> std)
{
    course_id = ci;
    course_name = cn;
    i.assign(ilist.begin(), ilist.end());
    s.assign(std.begin(), std.end());
}
void Course::ViewInstructorlist()
{
    for (list<Instructor>::iterator j = i.begin(); j != i.end(); ++j)
    {
        j->Print();
    }
    cout << endl;
}
void Course::ViewStudentlist() {
    for (list<Student>::iterator j = s.begin(); j != s.end(); ++j)
    {
        j->print2();
    }
    cout << endl;
};
void Course::SetStudent(Student std) {
    s.push_back(std);
}
void Course::SetInstructor(Instructor it)
{
    i.push_back(it);
}
void Course::print_std()
{
    cout << "\nCourse_id: " << GetCourseId() << endl;
    cout << "\nCourse_name: " << GetCourseName() << endl;
}
int Course::GetCourseId() { return course_id; }
string Course::GetCourseName() { return course_name; }
void Course::SetCourseId(int courseid) { course_id = courseid; }
void Course::SetCourseName(string coursename) { course_name = coursename; }

void  operator <<(ostream& out, const Course& c) {
    out << c.course_id << endl;
    out << c.course_name << endl;
};
void operator >>(istream& in, Course& c) {
    in >> c.course_id;
    in >> c.course_name;
}
void Course::addCourse()
{

    std::cout << "Adding Course by Academic Officer" << std::endl;
    sf::RenderWindow addCourseWindow(sf::VideoMode(700, 800), "ADD Invigilator:");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");
    sf::Text inputPrompt("Enter Course Information", font, 45);
    inputPrompt.setPosition(40.0f, 40.0f);
    inputPrompt.setOutlineColor(sf::Color::Black);
    inputPrompt.setOutlineThickness(3);
    sf::Text resultText("", font, 20);
    resultText.setPosition(340.f, 160.f);
    resultText.setFillColor(sf::Color::Black);
    sf::String userInput;

    int studentID = 0;
    string InstructorName;
    int noOfInstructors = 0;
    int InstructorID = 0;
    string  StudentName;
    int noOfStudents = 0;

    int  courseID = 0;
    string courseName;
    enum class InputState { COURSE_ID, COURSE_NAME, NO_OFINSTRUCTORS, INSTRUCTOR_ID, INSTRUCTOR_NAME, NO_OFSTUDENTS, STUDENT_ID, STUDENT_NAME, END };
    InputState currentState = InputState::COURSE_ID;

    Exam e;
    bool inputCompleted = false;
    sf::RectangleShape idInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape nameInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape noOfInstructorsInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape instructorIDInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape instructorNameInputBox(sf::Vector2f(250, 30));

    sf::RectangleShape noOfStudentsInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape StudentIdInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape StudentNameInputBox(sf::Vector2f(250, 30));

    idInputBox.setOutlineColor(sf::Color::Black);
    nameInputBox.setOutlineColor(sf::Color::Black);
    noOfInstructorsInputBox.setOutlineColor(sf::Color::Black);
    instructorIDInputBox.setOutlineColor(sf::Color::Black);
    instructorNameInputBox.setOutlineColor(sf::Color::Black);
    noOfStudentsInputBox.setOutlineColor(sf::Color::Black);
    StudentIdInputBox.setOutlineColor(sf::Color::Black);
    StudentNameInputBox.setOutlineColor(sf::Color::Black);
    idInputBox.setOutlineThickness(3);
    nameInputBox.setOutlineThickness(3);
    noOfInstructorsInputBox.setOutlineThickness(3);
    instructorIDInputBox.setOutlineThickness(3);
    instructorNameInputBox.setOutlineThickness(3);
    noOfStudentsInputBox.setOutlineThickness(3);
    StudentIdInputBox.setOutlineThickness(3);
    StudentNameInputBox.setOutlineThickness(3);

    sf::Text idLabel("Enter Course ID: ", font, 20);
    sf::Text nameLabel("Enter Course Name: ", font, 20);
    sf::Text noOfInstructorsLabel("Enter No Of Instructors: ", font, 20);
    sf::Text instructorIdLabel("Enter Instructor ID: ", font, 20);
    sf::Text InstructorNameLabel("Enter Instructor Name: ", font, 20);

    sf::Text noOfStudentsLabel("Enter No Of Students: ", font, 20);
    sf::Text StudentIdLabel("Enter Student ID: ", font, 20);
    sf::Text courseIDLabel("Enter Student Name: ", font, 20);

    sf::RectangleShape viewAddedCourse(sf::Vector2f(350.0f, 590.0f));
    viewAddedCourse.setPosition(330, 130);
    viewAddedCourse.setFillColor(sf::Color::White);
    viewAddedCourse.setOutlineColor(sf::Color::Black);
    viewAddedCourse.setOutlineThickness(3);

    idLabel.setOutlineColor(sf::Color::Black);
    nameLabel.setOutlineColor(sf::Color::Black);
    noOfInstructorsLabel.setOutlineColor(sf::Color::Black);
    instructorIdLabel.setOutlineColor(sf::Color::Black);
    InstructorNameLabel.setOutlineColor(sf::Color::Black);

    noOfStudentsLabel.setOutlineColor(sf::Color::Black);
    StudentIdLabel.setOutlineColor(sf::Color::Black);
    courseIDLabel.setOutlineColor(sf::Color::Black);
    idLabel.setOutlineThickness(3);
    nameLabel.setOutlineThickness(3);
    noOfInstructorsLabel.setOutlineThickness(3);
    instructorIdLabel.setOutlineThickness(3);
    InstructorNameLabel.setOutlineThickness(3);
    noOfStudentsLabel.setOutlineThickness(3);
    StudentIdLabel.setOutlineThickness(3);
    courseIDLabel.setOutlineThickness(3);


    idInputBox.setPosition(50, 170);
    nameInputBox.setPosition(50, 240);
    noOfInstructorsInputBox.setPosition(50, 310);
    instructorIDInputBox.setPosition(50, 380);
    instructorNameInputBox.setPosition(50, 450);

    noOfStudentsInputBox.setPosition(50, 520);
    StudentIdInputBox.setPosition(50, 590);
    StudentNameInputBox.setPosition(50, 660);

    idLabel.setPosition(50, 138);
    nameLabel.setPosition(50, 208);
    noOfInstructorsLabel.setPosition(50, 278);
    instructorIdLabel.setPosition(50, 348);
    InstructorNameLabel.setPosition(50, 418);

    noOfStudentsLabel.setPosition(50, 480);
    StudentIdLabel.setPosition(50, 558);
    courseIDLabel.setPosition(50, 628);

    sf::Text inputText("", font, 22);
    inputText.setPosition(380, 250);
    inputText.setFillColor(sf::Color::Black);
    Course Course;
    Student s;

    int inst = 0;
    int std = 0;
    while (addCourseWindow.isOpen()) {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);

        sf::Text enteredIdText2("", font, 20);
        sf::Text enteredNameText2("", font, 20);
        sf::Text enterednoOfInstructorText2("", font, 20);
        sf::Text enteredInstructorIdText2("", font, 20);
        sf::Text enteredExamNameText2("", font, 20);

        sf::Text  enterednoOfStudentsText2("", font, 20);
        sf::Text  enteredStudentIdText2("", font, 20);
        sf::Text   enteredStudentNameText2("", font, 20);
        enteredIdText2.setFillColor(sf::Color::Black);
        enteredNameText2.setFillColor(sf::Color::Black);
        enterednoOfInstructorText2.setFillColor(sf::Color::Black);
        enteredInstructorIdText2.setFillColor(sf::Color::Black);
        enteredExamNameText2.setFillColor(sf::Color::Black);
        enterednoOfStudentsText2.setFillColor(sf::Color::Black);
        enteredStudentIdText2.setFillColor(sf::Color::Black);
        enteredStudentNameText2.setFillColor(sf::Color::Black);

        sf::Text enteredIdText("", font, 20);
        sf::Text enteredNameText("", font, 20);
        sf::Text enterednoOfInstructorsText("", font, 20);
        sf::Text enteredInstructorIdText("", font, 20);
        sf::Text enteredInstructorNameText("", font, 20);

        sf::Text  enterednoOfStudentsText("", font, 20);
        sf::Text  enteredstudentIdText("", font, 20);
        sf::Text   enteredStudentNameText("", font, 20);


        enteredIdText.setFillColor(sf::Color::Black);
        enteredNameText.setFillColor(sf::Color::Black);
        enterednoOfInstructorsText.setFillColor(sf::Color::Black);
        enteredInstructorIdText.setFillColor(sf::Color::Black);
        enteredInstructorNameText.setFillColor(sf::Color::Black);
        enterednoOfStudentsText.setFillColor(sf::Color::Black);
        enteredstudentIdText.setFillColor(sf::Color::Black);
        enteredStudentNameText.setFillColor(sf::Color::Black);

        sf::Event event;
        while (addCourseWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                addCourseWindow.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode >= 32) {
                    userInput += static_cast<char>(event.text.unicode);
                }
                if (event.text.unicode == 8 && userInput.getSize() > 0) {
                    userInput.erase(userInput.getSize() - 1, 1);
                }

                if (event.text.unicode == 13) {
                    std::istringstream iss(userInput.toAnsiString());

                    std::ofstream fout("c.txt", std::ios_base::app);
                    switch (currentState) {

                    case InputState::COURSE_ID:
                        iss >> courseID;
                        fout << "\nCourse ID: " << courseID << "\n";
                        currentState = InputState::COURSE_NAME;
                        userInput.clear();
                        break;
                    case InputState::COURSE_NAME:
                        iss >> courseName;
                        fout << "Course Name: " << courseName << "\n";
                        currentState = InputState::NO_OFINSTRUCTORS;
                        userInput.clear();
                        break;
                    case InputState::NO_OFINSTRUCTORS:
                        iss >> noOfInstructors;
                        inst = noOfInstructors;
                        fout << "No Of Instructors: " << inst << "\n";
                        currentState = InputState::INSTRUCTOR_ID;
                        userInput.clear();
                        break;
                    case InputState::INSTRUCTOR_NAME:
                        iss >> InstructorName;
                        fout << "Instructor Name: " << InstructorName << "\n";
                        if (noOfInstructors != 0)
                        currentState = InputState::INSTRUCTOR_ID;
                        else
                            currentState = InputState::NO_OFSTUDENTS;
                        userInput.clear();
                        break;

                    case InputState::INSTRUCTOR_ID:
                        iss >> InstructorID;
                        fout << "Instructor ID: " << InstructorID << "\n";
                        e.SetExamid(InstructorID);
                        currentState = InputState::INSTRUCTOR_NAME;
                        userInput.clear();
                        if (noOfInstructors >= 1) {
                            noOfInstructors--;
                        }
                        else {
                            currentState = InputState::NO_OFSTUDENTS;
                        }
                        break;
                    case InputState::NO_OFSTUDENTS:
                        iss >> noOfStudents;
                        std = noOfStudents;
                        fout << "No Of Students: " << std << "\n";
                        currentState = InputState::STUDENT_ID;
                        userInput.clear();
                        break;
                    case InputState::STUDENT_ID:
                        iss >> studentID;
                        fout << "Student ID: " << studentID << "\n";
                        currentState = InputState::STUDENT_NAME;
                        userInput.clear();
                        if (noOfStudents >= 1) {
                            noOfStudents--;
                        }
                        break;

                    case InputState::STUDENT_NAME:
                        iss >> StudentName;
                        fout << "Student Name: " << StudentName << "\n";
                        if (noOfStudents > 0)
                            currentState = InputState::STUDENT_ID;
                        else
                            currentState = InputState::END;
                        userInput.clear();
                        break;
                    case InputState::END:
                        fout.close();
                        cout << "Close" << endl;
                        resultText.setString("Course Information Entered!");

                        if (noOfInstructors == 0 && noOfStudents == 0) {
                            currentState = InputState::END;
                        }
                        else {
                            currentState = InputState::INSTRUCTOR_ID; 
                        }
                        break;
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                addCourseWindow.close();
            }
            enteredIdText.setPosition(60.0f, 170.f);
            enteredNameText.setPosition(60.0f, 240.f);
            enterednoOfInstructorsText.setPosition(60.0f, 310.f);
            enteredInstructorIdText.setPosition(60.0f, 380.f);
            enteredInstructorNameText.setPosition(60.0f, 450.f);

            enterednoOfStudentsText.setPosition(60.0f, 520.f);
            enteredstudentIdText.setPosition(60.0f, 590.f);
            enteredStudentNameText.setPosition(60.0f, 660.f);

            enteredIdText.setString(to_string(courseID));
            enteredNameText.setString(courseName);
            enterednoOfInstructorsText.setString(to_string(inst));
            enteredInstructorIdText.setString(to_string(InstructorID));
            enteredInstructorNameText.setString(InstructorName);
            enterednoOfStudentsText.setString(to_string(std));
            enteredstudentIdText.setString(to_string(studentID));
            enteredStudentNameText.setString(StudentName);

            enteredIdText2.setPosition(350.f, 220.f);
            enteredNameText2.setPosition(350.0f, 250.f);
            enterednoOfInstructorText2.setPosition(350.0f, 280.f);
            enteredInstructorIdText2.setPosition(350.0f, 310.f);
            enteredExamNameText2.setPosition(350.0f, 340.f);

            enterednoOfStudentsText2.setPosition(350.0f, 370.f);
            enteredStudentIdText2.setPosition(350.0f, 400.f);
            enteredStudentNameText2.setPosition(350.0f, 430.f);

            enteredIdText2.setString("Course ID: " + to_string(studentID));
            enteredNameText2.setString("Course Name: " + InstructorName);
            enterednoOfInstructorText2.setString("No Of Instructors: " + inst);
            enteredInstructorIdText2.setString("Instructor ID: " + to_string(InstructorID));
            enteredExamNameText2.setString("Instructor Name: " + StudentName);

            enterednoOfStudentsText2.setString("No Of Students: " + to_string(std));
            enteredStudentIdText2.setString("Student ID: " + to_string(noOfStudents));
            enteredStudentNameText2.setString("Student Name: " + to_string(courseID));

            addCourseWindow.clear();

            addCourseWindow.draw(sprite);
            addCourseWindow.draw(idInputBox);
            addCourseWindow.draw(nameInputBox);
            addCourseWindow.draw(noOfInstructorsInputBox);
            addCourseWindow.draw(instructorIDInputBox);
            addCourseWindow.draw(instructorNameInputBox);

            addCourseWindow.draw(noOfStudentsInputBox);
            addCourseWindow.draw(StudentIdInputBox);
            addCourseWindow.draw(StudentNameInputBox);

            addCourseWindow.draw(idLabel);
            addCourseWindow.draw(nameLabel);
            addCourseWindow.draw(noOfInstructorsLabel);
            addCourseWindow.draw(instructorIdLabel);
            addCourseWindow.draw(InstructorNameLabel);

            addCourseWindow.draw(noOfStudentsLabel);
            addCourseWindow.draw(StudentIdLabel);
            addCourseWindow.draw(courseIDLabel);


            addCourseWindow.draw(viewAddedCourse);
            addCourseWindow.draw(inputPrompt);
            addCourseWindow.draw(resultText);
            addCourseWindow.draw(enteredIdText);
            addCourseWindow.draw(enteredNameText);
            addCourseWindow.draw(enterednoOfInstructorsText);
            addCourseWindow.draw(enteredInstructorIdText);
            addCourseWindow.draw(enteredInstructorNameText);
            addCourseWindow.draw(enterednoOfStudentsText);
            addCourseWindow.draw(enteredstudentIdText);
            addCourseWindow.draw(enteredStudentNameText);

            addCourseWindow.draw(enteredIdText2);
            addCourseWindow.draw(enteredNameText2);
            addCourseWindow.draw(enterednoOfInstructorText2);
            addCourseWindow.draw(enteredInstructorIdText2);
            addCourseWindow.draw(enteredExamNameText2);
            addCourseWindow.draw(enterednoOfStudentsText2);
            addCourseWindow.draw(enteredStudentIdText2);
            addCourseWindow.draw(enteredStudentNameText2);
            addCourseWindow.display();
        }
    }
}

//Instructor Class
Instructor::Instructor()
{
    instructor_id = 0;
    instructor_name = "\0";
}
Instructor::Instructor(int itid, string itn, list<Course> cl)
{
    instructor_id = itid;
    instructor_name = itn;
    Courselist.assign(cl.begin(), cl.end());
}
int Instructor::getcourse_list()
{
    for (list<Course>::iterator j = Courselist.begin(); j != Courselist.end(); ++j)
    {
        j->print_std();
    }
    return 0;
}
void Instructor::AddCourseList(Course clist)
{
    Courselist.push_back(clist);
}
void Instructor::ViewCourse()
{
    for (list<Course>::iterator j = Courselist.begin(); j != Courselist.end(); ++j)
    {
        j->Print();
    }
}
void Instructor::Print2()
{
    cout << "Intructor Id: " << GetInstructorId() << endl;
    cout << "Intructor Name: " << GetInstructorName() << endl;
    cout << "List of courses Instructor teaching: " << endl;
    ViewCourse();
}
int Instructor::GetInstructorId()
{
    return instructor_id;
}
string Instructor::GetInstructorName()
{
    return instructor_name;
}
void Instructor::SetInstructorId(int itid)
{
    instructor_id = itid;
};
void Instructor::SetInstructorName(string itn)
{
    instructor_name = itn;
}
void  operator <<(ostream& out, const Instructor& it) {
    out << it.instructor_id << endl;
    out << it.instructor_name << endl;
};
void operator >>(istream& in, Instructor& it) {
    in >> it.instructor_id;
    in >> it.instructor_name;
}

//Student Class
Student::Student()
{
    student_id = 0;
    student_name = "\0";
    student_address = "\0";
    Age = 0;
    DOB = "\0";
}
Student::Student(int id, string name, string add, int age, string db, list<Course> li)
{
    student_id = id;
    student_name = name;
    student_address = add;
    i.assign(li.begin(), li.end());
    Age = age;
    DOB = db;
}
void Student::add_course(Course li)
{
    i.push_back(li);
}
void Student::getcourse_list()
{
    for (list<Course>::iterator j = i.begin(); j != i.end(); ++j)
    {
        j->print_std();
    }
    cout << endl;
}
void Student::print2() {
    cout << "\nStudent ID: " << student_id;
    cout << "\nStudent Name: " << student_name;
}
int Student::getstd_id() { return student_id; }
string Student::getstd_name() { return student_name; }
string Student::getstd_add() { return student_address; }
string Student::getDOB() { return DOB; }
int Student::getAge() { return Age; }
void Student::setDOB(string db) { DOB = db; }
void Student::setage(int age) { Age = age; }
void Student::setstd_id(int id) { student_id = id; }
void Student::setstd_name(string name) { student_name = name; }
void Student::setstd_add(string add) { student_address = add; }
void Student::AddStudent()
{
    sf::RenderWindow addStudentWindow(sf::VideoMode(700, 800), "ADD Student:");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

    std::cout << "Adding Student by Academic Officer" << std::endl;
    sf::Text inputPrompt("Enter Student Information", font, 50);
    inputPrompt.setPosition(65.0f, 60.0f);
    inputPrompt.setOutlineColor(sf::Color::Black);
    inputPrompt.setOutlineThickness(3);
    sf::Text resultText("", font, 20);
    resultText.setPosition(80.f, 450.f);
    resultText.setFillColor(sf::Color::Black);
    sf::String userInput;

    int id = 0;
    string name;
    string address;
    int age = 0;
    string dob;
    enum class InputState { ID, NAME, ADDRESS, AGE, DOB };
    InputState currentState = InputState::ID;

    bool inputCompleted = false;
    sf::RectangleShape idInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape nameInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape addressInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape ageInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape dobInputBox(sf::Vector2f(250, 30));

    idInputBox.setOutlineColor(sf::Color::Black);
    nameInputBox.setOutlineColor(sf::Color::Black);
    addressInputBox.setOutlineColor(sf::Color::Black);
    ageInputBox.setOutlineColor(sf::Color::Black);
    dobInputBox.setOutlineColor(sf::Color::Black);
    idInputBox.setOutlineThickness(3);
    nameInputBox.setOutlineThickness(3);
    addressInputBox.setOutlineThickness(3);
    ageInputBox.setOutlineThickness(3);
    dobInputBox.setOutlineThickness(3);

    sf::Text idLabel("Student ID: ", font, 20);
    sf::Text nameLabel("Student Name: ", font, 20);
    sf::Text addressLabel("Student Address: ", font, 20);
    sf::Text ageLabel("Student Age: ", font, 20);
    sf::Text dobLabel("Student DOB: ", font, 20);

    sf::RectangleShape viewAddedStudent(sf::Vector2f(600.0f, 330.0f));
    viewAddedStudent.setPosition(50, 420);
    viewAddedStudent.setFillColor(sf::Color::White);
    viewAddedStudent.setOutlineColor(sf::Color::Black);
    viewAddedStudent.setOutlineThickness(3);

    idLabel.setOutlineColor(sf::Color::Black);
    nameLabel.setOutlineColor(sf::Color::Black);
    addressLabel.setOutlineColor(sf::Color::Black);
    ageLabel.setOutlineColor(sf::Color::Black);
    dobLabel.setOutlineColor(sf::Color::Black);
    idLabel.setOutlineThickness(3);
    nameLabel.setOutlineThickness(3);
    addressLabel.setOutlineThickness(3);
    ageLabel.setOutlineThickness(3);
    dobLabel.setOutlineThickness(3);

    idInputBox.setPosition(250, 150);
    nameInputBox.setPosition(250, 200);
    addressInputBox.setPosition(250, 250);
    ageInputBox.setPosition(250, 300);
    dobInputBox.setPosition(250, 350);

    idLabel.setPosition(50, 150);
    nameLabel.setPosition(50, 200);
    addressLabel.setPosition(50, 250);
    ageLabel.setPosition(50, 300);
    dobLabel.setPosition(50, 350);

    sf::Text inputText("", font, 22);
    inputText.setPosition(380, 250);
    inputText.setFillColor(sf::Color::Black);
    Student s;
    while (addStudentWindow.isOpen()) {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);

        sf::Text enteredIdText2("", font, 20);

        sf::Text enteredNameText2("", font, 20);

        sf::Text enteredAddressText2("", font, 20);

        sf::Text enteredAgeText2("", font, 20);

        sf::Text enteredDobText2("", font, 20);

        enteredIdText2.setFillColor(sf::Color::Black);
        enteredNameText2.setFillColor(sf::Color::Black);
        enteredAddressText2.setFillColor(sf::Color::Black);
        enteredAgeText2.setFillColor(sf::Color::Black);
        enteredDobText2.setFillColor(sf::Color::Black);

        sf::Text enteredIdText("", font, 20);

        sf::Text enteredNameText("", font, 20);

        sf::Text enteredAddressText("", font, 20);

        sf::Text enteredAgeText("", font, 20);

        sf::Text enteredDobText("", font, 20);

        enteredIdText.setFillColor(sf::Color::Black);
        enteredNameText.setFillColor(sf::Color::Black);
        enteredAddressText.setFillColor(sf::Color::Black);
        enteredAgeText.setFillColor(sf::Color::Black);
        enteredDobText.setFillColor(sf::Color::Black);



        sf::Event event;
        while (addStudentWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                addStudentWindow.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode >= 32) {
                    userInput += static_cast<char>(event.text.unicode);

                }
                if (event.text.unicode == 8 && userInput.getSize() > 0) {
                    userInput.erase(userInput.getSize() - 1, 1);
                }
                if (event.text.unicode == 13) {
                    std::istringstream iss(userInput.toAnsiString());

                    switch (currentState) {
                    case InputState::ID:
                        iss >> id;
                        s.setstd_id(id);
                        currentState = InputState::NAME;
                        userInput.clear();
                        break;
                    case InputState::NAME:
                        iss >> name;
                        s.setstd_name(name);


                        currentState = InputState::ADDRESS;
                        userInput.clear();
                        break;
                    case InputState::ADDRESS:
                        iss >> address;
                        s.setstd_add(address);
                        currentState = InputState::AGE;
                        userInput.clear();
                        break;
                    case InputState::AGE:
                        iss >> age;
                        s.setage(age);
                        currentState = InputState::DOB;
                        userInput.clear();
                        break;
                    case InputState::DOB:
                        iss >> dob;
                        userInput.clear(); // Clear userInput here

                        cout << "Student ID: " << s.getstd_id() << "\n";
                        cout << "Name: " << name << "\n";
                        cout << "Address: " << address << "\n";
                        cout << "Age: " << s.getAge() << "\n";
                        cout << "DOB: " << dob;

                        std::ofstream fout("Student.txt", std::ios_base::app);
                        if (fout.is_open()) {
                            fout << "\n";
                            fout  << id << "\n"
                                  <<  name << "\n"
                                  <<  address << "\n"
                                  << age << "\n"
                                  << dob << "\n";
                            fout.close();
                            resultText.setString("Student Information Stored in student.txt!");
                        }
                        else {
                            resultText.setString("Error: Unable to open student.txt for writing.");
                        }

                        currentState = InputState::ID;

                        resultText.setString("Student Information Entered!");
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                addStudentWindow.close();
            }
            enteredIdText.setPosition(255.f, 150.f);
            enteredNameText.setPosition(255.f, 200.f);
            enteredAddressText.setPosition(255.f, 250.f);
            enteredAgeText.setPosition(255.f, 300.f);
            enteredDobText.setPosition(255.f, 350.f);

            enteredIdText.setString(to_string(id));
            enteredNameText.setString(name);
            enteredAddressText.setString(address);
            enteredAgeText.setString(to_string(age));
            enteredDobText.setString(dob);

            enteredIdText2.setPosition(120.f, 500.f);
            enteredNameText2.setPosition(120.f, 530.f);
            enteredAddressText2.setPosition(120.f, 560.f);
            enteredAgeText2.setPosition(120.f, 590.f);
            enteredDobText2.setPosition(120.f, 620.f);
            enteredIdText2.setString("Student ID: " + to_string(id));
            enteredNameText2.setString("Name: " + name);
            enteredAddressText2.setString("Address: " + address);
            enteredAgeText2.setString("Age: " + to_string(age));
            enteredDobText2.setString("DOB: " + dob);

            addStudentWindow.clear();

            addStudentWindow.draw(sprite);
            addStudentWindow.draw(idInputBox);
            addStudentWindow.draw(nameInputBox);
            addStudentWindow.draw(addressInputBox);
            addStudentWindow.draw(ageInputBox);
            addStudentWindow.draw(dobInputBox);

            addStudentWindow.draw(idLabel);
            addStudentWindow.draw(nameLabel);
            addStudentWindow.draw(addressLabel);
            addStudentWindow.draw(ageLabel);
            addStudentWindow.draw(dobLabel);
            addStudentWindow.draw(viewAddedStudent);
            addStudentWindow.draw(inputPrompt);
            addStudentWindow.draw(resultText);
            addStudentWindow.draw(enteredIdText);

            addStudentWindow.draw(enteredNameText);
            addStudentWindow.draw(enteredAddressText);
            addStudentWindow.draw(enteredAgeText);
            addStudentWindow.draw(enteredDobText);
            addStudentWindow.draw(enteredIdText2);
            addStudentWindow.draw(enteredNameText2);
            addStudentWindow.draw(enteredAddressText2);
            addStudentWindow.draw(enteredAgeText2);
            addStudentWindow.draw(enteredDobText2);
            addStudentWindow.display();
        }
    }

}
void  operator <<(ostream& out, const Student& s) {
    out << s.student_id << endl;
    out << s.student_name << endl;
    out << s.student_address << endl;
    out << s.Age << endl;
    out << s.DOB << endl;

};
void operator >>(istream& in, Student& s) {
    in >> s.student_id;
    in >> s.student_name;
    in >> s.student_address;
    in >> s.Age;
    in >> s.DOB;
}

void Student::viewStudentRecord()
{
                     sf::RenderWindow recordWindow(sf::VideoMode(700, 800), "View Student Record");

                  sf::Font font;
                  font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

                  sf::Text recordLabel("View Student Record", font, 60);
                  recordLabel.setPosition(100, 120);
                  recordLabel.setOutlineColor(sf::Color::Black);
                  recordLabel.setOutlineThickness(3);

                  sf::Text recordDisplayText("", font, 20);
                  recordDisplayText.setFillColor(sf::Color::Black);

                  Student* s;
                  s = new Student[10];
                  ifstream fin;
                  fin.open("student.txt");

                  for (int i = 0; i < 10; i++) {
                      fin >> s[i];
                  }
                  sf::RectangleShape inputButton(sf::Vector2f(200, 30));
                  inputButton.setPosition(10, 230);
                  inputButton.setFillColor(sf::Color::White);
                  inputButton.setOutlineThickness(5);
                  inputButton.setOutlineColor(sf::Color::Black);

                  inputButton.setPosition(350, 250);

                  sf::RectangleShape recordButton(sf::Vector2f(500, 300));
                  recordButton.setFillColor(sf::Color::White);
                  recordButton.setOutlineThickness(5);
                  recordButton.setOutlineColor(sf::Color::Black);

                  recordButton.setPosition(100, 350);

                  sf::Text promptText("Enter the Student ID:", font, 24);
                  promptText.setPosition(100, 250);
                  promptText.setOutlineColor(sf::Color::Black);
                  promptText.setOutlineThickness(2);

                  sf::Text inputText("", font, 22);
                  inputText.setPosition(380, 250);
                  inputText.setFillColor(sf::Color::Black);

                  string enteredStudentID;
                  const char* c = new char;
                  bool input = false;
                  while (recordWindow.isOpen())
                  {
                      sf::Texture texture;
                      if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
                          cout << EXIT_FAILURE << endl;
                      }
                      sf::Sprite sprite;
                      sprite.setTexture(texture);
                      sprite.setScale(5.0f, 5.0f);

                      sf::Event viewRecordEvent;
                      while (recordWindow.pollEvent(viewRecordEvent))
                      {
                          if (viewRecordEvent.type == sf::Event::Closed)
                              recordWindow.close();
                          if (viewRecordEvent.type == sf::Event::TextEntered) {
                              if (viewRecordEvent.text.unicode < 128) {
                                  if (viewRecordEvent.type == sf::Event::TextEntered) {
                                      if (viewRecordEvent.text.unicode < 128) {
                                          // Append ASCII characters to the inputText
                                          if (viewRecordEvent.text.unicode == 13) {
                                              // Enter key pressed, you can handle submission here
                                              enteredStudentID = inputText.getString().toAnsiString();
                                              std::cout << "Student ID entered: " << inputText.getString().toAnsiString() << std::endl;
                                              c = enteredStudentID.c_str();
                                              inputText.setString("");
                                              input = true;

                                          }
                                          else {
                                              inputText.setString(inputText.getString() + static_cast<char>(viewRecordEvent.text.unicode));
                                          }
                                      }
                                  }
                              }
                          }
                      }
                      recordWindow.clear();
                      recordWindow.draw(sprite);
                      recordWindow.draw(promptText);
                      recordWindow.draw(recordLabel);
                      recordWindow.draw(inputButton);
                      recordWindow.draw(inputText);
                      recordWindow.draw(recordButton);
                      while (input)
                      {

                          int studentid = atoi(c);
                          recordDisplayText.setString(s[--studentid].Print());
                          recordDisplayText.setPosition(120, 350);
                          recordWindow.draw(recordDisplayText);

                          break;
                      }
                      recordWindow.display();
                  }
                  delete[] s;
}
//Exam Class
Exam::Exam()
{
    Exam_id = 0000;
    Date = "5/06/2000";
    time = "12:00";
    room_no = 123;
    cr = NULL;
    inv = NULL;
}
Exam::Exam(int exi, string dt, string t, Course* c, Invigilator* i)
{
    Exam_id = exi;
    Date = dt;
    time = t;
    cr = new Course;
    cr->SetCourseId(c->GetCourseId());
    cr->SetCourseName(c->GetCourseName());
    inv = new Invigilator;
    inv->setid(i->getid());
    inv->setname(i->getname());
}
string Exam::GetExamTime() { return time; }
void Exam::SetExamid(int exi) { Exam_id = exi; }
void Exam::SetExamDate(string dt) { Date = dt; }
void Exam::SetRoomNo(int rno) {
    room_no = rno;
}
void Exam::SetExamTime(string t) { time = t; }
int Exam::GetExamId() { return Exam_id; }
void Exam::SetExam(Course c)
{
    cr = new Course;
    cr->SetCourseId(c.GetCourseId());
    cr->SetCourseName(c.GetCourseName());
}
string Exam::GetExamDate() {
    return Date;
}
void Exam::SetInvigilator(Invigilator i)
{
    inv = new Invigilator;
    inv->setid(i.getid());
    inv->setname(i.getname());
}
void  operator <<(ostream& out, const Exam& e) {
    out << e.Exam_id << endl;
    out << e.Date << endl;
    out << e.time << endl;
    out << e.cr->GetCourseId() << endl;
    out << e.cr->GetCourseName() << endl;
    out << e.room_no << endl;
};
void operator >> (istream& in, AddExam* ae) {

    if (Exam* e = dynamic_cast<Exam*>(ae)) {
        in >> e->Exam_id;
        in >> e->Date;
        in >> e->time;
        int courseid;
        e->cr = new Course[1];

        in >> courseid;
        e->cr->SetCourseId(courseid);
        string coursename;
        in >> coursename;
        e->cr->SetCourseName(coursename);
        in >> e->room_no;
    }

}
void Exam::viewExamOnDate()
{
    sf::RenderWindow viewExamWindow(sf::VideoMode(700, 800), "Exams on Particular Date:");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");
    sf::Text viewExamLabel("View Exams", font, 60);
    viewExamLabel.setPosition(100, 120);
    viewExamLabel.setOutlineColor(sf::Color::Black);
    viewExamLabel.setOutlineThickness(3);

    sf::Text examsDisplayText("", font, 20);
    examsDisplayText.setFillColor(sf::Color::Black);
    string dateinput;
    AddExam* e[5];

    for (int i = 0; i < 5; ++i) {
        e[i] = new Exam;
    }
    ifstream fin;
    fin.open("exam.txt");
    for (int x = 0; x < 5; x++) {
        fin >> e[x];
    }

    fin.close();
    bool input = false;
    sf::RectangleShape inputButton(sf::Vector2f(200, 30));
    inputButton.setPosition(10, 230);
    inputButton.setFillColor(sf::Color::White);
    inputButton.setOutlineThickness(5);
    inputButton.setOutlineColor(sf::Color::Black);

    inputButton.setPosition(350, 250);

    sf::RectangleShape examViewtable(sf::Vector2f(500, 300));
    examViewtable.setFillColor(sf::Color::White);
    examViewtable.setOutlineThickness(5);
    examViewtable.setOutlineColor(sf::Color::Black);

    examViewtable.setPosition(100, 350);

    sf::Text promptText("Enter Date: ", font, 24);
    promptText.setPosition(100, 250);
    promptText.setOutlineColor(sf::Color::Black);
    promptText.setOutlineThickness(2);

    sf::Text inputText("", font, 22);
    inputText.setPosition(380, 250);
    inputText.setFillColor(sf::Color::Black);

    while (viewExamWindow.isOpen())
    {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);

        sf::Event viewEXaEvent;
        while (viewExamWindow.pollEvent(viewEXaEvent))
        {
            if (viewEXaEvent.type == sf::Event::Closed)
                viewExamWindow.close();
            if (viewEXaEvent.type == sf::Event::TextEntered) {
                if (viewEXaEvent.text.unicode < 128) {
                    if (viewEXaEvent.text.unicode == 13) {
                        dateinput = inputText.getString().toAnsiString();
                        std::cout << "Entered Date: " << inputText.getString().toAnsiString() << std::endl;
                        inputText.setString("");
                        input = true;

                    }
                    else {
                        inputText.setString(inputText.getString() + static_cast<char>(viewEXaEvent.text.unicode));
                    }
                }
            }
            sf::String userInput;
            if (viewEXaEvent.text.unicode == 8 && userInput.getSize() > 0) {
                userInput.erase(userInput.getSize() - 1, 1);
            }
            if (viewEXaEvent.type == sf::Event::KeyPressed && viewEXaEvent.key.code == sf::Keyboard::Escape) {
                viewExamWindow.close();
            }

        }
        viewExamWindow.clear();
        viewExamWindow.draw(sprite);
        viewExamWindow.draw(promptText);
        viewExamWindow.draw(viewExamLabel);
        viewExamWindow.draw(inputButton);
        viewExamWindow.draw(inputText);
        viewExamWindow.draw(examViewtable);

        while (input)
        {
            for (int x = 0; x < 5; x++)
            {
                if (dateinput == e[x]->GetExamDate()) {


                    examsDisplayText.setString(e[x]->Print());
                    examsDisplayText.setPosition(120, 350);
                    viewExamWindow.draw(examsDisplayText);
                    x++;
                }
                else
                {
                    examsDisplayText.setString("Not Found!");
                    examsDisplayText.setPosition(120, 370);
                }
            }

            break;
        }

        viewExamWindow.display();
    }
}
void Exam::addExam()
{
    sf::RenderWindow addExamWindow(sf::VideoMode(700, 800), "Add Exam:");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

    sf::Text inputPrompt("Enter Exam Information", font, 50);
    inputPrompt.setPosition(65.0f, 60.0f);
    inputPrompt.setOutlineColor(sf::Color::Black);
    inputPrompt.setOutlineThickness(3);
    sf::Text resultText("", font, 20);
    resultText.setPosition(80.f, 470.f);
    resultText.setFillColor(sf::Color::Black);
    sf::String userInput;
    int id = 0;
    string date;
    string time;
    int room_no = 0;
    int courseId = 0;
    string courseName;
    enum class InputState { ID, DATE, TIME, ROOM_NO, COURSE_ID, COURSE_NAME };
    InputState currentState = InputState::ID;

    bool inputCompleted = false;
    sf::RectangleShape idInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape DateInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape timeInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape roomNoInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape courseIdInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape courseNameInputBox(sf::Vector2f(250, 30));

    idInputBox.setOutlineColor(sf::Color::Black);
    DateInputBox.setOutlineColor(sf::Color::Black);
    timeInputBox.setOutlineColor(sf::Color::Black);
    roomNoInputBox.setOutlineColor(sf::Color::Black);
    courseIdInputBox.setOutlineColor(sf::Color::Black);
    courseNameInputBox.setOutlineColor(sf::Color::Black);

    idInputBox.setOutlineThickness(3);
    DateInputBox.setOutlineThickness(3);
    timeInputBox.setOutlineThickness(3);
    roomNoInputBox.setOutlineThickness(3);
    courseIdInputBox.setOutlineThickness(3);
    courseNameInputBox.setOutlineThickness(3);

    sf::Text idLabel("Exam ID: ", font, 20);
    sf::Text dateLabel("Exam Date: ", font, 20);
    sf::Text timeLabel("Exam Time: ", font, 20);
    sf::Text roomNoLabel("Exam Room No: ", font, 20);
    sf::Text courseIdLabel("Exam Course ID: ", font, 20);
    sf::Text courseNameLabel("Exam Course Name: ", font, 20);

    sf::RectangleShape viewAddedExam(sf::Vector2f(600.0f, 300.0f));
    viewAddedExam.setPosition(50, 460);
    viewAddedExam.setFillColor(sf::Color::White);
    viewAddedExam.setOutlineColor(sf::Color::Black);
    viewAddedExam.setOutlineThickness(3);

    idLabel.setOutlineColor(sf::Color::Black);
    dateLabel.setOutlineColor(sf::Color::Black);
    timeLabel.setOutlineColor(sf::Color::Black);
    roomNoLabel.setOutlineColor(sf::Color::Black);
    courseIdLabel.setOutlineColor(sf::Color::Black);
    courseNameLabel.setOutlineColor(sf::Color::Black);
    idLabel.setOutlineThickness(3);
    dateLabel.setOutlineThickness(3);
    timeLabel.setOutlineThickness(3);
    roomNoLabel.setOutlineThickness(3);
    courseIdLabel.setOutlineThickness(3);
    courseNameLabel.setOutlineThickness(3);

    idInputBox.setPosition(250, 150);
    DateInputBox.setPosition(250, 200);
    timeInputBox.setPosition(250, 250);
    roomNoInputBox.setPosition(250, 300);
    courseIdInputBox.setPosition(250, 350);
    courseNameInputBox.setPosition(250, 400);

    idLabel.setPosition(50, 150);
    dateLabel.setPosition(50, 200);
    timeLabel.setPosition(50, 250);
    roomNoLabel.setPosition(50, 300);
    courseIdLabel.setPosition(50, 350);
    courseNameLabel.setPosition(50, 400);

    sf::Text inputText("", font, 22);
    inputText.setPosition(380, 250);
    inputText.setFillColor(sf::Color::Black);
    Exam s;
    while (addExamWindow.isOpen()) {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);

        sf::Text enteredIdText2("", font, 20);

        sf::Text enteredDateText2("", font, 20);

        sf::Text enteredTimeText2("", font, 20);

        sf::Text enteredroomNoText2("", font, 20);

        sf::Text enteredcourseIdText2("", font, 20);

        sf::Text enteredcourseNameText2("", font, 20);

        enteredIdText2.setFillColor(sf::Color::Black);
        enteredDateText2.setFillColor(sf::Color::Black);
        enteredTimeText2.setFillColor(sf::Color::Black);
        enteredroomNoText2.setFillColor(sf::Color::Black);
        enteredcourseIdText2.setFillColor(sf::Color::Black);
        enteredcourseNameText2.setFillColor(sf::Color::Black);

        sf::Text enteredIdText("", font, 20);

        sf::Text enteredDateText("", font, 20);

        sf::Text enteredTimeText("", font, 20);

        sf::Text enteredroomNoText("", font, 20);

        sf::Text enteredcourseIdText("", font, 20);
        sf::Text enteredcourseNameText("", font, 20);
        enteredIdText.setFillColor(sf::Color::Black);
        enteredDateText.setFillColor(sf::Color::Black);
        enteredTimeText.setFillColor(sf::Color::Black);
        enteredroomNoText.setFillColor(sf::Color::Black);
        enteredcourseIdText.setFillColor(sf::Color::Black);
        enteredcourseNameText.setFillColor(sf::Color::Black);

        sf::Event event;
        while (addExamWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                addExamWindow.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode >= 32) {
                    userInput += static_cast<char>(event.text.unicode);
                }
                if (event.text.unicode == 8 && userInput.getSize() > 0) {
                    userInput.erase(userInput.getSize() - 1, 1);
                }
                if (event.text.unicode == 13) {
                    std::istringstream iss(userInput.toAnsiString());

                    switch (currentState) {
                    case InputState::ID:
                        iss >> id;
                        s.SetExamid(id);
                        currentState = InputState::DATE;
                        userInput.clear();
                        break;
                    case InputState::DATE:
                        iss >> date;
                        s.SetExamDate(date);
                        currentState = InputState::TIME;
                        userInput.clear();
                        break;
                    case InputState::TIME:
                        iss >> time;
                        s.SetExamTime(time);
                        currentState = InputState::ROOM_NO;
                        userInput.clear();
                        break;
                    case InputState::ROOM_NO:
                        iss >> room_no;
                        s.SetRoomNo(room_no);
                        currentState = InputState::COURSE_ID;
                        userInput.clear();
                        break;
                    case InputState::COURSE_ID:
                        iss >> courseId;
                        currentState = InputState::COURSE_NAME;
                        userInput.clear();
                        break;
                    case InputState::COURSE_NAME:
                        iss >> courseName;
                        userInput.clear();

                        std::ofstream fout("exam.txt", std::ios_base::app);
                        if (fout.is_open()) {
                            fout  << "\n" <<  id << "\n"
                                  << date << "\n"
                                  << time << "\n"
                                  << courseId << "\n"
                                  << courseName << "\n"
                            << room_no << "\n";
                            fout.close();
                            resultText.setString("Exam Information Stored in Exam.txt!");
                        }
                        else {
                            resultText.setString("Error: Unable to open Exam.txt for writing.");
                        }

                        currentState = InputState::ID;

                        resultText.setString("Exam Information Entered!");
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                addExamWindow.close();
            }
            enteredIdText.setPosition(255.f, 150.f);
            enteredDateText.setPosition(255.f, 200.f);
            enteredTimeText.setPosition(255.f, 250.f);
            enteredroomNoText.setPosition(255.f, 300.f);
            enteredcourseIdText.setPosition(255.f, 350.f);
            enteredcourseNameText.setPosition(255.f, 400.f);

            enteredIdText.setString(to_string(id));
            enteredDateText.setString(date);
            enteredTimeText.setString(time);
            enteredroomNoText.setString(to_string(room_no));
            enteredcourseIdText.setString(to_string(courseId));
            enteredcourseNameText.setString(courseName);

            enteredIdText2.setPosition(120.f, 500.f);
            enteredDateText2.setPosition(120.f, 530.f);
            enteredTimeText2.setPosition(120.f, 560.f);
            enteredroomNoText2.setPosition(120.f, 590.f);
            enteredcourseIdText2.setPosition(120.f, 620.f);
            enteredcourseNameText2.setPosition(120.f, 650.f);

            enteredIdText2.setString("Exam ID: " + to_string(id));
            enteredDateText2.setString("Exam Date: " + date);
            enteredTimeText2.setString("Exam Time: " + time);
            enteredroomNoText2.setString("Exam Room No: " + to_string(room_no));
            enteredcourseIdText2.setString("Exam Course ID: " + to_string(courseId));
            enteredcourseNameText2.setString("Exam Course Name: " + (courseName));
            addExamWindow.clear();

            addExamWindow.draw(sprite);
            addExamWindow.draw(idInputBox);
            addExamWindow.draw(DateInputBox);
            addExamWindow.draw(timeInputBox);
            addExamWindow.draw(roomNoInputBox);
            addExamWindow.draw(courseIdInputBox);
            addExamWindow.draw(courseNameInputBox);

            addExamWindow.draw(idLabel);
            addExamWindow.draw(dateLabel);
            addExamWindow.draw(timeLabel);
            addExamWindow.draw(roomNoLabel);
            addExamWindow.draw(courseIdLabel);
            addExamWindow.draw(courseNameLabel);
            addExamWindow.draw(viewAddedExam);
            addExamWindow.draw(inputPrompt);
            addExamWindow.draw(resultText);
            addExamWindow.draw(enteredIdText);
            addExamWindow.draw(enteredDateText);
            addExamWindow.draw(enteredTimeText);
            addExamWindow.draw(enteredroomNoText);
            addExamWindow.draw(enteredcourseIdText);
            addExamWindow.draw(enteredcourseNameText);
            addExamWindow.draw(enteredIdText2);
            addExamWindow.draw(enteredDateText2);
            addExamWindow.draw(enteredTimeText2);
            addExamWindow.draw(enteredroomNoText2);
            addExamWindow.draw(enteredcourseIdText2);
            addExamWindow.draw(enteredcourseNameText2);
            addExamWindow.display();
        }
    }

}
void Student::viewExamInfo()
{
    sf::RenderWindow viewExamWindow(sf::VideoMode(700, 800), "View Exam Information");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");
    sf::Text titleText("View Exam Information", font, 50);
    titleText.setPosition(100, 40);
    titleText.setOutlineColor(sf::Color::Black);
    titleText.setOutlineThickness(3);

    sf::Text examInfoLabel("Exam Information:", font, 16);
    examInfoLabel.setPosition(10, 50);

    sf::Text examInfoDisplayText("", font, 16);
    examInfoDisplayText.setPosition(100, 60);
    examInfoDisplayText.setFillColor(sf::Color::Black);

    AddExam* exams[20];
    for (int i = 0; i < 20; i++)
    {
        exams[i] = new Exam;
    }
    ifstream fin;
    fin.open("exam.txt");
    int size = 0;
    if (fin.is_open()) {
        for (int x = 0; x < 20; x++) {
            if (fin.eof())
            {
          
                break;
            }
            fin >> exams[x];
            size++;
        }
        fin.close();
    }
    size--;
    sf::RectangleShape examRecord(sf::Vector2f(610, 650));
    examRecord.setFillColor(sf::Color::White);
    examRecord.setOutlineThickness(5);
    examRecord.setOutlineColor(sf::Color::Black);
    examRecord.setPosition(40, 120);

    while (viewExamWindow.isOpen())
    {

        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);
        sf::String userInput;
        sf::Event viewExamEvent;
        while (viewExamWindow.pollEvent(viewExamEvent))
        {
            if (viewExamEvent.type == sf::Event::Closed)
                viewExamWindow.close();
        }
        if (viewExamEvent.text.unicode == 8 && userInput.getSize() > 0) {
            userInput.erase(userInput.getSize() - 1, 1);
        }
        viewExamWindow.clear();
        viewExamWindow.draw(sprite);
        viewExamWindow.draw(examRecord);
        viewExamWindow.draw(titleText);
        float l = 1.0;
        int k = 1, count = 0;
        //size--;
        for (int x = 0; x < size; x++) {

            if (count < 5)
            {
                examInfoDisplayText.setString(exams[x]->Print());
                examInfoDisplayText.setPosition(60, l * 120);
                viewExamWindow.draw(examInfoDisplayText);
                l += 1.05;
                if (count == 4)
                {
                    k *= 260;
                }
            }
            else if (count < 10 && count >= 5)
            {
                examInfoDisplayText.setString(exams[x]->Print());
                examInfoDisplayText.setPosition(k, l *19);
                viewExamWindow.draw(examInfoDisplayText);

                l += 6.7;
                if (count == 9)
                {
                    k += 200;
                }
            }
            else
            {
                examInfoDisplayText.setString(exams[x]->Print());
                examInfoDisplayText.setPosition(k, l *3);
                viewExamWindow.draw(examInfoDisplayText);

                l += 42;
            }
            count++;
        }
        viewExamWindow.display();

    }
}
//Invigilator Class
Invigilator::Invigilator()
{
    invigilator_id = 0;
    invigilator_name = "\0";
}
Invigilator::Invigilator(int id, string name, list<Exam>ex)
{
    invigilator_id = id;
    invigilator_name = name;
    exam.assign(ex.begin(), ex.end());
}
void Invigilator::add_exam(Exam ex)
{
    exam.push_back(ex);
}

void Invigilator::getexams()
{
    for (list<Exam>::iterator j = exam.begin(); j != exam.end(); ++j) {
        j->Print();
    }
    cout << endl;
}
void Invigilator::setid(int id) {
    invigilator_id = id;
}
void Invigilator::setname(string name) {
    invigilator_name = name;
}
int Invigilator::getid() {
    return invigilator_id;
}
string Invigilator::getname() {
    return invigilator_name;
}
void  operator <<(ostream& out, const Invigilator& i) {
    out << i.invigilator_id << endl;
    out << i.invigilator_name << endl;
}
void operator >>(istream& in, Invigilator& i) {
    in >> i.invigilator_id;
    in >> i.invigilator_name;
}
void Invigilator::markAttendance() {
    sf::RenderWindow attendanceWindow(sf::VideoMode(800, 600), "Mark Attendance");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

    sf::Text attendanceLabel("Mark Attendance", font, 60);
    attendanceLabel.setPosition(200, 50);
    attendanceLabel.setOutlineColor(sf::Color::Black);
    attendanceLabel.setOutlineThickness(3);

    sf::RectangleShape inputButton(sf::Vector2f(200, 30));
    sf::RectangleShape inputButton2(sf::Vector2f(200, 30));
    sf::RectangleShape inputButton3(sf::Vector2f(200, 30));
    sf::RectangleShape inputButton4(sf::Vector2f(200, 30));
    sf::RectangleShape inputButton5(sf::Vector2f(200, 30));
    inputButton.setPosition(440, 200);
    inputButton.setFillColor(sf::Color::White);
    inputButton.setOutlineThickness(5);
    inputButton.setOutlineColor(sf::Color::Black);

    inputButton2.setPosition(440, 250);
    inputButton2.setFillColor(sf::Color::White);
    inputButton2.setOutlineThickness(5);
    inputButton2.setOutlineColor(sf::Color::Black);
    inputButton3.setPosition(440, 300);
    inputButton3.setFillColor(sf::Color::White);
    inputButton3.setOutlineThickness(5);
    inputButton3.setOutlineColor(sf::Color::Black);
    inputButton4.setPosition(440, 350);
    inputButton4.setFillColor(sf::Color::White);
    inputButton4.setOutlineThickness(5);
    inputButton4.setOutlineColor(sf::Color::Black);
    inputButton5.setPosition(440, 400);
    inputButton5.setFillColor(sf::Color::White);
    inputButton5.setOutlineThickness(5);
    inputButton5.setOutlineColor(sf::Color::Black);

    sf::Text promptExamId("Enter Exam ID:", font, 24);
    promptExamId.setPosition(160, 200);
    promptExamId.setOutlineColor(sf::Color::Black);
    promptExamId.setOutlineThickness(2);

    sf::Text inputExamId("", font, 22);
    inputExamId.setPosition(450, 200);
    inputExamId.setFillColor(sf::Color::Black);

    sf::Text promptExamName("Enter Exam Name:", font, 24);
    promptExamName.setPosition(160, 250);
    promptExamName.setOutlineColor(sf::Color::Black);
    promptExamName.setOutlineThickness(2);

    sf::Text inputExamName("", font, 22);
    inputExamName.setPosition(450, 250);
    inputExamName.setFillColor(sf::Color::Black);

    sf::Text promptStudentId("Enter Student ID:", font, 24);
    promptStudentId.setPosition(160, 300);
    promptStudentId.setOutlineColor(sf::Color::Black);
    promptStudentId.setOutlineThickness(2);

    sf::Text inputStudentId("", font, 22);
    inputStudentId.setPosition(450, 300);
    inputStudentId.setFillColor(sf::Color::Black);

    sf::Text promptStudentName("Enter Student Name:", font, 24);
    promptStudentName.setPosition(160, 350);
    promptStudentName.setOutlineColor(sf::Color::Black);
    promptStudentName.setOutlineThickness(2);

    sf::Text inputStudentName("", font, 22);
    inputStudentName.setPosition(450, 350);
    inputStudentName.setFillColor(sf::Color::Black);

    sf::RectangleShape markAttendanceButton(sf::Vector2f(600, 90));
    markAttendanceButton.setPosition(120, 470);
    markAttendanceButton.setFillColor(sf::Color::White);
    markAttendanceButton.setOutlineThickness(5);
    markAttendanceButton.setOutlineColor(sf::Color::Black);

    sf::Text inputAttendance("", font, 22);
    inputAttendance.setPosition(450, 400);
    inputAttendance.setFillColor(sf::Color::Black);

    sf::Text promptAttendance("Enter Attendance (A/P): ", font, 24);
   promptAttendance.setPosition(160, 400);
   promptAttendance.setOutlineColor(sf::Color::Black);
   promptAttendance.setOutlineThickness(2);

    sf::Text markAttendanceText("", font, 20);
    markAttendanceText.setPosition(140, 480);
    markAttendanceText.setFillColor(sf::Color::Black);
    sf::String userInput;
    string examId, examName, studentId, studentName, attendanceStatus;
    enum class InputState { ID, NAME, STUDENT_ID, STUDENT_NAME, ATTENDANCE };
    InputState currentState = InputState::ID;
    while (attendanceWindow.isOpen()) {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);
        sf::Event attendanceEvent;
        while (attendanceWindow.pollEvent(attendanceEvent)) {
            if (attendanceEvent.type == sf::Event::Closed)
                attendanceWindow.close();
            if (attendanceEvent.type == sf::Event::TextEntered) {
                if (attendanceEvent.text.unicode < 128) {
                    // Append ASCII characters to the input fields
                    if (attendanceEvent.text.unicode < 128 && attendanceEvent.text.unicode >= 32) {
                        userInput += static_cast<char>(attendanceEvent.text.unicode);
                    }
                    if (attendanceEvent.text.unicode == 8 && userInput.getSize() > 0) {
                        userInput.erase(userInput.getSize() - 1, 1);
                    }

                    if (attendanceEvent.text.unicode == 13) {
                        // Enter key pressed, you can handle submission here
                        std::istringstream iss(userInput.toAnsiString());
                        switch (currentState)
                        {
                        case InputState::ID:
                            iss >> examId;
                            currentState = InputState::NAME;
                            userInput.clear();
                            break;
                        case InputState::NAME:
                            iss >> examName;
                            currentState = InputState::STUDENT_ID;
                            userInput.clear();
                            break;
                        case InputState::STUDENT_ID:
                            iss >> studentId;
                            currentState = InputState::STUDENT_NAME;
                            userInput.clear();
                            break;
                        case InputState::STUDENT_NAME:
                            iss >> studentName;
                            currentState = InputState::ATTENDANCE;
                            userInput.clear();
                            break;
                        case InputState::ATTENDANCE:
                            iss >> attendanceStatus;
                            userInput.clear();
                            std::cout << "Exam ID: " << examId << ", Exam Name: " << examName
                                << ", Student ID: " << studentId << ", Student Name: " << studentName
                                << ", Attendance: " << attendanceStatus << std::endl;

                            ofstream fout("attendance.txt", ios::app);
                            if (fout.is_open())
                            {

                                fout << "\nExam ID: " << examId << "\nExam Name:  " << examName << "\nStudent ID:  " << studentId << 
                                    "\nStudent Name: " << studentName << "\nAttendance Status: "
                                    << attendanceStatus << endl;
                                markAttendanceText.setString("Attendance Marked Successfully!");
                            }
                            else
                            {
                                markAttendanceText.setString("Attendance Not Marked!");
                            }

                        }
                    }
                }
            }
        }

        inputExamId.setString(examId);
        inputExamName.setString(examName);
        inputStudentId.setString(studentId);
        inputStudentName.setString(studentName);
        inputAttendance.setString(attendanceStatus);
        attendanceWindow.clear();
        attendanceWindow.draw(sprite);
        attendanceWindow.draw(attendanceLabel);
        attendanceWindow.draw(inputButton);
        attendanceWindow.draw(inputButton2);
        attendanceWindow.draw(inputButton3);
        attendanceWindow.draw(inputButton4);
        attendanceWindow.draw(inputButton5);
        attendanceWindow.draw(promptExamId);
        attendanceWindow.draw(inputExamId);
        attendanceWindow.draw(promptExamName);
        attendanceWindow.draw(inputExamName);
        attendanceWindow.draw(promptStudentId);
        attendanceWindow.draw(inputStudentId);
        attendanceWindow.draw(promptStudentName);
        attendanceWindow.draw(inputStudentName);
        attendanceWindow.draw(markAttendanceButton);
        attendanceWindow.draw(promptAttendance);
        attendanceWindow.draw(inputAttendance);
        attendanceWindow.draw(markAttendanceText);
        attendanceWindow.display();
    }
}

bool System::authentication(sf::RenderWindow& window, const string& userType)
{
    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {

        return EXIT_FAILURE;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(5.0f, 0.4f);

    sf::Texture texture2;
    if (!texture2.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/logo_authentication.jpg")) {

        cout << EXIT_FAILURE << endl;
    }


    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setScale(0.5f, 0.5f);
    sprite2.setPosition(340, 120);
    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

    // Create a text input box
    sf::Text inputText("Enter "  + userType + " Password:", font, 26);
    inputText.setPosition(200, 450);
    inputText.setFillColor(sf::Color::Black);

    sf::RectangleShape inputBox(sf::Vector2f(400, 40));
    inputBox.setPosition(200, 500);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);

    sf::Text inputPassword("", font, 26);
    inputPassword.setPosition(210, 510);
    inputPassword.setFillColor(sf::Color::Black);

    sf::Text message("", font, 26);
    message.setPosition(200, 560);
    message.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return false;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                return false; // Escape key pressed, authentication canceled
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 && !inputPassword.getString().isEmpty())
                    {
                        // Handle backspace
                        string currentInput = inputPassword.getString();
                        currentInput.pop_back();
                        inputPassword.setString(currentInput);
                    }
                    else if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        // Append other printable characters
                        inputPassword.setString(inputPassword.getString() + static_cast<char>(event.text.unicode));
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            {
                ifstream passwordFile(userType + "_authentication.txt");
                string storedPassword;
                if (passwordFile.is_open())
                {
                    passwordFile >> storedPassword;
                }
                else
                {
                    cout << "Error Opening Authentication File" <<  endl;
                }
                passwordFile.close();

                if (inputPassword.getString().toAnsiString() == storedPassword)
                {
                    return true; // Authentication successful
                }
                else
                {
                    message.setString("Incorrect Password. Try Again!");
                    inputPassword.setString("");
                }
            }
        }

        window.clear(lightGray);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(inputText);
        window.draw(inputBox);
        window.draw(inputPassword);
        window.draw(message);

        window.display();
    }

    return false; // Shouldn't reach here, but return false to be explicit
}
void AcademicOfficer::generateTimeTable()
{
    sf::RenderWindow timetableWindow(sf::VideoMode(1070, 840), "Exam Timetable");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");
    sf::Text titleText("Exam Timetable", font, 50);
    titleText.setPosition(300, 40);
    titleText.setOutlineColor(sf::Color::Black);
    titleText.setOutlineThickness(3);

    Exam* exams[20];
    for (int i = 0; i < 20; i++)
    {
        exams[i] = new Exam;
    }

    ifstream fin;
    fin.open("exam.txt");
    int size = 0;
    if (fin.is_open()) {
        for (int x = 0; x < 20; x++) {
            if (fin.eof())
            {
                break;
            }
            fin >> exams[x];
            size++;
        }
        fin.close();
    }
    size--;

    vector<sf::RectangleShape> examRectangles;
    int noOfBoxes = size + 6;
    for (int i = 0; i < noOfBoxes; i++) {
        sf::RectangleShape examRectangle(sf::Vector2f(250, 140));
        examRectangle.setFillColor(sf::Color::White);
        examRectangle.setOutlineThickness(5);
        examRectangle.setOutlineColor(sf::Color::Black);

        int row = i % 5;
        int col = i / 5;
        float xPos = 20 + col * 260;
        float yPos = 130 + row * 140;

        examRectangle.setPosition(xPos, yPos);
        examRectangles.push_back(examRectangle);
    }

    while (timetableWindow.isOpen())
    {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);

        sf::Event timetableEvent;
        while (timetableWindow.pollEvent(timetableEvent))
        {
            if (timetableEvent.type == sf::Event::Closed)
                timetableWindow.close();
            if (timetableEvent.type == sf::Event::KeyPressed && timetableEvent.key.code == sf::Keyboard::Escape)
            {
                timetableWindow.close();
            }
        }

        timetableWindow.clear();
        timetableWindow.draw(sprite);
        timetableWindow.draw(titleText);

        for (int i = 0; i < noOfBoxes; i++) {
            timetableWindow.draw(examRectangles[i]);
        }

        int no = 1;
            for (int i = 0; i < size; i++) {
                sf::Text examNoText("Exam No: " + to_string(no++) , font, 16);
            examNoText.setFillColor(sf::Color::Black);
            examNoText.setPosition(examRectangles[i].getPosition().x + 10, examRectangles[i].getPosition().y + 8);
            sf::Text examInfoText(exams[i]->Print(), font, 14);
            examInfoText.setFillColor(sf::Color::Black);
            examInfoText.setPosition(examRectangles[i].getPosition().x + 10, examRectangles[i].getPosition().y + 10);
            timetableWindow.draw(examNoText);
            timetableWindow.draw(examInfoText);
        }

        timetableWindow.display();
    }
}
void Invigilator::addInvigilator()
{
    std::cout << "Adding Invigilator by Academic Officer" << std::endl;
    sf::RenderWindow addInvigilatorWindow(sf::VideoMode(700, 800), "ADD Invigilator:");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");
    sf::Text inputPrompt("Enter Invigilator Information", font, 45);
    inputPrompt.setPosition(40.0f, 40.0f);
    inputPrompt.setOutlineColor(sf::Color::Black);
    inputPrompt.setOutlineThickness(3);
    sf::Text resultText("", font, 20);
    resultText.setPosition(340.f, 160.f);
    resultText.setFillColor(sf::Color::Black);
    sf::String userInput;

    int id = 0;
    string name;
    int noOFExams = 0;
    int examID = 0;
    string  examDate;
    string examTime;
    int roomNo = 0;
    int  courseID = 0;
    string courseName;
    enum class InputState { ID, NAME, /*NO_OFEXAMS,*/ EXAM_ID, EXAM_DATE, EXAM_TIME, ROOM_NO, COURSE_ID, COURSE_NAME, NEXT };
    InputState currentState = InputState::ID;

    Exam e;
    bool inputCompleted = false;
    sf::RectangleShape idInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape nameInputBox(sf::Vector2f(250, 30));
    //sf::RectangleShape noOFexamsInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape examsIDInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape examsDateInputBox(sf::Vector2f(250, 30));

    sf::RectangleShape examsTimeInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape examsRoomInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape courseIDInputBox(sf::Vector2f(250, 30));
    sf::RectangleShape courseNameInputBox(sf::Vector2f(250, 30));

    idInputBox.setOutlineColor(sf::Color::Black);
    nameInputBox.setOutlineColor(sf::Color::Black);
    //noOFexamsInputBox.setOutlineColor(sf::Color::Black);
    examsIDInputBox.setOutlineColor(sf::Color::Black);
    examsDateInputBox.setOutlineColor(sf::Color::Black);
    examsTimeInputBox.setOutlineColor(sf::Color::Black);
    examsRoomInputBox.setOutlineColor(sf::Color::Black);
    courseIDInputBox.setOutlineColor(sf::Color::Black);
    courseNameInputBox.setOutlineColor(sf::Color::Black);
    idInputBox.setOutlineThickness(3);
    nameInputBox.setOutlineThickness(3);
    //noOFexamsInputBox.setOutlineThickness(3);
    examsIDInputBox.setOutlineThickness(3);
    examsDateInputBox.setOutlineThickness(3);
    examsTimeInputBox.setOutlineThickness(3);
    examsRoomInputBox.setOutlineThickness(3);
    courseIDInputBox.setOutlineThickness(3);
    courseNameInputBox.setOutlineThickness(3);

    sf::Text idLabel("Invigilator ID: ", font, 20);
    sf::Text nameLabel("Invigilator Name: ", font, 20);
    //sf::Text noOfExamsLabel("No OF Exams: ", font, 20);
    sf::Text examIDLabel("Exam ID: ", font, 20);
    sf::Text examDateLabel("Exam Date: ", font, 20);

    sf::Text examsTimeLabel("Exam Time:", font, 20);
    sf::Text examsRoomLabel("Exam Room:", font, 20);
    sf::Text courseIDLabel("Course ID: ", font, 20);
    sf::Text courseNameLabel("Course Name: ", font, 20);

    sf::RectangleShape viewAddedInvigilator(sf::Vector2f(350.0f, 580.0f));
    viewAddedInvigilator.setPosition(330, 150);
    viewAddedInvigilator.setFillColor(sf::Color::White);
    viewAddedInvigilator.setOutlineColor(sf::Color::Black);
    viewAddedInvigilator.setOutlineThickness(3);

    idLabel.setOutlineColor(sf::Color::Black);
    nameLabel.setOutlineColor(sf::Color::Black);/*
    noOfExamsLabel.setOutlineColor(sf::Color::Black);*/
    examIDLabel.setOutlineColor(sf::Color::Black);
    examDateLabel.setOutlineColor(sf::Color::Black);

    examsTimeLabel.setOutlineColor(sf::Color::Black);
    examsRoomLabel.setOutlineColor(sf::Color::Black);
    courseIDLabel.setOutlineColor(sf::Color::Black);
    courseNameLabel.setOutlineColor(sf::Color::Black);

    idLabel.setOutlineThickness(3);
    nameLabel.setOutlineThickness(3);
    //noOfExamsLabel.setOutlineThickness(3);
    examIDLabel.setOutlineThickness(3);
    examDateLabel.setOutlineThickness(3);
    examsTimeLabel.setOutlineThickness(3);
    examsRoomLabel.setOutlineThickness(3);
    courseIDLabel.setOutlineThickness(3);
    courseNameLabel.setOutlineThickness(3);

    idInputBox.setPosition(50, 170);
    nameInputBox.setPosition(50, 240);
    //noOFexamsInputBox.setPosition(50, 310);
    examsIDInputBox.setPosition(50, 310);
    examsDateInputBox.setPosition(50, 380);

    examsTimeInputBox.setPosition(50, 450);
    examsRoomInputBox.setPosition(50, 520);
    courseIDInputBox.setPosition(50, 590);
    courseNameInputBox.setPosition(50, 660);

    idLabel.setPosition(50, 138);
    nameLabel.setPosition(50, 208);
    //noOfExamsLabel.setPosition(50, 278);
    examIDLabel.setPosition(50, 278);
    examDateLabel.setPosition(50, 348);

    examsTimeLabel.setPosition(50, 410);
    examsRoomLabel.setPosition(50, 480);
    courseIDLabel.setPosition(50, 550);
    courseNameLabel.setPosition(50, 620);

    sf::Text inputText("", font, 22);
    inputText.setPosition(380, 250);
    inputText.setFillColor(sf::Color::Black);
    Invigilator invigilator;
    Student s;
    while (addInvigilatorWindow.isOpen()) {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);

        sf::Text enteredIdText2("", font, 20);
        sf::Text enteredNameText2("", font, 20);
        //sf::Text enterednoOfExamsText2("", font, 20);
        sf::Text enteredExamIdText2("", font, 20);
        sf::Text enteredExamDateText2("", font, 20);

        sf::Text  examsTimeText2("", font, 20);
        sf::Text  examsRoomText2("", font, 20);
        sf::Text   courseIDText2("", font, 20);
        sf::Text courseNameText2("", font, 20);

        enteredIdText2.setFillColor(sf::Color::Black);
        enteredNameText2.setFillColor(sf::Color::Black);
        //enterednoOfExamsText2.setFillColor(sf::Color::Black);
        enteredExamIdText2.setFillColor(sf::Color::Black);
        enteredExamDateText2.setFillColor(sf::Color::Black);
        examsTimeText2.setFillColor(sf::Color::Black);
        examsRoomText2.setFillColor(sf::Color::Black);
        courseIDText2.setFillColor(sf::Color::Black);
        courseNameText2.setFillColor(sf::Color::Black);

        sf::Text enteredIdText("", font, 20);
        sf::Text enteredNameText("", font, 20);
        //sf::Text enterednoOfExamsText("", font, 20);
        sf::Text enteredExamIdText("", font, 20);
        sf::Text enteredExamDateText("", font, 20);

        sf::Text  examsTimeText("", font, 20);
        sf::Text  examsRoomText("", font, 20);
        sf::Text   courseIDText("", font, 20);
        sf::Text courseNameText("", font, 20);


        enteredIdText.setFillColor(sf::Color::Black);
        enteredNameText.setFillColor(sf::Color::Black);
        //enterednoOfExamsText.setFillColor(sf::Color::Black);
        enteredExamIdText.setFillColor(sf::Color::Black);
        enteredExamDateText.setFillColor(sf::Color::Black);
        examsTimeText.setFillColor(sf::Color::Black);
        examsRoomText.setFillColor(sf::Color::Black);
        courseIDText.setFillColor(sf::Color::Black);
        courseNameText.setFillColor(sf::Color::Black);

        sf::Event event;
        while (addInvigilatorWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                addInvigilatorWindow.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode >= 32) {
                    userInput += static_cast<char>(event.text.unicode);
                }
                if (event.text.unicode == 8 && userInput.getSize() > 0) {
                    userInput.erase(userInput.getSize() - 1, 1);
                }

                if (event.text.unicode == 13) {
                    std::istringstream iss(userInput.toAnsiString());

                    std::ofstream fout("Invigilator.txt", std::ios_base::app);
                    switch (currentState) {

                    case InputState::ID:
                        iss >> id;
                        s.setstd_id(id);
                        currentState = InputState::NAME;
                        userInput.clear();
                        break;
                    case InputState::NAME:
                        iss >> name;
                        s.setstd_name(name);
                        currentState = InputState::EXAM_ID;
                        userInput.clear();
                        break;
                    case InputState::EXAM_ID:
                        iss >> examID;
                        e.SetExamid(examID);
                        currentState = InputState::EXAM_DATE;
                        userInput.clear();
                        break;
                    case InputState::EXAM_DATE:
                        iss >> examDate;
                        currentState = InputState::EXAM_TIME;
                        userInput.clear();
                        break;
                    case InputState::EXAM_TIME:
                        iss >> examTime;
                        currentState = InputState::ROOM_NO;
                        userInput.clear();
                        break;
                    case InputState::ROOM_NO:
                        iss >> roomNo;
                        currentState = InputState::COURSE_ID;
                        userInput.clear();
                        break;
                    case InputState::COURSE_ID:
                        iss >> courseID;
                        currentState = InputState::COURSE_NAME;
                        userInput.clear();
                        break;
                    case InputState::COURSE_NAME:
                        iss >> courseName;
                        userInput.clear();
                        currentState = InputState::NEXT;
                        break;

                    case InputState::NEXT:
                        currentState = InputState::EXAM_ID;
                        if (fout.is_open()) {
                                fout << "Invigilator ID: " << id << "\n";
                                fout << "Invigilator Name: " << name << "\n";
                                //fout << "No Of Exams: " << noOFExams << "\n";
                                fout << "Exam TD: " << examID << "\n";
                                fout << "Exam Date: " << examDate << "\n";
                                fout << "Exam Time: " << examTime << "\n";
                                fout << "Exam Course ID: " << courseID << "\n";
                                fout  << "Exam Course Name: " << courseName << "\n";
                        }
                        else {
                            resultText.setString("Error: Unable to open Invigilator.txt for writing.");
                        }
                        fout.close();
                        cout << "Close" << endl;
                        resultText.setString("Invigilator Information Entered!");
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                addInvigilatorWindow.close();
            }
            enteredIdText.setPosition(60.0f, 170.f);
            enteredNameText.setPosition(60.0f, 240.f);
            //enterednoOfExamsText.setPosition(60.0f, 310.f);
            enteredExamIdText.setPosition(60.0f, 310.f);
            enteredExamDateText.setPosition(60.0f, 380.f);

            examsTimeText.setPosition(60.0f, 450.f);
            examsRoomText.setPosition(60.0f, 520.f);
            courseIDText.setPosition(60.0f, 590.f);
            courseNameText.setPosition(60.0f, 660.f);

            enteredIdText.setString(to_string(id));
            enteredNameText.setString(name);
            //enterednoOfExamsText.setString(to_string(noOFExams));
            enteredExamIdText.setString(to_string(examID));
            enteredExamDateText.setString(examDate);
            examsTimeText.setString(examTime);
            examsRoomText.setString(to_string(roomNo));
            courseIDText.setString(to_string(courseID));
            courseNameText.setString(courseName);

            enteredIdText2.setPosition(350.f, 220.f);
            enteredNameText2.setPosition(350.0f, 250.f);
            //enterednoOfExamsText2.setPosition(350.0f, 280.f);
            enteredExamIdText2.setPosition(350.0f, 280.f);
            enteredExamDateText2.setPosition(350.0f, 310.f);

            examsTimeText2.setPosition(350.0f, 340.f);
            examsRoomText2.setPosition(350.0f, 370.f);
            courseIDText2.setPosition(350.0f, 400.f);
            courseNameText2.setPosition(350.0f, 430.f);

            enteredIdText2.setString("Invigilator ID: " + to_string(id));
            enteredNameText2.setString("Name: " + name);
            //enterednoOfExamsText2.setString("noOFExams: " + noOFExams);
            enteredExamIdText2.setString("Exam ID: " + to_string(examID));
            enteredExamDateText2.setString("Exam Date: " + examDate);

            examsTimeText2.setString("Exam Time: " + examTime);
            examsRoomText2.setString("Exam Room NO: " + to_string(roomNo));
            courseIDText2.setString("Course ID: " + to_string(courseID));
            courseNameText2.setString("Course Name: " + courseName);

            addInvigilatorWindow.clear();

            addInvigilatorWindow.draw(sprite);
            addInvigilatorWindow.draw(idInputBox);
            addInvigilatorWindow.draw(nameInputBox);
            //addInvigilatorWindow.draw(noOFexamsInputBox);
            addInvigilatorWindow.draw(examsIDInputBox);
            addInvigilatorWindow.draw(examsDateInputBox);

            addInvigilatorWindow.draw(examsTimeInputBox);
            addInvigilatorWindow.draw(examsRoomInputBox);
            addInvigilatorWindow.draw(courseNameInputBox);
            addInvigilatorWindow.draw(courseIDInputBox);

            addInvigilatorWindow.draw(idLabel);
            addInvigilatorWindow.draw(nameLabel);
            //addInvigilatorWindow.draw(noOfExamsLabel);
            addInvigilatorWindow.draw(examIDLabel);
            addInvigilatorWindow.draw(examDateLabel);

            addInvigilatorWindow.draw(examsTimeLabel);
            addInvigilatorWindow.draw(examsRoomLabel);
            addInvigilatorWindow.draw(courseIDLabel);
            addInvigilatorWindow.draw(courseNameLabel);


            addInvigilatorWindow.draw(viewAddedInvigilator);
            addInvigilatorWindow.draw(inputPrompt);
            addInvigilatorWindow.draw(resultText);
            addInvigilatorWindow.draw(enteredIdText);
            addInvigilatorWindow.draw(enteredNameText);
            //addInvigilatorWindow.draw(enterednoOfExamsText);
            addInvigilatorWindow.draw(enteredExamIdText);
            addInvigilatorWindow.draw(enteredExamDateText);
            addInvigilatorWindow.draw(examsTimeText);
            addInvigilatorWindow.draw(examsRoomText);
            addInvigilatorWindow.draw(courseIDText);
            addInvigilatorWindow.draw(courseNameText);

            addInvigilatorWindow.draw(enteredIdText2);
            addInvigilatorWindow.draw(enteredNameText2);
            //addInvigilatorWindow.draw(enterednoOfExamsText2);
            addInvigilatorWindow.draw(enteredExamIdText2);
            addInvigilatorWindow.draw(enteredExamDateText2);
            addInvigilatorWindow.draw(examsTimeText2);
            addInvigilatorWindow.draw(examsRoomText2);
            addInvigilatorWindow.draw(courseIDText2);
            addInvigilatorWindow.draw(courseNameText2);
            addInvigilatorWindow.display();
        }
    }

}
void Room::addRoom()
{
    std::cout << "Adding Room by Academic Officer" << std::endl;
    sf::RenderWindow addRoomWindow(sf::VideoMode(700, 800), "ADD Student:");

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

    std::cout << "Adding Room by Academic Officer" << std::endl;
    sf::Text inputPrompt("Enter Room Information", font, 50);
    inputPrompt.setPosition(65.0f, 60.0f);
    inputPrompt.setOutlineColor(sf::Color::Black);
    inputPrompt.setOutlineThickness(3);
    sf::Text resultText("", font, 30);
    resultText.setPosition(80.f, 380.f);
    resultText.setFillColor(sf::Color::Black);
    sf::String userInput;

    int roomNo = 0;
    string roomTelExt;
    int roomCapacity = 0;

    enum class InputState { ROOM_NO, ROOM_CAPACITY, TEL_EXT, };
    InputState currentState = InputState::ROOM_NO;

    bool inputCompleted = false;
    sf::RectangleShape roomNoBox(sf::Vector2f(250, 30));
    sf::RectangleShape roomCapacityBox(sf::Vector2f(250, 30));
    sf::RectangleShape roomTelextBox(sf::Vector2f(250, 30));

    roomNoBox.setOutlineColor(sf::Color::Black);
    roomCapacityBox.setOutlineColor(sf::Color::Black);
    roomTelextBox.setOutlineColor(sf::Color::Black);
    roomNoBox.setOutlineThickness(3);
    roomCapacityBox.setOutlineThickness(3);
    roomTelextBox.setOutlineThickness(3);

    sf::Text roomNoLabel("Room No. : ", font, 20);
    sf::Text roomCapacityLabel("Room Capacity: ", font, 20);
    sf::Text roomTelextLabel("Room Telephone Ext. : ", font, 20);

    sf::RectangleShape viewAddedRoom(sf::Vector2f(600.0f, 430.0f));
    viewAddedRoom.setPosition(50, 320);
    viewAddedRoom.setFillColor(sf::Color::White);
    viewAddedRoom.setOutlineColor(sf::Color::Black);
    viewAddedRoom.setOutlineThickness(3);

    roomNoLabel.setOutlineColor(sf::Color::Black);
    roomCapacityLabel.setOutlineColor(sf::Color::Black);
    roomTelextLabel.setOutlineColor(sf::Color::Black);
    roomNoLabel.setOutlineThickness(3);
    roomCapacityLabel.setOutlineThickness(3);
    roomTelextLabel.setOutlineThickness(3);

    roomNoBox.setPosition(280, 150);
    roomCapacityBox.setPosition(280, 200);
    roomTelextBox.setPosition(280, 250);

    roomNoLabel.setPosition(50, 150);
    roomCapacityLabel.setPosition(50, 200);
    roomTelextLabel.setPosition(50, 250);

    sf::Text inputText("", font, 22);
    inputText.setPosition(380, 250);
    inputText.setFillColor(sf::Color::Black);
    Room r;
    while (addRoomWindow.isOpen()) {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
            cout << EXIT_FAILURE << endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(5.0f, 5.0f);

        sf::Text roomNoText2("", font, 25);

        sf::Text roomCapacityText2("", font, 25);

        sf::Text roomTelextText2("", font, 25);

        roomNoText2.setFillColor(sf::Color::Black);
        roomCapacityText2.setFillColor(sf::Color::Black);
        roomTelextText2.setFillColor(sf::Color::Black);

        sf::Text roomNoText("", font, 20);

        sf::Text roomCapacityText("", font, 20);

        sf::Text roomTelextText("", font, 20);

        roomNoText.setFillColor(sf::Color::Black);
        roomCapacityText.setFillColor(sf::Color::Black);
        roomTelextText.setFillColor(sf::Color::Black);


        sf::Event event;
        while (addRoomWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                addRoomWindow.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode >= 32) {
                    userInput += static_cast<char>(event.text.unicode);
                }
                if (event.text.unicode == 8 && userInput.getSize() > 0) {
                    userInput.erase(userInput.getSize() - 1, 1);
                }
                if (event.text.unicode == 13) {
                    std::istringstream iss(userInput.toAnsiString());

                    switch (currentState) {
                    case InputState::ROOM_NO:
                        iss >> roomNo;
                        r.setroom_no(roomNo);
                        currentState = InputState::ROOM_CAPACITY;
                        userInput.clear();
                        break;
                    case InputState::ROOM_CAPACITY:
                        iss >> roomCapacity;
                        r.setcapacity(roomCapacity);
                        currentState = InputState::TEL_EXT;
                        userInput.clear();
                        break;
                    case InputState::TEL_EXT:
                        iss >> roomTelExt;
                        r.settel_ext(roomTelExt);
                        userInput.clear();

                        cout << "Room roomNo: " << r.getroom_no() << "\n";
                        cout << "roomCapacity: " << roomCapacity << "\n";
                        cout << "roomTelExt: " << roomTelExt << "\n";

                        std::ofstream fout("room.txt", std::ios_base::app);
                        if (fout.is_open()) {
                            fout << "\n";
                            fout << "Room No: " << roomNo << "\n"
                                << "Room Capacity: " << roomCapacity << "\n"
                                << "Room Telephone Ext.: " << roomTelExt << "\n\n";
                            fout.close();
                            resultText.setString("Room Information Stored in Room.txt!");
                        }
                        else {
                            resultText.setString("Error: Unable to open Room.txt for writing.");
                        }

                        currentState = InputState::ROOM_NO;

                        resultText.setString("Room Information Entered!");
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                addRoomWindow.close();
            }
            roomNoText.setPosition(290.f, 150.f);
            roomCapacityText.setPosition(290.f, 200.f);
            roomTelextText.setPosition(290.f, 250.f);

            roomNoText.setString(to_string(roomNo));
            roomCapacityText.setString(to_string(roomCapacity));
            roomTelextText.setString(roomTelExt);

            roomNoText2.setPosition(120.f, 450.f);
            roomCapacityText2.setPosition(120.f, 490.f);
            roomTelextText2.setPosition(120.f, 530.f);
            roomNoText2.setString("Room No: " + to_string(roomNo));
            roomCapacityText2.setString("Room Capacity: " + to_string(roomCapacity));
            roomTelextText2.setString("Room Telephone Ext.: " + roomTelExt);

            addRoomWindow.clear();

            addRoomWindow.draw(sprite);
            addRoomWindow.draw(roomNoBox);
            addRoomWindow.draw(roomCapacityBox);
            addRoomWindow.draw(roomTelextBox);

            addRoomWindow.draw(roomNoLabel);
            addRoomWindow.draw(roomCapacityLabel);
            addRoomWindow.draw(roomTelextLabel);
            addRoomWindow.draw(viewAddedRoom);
            addRoomWindow.draw(inputPrompt);
            addRoomWindow.draw(resultText);
            addRoomWindow.draw(roomNoText);
            addRoomWindow.draw(roomCapacityText);
            addRoomWindow.draw(roomTelextText);
            addRoomWindow.draw(roomNoText2);
            addRoomWindow.draw(roomCapacityText2);
            addRoomWindow.draw(roomTelextText2);
            addRoomWindow.display();
        }
    }
}
void displayStudentMenu(sf::RenderWindow& window)
{
    window.clear();
    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");
    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
        cout << EXIT_FAILURE << endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(5.0f, 0.4f);
   
    sf::Text studentText("Student Menu", font, 80);
    studentText.setFillColor(darkerYaleBlue);
    studentText.setPosition(80, 80);
    sf::Texture texture2;
    if (!texture2.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/logo.stt.png")) {
        cout << EXIT_FAILURE << endl;
    }

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setScale(0.55f, 0.6f);
    sprite2.setPosition((window.getSize().x - sprite2.getGlobalBounds().width) / 1.0,
        window.getSize().y - sprite2.getGlobalBounds().height);

    sf::RectangleShape viewExamButton(sf::Vector2f(300, 80));
    viewExamButton.setPosition(100, 200);
    viewExamButton.setFillColor(offWhiteColor);
    viewExamButton.setOutlineColor(darkerYaleBlue);
    viewExamButton.setOutlineThickness(10);
    sf::Text viewExamButtonText("View Exam Information", font, 26);
    viewExamButtonText.setPosition(110, 220);
    viewExamButtonText.setFillColor(sf::Color::Black);

    sf::RectangleShape viewRecordButton(sf::Vector2f(300, 80));
    viewRecordButton.setPosition(100, 320);
    viewRecordButton.setFillColor(offWhiteColor);
    viewRecordButton.setOutlineColor(darkerYaleBlue);
    viewRecordButton.setOutlineThickness(10);
    sf::Text viewRecordButtonText("View Student Record", font, 26);
    viewRecordButtonText.setPosition(110, 340);
    viewRecordButtonText.setFillColor(sf::Color::Black);

    window.clear(lightGray);
    window.draw(sprite);
    window.draw(sprite2);
    window.draw(studentText);
    window.draw(viewExamButton);
    window.draw(viewExamButtonText);
    window.draw(viewRecordButton);
    window.draw(viewRecordButtonText);
    window.display();
    while (window.isOpen())
    {
        int inp = 1;
        handleStudentAction(window, inp);
    }
}
void displayAcademicOfficerMenu(sf::RenderWindow& window)
{
    window.clear();
    
    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");
  
    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
        cout << EXIT_FAILURE << endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(5.0f, 0.4f);
    window.clear(lightGray);
    window.draw(sprite);

    sf::Texture texture2;
    if (!texture2.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/logo.ao1.png")) {
        cout << EXIT_FAILURE << endl;
    }

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setScale(0.53f, 0.565f);
    sprite2.setPosition((window.getSize().x - sprite2.getGlobalBounds().width) / 1.0,
        window.getSize().y - sprite2.getGlobalBounds().height);

    window.draw(sprite2);
    sf::Text officerText("Academic Officer Menu", font, 70);
    officerText.setPosition(70, 80);
    officerText.setFillColor(darkerYaleBlue);
    window.draw(officerText);

    sf::RectangleShape viewExamsButton(sf::Vector2f(300, 70));
    viewExamsButton.setPosition(100, 200);
    viewExamsButton.setFillColor(offWhiteColor);
    viewExamsButton.setOutlineColor(darkerYaleBlue);
    viewExamsButton.setOutlineThickness(10);
    sf::Text viewExamsButtonText("View Exams on Date", font, 26);
    viewExamsButtonText.setPosition(110, 210);
    viewExamsButtonText.setFillColor(sf::Color::Black);

    sf::RectangleShape addStudentButton(sf::Vector2f(300, 70));
    addStudentButton.setPosition(100, 310);
    addStudentButton.setFillColor(offWhiteColor);
    addStudentButton.setOutlineColor(darkerYaleBlue);
    addStudentButton.setOutlineThickness(10);
    sf::Text addStudentButtonText("Add Student", font, 26);
    addStudentButtonText.setPosition(110, 320);
    addStudentButtonText.setFillColor(sf::Color::Black);

    sf::RectangleShape addInvigilatorButton(sf::Vector2f(300, 70));
    addInvigilatorButton.setPosition(100, 420);
    addInvigilatorButton.setFillColor(offWhiteColor);
    addInvigilatorButton.setOutlineColor(darkerYaleBlue);
    addInvigilatorButton.setOutlineThickness(10);
    sf::Text addInvigilatorButtonText("Add Invigilator", font, 26);
    addInvigilatorButtonText.setPosition(110, 430);
    addInvigilatorButtonText.setFillColor(sf::Color::Black);

    sf::RectangleShape addExamButton(sf::Vector2f(300, 70));
    addExamButton.setPosition(100, 530);
    addExamButton.setFillColor(offWhiteColor);
    addExamButton.setOutlineColor(darkerYaleBlue);
    addExamButton.setOutlineThickness(10);
    sf::Text addExamButtonText("Generate Exam Timetable", font, 25);
    addExamButtonText.setPosition(110, 540);
    addExamButtonText.setFillColor(sf::Color::Black);

    sf::RectangleShape addCourseButton(sf::Vector2f(300, 70));
    addCourseButton.setPosition(100, 640);
    addCourseButton.setFillColor(offWhiteColor);
    addCourseButton.setOutlineColor(darkerYaleBlue);
    addCourseButton.setOutlineThickness(10);
    sf::Text addCourseButtonText("Add Course", font, 26);
    addCourseButtonText.setPosition(110, 650);
    addCourseButtonText.setFillColor(sf::Color::Black);

    sf::RectangleShape addRoomButton(sf::Vector2f(300, 70));
    addRoomButton.setPosition(100, 750);
    addRoomButton.setFillColor(offWhiteColor);
    addRoomButton.setOutlineColor(darkerYaleBlue);
    addRoomButton.setOutlineThickness(10);
    sf::Text addRoomButtonText("Add Room", font, 26);
    addRoomButtonText.setPosition(110, 760);
    addRoomButtonText.setFillColor(sf::Color::Black);

    window.draw(viewExamsButton);
    window.draw(viewExamsButtonText);
    window.draw(addStudentButton);
    window.draw(addStudentButtonText);
    window.draw(addInvigilatorButton);
    window.draw(addInvigilatorButtonText);
    window.draw(addExamButton);
    window.draw(addExamButtonText);
    window.draw(addCourseButton);
    window.draw(addCourseButtonText);
    window.draw(addRoomButton);
    window.draw(addRoomButtonText);

    window.display();
    while (window.isOpen())
    {
        int ip = 2;
        handleAcademicOfficerAction(window, ip);
    }
}
void handleStudentAction(sf::RenderWindow& window, int& input)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (input == 1)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                window.clear();
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 200 && mousePos.y <= 280)
                {
                    Student student;
                    student.viewExamInfo();
                }

                else if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 320 && mousePos.y <= 400)
                {
                    Student student;
                    student.viewStudentRecord();
                }

                }
            }
        }
    }
void handleInvigilatorAction(sf::RenderWindow& window, int& input)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (input == 3) // Assuming 3 is the identifier for invigilator
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                window.clear();
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 200 && mousePos.y <= 270)
                {
                    Invigilator invigilator;
                    invigilator.markAttendance();
                }
            }
        }
    }
}
void displayInvigilatorMenu(sf::RenderWindow& window)
{
    window.clear();

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
        cout << EXIT_FAILURE << endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(5.0f, 0.4f);

    sf::Texture texture2;
    if (!texture2.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/logo_invigilator.png")) {
        cout << EXIT_FAILURE << endl;
    }

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setScale(2.2f, 2.2f);
    sprite2.setPosition((window.getSize().x - sprite2.getGlobalBounds().width) / 1.0,
        window.getSize().y - sprite2.getGlobalBounds().height);

    window.clear(lightGray);
    window.draw(sprite);
    window.draw(sprite2);

    sf::Text invigilatorText("Invigilator Menu", font, 70);
    invigilatorText.setPosition(70, 80);
    invigilatorText.setFillColor(darkerYaleBlue);
    window.draw(invigilatorText);


    sf::RectangleShape makAttendanceButton(sf::Vector2f(300, 80));
    makAttendanceButton.setPosition(100, 200);
    makAttendanceButton.setFillColor(offWhiteColor);
    makAttendanceButton.setOutlineColor(darkerYaleBlue);
    makAttendanceButton.setOutlineThickness(10);
    sf::Text makAttendanceButtonText("Mark Attendance", font, 26);
    makAttendanceButtonText.setPosition(110, 220);
    makAttendanceButtonText.setFillColor(sf::Color::Black);


    window.draw(makAttendanceButton);
    window.draw(makAttendanceButtonText);
    window.display();
    while (window.isOpen())
    {
        int inp = 3; 
        handleInvigilatorAction(window, inp); 
    }
}
int handleInstructorAction(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return 0; // Close the program
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 200 && mousePos.y <= 280)
            {
                AddExam* exam = new Exam;
                exam->addExam();
            }
            else if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 320 && mousePos.y <= 400)
            {
                Instructor i;
                //i.markExam();
                return 2;
            }
            else if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 440 && mousePos.y <= 520)
            {
                return 3; // "Assign Grade" button pressed
            }
        }

        // Handle other events as needed
    }

    return 0; // No relevant event detected
}
void displayInstructorMenu(sf::RenderWindow& window)
{
    window.clear();

    sf::Font font;
    font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
        cout << EXIT_FAILURE << endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(5.0f, 0.4f);

    sf::Texture texture2;
    if (!texture2.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/logo_instructor.png")) {
        cout << EXIT_FAILURE << endl;
    }

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setScale(0.7f, 0.8f);
    sprite2.setPosition((window.getSize().x - sprite2.getGlobalBounds().width) / 1.0,
        window.getSize().y - sprite2.getGlobalBounds().height);

    window.clear(lightGray);
    window.draw(sprite);
    window.draw(sprite2);

    sf::Text instructorText("Instructor Menu", font, 70);
    instructorText.setPosition(70, 80);
    instructorText.setFillColor(darkerYaleBlue);
    window.draw(instructorText);

    // Create "Create Exam" button
    sf::RectangleShape createExamButton(sf::Vector2f(300, 80));
    createExamButton.setPosition(100, 200);
    createExamButton.setFillColor(offWhiteColor);
    createExamButton.setOutlineColor(darkerYaleBlue);
    createExamButton.setOutlineThickness(10);
    sf::Text createExamButtonText("Add Exam", font, 26);
    createExamButtonText.setPosition(110, 220);
    createExamButtonText.setFillColor(sf::Color::Black);

    // Create "Mark Exams" button
    sf::RectangleShape markExamsButton(sf::Vector2f(300, 80));
    markExamsButton.setPosition(100, 320);
    markExamsButton.setFillColor(offWhiteColor);
    markExamsButton.setOutlineColor(darkerYaleBlue);
    markExamsButton.setOutlineThickness(10);
    sf::Text markExamsButtonText("Mark Exams", font, 26);
    markExamsButtonText.setPosition(110, 340);
    markExamsButtonText.setFillColor(sf::Color::Black);

    // Create "Assign Grade" button
    sf::RectangleShape assignGradeButton(sf::Vector2f(300, 80));
    assignGradeButton.setPosition(100, 440);
    assignGradeButton.setFillColor(offWhiteColor);
    assignGradeButton.setOutlineColor(darkerYaleBlue);
    assignGradeButton.setOutlineThickness(10);
    sf::Text assignGradeButtonText("Assign Grade", font, 26);
    assignGradeButtonText.setPosition(110, 460);
    assignGradeButtonText.setFillColor(sf::Color::Black);

    window.draw(createExamButton);
    window.draw(createExamButtonText);
    window.draw(markExamsButton);
    window.draw(markExamsButtonText);
    window.draw(assignGradeButton);
    window.draw(assignGradeButtonText);
    window.display();

    while (window.isOpen())
    {
        int inp = 4; 
        handleInstructorAction(window);
    }
}


void handleAcademicOfficerAction(sf::RenderWindow& window, int& input)
{
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (input == 2)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 200 && mousePos.y <= 270)
                    {
                        Exam exam;
                        exam.viewExamOnDate();
                    }


                    if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 310 && mousePos.y <= 380)
                    {
                        Student student;
                        student.AddStudent();
                    }

                    if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 420 && mousePos.y <= 490)
                    {
                        Invigilator invigilator;
                        invigilator.addInvigilator();
                    }
            

                    if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 530 && mousePos.y <= 600)
                    {
                        AcademicOfficer ao;
                        ao.generateTimeTable();
                    }

                    if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 640 && mousePos.y <= 710)
                    {
                        Course course;
                        course.addCourse();
                    }

                    if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 750 && mousePos.y <= 820)
                    {
                        Room room;
                        room.addRoom();
                    }

                }
            }
        }
    }

int main()
{
    int input = 0;

    sf::RenderWindow window(sf::VideoMode(950, 850), "Exam Management System");

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/color.png")) {
       
        return EXIT_FAILURE;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(5.0f, 0.4f);

    sf::Texture texture2;
    if (!texture2.loadFromFile("C:/Users/hassa/source/repos/Project3/Project3/logo_exam.png")) {
     
        cout << EXIT_FAILURE << endl;
    }


    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setScale(0.8f, 0.75f);
    sprite2.setPosition((window.getSize().x - sprite2.getGlobalBounds().width) / 0.6,
        window.getSize().y - sprite2.getGlobalBounds().height);
    System s;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
              
                if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 200 && mousePos.y <= 280)
                {
                    input = 1;
                    if (s.authentication(window, "student"))
                    {
                        displayStudentMenu(window);
                    }
                }
                if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 320 && mousePos.y <= 400)
                {
                    input = 2;
                    if (s.authentication(window, "academic_officer"))
                    {
                        displayAcademicOfficerMenu(window);
                    }
                }
                if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 440 && mousePos.y <= 520)
                {
                    input = 3;
                    if (s.authentication(window, "invigilator"))
                    {
                        displayInvigilatorMenu(window);
                    }
                }
                if (mousePos.x >= 100 && mousePos.x <= 400 && mousePos.y >= 560 && mousePos.y <= 640)
                {
                    input = 4;
                    if (s.authentication(window, "instructor"))
                    {
                        displayInstructorMenu(window);
                    }
                }

            }
        }

        window.clear(lightGray);

        window.draw(sprite);
        window.draw(sprite2);
        sf::Font font;
        font.loadFromFile("C:/Users/hassa/Downloads/SuperCorn-X3xGg.ttf");  

        sf::Text titleText("Exam Management System", font, 60);
        titleText.setPosition(80, 80);
        titleText.setFillColor(darkerYaleBlue);
        window.draw(titleText);

        sf::RectangleShape studentButton(sf::Vector2f(300, 80));
        studentButton.setPosition(100, 200);
        studentButton.setFillColor(offWhiteColor);
        studentButton.setOutlineColor(darkerYaleBlue);
        studentButton.setOutlineThickness(10);
        sf::Text studentButtonText("Student", font, 26);
        studentButtonText.setPosition(110, 220);
        studentButtonText.setFillColor(sf::Color::Black);

        sf::RectangleShape academicButton(sf::Vector2f(300, 80));
        academicButton.setPosition(100, 320);
        academicButton.setFillColor(offWhiteColor);
        academicButton.setOutlineColor(darkerYaleBlue);
        academicButton.setOutlineThickness(10);
        sf::Text academicButtonText("Academic Officer", font, 26);
        academicButtonText.setPosition(110, 340);
        academicButtonText.setFillColor(sf::Color::Black);

        sf::RectangleShape invigilatorButton(sf::Vector2f(300, 80));
        invigilatorButton.setPosition(100, 440);
        invigilatorButton.setFillColor(offWhiteColor);
        invigilatorButton.setOutlineColor(darkerYaleBlue);
        invigilatorButton.setOutlineThickness(10);
        sf::Text invigilatorButtonText("Invigilator", font, 26);
        invigilatorButtonText.setPosition(110, 460);
        invigilatorButtonText.setFillColor(sf::Color::Black);

        sf::RectangleShape instructorButton(sf::Vector2f(300, 80));
        instructorButton.setPosition(100, 560);
        instructorButton.setFillColor(offWhiteColor);
        instructorButton.setOutlineColor(darkerYaleBlue);
        instructorButton.setOutlineThickness(10);
        sf::Text instructorButtonText("Instructor", font, 26);
        instructorButtonText.setPosition(110, 580);
        instructorButtonText.setFillColor(sf::Color::Black);

        window.draw(studentButton);
        window.draw(studentButtonText);
        window.draw(academicButton);
        window.draw(academicButtonText);
        window.draw(invigilatorButton);
        window.draw(invigilatorButtonText);
        window.draw(instructorButton);
        window.draw(instructorButtonText);
        window.display();
   
     
    }
    
    return 0;
}


