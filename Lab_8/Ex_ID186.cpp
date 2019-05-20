/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 08: 08005_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Mon May 06 01:55:17 2019

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "08005_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of words in the list:
{"..", "~/", "expect"} event in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

#pragma region Student

/**
 * Student class definition
*/
class Student
{
    int id;
    char *name;
    float gpa;

public:
    Student(int _id, const char *_name, float _gpa);
    Student(const Student &obj);
    Student &operator=(const Student &obj);
    ~Student();
    void print();
    friend void binWrite(const Student &s, const char *fileName);
};

/**
 * Student class implementations
*/

Student::Student(int _id, const char *_name, float _gpa)
{
    this->id = _id;
    this->gpa = _gpa;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

Student::Student(const Student &obj)
{
    this->id = obj.id;
    this->gpa = obj.gpa;
    this->name = new char[strlen(obj.name) + 1];
    strcpy(this->name, obj.name);
}

Student &Student::operator=(const Student &obj)
{
    this->id = obj.id;
    this->gpa = obj.gpa;
    this->name = new char[strlen(obj.name) + 1];
    strcpy(this->name, obj.name);
    return *this;
}

Student::~Student()
{
    delete[] this->name;
}

void Student::print()
{
    cout << "------------------------------" << endl;
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "GPA: " << this->gpa << endl;
    cout << "------------------------------";
}

#pragma endregion Student

/**
 * Function that reads the text file and then returns a Student object
*/
Student textRead(const char *fileName)
{
    ifstream fin(fileName, ios::in);
    string s;
    getline(fin, s);
    int i = 0;
    while (s[i] != ','){
        i++;
    }
    int ID = stoi(s.substr(0, i));
    i++;
    int j = i;
    while (s[i] != ',')
    {
        i++;
    }
    string name = s.substr(j, i - j);
    i++;
    float gpa = stof(s.substr(i, s.length() - i));
    return Student(ID, name.c_str(), gpa);
    fin.close();
}

/**
 * Friend function that writes the object into binary file
*/
void binWrite(const Student &s, const char *fileName){
    ofstream ofs(fileName, ios::binary);
    ofs.write((char*)&s.id, sizeof(int));
    int len = strlen(s.name);
    ofs.write((char*)&len, sizeof(int));
    ofs.write(s.name, len * sizeof(char));
    ofs.write((char*) &s.gpa, sizeof(float));
    ofs.close();
}

/**
 * Function reads the data and then returns the Student object from binary file
*/
Student binRead(const char *fileName)
{
    fstream ifs;
    ifs.open(fileName, ios::in | ios::binary);
    if (ifs.fail())
        throw "File not found.";
    int id;
    int nameLen;
    float gpa;
    char *name;
    ifs.read((char *)&id, sizeof(int));
    ifs.read((char *)&nameLen, sizeof(int));
    name = new char[nameLen + 1];
    ifs.read(name, nameLen * sizeof(char));
    name[nameLen] = '\0';
    ifs.read((char *)&gpa, sizeof(float));
    ifs.close();
    Student res(id, name, gpa);
    delete[] name;
    return res;
}

void process(const char *fileName)
{
    Student s = textRead(fileName);
    binWrite(s, "student.bin");
    binRead("student.bin").print();
}

int main(int argc, char *argv[])
{
    process("inp.txt");
    system("pause");
    return 0;
}
