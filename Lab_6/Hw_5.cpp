#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06010_sol.cpp"
using namespace std;

/* Viết hàm đệ quy đảo ngược thứ tự của các phần tử trong một mảng số nguyên (có thể viết thêm hàm phụ trợ). 
/* Your code MUST NOT contain any words in the list: 
{"include", "while", "for", "goto"} even in the comments */
/* Implement the recursiveReverse function without any loops*/
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
void Reverse(int *arr, int numberOfElements, int i)
{
    if (i > numberOfElements / 2){
        return;
    }
    else{
        swap(arr[i - 1], arr[numberOfElements - i]);
        Reverse(arr, numberOfElements, i + 1);
    }
}
void recursiveReverse(int *arr, int numberOfElements)
{
    Reverse(arr, numberOfElements, 1);
}

int main(int argc, char *argv[])
{

    ifstream fileIn("inp.txt", ios::in);
    int numberOfElements;
    fileIn >> numberOfElements;
    int *arr = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
        fileIn >> arr[i];
    recursiveReverse(arr, numberOfElements);
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << arr[i];
        if (i < numberOfElements - 1)
            cout << " ";
    }
    fileIn.close();
    delete[] arr;
    system("pause");
    return 0;
}