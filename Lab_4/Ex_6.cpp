/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 04: 04008_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Thu Mar 28 16:43:40 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

/* Write the code to calculate and print to screen */
void multipleMatrix(int mA, int nA, int **A, int mB, int nB, int **B)
{
	if (nA != mB)
	{
		cout << -1;
		return;
	}
	int **Arr = new int *[mA];
	for (int i = 0; i < mA; i++)
	{
		Arr[i] = new int[nB]{};
	}
	for (int Row = 0; Row < mA; Row++)
	{
		for (int Col = 0; Col < nB; Col++)
		{
			for (int i = 0; i < nA; i++)
			{
				Arr[Row][Col] += A[Row][i] * B[i][Col];
			}
			cout << Arr[Row][Col] << ((Col < nB - 1) ? " " : "");
		}
		cout << ((Row < mA - 1) ? "\n" : "");
	}
	delete[] A;
}

int main(int argc, char *argv[])
{
	// Section: read testcase
	///Student may comment out this section for local testing
	ifstream fileIn("inp.txt", ios::in);
	int mA, nA, mB, nB;
	fileIn >> mA >> nA;
	int **A = new int *[mA];
	for (int i = 0; i < mA; i++)
		A[i] = new int[nA];
	for (int i = 0; i < mA; i++)
		for (int j = 0; j < nA; j++)
			fileIn >> A[i][j];
	fileIn >> mB >> nB;
	int **B = new int *[mB];
	for (int i = 0; i < mB; i++)
		B[i] = new int[nB];
	for (int i = 0; i < mB; i++)
		for (int j = 0; j < nB; j++)
			fileIn >> B[i][j];
	multipleMatrix(mA, nA, A, mB, nB, B);
	fileIn.close();
	// Tidy dynamic memory
	for (int i = 0; i < mA; i++)
		delete[] A[i];
	delete[] A;
	for (int i = 0; i < mB; i++)
		delete[] B[i];
	delete[] B;
	// Endsection: read testcase
	//------------------------------------
	// Section: Function call

	// Endsection: Function call
	system("pause");
	return 0;
}
