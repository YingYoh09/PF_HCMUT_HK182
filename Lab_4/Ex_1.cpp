/**
	Faculty of Computer Science and Engineering
	Ho Chi Minh City University of Technology
	Programming fundamentals - spring 2019
	Lab 04: 04001_ini.cpp
	@author CSE - HCMUT
	@version 1.0 Sat Mar 23 23:25:31 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;
/**
Print out the array 10x10 with option.
*/
void printArray(int option, int arr[10][10])
{
	long int res = 0;
	switch (option)
	{
	case 1:
		goto option1;
		break;
	case 2:
		goto option2;
		break;
	case 3:
		goto option3;
		break;
	case 4:
		goto option4;
		break;
	}
option1:
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout <<arr[i][j];
			if (j < 9)
				cout <<' ';
		}
		if (i < 9)
			cout <<"\n";
	}
	return;
option2:
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			res += arr[i][j];
		}
	}
	cout << res;
	return;
option3:
	for (int i = 0; i < 10; i++)
	{
		res = 0;
		for (int j = 0; j < 10; j++)
		{
			res += arr[j][i];
		}
		cout <<res;
		if (i < 9)
			cout <<' ';
	}
option4:
	for (int i = 0; i < 10; i++)
	{
		long int sum = 0;
		int resSum = 1 - __LONG_MAX__;
		for (int j = 0; j < 10; j++)
		{
			sum += arr[i][j];
		}
		if (sum > resSum)
		{
			res = i;
			resSum = sum;
		}
		if (i < 9)
			cout <<' ';
	}
	cout <<res;
}
int main(int argc, char *argv[])
{
	// Section: Data declarations
	int option;
	int arr[10][10];

	ifstream fileIn("inp.txt", ios::in);
	fileIn >> option;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			fileIn >> arr[i][j];
	fileIn.close();
	// Endsection: read testcase
	//------------------------------------
	// Section: Function call
	printArray(option, arr);
	// Endsection: Function call
	system("pause");
	return 0;
}