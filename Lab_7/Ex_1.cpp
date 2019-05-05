#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <vector>
#define FILENAME "07001_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the list:
{"include", "vector"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer
{
    int value;

public:
    // The constructor
    Integer(int _value);

    // The getter
    int getValue();

    //The setter
    void setValue(int _value);
};

int Integer::getValue(){
    return value;
}
void Integer::setValue(int _value){
    value = _value;
}
Integer::Integer(int _value){
    value = _value;
}

/**
* Student implement Integer's methods here
*/

void process(vector<Integer> integerVector)
{
    int numberOfElements = integerVector.size();
    int temp;
    int count = 1;
    while (count != 0)
    {
        count = 0;
        for (int i = 0; i < numberOfElements - 1; i++)
        {
            if (integerVector[i].getValue() > integerVector[i + 1].getValue())
            {
                count++;
                temp = integerVector[i].getValue();
                integerVector[i].setValue(integerVector[i + 1].getValue());
                integerVector[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << integerVector[i].getValue();
        if (i < numberOfElements - 1)
            cout << " ";
    }
}

int main(int argc, char *argv[])
{
    ifstream fileIn("inp.txt",ios::in);
        vector<Integer> integerVector;
        int temp;
        while (!fileIn.eof())
        {
            fileIn >> temp;
            integerVector.push_back(Integer(temp));
        }
        process(integerVector);
    fileIn.close();
    return 0;
}