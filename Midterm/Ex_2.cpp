#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <math.h>

using namespace std;

void findLongestChain(int M, int N, int **a)
{
    long int maxRes = -1, res = -1;
    for (int i = 0; i < N; i++)
    {
        long int sum = 0;
        bool duong = 1;
        for (int j = 0; j < M; j++)
        {
            if (a[j][i] <= 0){
                duong = 0;
                break;
            }
            sum += a[j][i];
        }
        if (duong){
            if (sum>maxRes){
                res = i;
                maxRes = sum;
            }
        }
    }
    cout << res;
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        int numberOfRows, numberOfColumns;
        fileIn >> numberOfRows >> numberOfColumns;
        int **matrix = new int *[numberOfRows];
        for (int row = 0; row < numberOfRows; row++)
        {
            matrix[row] = new int[numberOfColumns];
            for (int col = 0; col < numberOfColumns; col++)
                fileIn >> matrix[row][col];
        }
        findLongestChain(numberOfRows, numberOfColumns, matrix);
        fileIn.close();
        //Tidy dynamic memory
        for (int row = 0; row < numberOfRows; row++)
            delete[] matrix[row];
        delete[] matrix;
    system("pause");
    return 0;
}