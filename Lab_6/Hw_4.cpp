#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06007_sol.cpp"
using namespace std;

/* 
find max element
 */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/* Write the recursive function returning the max value in the array */
int recursiveMax(int *arr, int numberOfElements)
{
    if (numberOfElements == 1)
        {return arr[0];}
    else
        return max(arr[numberOfElements-1],recursiveMax(arr, numberOfElements - 1));
}

int main(int argc, char *argv[])
{
   
   ifstream fileIn("inp.txt",ios::in);
    int numberOfElements;
    fileIn >> numberOfElements;
    int *arr = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        fileIn >> arr[i];
    }
    cout << recursiveMax(arr, numberOfElements);
    delete[] arr;
    fileIn.close();
    system("pause");
    return 0;
}
