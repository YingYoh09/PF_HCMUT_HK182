#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <vector>
using namespace std;

/*class Integer {
	int value;
public:
	// The constructor
	Integer(int _value);

	// The getter
	int getValue();

	//The setter
	void setValue(int _value);
};

Integer::Integer(int _value) {
    value = _value;
}

int Integer::getValue() {
    return value;
}

void Integer::setValue(int _value) {
    value = _value;
}

void process(vector<Integer> integerVector) {
    int numberOfElements = integerVector.size();
    int temp;
    int count = 1;
    while (count != 0) {
        count = 0;
        for (int i = 0; i < numberOfElements - 1; i++) {
            if (integerVector[i].getValue() > integerVector[i + 1].getValue()) {
                count++;
                temp = integerVector[i].getValue();
                integerVector[i].setValue(integerVector[i+1].getValue());
                integerVector[i+1] = temp;
            }
        }
    }
    for (int i = 0; i < numberOfElements; i++) {
        cout << integerVector[i].getValue();
        if (i < numberOfElements - 1) cout << " ";
    }
}

int main(int argc, char* argv[]) {
    ifstream fileIn("lab7.txt",ios::in);
        vector<Integer> integerVector;
        int temp;
        while (!fileIn.eof()) {
            fileIn >> temp;
            integerVector.push_back(Integer(temp));
        }
        process(integerVector);
        fileIn.close();
    return 0;
}*/

/*class Integer {
	int value;
public:
    Integer () {}
	// Methods prototypes only
    Integer (int _value) {value = _value;}
    void setValue(int _value) {value = _value;}
    int getValue() {return value;}
    void max(Integer*, Integer);
    Integer operator[](Integer);
    Integer operator+(int);
    friend bool operator== (Integer&,int) ;
    friend bool operator< (Integer&,int);
    void operator= (const Integer& I) {
        value = I.value;
    }
    operator int() {return value;}
};  
    Integer Integer::operator[](Integer index) {
        Integer* pI;
        int i = (int)index;
        return pI[i];
    }
    Integer Integer::operator+(int i) {
        return value += i;    
    }
    
    bool operator== (Integer& K,int i) {
        return K.getValue() == i;
    }
    bool operator< (Integer& K, int i) {
        return K.getValue() < i;
    }

Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(-1);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

int main(int argc, char* argv[]) {

}*/

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

Champion::Champion(int _id, int _health, int _damage)
{
    // Hint: set the corresponding passed values to id, heath, and damage
    // Hint: We have a static variable for alive champion counting!
    id = _id;
    heath = _health;
    damage = _damage;
    numberOfAliveChampions++;
}

Champion::~Champion()
{
    // Think: What must be done when the the object is destroyed?
    // Hint: We have a static variable for alive champion counting!
    numberOfAliveChampions--;
}
/* This champion attack another champion, the victim will lose an amount of health
equal to the attacker damage, return true if the victim dies after being attacked */
bool Champion::attack(Champion &_victim)
{
    _victim.heath = _victim.heath - Champion::damage;
    if (_victim.heath <= 0)
        return 1;
    else
        return 0;
}

int Champion::getHeath()
{
    if (this->heath < 0)
        return 0;
    else
        return this->heath;
}

int Champion::getNumberOfAliveChampions()
{ // Why static? What is a static method?
    return numberOfAliveChampions;
}

int Champion::numberOfAliveChampions = 0;

/* For each event, if event is true then the champion A attack the champion B and vise versa.
Return 1 if the champion A killed the champion B, return -1 if the champion B killed the champion A,
or return 0 if no one dies after the fight. Please note that, to mark that a champion is killed,
you have to delete that champion object and set the corresponding pionter to NULL*/
int fight(Champion *&a, Champion *&b, bool *eventList, int numberOfEvent)
{
    for (int i = 0; i < numberOfEvent; i++)
    {
        if (1 == eventList[i])
        {
            if ((*a).attack(*b))
            {
                delete b;
                b = NULL;
                return 1;
            }
        }
        else
        {
            if ((*b).attack(*a))
            {
                delete a;
                a = NULL;
                return -1;
            }
        }
    }
    return 0;
}

