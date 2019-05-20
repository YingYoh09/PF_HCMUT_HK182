#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;

class Avenger
{
private:
    int power;
    int health;
    int cost;

public:
    Avenger(int _power, int _health, int _cost){
        power = _power;
        health = _health;
        cost = _cost;
    }

    int getpower(){
        return power;
    }
    void setpower(int _power){
        power = _power;
    }

    int gethealth()
    {
        return health;
    }
    void sethealth(int _health)
    {
        health = _health;
    }

    int getcost()
    {
        return cost;
    }
    void setcost(int _cost)
    {
        cost = _cost;
    }

    bool attack()
    {
        if (health < cost)
        {
            return 0;
        }
        health -= cost;
        return 1;
    }

    Avenger* readData(char *fileName);
    ~Avenger(){};
    Avenger powerUp(Avenger& a){
        a.power++;
        return a;
    }
    
};

Avenger* Avenger::readData(char* fileName){
    ifstream ifs(fileName, ios::in);
    int i, j, k;
    ifs >> i >> j >> k;
    setpower(i);
    sethealth(j);
    setcost(k);
    ifs >> i;
    j = 0;
    while (j <= i && attack() && gethealth() > 0 ){
        j++;
    }
    cout << gethealth() << ' ' << j << ' ';
    cout << (i == j) ? 1 : 0;
    ifs.close();
    return this;
}

int main(int argc, char *argv[])
{
    Avenger a(0, 0, 0);
    a.readData("inp.txt");
    Avenger ir(1, 1, 1);
    ir.powerUp(ir).powerUp(ir).powerUp(ir);
    return 0;
}