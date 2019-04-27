/**
 * print 1 2 3 ... n

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06000_sol.cpp"
using namespace std;
void process(int n) {
    /// Student call the recursive function from here
    if (1==n)
    {
    }
    else
    {
        process(n-1);
        cout << ' ';
    }
    cout << n;
}


int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        int n;
        fileIn >> n;
        process(n);
        fileIn.close();
        system("pause");
    // Endsection: read testcase
    //------------------------------------
    return 0;
}