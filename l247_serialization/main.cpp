//
//  main.cpp
//  l247_serialization
//
//  Created by Hongbo Niu on 2022-11-28.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    int roll;
    string branch;

    friend ofstream& operator<<(ofstream& ofs, Student &s);
    friend ifstream& operator>>(ifstream& ifs, Student &s);
};

ofstream& operator<<(ofstream& ofs, Student &s)
{
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Student &s)
{
    while(!ifs.eof())
    {
        ifs>>s.name>>s.roll>>s.branch;
        cout<<"Name:"<<s.name<<" Roll:"<<s.roll<<" Branch:"<<s.branch<<endl;
    }
    return ifs;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Student s1;
    s1.name="Khan"; s1.roll=23; s1.branch="CS";
    
    ofstream ofs("Student.txt", ios::app);
    ofs<<s1;
    ofs.close();
    
    ifstream ifs("Student.txt");
    if(ifs)
    {
        ifs>>s1;
    }
    ifs.close();
    
    return 0;
}
