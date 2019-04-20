/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 05: 05007_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun Apr 14 18:40:42 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05007_sol.cpp"
using namespace std;

/* Please note that your code MUST NOT contain any words in
{"include", "string", "strstr"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/// Students may define some functions as need
/* Write the code to process the text and then print to screen */


bool isInText(int plength, char *pattern,char *text, int location)
{
    for (int i = location; i < location + plength; i++)
    {
        if (pattern[i-location] != text[i])
            return 0;
    }
    return 1;
}


void process(char *text, char **priText, int numberOfPriText)
{
    int length = strlen(text);
    char *res = new char[length];
    int reslength = 0;
    for (int i = 0; i < length; i++)
    {
        int z = text[i];
        if (z >= int('A') && z <= int('Z'))
        {
            text[i] = char(text[i] + int('a') - int('A'));
        }
        else
            text[i] = text[i];
    }
    char **thuong = new char *[numberOfPriText];
    for (int i = 0; i < numberOfPriText; i++)
    {
        thuong[i] = new char[strlen(priText[i]) + 1];
        strcpy(thuong[i], priText[i]);  
        for (int j = 0; j < strlen(thuong[i]); j++)
        {
            int z = priText[i][j];
            if (z >= int('A') && z <= int('Z'))
            {
                thuong[i][j] = char(priText[i][j] + int('a') - int('A'));
            }
            else
                thuong[i][j] = priText[i][j];
        }
    }
    for (int k = 0; k < numberOfPriText; k++){
        for (int i = 0; i < length; i++)
        {
            if (isInText(strlen(thuong[k]), thuong[k], text, i))
            {
                for (int j = i; j < i + strlen(thuong[k]); j++)
                {
                    text[j] = priText[k][j - i];
                }
            }
        }
    }
    for (int i = 0; i < length - 1; i++)
    {
        switch (text[i])
        {
        case '!':
        case '?':
        case ':':
        case '.':
            if (int(text[i + 1]) >= int('a') && int(text[i + 1]) <= int('z'))
            {
                text[i+1] = char(int(text[i+1]) + int('A') - int('a'));
            }
            break;

        }
    }
    cout << text;
}

int main(int argc, char *argv[])
{
   ifstream fileIn("inp.txt",ios::in);
        string line;
        getline(fileIn, line);
        char *text = new char[line.length() + 1];
        strcpy(text, line.c_str());
        getline(fileIn, line);
        int numberOfPriText = stoi(line);
        char **priText = new char *[numberOfPriText];
        for (int i = 0; i < numberOfPriText; i++)
        {
            getline(fileIn, line);
            priText[i] = new char[line.length() + 1];
            strcpy(priText[i], line.c_str());
        }
        process(text, priText, numberOfPriText);
        fileIn.close();
        delete[] text;
        for (int i = 0; i < numberOfPriText; i++)
            delete[] priText[i];
        delete[] priText;
        system("pause");
    return 0;
}
