#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06008_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the list:
{"include", "for", "while", "goto"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/* Write the recursive function returning the index of
the first appearance of the key in the array */
int recursiveSearch(int *arr, int numberOfElements, int key)
{
    if (numberOfElements - 1 == - 1){
        return -1;
    }
    else
    {
        if (arr[numberOfElements - 1] == key) {
            return numberOfElements - 1;
        }
        else return recursiveSearch(arr, numberOfElements - 1, key);
    }
    
}
int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        int key, numberOfElements;
        fileIn >> key >> numberOfElements;
        int *arr = new int[numberOfElements];
        for (int i = 0; i < numberOfElements; i++)
            fileIn >> arr[i];
        cout << recursiveSearch(arr, numberOfElements, key);
        fileIn.close();
        delete[] arr;
    system("pause");
}