struct Match
{
    int indexOfA;
    int indexOfB;
    int numberOfEvents;
    bool *eventList;
};

/* There are many matches, in each match, the two champion will fight with each other */
void combat(Champion **championList, int numberOfChampions, Match *matchList, int numberOfMatches)
{
    for (int i = 0; i < numberOfChampions; i++)
    {
        if (championList[matchList[i].indexOfA] != NULL && championList[matchList[i].indexOfB] != NULL)
            fight(championList[matchList[i].indexOfA], championList[matchList[i].indexOfB], matchList[i].eventList, matchList[i].numberOfEvents);
    }
}

/*int main(int argc, char* argv[]) {
    ifstream fileIn("lab7.txt",ios::in);
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
    return 0;
}
*/

/*class Integer {
	int value;
public:
    //Prototypes only
    Integer(double s) {value = (int)s;}
    void toString(char*&);
    char* tochar(int,char*);
    int getValue(){return value;}
    char* temp = new char [999];
};
void Integer::toString(char*& c) {
    int j = getValue();
    sprintf(temp, "%d", j);
    c = temp;
}


void process(double d) {
	Integer i = d;
	char* c = NULL;
	i.toString(c);
	cout << c;
	delete[] c;
}


int main() {
    process(685.412);
}
*/

#pragma region Classes definition
/**
 *	Classes definition
*/

class Coordinator
{ //singleton pattern: create only 1 instance
protected:
    class SmartPointer
    {
        Coordinator *ptr;
        bool haveToDeleteMem;

    public:
        SmartPointer();
        SmartPointer(const SmartPointer &_obj);
        SmartPointer(Coordinator *_ptr);
        static SmartPointer instancePtr;
        bool *availableServiceSlot;
        int numberOfServiceSlot;
        ;
        Coordinator *operator=(Coordinator *_ptr);
        Coordinator *operator=(const SmartPointer &_obj);
        bool operator==(Coordinator *_ptr);
        Coordinator *operator->();
        Coordinator &operator*();
        operator Coordinator *();
        ~SmartPointer();
    };
    static SmartPointer instancePtr;
    bool *availableServiceSlot;
    int numberOfServiceSlot;
    int recentlyGot;
    Coordinator();
    Coordinator(const Coordinator &obj) = delete;
    Coordinator &operator=(const Coordinator &obj) = delete;

public:
    static Coordinator *getInstance();
    ~Coordinator();
    void init(int _numberOfServiceSlot);
    int getSlot();
    void giveBack(int _slotNumber);
};

Coordinator::SmartPointer Coordinator::instancePtr = NULL;
#pragma endregion Classes definition

#pragma region Coordinator::SmartPointer subclass impelentation
/**
 *	Coordinator::SmartPointer subclass definition
*/

/* This default constructor initializes the member "this->ptr" with NULL value and denotes that
this object is the original one, the destructor has to delete the data at the memory block 
that the "this->ptr" pointer point to. */
Coordinator::SmartPointer::SmartPointer()
{
    ptr = NULL;
    haveToDeleteMem = 1;
}

/* This copy constructor DOES NOT perform a deep copy operation, the "this->ptr" pointer is initialized
to the same value with the "_obj.ptr". Because this is a copy constructor, the created object is a copy of
another object, so the destructor MUST NOT delete the memory that the "this->ptr" pointer point to. */
Coordinator::SmartPointer::SmartPointer(const SmartPointer &_obj)
{
    this->ptr = _obj.ptr;
    haveToDeleteMem = false;
}

