/*
	* Ho Chi Minh City University of Technology
	* Faculty of Computer Science and Engineering
	* Initial code for Assignment 2b
	* Programming Fundamentals CO1011 - Spring 2019
	* Author: Tran Ngoc Bao Duy
	* Date: 16.4.2019
	* Implementation of the header musketeer.h. You will write/edit this file to complete this assignment.
*/
#include "musketeer.h"

enum Heroes
{
	Artagnan = 999,
	Athos = 900,
	Porthos = 888,
	Aramis = 777
} Hero;

void advanture(int R, int N, int ID, int M, int* E, int nEvents) {
	//get HP and heroes
	switch (ID)
	{
	case 1:
		Hero = Artagnan;
		break;
	case 2:
		Hero = Athos;
		break;
	case 3:
		Hero = Porthos;
		break;
	case 4:
		Hero = Aramis;
		break;
	}
	int HP = Hero;

	int diamond = 0, R = 0;
	for (int i = 0; i < nEvents; i++)
	{
		R = HP + M;
		switch (E[i])
		{
		case 0:
			diamond++;
			break;
		case 1:
			hostle(HP, M, R);
			break;
		case 100 ... 199:
			meetGuard(i,R,E[i],M,HP);
			break;
		case 200 ... 299:
			meetMerchant();
			break;
		case 300 ... 399:
			break;
		case 500 ... 599:
			break;
		case 666:
			break;
		case 777:
			break;
		case 999:
			break;
		}
	}
	//if(0 >= HP) Ending(2);
	//case 3 khi di den sk cuoi van chua lay dc so kc can thiet
}

void Ending(int i,int R=0){
	switch (i)
	{
	case 1:
		cout << R;
		break;
	case 2:
		cout << -1;
		break;
	case 3:
		cout << 0;
		break;
	}
	exit(0);
}

void hostle(int &HP, int &M, int R)
{
	if (Porthos == Hero)
	{
		if (R <= 3 | ){

		}
	}
	if (min(Hero - HP, M) < 0)
		cout << "hostle am kia";
	HP += min(Hero - HP, M);
	M -= M - min(Hero - HP, M);
}

void meetGuard(int i,int R,int Ei, int &M, int &HP){
	int h1 = i % (100 + R);
	int h2 = Ei % (100 + R);
	if (Athos == Hero)
	{
		//Athos thua
		if (h1 < h2 && h2 > M && isPrimeNumber(h2))
		{
			HP -= Ei;
			if (HP <= 0)
				Ending(2);
		}
		return;
	}
	if (h1 >= h2)
	{
		M += Ei;
		M = (M > 999) ? 999 : M;
	}
	else
	{
		HP -= Ei;
		if (HP <= 0)
			Ending(2);
	}
}
bool isPrimeNumber(int num){
	for (int i = 2; i < num-1; i++)
	{
		if (num % i == 0) return 0;
	}
	return 1;
}



void meetMerchant(){
	
}