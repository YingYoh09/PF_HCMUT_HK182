/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 05: 05006_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun Apr 14 14:04:05 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05006_sol.cpp"
using namespace std;

/* Please note that your code MUST NOT contain any of words in
{"include", "string"}; even in the comments or variables name*/

/*Viết chương trình xóa tất cả các số nguyên âm của một chuỗi đã biết trước


Input: Chuỗi
Example: 
Input: "Chuoi-122t2ri"
=> Output: "Chuoit2ri"
Input: "Chuoi-122.22ri" 
=> Output: "Chuoi.22ri"
Input: "Chuoi--122.22ri" 
=> Output: "Chuoi-.22ri"
*/

// Student may define some function as need

/* Write the code to process the text and then print to screen */
void process(char *inputText)
{
    int len = strlen(inputText);
    bool *isRemoved = new bool[len + 1];
    int i = 0;
    for (i; i < len - 1;i++){
        if ('-' == inputText[i] && inputText[i+1] <='9' && inputText[i+1] >='0'){
            int j = i + 1;
            bool iszero = 1;
            for (j; j < len && inputText[j] <= '9' && inputText[j] >= '0';j++)
            {
                if (inputText[j] != '0')
                    iszero = 0;
            }
            if (!iszero) {
                for (i; i < j;i++){
                    isRemoved[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (!isRemoved[i])
            cout << inputText[i];
    }
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        string line;
        if (!fileIn.eof())
            getline(fileIn, line);
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        process(cstr);
        fileIn.close();
        delete[] cstr;
        system("pause");
    return 0;
}