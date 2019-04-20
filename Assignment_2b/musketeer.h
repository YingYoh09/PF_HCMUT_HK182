/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 2b
    * Programming Fundamentals CO1011 - Spring 2019
    * Author: Tran Ngoc Bao Duy
    * Date: 16.4.2019
    * Header file for your function and variables. You will write/edit this file to complete this assignment.
*/

#include "core.h"

/*
    Procedure to simulate the advanture of musketeer
    * Input: R, N, ID, M, E (in description) and the number of events list E.
    * Output: Display in the rule in description.
    * PLEASE DO NOT CHANGE THE PROTOTYPE OF THIS FUNCTION
*/
class heroes
{
private:
    int R, Money;
    int maxHP, HP;
    bool WonGWS, porthosHasCuli, trickedbyJeannie;

public:
    int diamond;

public:
    heroes() : diamond(0), WonGWS(0), porthosHasCuli(0), trickedbyJeannie(0){};
    ~heroes(){};
    void init(int M, int ID, int R)
    {
        this->Money = M;
        this->maxHP = getmaxHPfromID(ID);
        this->HP = maxHP;
        this->R = R;
    }
    int getmaxHPfromID(int ID) const;
    void Ending(int i);
    bool isPrimeNumber(int a);
    int lostHP(int Ei);

    void hostel();
    void meetGuard(int i, int Ei);
    void meetMerchant(int i, int Ei);
    void meetGWS(int i, int Ei);
    void meetTitan(int i, int Ei);
    void meetMilady();
    int findFibonacci();
    void meetJeanne(int i, int Ei);
    void meetLancelot(int i, int Ei);
    bool isFibonacci(int a);
};

void advanture(int R, int N, int ID, int M, int* E, int nEvents);
