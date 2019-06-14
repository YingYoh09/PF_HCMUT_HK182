#include "core.h"
#include <algorithm>

/* Start block: DO NOT CHANGE
    * Please do not change anything in this code block (including whitespace, empty lines)
    * If changes, your submission is marked as zero.
*/

/*
    * Default constructor for Battle class
*/
Battle::Battle(MemoryManager* manager) {
    this->musketeers = NULL;
    this->events = NULL;
    this->manager = manager;
}

/*
    * Default destructor for Battle class
*/
Battle::~Battle() {
    this->finalize();
}

/*
    * Method: read data from input file and assign values to musketeers
    * Input:
    * - filename: the name of input file
    * Output:
    * - Returns true if read file successfully, otherwise returns false
*/
bool Battle::readDataFromFile(string filename) {
    fstream fs(filename, ios::in);

    if (!fs.is_open()) return false;

    this->musketeers = new Musketeer[NUM_OF_MUSKETEERS];

    int* cystalPointer = NULL;
    int cystal = 0;

    for (int i = 0; i < NUM_OF_MUSKETEERS; i++) {
        this->musketeers[i].setMemoryManger(this->manager);
        this->musketeers[i].setTeam(this->musketeers);
        
        for (int j = 0; j < NUM_OF_CYSTAL; j++) {
            fs >> cystal;

            if (cystal > 0) {
                manager->allocate(cystalPointer);
                *cystalPointer = cystal;
                this->musketeers[i].setCystalPointer(j + 1, cystalPointer);
            }
        }
    }
    
    fs >> this->firstMusketeer;

    string eventsInText = "";
    fs.ignore();
    getline(fs, eventsInText);

    int numOfSpaces = 0;
    for (int i = 0; i < eventsInText.length(); i++) {
        if (eventsInText.at(i) == ' ') numOfSpaces++;
    }

    int numOfEvents = numOfSpaces + 1;

    this->events = new int[numOfEvents];

    stringstream ss(eventsInText);

    for (int i = 0; i < numOfEvents; i++)
        ss >> this->events[i];
    
    this->numOfEvents = numOfEvents;
    
    return true;
}

void Battle::display() {
    for (int i = 0; i < NUM_OF_MUSKETEERS; i++) {
        cout << this->musketeers[i].getHP() << " ";

        for (int j = 0; j < NUM_OF_CYSTAL; j++) {
            if (this->musketeers[i].getCystalPointer(j + 1) != NULL)
                cout << *(this->musketeers[i].getCystalPointer(j + 1));
            else cout << 0;
            if (j < NUM_OF_CYSTAL - 1) cout << " ";
        }
    
        cout << endl;
    }

    cout << this->manager->getNumOfAllocation();
}
/* End block: DO NOT CHANGE */

/* Start block: TO DO
    * You have to complete only one method of Battle class
*/

/*
    * Method: Emulate this battle
    * Input: None
    * Output: None
*/
void Battle::struggle() {
    // TO-DO
	musketeers[0].setHP(999);
	musketeers[1].setHP(900);
	musketeers[2].setHP(888);
	musketeers[3].setHP(777);

    for (int i = 0; i < numOfEvents; i++)
    {
		//Healing HP
		for (int l = firstMusketeer + 1; l < firstMusketeer + 4; l++)
			switch (l % 4)
			{
			case 0:
				musketeers[l % 4].setHP(min(999, musketeers[l % 4].getHP() + 200));
				break;
			case 1:
				musketeers[l % 4].setHP(min(900, musketeers[l % 4].getHP() + 150));
				break;
			case 2:
				musketeers[l % 4].setHP(min(888, musketeers[l % 4].getHP() + 100));
				break;
			case 3:
				musketeers[l % 4].setHP(min(777, musketeers[l % 4].getHP() + 50));
				break;
			}
		//Nhặt Crystal
		if (events[i] > 9 && events[i] < 40)
		{
			
		}
		//TODO: Chưa xử lí OutRange
		//Gặp Quái vật
		int j = firstMusketeer;//current musk có crystal
		int typeOfCrystal = ((events[i] * -1) % 100) / 10;
		int* currentCrystal = musketeers[firstMusketeer].getCystalPointer(typeOfCrystal);
		//NULL -> kiếm ptr có crystal tiếp theo
		for (j = firstMusketeer; j < firstMusketeer + 4; j++)
		{
			int* tmpCrystal = musketeers[j % 4].getCystalPointer(typeOfCrystal);
			if (NULL != tmpCrystal)
			{
				currentCrystal = tmpCrystal;
				j = j % 4;
				break;
			}
		}
		//có Crystal thỏa hay k 
		if (currentCrystal != NULL)
		{
			(*currentCrystal)--;
			if (0 == *currentCrystal ) {
				manager->deallocate(musketeers[j].getCystalPointer(typeOfCrystal));
				musketeers[j].setCystalPointer(typeOfCrystal,NULL);
				currentCrystal = NULL;
			}
		}
		else
		{
			//Case d, Aramis
			if (firstMusketeer == 3) {
				for (j = 3; j < 3 + 4; j++)
					for (int currentType = 0; currentType < 3; currentType++)
					{
						int* tmpCrystal = musketeers[j % 4].getCystalPointer(currentType);
						if (NULL != tmpCrystal && *tmpCrystal > 1 && (*tmpCrystal) * 10 < musketeers[3].getHP())
						{
							int* tmp;
							manager->allocate(tmp);
							*tmp = (*tmpCrystal) - 1;
							//set crystal mới vô Aramis
							this->musketeers[3].setCystalPointer(typeOfCrystal, tmp);
							//mất máu 10xlevel nhưng mà vì trên có check < hp rồi nên -> hp - nó >= 1 k xuống 0
							this->musketeers[3].setHP(this->musketeers[3].getHP() - (*tmpCrystal) * 10);
							//xóa crystal cũ đi
							manager->deallocate(musketeers[j % 4].getCystalPointer(currentType));
							musketeers[j % 4].setCystalPointer(currentType, NULL);
							goto NEXTEVENT;
						}
					}
				NEXTEVENT: continue;
			}
			//đấu
			float fE;
			switch (-1 * events[i] % 100)
			{
			case 11: fE = 0.65f;
				break;
			case 12: fE = 0.95f;
				break;
			case 21: fE = 0.85f;
				break;
			case 22: fE = 0.9f;
				break;
			case 31: fE = 0.4f;
				break;
			case 32: fE = 1.0f;
				break;
			}
			int K = musketeers[0].findMaxPrimeNumber(-1*events[i]);
			int dmg = floor(events[i]*-1 * fE + int(round(pow(fE,firstMusketeer + 1) * K)) % 100);
			
			if (musketeers[firstMusketeer].getHP() - dmg < 1)
			{
				musketeers[firstMusketeer].setHP(0);
				firstMusketeer++;
			}
			else
			{
				musketeers[firstMusketeer].setHP(musketeers[firstMusketeer].getHP() - dmg);
			}
			
		}
    }
}

/*
    * Method: finalize a battle, deallocate any dynamic memories. 
    * Input: None
    * Output: None
*/
void Battle::finalize() {
    // TO-DO
}
/* End block: TO DO */
