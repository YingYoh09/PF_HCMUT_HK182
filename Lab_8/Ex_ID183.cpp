/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 08: 08002_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun May 05 16:04:59 2019

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#define FILENAME "08002_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of the words in the list
{"..", "~/", "expect"} even in the comment */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/// Student may implement something as need

void process(const char *fileName)
{

    ifstream fin(fileName, ios::in);
    int word = 0;
    while (!fin.eof())
    {
        string s;
        getline(fin, s);
        s = s + " ";
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] != ' ' && s[i+1]== ' '){
                word++;
            }
        }
        
    }
    cout << word;
    fin.close();
}

int main(int argc, char *argv[])
{
    process("inp.txt");
    system("pause");
    return 0;
}