/* This constructor initializes the member "this->ptr" to the same value with  "_ptr" and denotes
 that this object is the original one, the destructor has to delete the data at the memory block 
that the "this->ptr" pointer point to. */
Coordinator::SmartPointer::SmartPointer(Coordinator *_ptr)
{
    ptr = _ptr;
    haveToDeleteMem = true;
}

/* This assign operator first deletes the memory block that the "this->ptr" pointer point to 
and then assigns the passed value to "this->ptr" pointer. */
Coordinator *Coordinator::SmartPointer::operator=(Coordinator *_ptr)
{
    delete this->ptr;
    this->ptr = _ptr;
    return this->ptr;
}

Coordinator *Coordinator::SmartPointer::operator=(const SmartPointer &_obj)
{
    this->ptr = _obj.ptr;
    haveToDeleteMem = false;
    return this->ptr;
}

/* This operator simply checks if the passed value is equal to the value stored in "this->ptr" pointer. */
bool Coordinator::SmartPointer::operator==(Coordinator *_ptr)
{
    return (this->ptr == _ptr);
}

/* Structure dereference operator */
Coordinator *Coordinator::SmartPointer::operator->()
{
    return this->ptr;
}

/* Pointer dereference operator */
Coordinator &Coordinator::SmartPointer::operator*()
{
    return *this->ptr;
}

/* Typecast operator */
Coordinator::SmartPointer::operator Coordinator *()
{
    return this->ptr;
}

/* This destructor checks if it has to delete the memory block that the "this->ptr" pointer point to.
If yes, it deletes that memory block and then set the "this->ptr" pointer" to NULL. */
Coordinator::SmartPointer::~SmartPointer()
{
    if (haveToDeleteMem)
    {
        delete ptr;
        ptr = NULL;
    }
}
#pragma endregion Coordinator::SmartPointer subclass impelentation

#pragma region Coordinator class implementation
/**
 *	Coordinator class implementation
*/

/* The default constructor initializes the "instancePtr" pointer to NULL
and sets the "recentlyGot" member to -1 (the value indicating that no service slot has been allocated) */
Coordinator::Coordinator()
{
    Coordinator::instancePtr = NULL;
    this->recentlyGot = -1;
}

/* This class destructor deletes the dynamic memory block that is pointed to
by the "this->availableServiceSlot" pointer. */
Coordinator::~Coordinator()
{
    delete[](this->availableServiceSlot);
}

/* "Coordinator::instancePtr" is a smart pointer, it can be used as a usual pointer.
Write the code to check if it is NULL or not. If it is NULL, create a new Coordinator
and then return the pointer pointing to it. If it is not NULL,  just simply return its value.
This helps control that only one object of the "Coordinator" class is created during the runtime */
Coordinator *Coordinator::getInstance()
{
    if (instancePtr == NULL)
    {
        instancePtr = new Coordinator;
    }
    return instancePtr;
}

/* Allocate an array of boolean with the size of "_numberOfServiceSlot" and then 
assign its address to the "this->availableServiceSlot" pointer.
Please note that all the service slots are available at first. */
void Coordinator::init(int _numberOfServiceSlot)
{
    bool *arr = new bool[_numberOfServiceSlot];
    for (int i = 0; i < _numberOfServiceSlot; i++)
    {
        arr[i] = true;
    }
    this->availableServiceSlot = arr;
}

/* Return the nearest available slot from the recently got */
int Coordinator::getSlot()
{
    for (int i = this->recentlyGot + 1; i < this->numberOfServiceSlot; i++)
    {
        if (this->availableServiceSlot[i])
        {
            this->availableServiceSlot[i] = false;
            this->recentlyGot = i;
            return i;
        }
    }
    for (int i = 0; i <= this->recentlyGot; i++)
    {
        if (this->availableServiceSlot[i])
        {
            this->availableServiceSlot[i] = false;
            this->recentlyGot = i;
            return i;
        }
    }
    return -1;
}

