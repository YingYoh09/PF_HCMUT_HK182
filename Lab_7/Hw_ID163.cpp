#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07001b_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the list
{"include", "string"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer
{
    int value;

public:
    Integer(double d);
    char *toString(char *&c);
    //Prototypes only
};

Integer::Integer(double d)
{
    value = d;
}

char *Integer::toString(char *&c)
{
    if (value == 0){
        c = new char[2];
        c[0] = '0';
        c[1] = '\0';
        return c;
    }
    int scs = 0, i = value;
    for (scs; i != 0; scs++)
    {
        i = i / 10;
    }
    c = new char[scs + 3];
    if (value < 0)
    {
        scs++;
        c[0] = '-';
    }
    for (i = scs - 1; value != 0; i--)
    {
        c[i] = abs(value % 10) + 48;
        value = value / 10;
    }
    c[scs] = '\0';
}

//Methods implementation
void process(double d)
{
    Integer i = d;
    char *c = NULL;
    i.toString(c);
    cout << c;
    delete[] c;
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt", ios::in);

    double d;
    fileIn >> d;
    process(d);
    fileIn.close();
    system("pause");
    return 0;
}