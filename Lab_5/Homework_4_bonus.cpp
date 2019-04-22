/**
	Faculty of Computer Science and Engineering
	Ho Chi Minh City University of Technology
	Programming fundamentals - spring 2019
	Lab 05: 05002_ini.cpp
	@author CSE - HCMUT
	@version 1.0 Sat Apr 13 17:56:39 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05002_sol.cpp"
using namespace std;

/* Please note that your code must not contain any of words in
 {"include"}; */

//---------------------------------------------------------
// Begin implementation
//---------------------------------------------------------

/* Write the code to print to screen the longest common substring*/
void getLongestCommonSubstring(char *str1, char *str2)
{
	string s1(str1), s2(str2);
	for (int k = min(s1.length(), s2.length()); k > 0; k--)
	{
		for (int i = 0; i < s1.length() - k; i++)
		{
			for (int j = 0; j < s2.length() - k; j++)
			{
				if (s1.substr(i, k) == s2.substr(j,k)){
					cout << s1.substr(i, k);
					return;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{ifstream fileIn("inp.txt",ios::in);
		string str1, str2;
		if (!fileIn.eof())
			getline(fileIn, str1);
		if (!fileIn.eof())
			getline(fileIn, str2);
		char *cstr1 = new char[str1.length() + 1];
		strcpy(cstr1, str1.c_str());
		char *cstr2 = new char[str2.length() + 1];
		strcpy(cstr2, str2.c_str());
		getLongestCommonSubstring(cstr1, cstr2);
		delete[] cstr1;
		delete[] cstr2;
		fileIn.close();
		system("pause");
	return 0;
}