#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07002_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer
{
	int value;

public:
	Integer(int a):value(a) {}
	Integer(){}
	//so sánh bằng
	bool operator==(int a){
		if (a == value){
			return 1;
		}
		else
			return 0;
	}
	//so sánh bé hơn
	friend bool operator<(const Integer &a1, const Integer &a2);
	friend Integer& operator+(const Integer &a1, const Integer &a2);
	operator int(){
		return value;
	}
	Integer& operator [](Integer &a);
};

Integer& Integer::operator [](Integer &a){
	int i = int(a);
	Integer *pI;
	pI = &a;
	return pI[i];
}

bool operator<(const Integer &a1, const Integer &a2)
{
	return a1.value < a2.value;
}
Integer &operator+(const Integer &a1, int){
	
}
/**
 * Student implement Integer's methods here
*/
Integer max(Integer *arr, Integer numberOfElements)
{
	if (arr == NULL || numberOfElements == 0)
		return Integer(-1);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main(int argc, char *argv[])
{
	
	ifstream fileIn("inp.txt",ios::in);
		int numberOfElements;
		fileIn >> numberOfElements;
		Integer *arr = new Integer[numberOfElements];
		int temp;
		for (int i = 0; i < numberOfElements; i++)
		{
			fileIn >> temp;
			arr[i] = temp;
		}
		cout << max(arr, numberOfElements);
		delete[] arr;
		fileIn.close();
	return 0;
}