/* Mark that the slot indexed _slotNumber is available */
void Coordinator::giveBack(int _slotNumber)
{
    if (_slotNumber < 0 || _slotNumber > this->numberOfServiceSlot - 1)
        return;
    this->availableServiceSlot[_slotNumber] = true;
}

#pragma endregion Coordinator class implementation

class TimePoint
{
public:
    const int timeStamp;
    int *const eventList;
    const int numberOfEvents;
    TimePoint(int _timeStamp, int _numberOfEvents) : timeStamp(_timeStamp), eventList(new int[_numberOfEvents]), numberOfEvents(_numberOfEvents) {}
    TimePoint(const TimePoint &_obj) : timeStamp(_obj.timeStamp), eventList(new int[_obj.numberOfEvents]), numberOfEvents(_obj.numberOfEvents)
    {
        for (int i = 0; i < _obj.numberOfEvents; i++)
            this->eventList[i] = _obj.eventList[i];
    }
    TimePoint &operator=(const TimePoint &_obj) = delete;
    ~TimePoint() { delete[] eventList; }
};

void process(int _numberOfTimeSlot, vector<TimePoint> _timePoint)
{
    int numberOfTimePoints = _timePoint.size();
    if (numberOfTimePoints == 0)
        return;
    Coordinator &coordinator = *(Coordinator::getInstance());
    coordinator.init(_numberOfTimeSlot);
    for (int i = 0; i < numberOfTimePoints; i++)
    {
        for (int j = 0; j < _timePoint[i].numberOfEvents; j++)
        {
            if (_timePoint[i].eventList[j] == -1)
                coordinator.getSlot();
            else
                coordinator.giveBack(_timePoint[i].eventList[j]);
        }
    }
}

int main(int argc, char *argv[])
{
    vector<TimePoint> timePoint;
    ifstream fileIn("lab7.text", ios::in);
    string line;
    getline(fileIn, line);
    int numberOfTimeSlot = stoi(line);
    int timeStamp;
    int numberOfEvents;
    while (!fileIn.eof())
    {
        getline(fileIn, line);
        if (line.length() == 0)
            continue;
        stringstream ss(line);
        ss >> timeStamp >> numberOfEvents;
        TimePoint temp(timeStamp, numberOfEvents);
        for (int i = 0; i < numberOfEvents; i++)
        {
            ss >> temp.eventList[i];
        }
        timePoint.push_back(temp);
    }
    process(numberOfTimeSlot, timePoint);
    Coordinator &coordinator = *(Coordinator::getInstance());
    cout << coordinator.getSlot();
    fileIn.close();
    return 0;
}

