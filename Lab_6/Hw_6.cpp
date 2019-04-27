#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06012_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the list:
{"include", "for", "while", "goto", "string"} even in the comments */
/**
 * Hiện thực hàm đệ quy đảo ngược thứ tự của các ký tự có chỉ số từ [begin đến end] 
 */
void swap(char &a, char &b)
{
    char c = a;
    a = b;
    b = c;
}

void Reverse(char *text, int numberOfElements, int i, int from)
{
    if (i > numberOfElements / 2)
    {
        return;
    }
    else
    {
        swap(text[from + i - 1], text[from + numberOfElements - i]);
        Reverse(text, numberOfElements, i + 1, from);
    }
}

void revert(char *text, int fromPosition, int toPosition)
{
    Reverse(text, toPosition - fromPosition + 1, 1,fromPosition);
}

int main(int argc, char *argv[])
{
   ifstream fileIn("inp.txt",ios::in);
        string line;
        getline(fileIn, line);
        int beginPos = stoi(line);
        getline(fileIn, line);
        int endPos = stoi(line);
        getline(fileIn, line);
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        revert(cstr, beginPos, endPos);
        cout << cstr;
        fileIn.close();
        delete[] cstr;
        system("pause");
    // Endsection: read testcase
    //------------------------------------
    return 0;
}
