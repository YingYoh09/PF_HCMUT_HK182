#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05003_sol.cpp"
using namespace std;
/* Please note that your code must not contain any of words in
 {"string", "include"}; */

//---------------------------------------------------------
// Begin implementation
//---------------------------------------------------------

/* Định nghĩa: Khoảng cách Hamming giữa hai chuỗi S1 và S2 (có độ dài 


bằng nhau) là số lần thay thế ký tự tối thiểu để chuyển đổi một chuỗi 


thành chuỗi khác.



Hiện thực hàm int hamming(char* str1, char* str2) để tính khoảng cách Hamming của hai chuỗi?



Input: Hai chuỗi S1, S2



testcase:


A C C G A C T A C T A G


A C C C A C T A C A A G


expect:


2 */
void hamming(char *str1, char *str2)
{
    int length = strlen(str1);
    int res = 0;
    for (int i = 0; i < length;i++){
        if (str1[i] != str2[i]) res++;
    }
    cout << res;
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
        hamming(cstr1, cstr2);
        delete[] cstr1;
        delete[] cstr2;
        fileIn.close();
    // Endsection: read testcase
    system("pause");
    //------------------------------------
    return 0;
}