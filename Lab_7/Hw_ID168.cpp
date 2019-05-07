
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07004_sol.cpp"
    using namespace std;
//------------------------------

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

CaesarMessage::CaesarMessage()
{
}

CaesarMessage::CaesarMessage(CaesarMessage &obj)
{
    textBuffer = new char[strlen(obj.textBuffer) + 1];
    strcpy(textBuffer, obj.textBuffer);
}

CaesarMessage::~CaesarMessage()
{
    delete[] this->textBuffer;
    this->textBuffer = NULL;
}

void CaesarMessage::encode(const char *_message, int _shift)
{
    int length = strlen(_message);
    char *fixedMessage = new char[strlen(_message)];
    char *textBuffed = new char[strlen(_message)];
    for (int i = 0; i < length; i++)
    {
        if ((int)'A' <= _message[i] && (int)'Z' >= _message[i])
            fixedMessage[i] = _message[i] + 32;
        else
            fixedMessage[i] = _message[i];
    }
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if (fixedMessage[i] >= (int)'a' && fixedMessage[i] <= (int)'z')
        {
            textBuffed[index] = fixedMessage[i];
            index++;
        }
    }
    for (int i = 0; i < index; i++)
    {
        int num = (int)textBuffed[i] + _shift;
        if (num > 122)
            textBuffed[i] = 96 + (num - 122);
        else
            textBuffed[i] = num;
    }
    textBuffer = new char[strlen(textBuffed)];
    strcpy(textBuffer, textBuffed);
    delete[] textBuffed;
    textBuffed = NULL;
    delete[] fixedMessage;
    fixedMessage = NULL;
}

void CaesarMessage::decode(int _shiftKey, char *&_textContainer)
{
    _textContainer = new char[strlen(textBuffer) + 1];
    for (int i = 0; i < strlen(textBuffer); i++)
    {
        int num = (int)textBuffer[i] - _shiftKey;
        if (num < 97)
            _textContainer[i] = 122 - (96 - num);
        else
            _textContainer[i] = num;
    }
}

void process(CaesarMessage msg, int shiftKey, char *&container)
{
    msg.decode(shiftKey, container);
}

int main(int argc, char *argv[])
{
    int shift;
    cin >> shift;
    string line;
    string inputString;
    while (!cin.eof())
    {
        getline(cin, line);
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
    // Endsection: read testcase
    //------------------------------------
    return 0;
}