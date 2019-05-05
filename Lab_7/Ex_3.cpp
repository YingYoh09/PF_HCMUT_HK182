/**
	Faculty of Computer Science and Engineering
	Ho Chi Minh City University of Technology
	Programming fundamentals - spring 2019
	Lab 07: 07003_ini.cpp
	@author CSE - HCMUT
	@version 1.0 Tue Apr 23 10:19:58 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07003_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

//------------------------------------------------------------------------
/**
* Champion class definition 
*/
class Champion
{
	int id;
	int heath;
	int damage;
	static int numberOfAliveChampions; // Think: Why static? What is a static member?
	/* What are the differences between a static member and the others? */
public:
	Champion(int _id, int _health, int _damage);
	~Champion();
	bool attack(Champion &_victim);
	int getHeath();
	static int getNumberOfAliveChampions(); // Why static? What is a static method?
											/* What are the differences between a static method and the others? */
};

/**
* Champion class implementation
*/

/* The constructor */
Champion::Champion(int _id, int _health, int _damage)
{
	// Hint: set the corresponding passed values to id, heath, and damage
	// Hint: We have a static variable for alive champion counting!
	id = _id;
	heath = _health;
	damage = _damage;
	numberOfAliveChampions++;
}

/* The destructor */
Champion::~Champion() {
	// Think: What must be done when the the object is destroyed?
	// Hint: We have a static variable for alive champion counting!
	numberOfAliveChampions--;
}

/* This champion attack another champion, the victim will lose an amount of health
equal to the attacker damage, return true if the victim dies after being attacked */
bool Champion::attack(Champion& _victim) {
	if (this->damage >= _victim.heath){
		return 1;
	}
	else {
		_victim.heath -= this->damage;
		return 0;
	}
}

/* The getter for instance member: this->heath */
int Champion::getHeath()
{
	return this->heath;
}

/* The getter for the class member: Champion::numberOfAliveChampions */
int Champion::getNumberOfAliveChampions()
{ // Why static? What is a static method?
	return numberOfAliveChampions;
}
// Think: What are the differences between the two getter above?

// Think: What is the following line for?
int Champion::numberOfAliveChampions = 0;

/**
* Some function for combating (of course, champion have to combat :v)
*/

/* For each event, if event is true then the champion A attack the champion B and vise versa.
Return 1 if the champion A killed the champion B, return -1 if the champion B killed the champion A,
or return 0 if no one dies after the fight. Please note that, to mark that a champion is killed,
you have to delete that champion object and set the corresponding pionter to NULL*/
int fight(Champion*& a, Champion*& b, bool* eventList, int numberOfEvent) {
	/*Please note that, to mark that a champion is killed,
	you have to delete that champion object and set the corresponding pionter to NULL */
	for (int i = 0; i < numberOfEvent; i++)
	{
		if (eventList[i]==1){
			if (a->attack(*b)){
				delete b;
				b = NULL;
				return 1;
				break;
			}
		}
		else{
			if (b->attack((*a)))
			{
				delete a;
				a = NULL;
				return -1;
				break;
			}
		}
	}
	return 0;
}

//------------------------------------------------------------------------

struct Match {
	int indexOfA;
	int indexOfB;
	int numberOfEvents;
	bool* eventList;
};

/* There are many matches, in each match, the two champion will fight with each other */
void combat(Champion** championList, int numberOfChampions, Match* matchList, int numberOfMatches) {
	for (int i = 0; i < numberOfChampions; i++) {
		if (championList[matchList[i].indexOfA] != NULL && championList[matchList[i].indexOfB] != NULL)
			fight(championList[matchList[i].indexOfA], championList[matchList[i].indexOfB], matchList[i].eventList, matchList[i].numberOfEvents);
	}
}


int main(int argc, char* argv[]) {
	ifstream fileIn("inp.txt",ios::in);
		int numberOfChampions;
		fileIn >> numberOfChampions;
		Champion** champList = new Champion*[numberOfChampions];
		int id, health, damage;
		for (int i = 0; i < numberOfChampions; i++) {
			fileIn >> id >> health >> damage;
			champList[i] = new Champion(id, health, damage);
		}
		int numberOfMatches;
		fileIn >> numberOfMatches;
		Match* matchList = new Match[numberOfMatches];
		for (int i = 0; i < numberOfMatches; i++) {
			fileIn >> matchList[i].indexOfA >> matchList[i].indexOfB;
			fileIn >> matchList[i].numberOfEvents;
			matchList[i].eventList = new bool[matchList[i].numberOfEvents];
			for (int j = 0; j < matchList[i].numberOfEvents; j++) fileIn >> matchList[i].eventList[j];
		}
		combat(champList, numberOfChampions, matchList, numberOfMatches);
		cout << Champion::getNumberOfAliveChampions();
		fileIn.close();
		for (int i = 0; i < numberOfChampions; i++) delete champList[i];
		delete[] champList;
		for (int i = 0; i < numberOfMatches; i++) delete[] matchList[i].eventList;
		delete[] matchList;
}
