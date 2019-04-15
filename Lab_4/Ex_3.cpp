/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 04: 04004_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Wed Mar 27 14:11:27 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

/* Given arr is an matrix of 5x5, write the code to find the number
of number 1 in rows and columns and then print to the screen following
the required format as in the exercise description.*/
void findTheMostNumberOfOneInMatrix(bool arr[5][5])
{
	int maxCol = -1, maxRow = -1;
	int resCol = -1, resRow = -1;
	for (int i = 0; i < 5; i++)
	{
		int tempCol = 0, tempRow = 0;
		for (int j = 0; j < 5; j++)
		{
			tempRow += arr[i][j];
			tempCol += arr[j][i];
		}
		if (tempCol > maxCol)
		{
			maxCol = tempCol;
			resCol = i;
		}
		if (tempRow > maxRow)
		{
			maxRow = tempRow;
			resRow = i;
		}
	}
	cout << "Row index: " << resRow << "\n";
	cout << "Column index: " << resCol;
}

int main(int argc, char *argv[])
{
	bool arr[5][5];
	// Section: read testcase
	///Student may comment out this section for local testing
	ifstream fileIn("inp.txt", ios::in);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fileIn >> arr[i][j];
		}
	}
	fileIn.close();
	// Endsection: read testcase
	//------------------------------------
	// Section: Function call
	findTheMostNumberOfOneInMatrix(arr);
	// Endsection: Function call
	return 0;
}