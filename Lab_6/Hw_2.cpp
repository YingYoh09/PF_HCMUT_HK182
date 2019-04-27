#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06001_sol.cpp"
using namespace std;
/*
Viết chương trình tính tổng từ 1 đến n số nguyên bằng phương pháp đệ quy.
*/
int reSum(int n)
{
    if (1 == n){
        return 1;
    }
    else
        return n + reSum(n - 1);
}

int main(int argc, char *argv[])
{ifstream fileIn("inp.txt",ios::in);
        int n;
        fileIn >> n;
        cout << reSum(n);
        fileIn.close();
        system("pause");
    return 0;
}