/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 05: 05005_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun Apr 14 09:46:43 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05005_sol.cpp"
using namespace std;

/* Please note that your code MUST NOT contain any word in 
{"string", "strstr", "strpbrk", "strchr", "memchr", "include"}
even in the comments */
//----------------------------------------------------------------
// Begin implementation
//----------------------------------------------------------------
/// Student may define some more functions as need.
/* Write the function returning integer value */

bool isInText(int plength, char *pattern,char *text, int location)
{
    for (int i = location; i < location + plength; i++)
    {
        if (pattern[i-location] != text[i])
            return 0;
    }
    
    return 1;
}

int count(char *pattern, char *text)
{
    int plength = strlen(pattern);
    int tlength = strlen(text);
    int res=0;
    for (int i = 0; i < tlength - plength+1; i++){
        if (isInText(plength, pattern, text, i))
            res++;
    }
    return res;
}

bool codeCheck()
{
    const char *forbiddenKeyword[] = {"string", "strstr", "strpbrk", "strchr", "memchr", "include"};
    fstream ifs;
    ifs.open("main.cpp", ios::in);
    if (ifs.fail())
        ifs.open(FILENAME, ios::in);
    if (ifs.fail())
        return true;
    ifs.seekg(0, ifs.end);
    int fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char *fileContent = new char[fileSize];
    ifs.read(fileContent, fileSize);
    ifs.close();
    *strstr(fileContent, "bool codeCheck() {") = '\0';
    char *todoSegment = strstr(fileContent, "// Begin implementation");
    int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char *);
    for (int i = 0; i < numberOfForbiddenKeyword; i++)
    {
        if (strstr(todoSegment, forbiddenKeyword[i]))
            return false;
    }
    delete[] fileContent;
    return true;
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        string str1, str2;
        if (!fileIn.eof())
            getline(fileIn, str1);
        if (!fileIn.eof())
            getline(fileIn, str2);
        char *cstr1 = new char[str1.length() + 1];
        strcpy(cstr1, str1.c_str());
        char *cstr2 = new char[str2.length() + 1];
        strcpy(cstr2, str2.c_str());
        cout << count(cstr1, cstr2);
        delete[] cstr1;
        delete[] cstr2;
        fileIn.close();
    system("pause");
    return 0;
}
