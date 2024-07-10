#include<iostream>
#include<sstream>
#include"Printt.h"
using namespace std;
class Room: public Printable {
public:
    int room_no;
    int capacity;
    string tel_ext;

    Room()
    {
        room_no = capacity = 0;
        tel_ext = " ";
    }
    Room(int no, int cap, int ext)
    {
        room_no = no;
        capacity = cap;
        tel_ext = ext;
    }
    string Print() override
    {
        ostringstream oss;
       oss << "\nRoom no: " << room_no;
       oss << "\nCapacity: " << capacity;
       oss << "\nTelephone Extension: " << tel_ext;
       return oss.str();
    }
    void edit_room(int no)
    {
        cout << "\nEnter room no: ";
        cin >> room_no;
        cout << "\nEnter capacity:";
        cin >> capacity;
        cout << "Enter Telephone Extension: ";
        cin >> tel_ext;
    }
    int getroom_no() { return room_no; }
    int getcapacity() { return capacity; }
  string gettel_ext() { return tel_ext; }
    void setroom_no(int no) { room_no = no; }
    void setcapacity(int cap) { capacity = cap; }
    void settel_ext(string tel) { tel_ext = tel; }
    friend void operator <<(ostream& out, const Room& r);
    friend void operator >>(istream& in, Room& r);
    void addRoom();
   
};
void  operator <<(ostream& out, const Room& r) {
    out << r.room_no << endl;
    out << r.capacity << endl;
    out << r.tel_ext << endl;
}
void operator >>(istream& in, Room& r) {
    in >> r.room_no;
    in >> r.capacity;
    in >> r.tel_ext;
}