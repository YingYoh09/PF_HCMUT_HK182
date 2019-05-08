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

    char *temp = new char[strlen(_message)];
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
    temp[num] = '\0';
    textBuffer = temp;
    delete[] textBuf;
    textBuf = NULL;
}

/* Decode the textBuffer content and then store the result in the textContainer */
void CaesarMessage::decode(int _shiftKey, char *&_textContainer)
{
    char* _textCon = new char[strlen(textBuffer) + 1];
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
int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt", ios::in);
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
}
