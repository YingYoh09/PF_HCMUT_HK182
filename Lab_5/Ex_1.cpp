/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 05: 05001_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat Apr 13 08:28:28 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <cstring>
#define FILENAME "05001_sol.cpp"
using namespace std;

/* Please note that your code must not contain any of words in
 {"string", "include"}; */

//---------------------------------------------------------
// Begin implementation
//---------------------------------------------------------

/* Write the code to print out the processed text*/
void process(char *text)
{
    int length = 0;
    while (text[length] != '\0')
        length++;
    char *res = new char[length];
    int reslength = 0;
    for (int i = 0; i < length; i++)
    {
        int z = text[i];
        if (z >= int('a') && z <=int('z'))
            res[reslength++] = text[i];
        if (z >= int('A') && z <= int('Z'))
            res[reslength++] = char(text[i] + int('a') - int('A'));
        if (text[i] == '.')
            res[reslength++] = ' ';
    }
    for (int i = 0; i < reslength; i++)
    {
        cout << res[i];
    }
}

bool codeCheck()
{
    const char *forbiddenKeyword[] = {"string", "include"};
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
        string inStr;
        string line;
        int lineCount = 0;
        while (!fileIn.eof())
        {
            lineCount++;
            getline(fileIn, line);
            inStr += line;
        }
        fileIn.close();
        char *inpText = new char[inStr.length() + 1];
        strcpy(inpText, inStr.c_str());
        process(inpText);
        delete[] inpText;
        // Endsection: read testcase
        //------------------------------------
        system("pause");
        return 0;
}
