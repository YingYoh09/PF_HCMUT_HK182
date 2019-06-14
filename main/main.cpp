#include "core.h"

int main() {
    MemoryManager* manager = new MemoryManager;
    Battle* theBattle = new Battle(manager);
    theBattle->readDataFromFile("input.txt");
    theBattle->struggle();
    theBattle->display();
    delete manager;
    delete theBattle;
	system("pause");
    return 0;
}