/*class CaesarMessage {
	char* textBuffer;
public:
	CaesarMessage();
	CaesarMessage(CaesarMessage& obj);
	~CaesarMessage();
	void encode(const char* _message, int _shift);
	void decode(int _shiftKey, char*& _textContainer);
};

CaesarMessage::CaesarMessage() {
}

CaesarMessage::CaesarMessage(CaesarMessage& obj) {
    textBuffer = new char [strlen(obj.textBuffer)+1];
    strcpy(textBuffer,obj.textBuffer);
}

CaesarMessage::~CaesarMessage() {	
    delete[] this->textBuffer;
	this->textBuffer = NULL;
}

void CaesarMessage::encode(const char* _message, int _shift) {
    int length = strlen(_message);
    char* fixedMessage = new char [strlen(_message)];
    char* textBuffed = new char [strlen(_message)];
    for (int i = 0; i < length; i++) {
        if ( (int)'A' <= _message[i] && (int)'Z' >= _message[i]) fixedMessage[i] = _message[i] + 32;
        else fixedMessage[i] = _message[i];
    }
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (fixedMessage[i] >= (int)'a' && fixedMessage[i] <= (int)'z') {
            textBuffed[index] = fixedMessage[i];
            index++;
        }
    }
    for (int i = 0; i < index; i++) {
        int num = (int)textBuffed[i] + _shift; 
        if (num > 122) textBuffed[i] = 96 + (num - 122);
        else textBuffed[i] = num;
    }
    textBuffer = textBuffed;
    delete [] fixedMessage;
    fixedMessage = NULL;
}

void CaesarMessage::decode(int _shiftKey, char*& _textContainer) {
    char* textContain = new char [strlen(textBuffer)+1];
    for (int i = 0; i < strlen(textBuffer); i++) {
        int num = (int) textBuffer[i] - _shiftKey;
        if (num < 97) textContain[i] = 122 - (96 - num);
        else textContain[i] = num;
    }   
    textContain[strlen(textBuffer)] = '\0';
    _textContainer = textContain;
}

void process(CaesarMessage msg, int shiftKey, char*& container) {
    msg.decode(shiftKey, container);
}

int main(int argc, char* argv[]) {
    ifstream fileIn("lab7.txt",ios::in);
        int shift;
        fileIn >> shift;
        string line;
        string inputString;
        while (!fileIn.eof()) {
            getline(fileIn, line);
            inputString += line;
        }
        char* plainText = new char[strlen(inputString.c_str()) + 1];
        strcpy(plainText, inputString.c_str());
        char* decodedText;
        {
            CaesarMessage msg;
            msg.encode(plainText, shift);
            process(msg, shift, decodedText);
        }
        cout << decodedText;
        delete[] decodedText;
        delete[] plainText;
        fileIn.close();
    // Endsection: read testcase
    //------------------------------------
    return 0;
}*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07004_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

//---------------------------------------------------------------------------
/**
* CaesarMessage class definition
*/
class CaesarMessage
{
    char *textBuffer;

public:
    CaesarMessage();
    CaesarMessage(CaesarMessage &obj);
    ~CaesarMessage();
    void encode(const char *_message, int _shift);
    void decode(int _shiftKey, char *&_textContainer);
};

/**
* CaesarMessage class implementation
*/

/* The default constructor */
CaesarMessage::CaesarMessage()
{
}

/* The copy constructor */
CaesarMessage::CaesarMessage(CaesarMessage &obj)
{
    textBuffer = new char[strlen(obj.textBuffer) + 1];
    strcpy(textBuffer, obj.textBuffer);
}

/* The destructor */
CaesarMessage::~CaesarMessage()
{
    /* You have to tidy the dynamic memory, right?
	But, wait! What will happen if the textBuffer has been deleted already?
	Can that problem happen? When, why? And what is the solution? */
    delete[] this->textBuffer;
    this->textBuffer = NULL;
}

/* Encode the input message and then store the result in the textBuffer */
void CaesarMessage::encode(const char *_message, int _shift)
{
    char *textBuf = new char[strlen(_message)];
    int num = 0;
    for (int i = 0; i < strlen(_message); i++)
    {
        if (_message[i] >= 'A' && _message[i] <= 'Z')
        {
            textBuf[num++] = _message[i] + 32;
        }
        if (_message[i] >= 'a' && _message[i] <= 'z')
        {
            textBuf[num++] = _message[i];
        }
    }

    char *temp = new char[strlen(textBuf)];
    for (int i = 0; i < num; i++)
    {
        if ((textBuf[i] + _shift) > (int)'z')
        {
            temp[i] = (int)textBuf[i] + _shift - 'z' + 'a' - 1;
        }
        else
        {
            temp[i] = int(textBuf[i]) + _shift;
        }
    }
    temp[strlen(textBuf)] = '\0';
    textBuffer = temp;
    delete[] textBuf;
    textBuf = NULL;
}

