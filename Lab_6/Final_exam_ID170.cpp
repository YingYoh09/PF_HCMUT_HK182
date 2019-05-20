#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;
bool isPrimeNumber(int a)
{
    if (a < 2)
        return 0;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int nextPosition(char *numStr, int currentIndex){
    if (currentIndex == strlen(numStr) || numStr[currentIndex] == ','){
        return currentIndex - 1;
    }
    else
    {
        return nextPosition(numStr, currentIndex + 1);
    }
}
void conv(char *tmp, char *numStr,int a,int b)
{
    for (int i = a; i <= b; i++)
    {
        tmp[i - a] = numStr[i];
    }
}
void mul(char *numStr, int currentIndex, long long result)
{
    if (currentIndex >= strlen(numStr)){
        cout << result;
    }
    else
    {
        int ne = nextPosition(numStr, currentIndex);
        char *tmp = new char [ne - currentIndex + 2];
        conv(tmp, numStr, currentIndex, ne);
        int numtemp = round(atof(tmp));
        if (!isPrimeNumber(numtemp))
        {
            delete[] tmp;
            mul(numStr, strlen(numStr), result);
        }
        else{
            result *= numtemp;
            delete[] tmp;
            mul(numStr, ne+3, result);
        }
    }
}
int main(int argc, char *argv[])
{
   ifstream fileIn("inp.txt",ios::in);
        string line;
        getline(fileIn, line);
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        mul(cstr, 0, 1);
        fileIn.close();
        delete[] cstr;
        system("pause");
}