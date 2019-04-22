/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 05: 05004_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat Apr 13 21:11:42 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;

/* Please note that your code must not contain any of words
in the array: {"string", "include"} or you will loss all the testcase*/

// Begin implementation

/*
Viết chương trình xóa các ký tự mà số lần xuất hiện nhỏ hơn giá trị p.
Input: Chuỗi ký tự, giá trị p
Hiện thực hàm void process(char* text, int p);
 */
void process(char *text, int p)
{
    int len = strlen(text);
    int Ch[1000]{};
    for (int i = 0; i < len; i++)
    {
        Ch[text[i]]++;
    }
    for (int i = 0; i < len; i++)
    {
        if (Ch[text[i]] >= p) {
            cout << text[i];
        }
    }
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        string str;
        if (!fileIn.eof())
            getline(fileIn, str);
        int p;
        fileIn >> p;
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        process(cstr, p);
        delete[] cstr;
        fileIn.close();
        system("pause");
        return 0;
}
