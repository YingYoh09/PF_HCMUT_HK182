//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/// Prototype declaration
void Initialization();
void Finalization();

void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void ProcessUserChoice();
///--------------------------------------------------------------------

bool __coreInitialized = false;  /// an example of global variable
int  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
// TODO: add more global variables to complete tasks
ifstream fin("conf.json", ios::in);
string menu[5];
string WelcomeText[9];
///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */


void Initialization() {
    LoadMenu();
    // TODO: write the code to initialize the program
    __coreInitialized = true;
	for (int i = 0; i < 9; i++){
		WelcomeText[i] = "";
	}
}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
    // TODO: write the code to clean up when the program exits
    fin.close();
}

void LoadConfiguration() {
    // TODO: write code to load data from the configuration file
	string s = "empty";
	do
	{
		getline(fin, s);
	} while (s.find("WelcomeText") == -1 && !fin.eof());
	if (s == "") { goto printWT; }
	for (int i = 0; i < 9; i++) {
		getline(fin, s);
		if (s.find("},") != -1)
			break;
		int j = int(s[9]) - int('1');
		WelcomeText[j] = s;
		WelcomeText[j].erase(0, 14);
		if (j == 8) {
			WelcomeText[j].erase(WelcomeText[j].length() - 1, 1);
		}
		else WelcomeText[j].erase(WelcomeText[j].length() - 2, 2);
	}
	
	printWT:
	for (int i = 0; i < 9; i++) {
		cout << WelcomeText[i] << "\n";
	}
	fin.seekg(0);
}

void LoadMenu() {
    // TODO: write code to load menu from the configuration file
	string s = "empty";
	do
	{
		getline(fin, s);
	} while (s.find("Menu") == -1 && !fin.eof());
	if (s == "") { goto endgetmenu; }

	for (int i = 0; i < 5; i++) {
		getline(fin, s);
		int j = int(s[8]) - int ('1');
		menu[j] = s;
		menu[j].erase(0, 13);
		if (j == 4) {
			menu[j].erase(menu[j].length() - 1, 1);
		}
		else menu[j].erase(menu[j].length() - 2, 2);
	}
	endgetmenu:
	fin.seekg(0);
}

void DisplayMenu() {
    // TODO: Display the menu loaded from configuration file
    for (int i = 0; i < 5; i++){
    	cout << i + 1 << ". " << menu[i] << "\n";
    }
}

void ProcessUserChoice() {
	// TODO: Read user input and process
	string s;
	Wrong:cout << "Please select: ";
	getline(cin, s);
	while (s[0] == ' ') { s.erase(0, 1); }
	while (s.length() > 0 && s[s.length()-1] == ' ') { 
		s.erase(s.length()-1, 1); }
	if (s[0] == '+') {
		s.erase(0,1);
	}

	// check integer
	if (s.length() == 0) {
		cout << "Invalid input, please input an integer number.\n";
		goto Wrong;
	}
	for (int i = 0; i < s.length(); i++) {
		int int0 = (int)'0';
		int int9 = (int)'9';
		if (((int0 > (int)s[i]) || ((int)s[i] > int9)) && ((s[0] != '-') || (i != 0))) {
			cout << "Invalid input, please input an integer number.\n";
			goto Wrong;
		}
	}

	// check 1 - 5
	while (s[0] == '0') {
		s.erase(0, 1);
	}
	if (s.length() != 1) {
		cout << "Please select a number from 1 to 5.\n";
		goto Wrong;
	}
	__userChoice = stoi(s);
	if (__userChoice < 1 || __userChoice > 5) {
		cout << "Please select a number from 1 to 5.\n";
		goto Wrong;
	}
	// update
	if (__userChoice == 5) {
		cout << "Exiting...";
		__isExiting = true;
		exit(0);
	}
	cout << "You select menu item " << __userChoice << ". Processing . . . Done!\n";
}