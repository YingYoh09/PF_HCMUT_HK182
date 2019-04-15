/*
	* Ho Chi Minh City University of Technology
	* Faculty of Computer Science and Engineering
	* Initial code for Assignment 1b
	* Programming Fundamentals CO1011 - Spring 2019
	* Author: Tran Ngoc Bao Duy
	* Date: 05.4.2019
	* Only write/edit in the body of combat function to complete this assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

void combat(int hp1, int hp2, int d)
{

	// TODO: You have to complete this function followed by requirements
	//Ngu lam quan
	bool Aramis = 0, Porthos = 0, Athos = 0, Jussac = 0, Artagnan = 0;
	//check ton tai hero
	switch (hp1)
	{
	case 777:
		Aramis = 1;
		break;
	case 888:
		Porthos = 1;
		break;
	case 900:
		Athos = 1;
		break;
	case 999:
		Artagnan = 1;
		break;
	default:
		break;
	}
	if (hp2 == 888)
		Jussac = 1;
	// Init
	float p1 = float(hp1) / 1000 * (1000 - d);
	float p2 = float(hp2) / 1000 * d;
	float h1 = fmod(hp1 + hp2, 100);
	float h2 = fmod((h1 * hp2), 100);
	float pR = 0;
	// Dinh te tuong
	if (d == 987)
	{
		if (Artagnan || (h1 + h2 == 99))
			goto calc;
		else
			goto label;
	}
	else if (d != 987 && max(hp1, hp2) == 284 && min(hp1, hp2) == 220)
	{
		pR = 0.5;
		goto label;
	}

hero_skill:
	if (!Jussac & Aramis & (p1 < p2 || h1 < h2))
	{
		d = 1;
		p1 = float(hp1) / 1000 * (1000 - d);
		p2 = float(hp2) / 1000 * d;
	}

	if (!Jussac & Porthos)
		h1 *= 10;
	if (Artagnan & Jussac)
	{
		printf("%.2f", 1.0);
		return;
	}
	if (Jussac & !(Athos | Porthos | Aramis))
	{
		printf("%.2f", 0.01);
		return;
	}
calc:
	if (h1 * p1 + h2 * p2 == 0)
	{
		if (h1 == 0 && h2 == 0)
		{
			pR = 0;
		}
		else
		{
			pR = (p1 < p2) ? 0 : 1;
		}
	}
	else
		pR = (h1 * p1 - h2 * p2) / (h1 * p1 + h2 * p2);
	if ((d != 987) & !Jussac & Athos & (pR < 0.5))
		pR = 0.5f;
	pR = (pR < 0) ? 0.00f : pR;
	pR = (pR > 1) ? 1.00f : pR;
label:
	printf("%.2f", pR);
}

int main(int argc, char **argv)
{
	int hp1, hp2, d;
	ifstream fileIn("inp.txt", ios::in);
	fileIn >> hp1;
	fileIn >> hp2;
	fileIn >> d;
	combat(hp1, hp2, d);
	cout << endl;
}