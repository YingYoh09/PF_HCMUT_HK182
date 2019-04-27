
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06002_sol.cpp"
    using namespace std;

/* 
Viết chương trình tính số Fibonacci thứ n bằng phương pháp đệ quy.
/* Implement the recursive function */
int fibo(int n)
{
    if ( 1==n || 2==n ){
        return 1;
    }
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main(int argc, char *argv[])
{
   ifstream fileIn("inp.txt",ios::in);
        int n;
        fileIn >> n;
        cout << fibo(n);
        fileIn.close();
        system("pause");
    return 0;
}