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

const int Artagnan = 999, Athos = 900, Porthos = 888, Aramis = 777;

void advanture(int R, int N, int ID, int M, int* E, int nEvents) {
	//init
	heroes hero;
	hero.init(M, ID, R);

	for (int i = 0; i < nEvents; i++)
	{
		switch (E[i])
		{
		case 0:
			hero.diamond++;
			break;
		case 1:
			hero.hostel();
			break;
		case 100 ... 199:
			hero.meetGuard(i + 1, E[i]);
			break;
		case 200 ... 299:
			hero.meetMerchant(i + 1, E[i]);
			break;
		case 300 ... 399:
			hero.meetGWS(i + 1, E[i]);
			break;
		case 500 ... 599:
			hero.meetTitan(i + 1, E[i]);
			break;
		case 666:
			hero.meetMilady();
			break;
		case 777:
			hero.meetJeanne(i + 1, E[i]);
			break;
		case 999:
			hero.meetLancelot(i + 1, E[i]);
			break;
		}
		if (hero.diamond == N) hero.Ending(1);
	}
	if (hero.diamond != N) hero.Ending(3);
}

int heroes::getmaxHPfromID(int ID) const{
	switch (ID)
	{
	case 1:
		return Artagnan;
	case 2:
		return Athos;
	case 3:
		return Porthos;
	case 4:
		return Aramis;
	}
}

void heroes::Ending(int i){
	switch (i)
	{
	case 1:
		cout << HP + Money;
		break;
	case 2:
		cout << -1;
		break;
	case 3:
		cout << 0;
		break;
	}
	system("pause");
	exit(0);
}

bool heroes::isPrimeNumber(int a){
	if (a < 2)
		return 0;
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}

int heroes::lostHP(int Ei){
	if (WonGWS){
		return round(float (Ei) / float (pow(2, R + 5)) * float (R + 10));
	}
	else return Ei;
}
//-------------------------
void heroes::hostel(){
	if (Porthos == maxHP)
	{
		if (R >= 3 && Money > 2){
			int P = R - 1;
			while (P > 1 && !isPrimeNumber(P))
				P--;
			while (R >= 3 && Money > 2 && Money >= P && HP < maxHP){
				HP++;
				Money -= P;
			}
		}
		
		return;
	}

	while (HP < maxHP && Money > 0){
		HP++;
		Money--;
	}
}

void heroes::meetGuard(int i, int Ei){
	int h1 = i % (100 + R);
	int h2 = Ei % (100 + R);
	switch (maxHP)
	{
	case Athos:
		//Athos thua
		if (h1 < h2 && h2 > Money && isPrimeNumber(h2))
		{
			HP -= lostHP(Ei);
			if (HP <= 0)
				Ending(2);
		}
		return;
	case Porthos:
		if (porthosHasCuli) {
			return;
		}
		else break;
	default:
		break;
	}
	if (h1 >= h2)
	{
		Money += Ei;
		Money = (Money > 999) ? 999 : Money;
	}
	else
	{
		if (Aramis == maxHP && HP - lostHP(Ei) < 1){
			return;
		}
		HP -= lostHP(Ei);
		if (HP <= 0)
			Ending(2);
	}
}

void heroes::meetMerchant(int i, int Ei){
	int h1 = i % (100 + R);
	int h2 = Ei % (100 + R);
	if (h1 >= h2)
	{
		Money *= 2;
		Money = (Money > 999) ? 999 : Money;
	}
	else
		Money /= 2;
}

void heroes::meetGWS(int i, int Ei){
	if (WonGWS) return;
	int h1 = i % (100 + R);
	int h2 = Ei % (100 + R);
	if (h1 >= h2)
	{
		WonGWS = 1;
	}
	else
		diamond = 0;
}

void heroes::meetTitan(int i, int Ei){
	int h1 = i % (100 + R);
	int h2 = Ei % (100 + R);
	if (h1 >= h2){
		if (Porthos == maxHP) porthosHasCuli = 1; 
	}
	else
	{
		if (Aramis == maxHP && HP - lostHP(Ei) < 1)
		{
			return;
		}
		HP -= lostHP(Ei);
		if (HP <= 0)
			Ending(2);
	}
}
//-----------------Milady-----------------
int heroes::findFibonacci(){
	int fibo[3]{1,1,2};
	int i = 3;
	while (fibo[(i - 1) % 3] < HP){
		fibo[(++i - 1) % 3] = fibo[(i - 2) % 3] + fibo[(i - 3) % 3];
	}
	return fibo[(i - 2) % 3];
}
void heroes::meetMilady(){
	switch (maxHP){
		case Artagnan:
			Ending(2);
		case Athos:
			Money = 999;
			break;
		case Aramis:
		case Porthos:
			if (2 < HP) {
				HP = findFibonacci();
			}
			break;
		}
}

void heroes::meetJeanne(int i, int Ei){
	if (trickedbyJeannie) return;
	trickedbyJeannie = 1;
	int Q = R % 100;
	while (!isPrimeNumber(Q) && (R % 100) % Q != 0)
	{
		Q--;
	}
	if (Q == 0) Q = 1;
	if (Aramis == maxHP && 0 < diamond && Money >= Q)
	{
		diamond--;
		int h1 = i % (100 + R);
		int h2 = Ei % (100 + R);
		if (h1 >= h2)
		{
			diamond++;
		}
		else {
			Money -= Q;
		}
		return;
	}
	else diamond = (diamond > 0) ? (diamond - 1) : 0;
}

void heroes::meetLancelot(int i, int Ei){
	if (!isFibonacci(i)) Ending(2);

	int h1 = i % (100 + R);
	int h2 = Ei % (100 + R);
	if (h1 >= h2)
	{
		HP = maxHP;
		Money = 999;
	}
	else
	{
			Ending(2);
	}
}
bool heroes::isFibonacci(int a){
	int fibo[3]{1, 1, 2};
	int i = 3;
	while (fibo[(i - 1) % 3] <= a)
	{
		fibo[(++i - 1) % 3] = fibo[(i - 2) % 3] + fibo[(i - 3) % 3];
	}
	return (fibo[(i - 2) % 3] == a);
}