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
/* Viết chương trình chuẩn hóa văn bản
void processText(char* text, char** priText)
Các ký tự viết hoa sai chỗ được chỉnh lại, sau các dấu chấm câu cần viết hoa (gồm dấu chấm, dấu hai chấm, chấm hỏi, chấn than), các từ tên riêng viết hoa theo quy định.
Input: Một chuỗi, tập từ tên riêng.
Ví dụ:
testcase:
CHOE RyOng-hAE la pHU ta cua KiM JOng-un tU kHi Ong Kim cHUA Len NAm qUyEn vA dUoC nhan XeT lA NgUOi rat tu tin.
Choe Ryong-hae
Kim Jong-un
ong Kim
expect:
Choe Ryong-hae la phu ta cua Kim Jong-un tu khi ong Kim chua len nam quyen va duoc nhan xet la nguoi rat tu tin.
Trong đó, dòng đầu của testcase là đoạn văn bản, các dòng tiếp theo trong testcase mỗi dòng là một tên riêng */

bool isInText(char *text, char *thuong, int loc){
    for (int i = loc; i < loc + strlen(thuong); i++)
    {
        if (text[i] != thuong[i-loc])
            return 0;
    }
    return 1;
}

void process(char *text, char **priText, int numberOfPriText)
{

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i]<= 'Z')
            text[i] = char(text[i] + 32);
    }

    char **thuong = new char*[numberOfPriText];
    for (int i = 0; i < numberOfPriText; i++)
    {
        thuong[i] = new char[strlen(priText[i])];
        for (int j = 0; j < strlen(priText[i]);j++){
            switch (priText[i][j])
            {
            case 'A'...'Z':
                thuong[i][j] = char (priText[i][j] + 32);
                break;
            default:
                thuong[i][j] = priText[i][j];
                break;
            }
        }
        thuong[i][strlen(priText[i])] = NULL;
    }
    for (int i = 0; i < numberOfPriText;i++){
        for (int j = 0; j < strlen(text) - strlen(thuong[i]); j++)
        {
            if (isInText(text,thuong[i],j)){
                int point = j;
                for (j;j < point + strlen(thuong[i]);j++)
                {
                    text[j] = priText[i][j - point];
                }
                
            }
        }
    }
    for (int i = 0; i < strlen(text) - 1; i++)
    {
        switch (text[i])
        {
            case ':':
            case '.':
            case '?':
            case '!':
                if (text[i+1] <= 'z' && text[i+1] >= 'a')
                    text[i + 1] = char(text[i + 1] - 32);
                break;
            default:            
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
