/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07005_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun Apr 28 16:11:32 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07005_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

/* An abstract class named "Champion" with the 4 methods without method body */
class Champion
{
protected:
    int id;
    int health;
    int armor;
    int magicResitance;
    int physicalDamage;
    int abilityPower;

public:
    Champion(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower);
    bool takePhysicalDamage(int _physicalDamageTaken);
    bool takeMagicDamage(int _magicDamageTaken);
    void printStatus();
    // Abstract methods returning true if the target's health is run out after being attacked.
    virtual bool skill1(Champion &_champ) = 0;
    virtual bool skill2(Champion &_champ) = 0;
};

/* The default constructor initializes the object with champion's properties.
In such, the armor and magic resistance properties must not be negative or exceed 99 */
Champion::Champion(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower)
{
    if (_armor < 0 || _armor > 99)
        throw "Invalid armor value.";
    if (_magicResitance < 0 || _magicResitance > 99)
        throw "Invalid magic resistance value.";
    this->id = _id;
    this->health = _health;
    this->armor = _armor;
    this->magicResitance = _magicResitance;
    this->physicalDamage = _physicalDamage;
    this->abilityPower = _abilityPower;
}

/* This method calculates and reduces the "health" property of the host object
according to the physical damage taken. If the "health" property goes zero or
negative after being attacked, return true and vise versa. */
bool Champion::takePhysicalDamage(int _physicalDamageTaken)
{
    this->health -= (_physicalDamageTaken * this->armor / 100);
    if (this->health <= 0)
        return true;
    return false;
}

/* This method calculates and reduces the "health" property of the host object
according to the magic damage taken. If the "health" property goes zero or
negative after being attacked, return true and vise versa. */
bool Champion::takeMagicDamage(int _magicDamageTaken)
{
    this->health -= (_magicDamageTaken * this->magicResitance / 100);
    if (this->health <= 0)
        return true;
    return false;
}

void Champion::printStatus()
{
    cout << "---Champion status---" << endl;
    cout << "Champion ID: " << this->id << endl;
    cout << "Health     : " << this->health;
}

class ChampionA:public Champion
{
public:
    ChampionA(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower) : Champion( _id,  _health,  _armor,  _magicResitance,  _physicalDamage,  _abilityPower){}
    ~ChampionA(){};
    bool skill1(Champion &_champ){
        return _champ.takePhysicalDamage(100 + (physicalDamage * 20) / 100);
    }
    bool skill2(Champion &_champ){
        return _champ.takePhysicalDamage(20 + (physicalDamage * 80) / 100);
    }
};
class ChampionB : public Champion
{
public:
    ChampionB(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower) : Champion(_id, _health, _armor, _magicResitance, _physicalDamage, _abilityPower) {}
    ~ChampionB(){};
    bool skill1(Champion &_champ)
    {
        return _champ.takeMagicDamage(30 + (abilityPower * 70) / 100);
    }
    bool skill2(Champion &_champ)
    {
        return _champ.takeMagicDamage(90 + (abilityPower * 30) / 100);
    }
};

void process(ChampionA &a, ChampionB &b, int *skillSequence, int numberOfSkills)
{
    for (int i = 0; i < numberOfSkills; i++)
    {
        switch (skillSequence[i])
        {
        case 0:
            if (a.skill1(b))
                return;
            break;
        case 1:
            if (a.skill2(b))
                return;
            break;
        case 2:
            if (b.skill1(a))
                return;
            break;
        case 3:
            if (b.skill2(a))
                return;
            break;
        default:
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        int id;
        int health;
        int armor;
        int magicResitance;
        int physicalDamage;
        int abilityPower;
        // Read ChampionA
        fileIn >> id >> health >> armor >> magicResitance >> physicalDamage >> abilityPower;
        ChampionA a(id, health, armor, magicResitance, physicalDamage, abilityPower);
        // Read ChampionB
        fileIn >> id >> health >> armor >> magicResitance >> physicalDamage >> abilityPower;
        ChampionB b(id, health, armor, magicResitance, physicalDamage, abilityPower);
        // Read skill sequence
        int numberOfSkills;
        fileIn >> numberOfSkills;
        int *skill = new int[numberOfSkills];
        for (int i = 0; i < numberOfSkills; i++)
            fileIn >> skill[i];
        process(a, b, skill, numberOfSkills);
        a.printStatus();
        cout << endl;
        b.printStatus();
        delete[] skill;
        fileIn.close();
}