#ifndef ADDEXAM_H
#define ADDEXAM_H
#include<string>
#include<sstream>
using namespace std;
class AddExam
{
public:

	virtual void addExam() = 0;
	virtual string GetExamDate() = 0;
	virtual string Print() = 0;
};
#endif