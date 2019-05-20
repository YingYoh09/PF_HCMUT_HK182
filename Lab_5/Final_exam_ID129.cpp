#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05008_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

/* Write the function returning a double number */
double weight(char *text, double weightVector[])
{
    double res = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        res += weightVector[text[i] - 'A'];
    }
    return res;
}
int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        string line;
        double weightVector[26];
        for (char i = 'A'; i <= 'Z'; i++)
        {
            getline(fileIn, line);
            weightVector[i - 'A'] = stof(line);
        }
        getline(fileIn, line);
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        cout << setprecision(4) << fixed << weight(cstr, weightVector);
        fileIn.close();
        delete[] cstr;
        system("pause");
    return 0;
}
