#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

void printBlockchainStructure(int k)
{
	if (k < 0){
		cout << "[]";
		return;
	}
	int n = 2*k;
	double A[3];
	A[0] = 0;
	A[1] = 1;
	for (int i = 1; i <= n; i+=2)
	{
		if (i != 1)	A[i % 3] = A[(i - 1) % 3] * 12 + A[(i - 2) % 3];
		A[(i + 1) % 3] = A[(i) % 3] * 12 + A[(i - 1) % 3];
		cout << setprecision(0) << fixed;
		cout << "[" << A[i % 3] << " " << A[(i + 1) % 3] << "]";
		if (i < n - 2)
			cout << "-";
	}
	
}

int main(int narg, char **argv)
{
	ifstream ifs("inp.txt",ios::in);

	int number;
	string line;

	for (int count = 0; ifs.good() && count < 1; count++)
	{
		getline(ifs, line);
		switch (count)
		{
		case 0:
			number = stoi(line);
			break;
		default:
			break;
		}
	}

	ifs.close();

	printBlockchainStructure(number);
	system("pause");
	return 0;
}
