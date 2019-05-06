/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07003b_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat Apr 27 23:01:03 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <vector>
#define FILENAME "07003b_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

#pragma region Classes definition
/**
 *	Classes definition
*/

class Coordinator
{
protected:
    class SmartPointer
    {
        Coordinator *ptr;
        bool haveToDeleteMem;

    public:
        SmartPointer();
        SmartPointer(const SmartPointer &_obj);
        SmartPointer(Coordinator *_ptr);
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
    ptr = _obj.ptr;
    haveToDeleteMem = 0;
}

/* This constructor initializes the member "this->ptr" to the same value with  "_ptr" and denotes
 that this object is the original one, the destructor has to delete the data at the memory block 
that the "this->ptr" pointer point to. */
Coordinator::SmartPointer::SmartPointer(Coordinator *_ptr)
{
    ptr = _ptr;
    haveToDeleteMem = 1;
}

/* This assign operator first deletes the memory block that the "this->ptr" pointer point to 
and then assigns the passed value to "this->ptr" pointer. */
Coordinator *Coordinator::SmartPointer::operator=(Coordinator *_ptr)
{
    delete this->ptr;
    this->ptr = _ptr;
}

/* This operator is the same with the copy constructor, it is implicitly called when initializing
an object using the assign operator. So you just simply copy the body of the copy constructor to this
Todo segment */
Coordinator *Coordinator::SmartPointer::operator=(const SmartPointer &_obj)
{
    ptr = _obj.ptr;
    haveToDeleteMem = 0;
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
    if (haveToDeleteMem){
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
    delete[] this->availableServiceSlot;
}

/* "Coordinator::instancePtr" is a smart pointer, it can be used as a usual pointer.
Write the code to check if it is NULL or not. If it is NULL, create a new Coordinator
and then return the pointer pointing to it. If it is not NULL,  just simply return its value.
This helps control that only one object of the "Coordinator" class is created during the runtime */
Coordinator *Coordinator::getInstance()
{
    if (instancePtr == NULL){
        instancePtr =new Coordinator;
        return instancePtr;
    }
    else
        return instancePtr;
}

/* Allocate an array of boolean with the size of "_numberOfServiceSlot" and then 
assign its address to the "this->availableServiceSlot" pointer.
Please note that all the service slots are available at first. */
void Coordinator::init(int _numberOfServiceSlot)
{
    bool *a = new bool[_numberOfServiceSlot];
    availableServiceSlot = a;
    for (int i = 0; i < _numberOfServiceSlot; i++)
    {
        availableServiceSlot[i] = 1;
    }
    
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
    ifstream fileIn("inp.txt", ios::in);
    vector<TimePoint> timePoint;
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