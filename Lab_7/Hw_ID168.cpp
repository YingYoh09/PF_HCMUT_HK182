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
    textBuffer = new char[strlen(obj.textBuffer)];
    for (int i = 0; i < strlen(obj.textBuffer); i++)
    {
        textBuffer[i] = obj.textBuffer[i];
    }
    
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
    /* Guide: Lower case all the characters and then do the shifting.
	Just encode the alphabet, ignore any others */
    int i;
    for (i = 0; i < strlen(_message); i++)
    {
        if (tolower(_message[i]) >= 'a' && tolower(_message[i]) <= 'z')
            i++;
    }
    
    textBuffer = new char[i];
    int num = 0;
    for (int i = 0; i < strlen(_message);i++)
    {
        if (tolower(_message[i]) >= 'a' && tolower(_message[i]) <= 'z'){
            textBuffer[num++] = (tolower(_message[i]) + _shift - 'a') % 26 + 'a';
        }
    }
}

/* Decode the textBuffer content and then store the result in the textContainer */
void CaesarMessage::decode(int _shiftKey, char *&_textContainer)
{
    _textContainer = new char[strlen(textBuffer)];
    int i = 0;
    for (i = 0; i < strlen(textBuffer) && (textBuffer[i]<= 'z' && textBuffer[i]>='a'); i++)
    {
        if ((textBuffer[i] - _shiftKey - 'a')>= 0) {
            _textContainer[i] = (textBuffer[i] - _shiftKey - 'a') % 26 + 'a';
        }
        else {
            _textContainer[i] = (textBuffer[i] - _shiftKey - 'a') + 'z'+1;
        }
    }
    _textContainer[i] = '\0';
}

/* Notice this function */
void process(CaesarMessage msg, int shiftKey, char *&container)
{
    msg.decode(shiftKey, container);
}
int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
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
        system("pause");
        return 0;
}