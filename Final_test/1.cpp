#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;

/* Your code MUST NOT contain any words in the list:
{"include", "goto", "string"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------
const int F = -999;
const int P = -998;
int nhay = 0;
int n = 0;
int *a;

void getdata(char *str)
{
	int i = 1;
	for (i; i < strlen(str); i++)
	{
		if (str[i] == ';')
			i++;
	}
	a = new int[i];
	char *pch;
	pch = strtok(str, ";");
	while (pch != NULL)
	{
		if (*pch >= 0 && *pch <= 9)
		{
			a[n++] = stoi(pch);
		}
		else if (*pch = 'F')
		{
			a[n++] = F;
		}
		else if (*pch = 'P')
		{
			a[n++] = P;
		}
		else
			a[n++] = 17;
		pch = strtok(NULL, ";");
	}
}

void iKnowTheFuture(long health, long numOfCreature, char *timeLine, int index, int sumOfStones)
{
	if (sumOfStones = 21)
	{
		cout << health << ' ' << numOfCreature / 2;
	}
	else if (health <= 0)
	{
		cout << 0 << ' ' << numOfCreature;
	}
	else if (index == 0)
	{
		getdata(timeLine);
		iKnowTheFuture(health, numOfCreature, timeLine, index + 1, sumOfStones);
	}
	else if (index == n + 1)
	{
		cout << health << ' ' << numOfCreature;
	}
	else
	{
		switch (a[index - 1])
		{
		case 1 ... 6:
			a[index - 1] = 17;
			iKnowTheFuture(health, numOfCreature, timeLine, index + 1, sumOfStones + a[index - 1]);
			break;
		case F:
			iKnowTheFuture(health, numOfCreature, timeLine, min(index + 2, n), sumOfStones);
			break;
		case P:
			iKnowTheFuture(health, numOfCreature, timeLine, max(index - 1, 1), sumOfStones);
			break;
		case 9:
			iKnowTheFuture(health - 9, numOfCreature, timeLine, index + 1, sumOfStones);
			break;
		default:
			iKnowTheFuture(health, numOfCreature, timeLine, index + 1, sumOfStones);
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	ifstream fileIn("inp.txt",ios::in);
		string line;
		int health;
		int numOfCreature;

		getline(fileIn, line);
		health = stoi(line);

		getline(fileIn, line);
		numOfCreature = stoi(line);

		getline(fileIn, line);
		char *cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());

		iKnowTheFuture(health, numOfCreature, cstr, 0, 0);
		fileIn.close();
		delete[] cstr;
	return 0;
}