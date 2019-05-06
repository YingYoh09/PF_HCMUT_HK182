/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07006_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun Apr 28 18:05:54 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <cstdint>
#define FILENAME "07006_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

/*
 * Interface definitions
*/

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
    int numberOfBytes;

public:
    Integer(int _value) { value = _value; }
    size_t serialize(uint8_t *&_byteBuffer);
    size_t convertToText(char *&_textBuffer);
};

size_t Integer::serialize(uint8_t *&_byteBuffer) {
    int i = value;
    int temp = value;
    numberOfBytes = 0;
    while (i != 0){
        i = i >> 8;
        numberOfBytes++;
    }
    _byteBuffer = new uint8_t[numberOfBytes];
    for (i = numberOfBytes - 1; i >= 0; i--)
    {
        _byteBuffer[i] = int (value & 0xFF);
        value = value >> 8;
    }
    value = temp;
    return numberOfBytes;
}
size_t Integer::convertToText(char *&_textBuffer){
    int temp = value;
    int scs;
    for (scs = 0; temp > 0; scs++)
    {
        temp = temp / 10;
    }
    temp = value;
    _textBuffer = new char[scs+1];
    for (int i = scs - 1; i >= 0; i--)
    {
        _textBuffer[i] = '0' + temp % 10;
        temp = temp / 10;
    }
    _textBuffer[scs] = '\0';
    return scs;
}


void process(int value)
{
    Integer integer(value);
    uint8_t *buffer;
    char *text;
    int bufferSize = integer.serialize(buffer);
    integer.convertToText(text);
    cout << text << endl;
    for (int i = 0; i < bufferSize; i++)
    {
        cout << (int)buffer[i];
        if (i < bufferSize - 1)
            cout << " ";
    }
    delete[] buffer;
    delete[] text;
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        int value;
        fileIn >> value;
        process(value);
        fileIn.close();
        system("pause");
    return 0;
}