/* Decode the textBuffer content and then store the result in the textContainer */
void CaesarMessage::decode(int _shiftKey, char *&_textContainer)
{
    char *_textCon = new char[strlen(textBuffer) + 1];
    for (int i = 0; i < strlen(textBuffer); i++)
    {
        if ((textBuffer[i] - _shiftKey) < (int)'a')
        {
            _textCon[i] = (int)textBuffer[i] - _shiftKey + 'z' - 'a' + 1;
        }
        else
        {
            _textCon[i] = (int)textBuffer[i] - _shiftKey;
        }
    }
    _textCon[strlen(textBuffer)] = '\0';
    _textContainer = _textCon;
}

/* Notice this function */
void process(CaesarMessage msg, int shiftKey, char *&container)
{
    msg.decode(shiftKey, container);
}
/*int main(int argc, char *argv[])
{
    ifstream fileIn("lab7.txt", ios::in);
    int shift;
    fileIn >> shift;
    string line;
    string inputString;
    while (!fileIn.eof())
    {
        getline(fileIn, line);
        inputString += line;
    }
    char *plainText = new char[strlen(inputString.c_str()) + 1];
    strcpy(plainText, inputString.c_str());
    char *decodedText;
    {
        CaesarMessage msg;
        msg.encode(plainText, shift);
        process(msg, shift, decodedText);
    }
    cout << decodedText;
    delete[] decodedText;
    delete[] plainText;
    fileIn.close();
  // system("pause");
    return 0;
}*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <cstdint>
using namespace std;

class Serializable
{
public:
    /* Separate the value stored in the object into bytes then 
	store those bytes in the _byteBuffer, most significant byte first.
	Finally, return the number of bytes in the _byteBuffer */
    virtual size_t serialize(uint8_t *&_byteBuffer) = 0;
};

class ToTextConvertible
{
public:
    /* Convert the value stored in the object to text then store its characters 
	in the _textBuffer. Finally, return the number of characters in the _textBuffer */
    virtual size_t convertToText(char *&_textBuffer) = 0;
};

/*
 * Integer class implementation
*/
class Integer : public Serializable, public ToTextConvertible
{
    int value;

public:
    Integer(int k) { value = k; }
    size_t serialize(uint8_t *&_byteBuffer)
    {
        int binaryNum[1024];
        size_t numberOfBin = 4;
        int val = this->value;
        for (int i = 0; i < 1024; i++)
        {
            binaryNum[i] = 0;
        }
        int i = 0;
        while (val > 0)
        {
            binaryNum[i] = val % 2;
            val = val / 2;
            i++;
        }
        i = numberOfBin * 8;
        int index = i - 1;
        int Binary[numberOfBin];
        uint8_t *tempByte = new uint8_t[numberOfBin];
        for (int count = 0; count < numberOfBin; count++)
        {
            int temp[8];
            for (int j = 0; j < 8; j++)
            {
                temp[j] = binaryNum[index--];
            }
            Binary[count] = 0;
            for (int j = 0; j < 8; j++)
            {
                Binary[count] += temp[j] * pow(2, 8 - (j + 1));
            }
            tempByte[count] = (uint8_t)Binary[count];
        }
        tempByte[numberOfBin] = '\0';
        _byteBuffer = tempByte;
        return numberOfBin;
    }
    size_t convertToText(char *&_textBuffer)
    {
        char *temp = new char;
        sprintf(temp, "%d", value);
        int length = strlen(temp);
        temp[length] = '\0';
        _textBuffer = temp;
        return strlen(_textBuffer);
    }
};

void process(int value)
{
    Integer integer(value);
    uint8_t *buffer;
    char *text;
    int bufferSize = integer.serialize(buffer);
    integer.convertToText(text);
    cout << bufferSize << '\n';
    cout << strlen(text) << '\n';
    cout << text << endl;
    for (int i = 0; i < bufferSize; i++)
    {
        cout << setbase(16) << (int)buffer[i];
        if (i < bufferSize - 1)
            cout << " ";
    }
    delete[] buffer;
    delete[] text;
}

/*int main() {
    process (9999);
}*/
