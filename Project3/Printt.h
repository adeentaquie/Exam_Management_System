#ifndef PRINTABLE_H
#define PRINTABLE_H
#include<string>
#include<sstream>
using namespace std;
class Printable {
public:
    virtual string Print() = 0;
};
#endif