//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#include "core.h"

using namespace std;

int numberOfRecord = -1;

void PrintOutput(const char *pRequest, void *pData, void *&pOutput, int N)
{
	cout << pRequest << ":";
	int *pInt = (int *)pOutput;
	for (int i = 0; i < N; ++i)
	{
		cout << ' ' << *pInt++;
	}
	cout << '\n';
	free(pOutput);
}

void Initialization()
{
	// TODO: Please implement the initialization step if it is required
	//       for your program. You can ignore this one if you don't have
	//       anything to initialize.
}

void Finalization()
{
	// TODO: Please implement this finalization step if you have to clean up
	//       the application before exiting. Please ignore if you don't have
	//       anything to do before exiting.
	// NOTE: Any data that you allocated MUST BE CLEAN UP
}

void LoadData(const char *pFName, void *&pData)
{
	ifstream ifs(pFName, ios::in);
	string line;
	while (!ifs.eof())
	{
		getline(ifs, line);
		numberOfRecord++;
	}
	ifs.seekg(0);
	pData =(Record*) malloc(numberOfRecord*sizeof(Record));
	Record *arr = (Record *)pData;
	//get menu name
	getline(ifs, line);deleteSpace(line);
	int commaPosition, index = 0;
	int a[10];
	while (line.length() > 0)
	{
		commaPosition = line.find(',', 0);
		if (-1 == commaPosition)
			break;
		a[index++] = getID(line.substr(0, commaPosition));
		line = line.substr(commaPosition + 1);
	}
	a[index++] = getID(line.substr(0, commaPosition));
	//get number data
	double temp[10];
	for (int i = 0; i < numberOfRecord; i++)
	{
		getline(ifs, line);
		deleteSpace(line);
		int commaPosition, index = 0;
		while (line.length() > 0)
		{
			commaPosition = line.find(',', 0);
			if (-1 == commaPosition)	break;
			temp[index++] = atof(line.substr(0, commaPosition).c_str());
			line = line.substr(commaPosition + 1);
		}
		temp[index++] = atof(line.substr(0, commaPosition).c_str());
		arr[i].readData(temp[a[0]], temp[a[1]], temp[a[2]], temp[a[3]], temp[a[4]], temp[a[5]], temp[a[6]], temp[a[7]], temp[a[8]]);
	}
	ifs.close();
}

void ReleaseData(void *&pData)
{
	free(pData);
}

void ProcessRequest(const char *pRequest, void *pData, void *&pOutput, int &N)
{
	// TODO: Please implement this function to process requests from client.
	//       The reuqest is given in form of a string pointed by pRequest.
	//       The data that you stored if pointed by pData.
	//       The output MUST BE STORED in the memory pointed by pOutput.
	//       N is the number of integers in the output.
	int i = 0;
	N = 0;
	pOutput = (int *)malloc(5 * sizeof(int) + 1);
	int *pInt = (int *)pOutput;
	string req[5];
	int inp = 0;

	while (pRequest[i]==' ') i++;
	if (pRequest[i]=='C'){
		pInt[N++] = numberOfRecord;
	}
	else if (pRequest[i] == 'D')
	{
		i += 3;
		while (i < strlen(pRequest))
		{
			req[inp++] = getReq(pRequest, i);
			i++;
		}
		Request_DI((Record *)pData, pInt, N, req[0], getID(req[1]));
	}
	else if (pRequest[i] == 'H')
	{
		i += 3;
		while (i < strlen(pRequest))
		{
			req[inp++] = getReq(pRequest, i);
			i++;
		}
		Request_HI((Record *)pData, pInt, N, getID(req[0]), stoi(req[1]), stoi(req[2]), stoi(req[3]));
	}
}

string getReq(const char * pRequest, int &i){
	string temp;
	while (i < strlen(pRequest) && pRequest[i] != ' ')
	{
		temp += pRequest[i++];
	}
	return temp;
}

int getID(string s){
	if ("Pregnancies" == s){
		return 0;
	}
	if ("Glucose" == s)
	{
		return 1;
	}
	if ("BloodPressure" == s)
	{
		return 2;
	}
	if ("SkinThickness" == s)
	{
		return 3;
	}
	if ("Insulin" == s)
	{
		return 4;
	}
	if ("BMI" == s)
	{
		return 5;
	}
	if ("DiabetesPedigreeFunction" == s)
	{
		return 6;
	}
	if ("Age" == s)
	{
		return 7;
	}
	if ("Outcome" == s)
	{
		return 8;
	}
	return -1;
}
void deleteSpace(string &s){
	while(s.find(' ',0) != -1){
		s.erase(s.find(' ', 0), 1);
	}
}

void Request_DI(Record *arr, int *&pInt, int &N, string s, int col){
	double mean = 0, res = 0;
	for (int i=0; i < numberOfRecord;i++){
		mean += arr[i].a[col];
	}
	mean = mean / numberOfRecord;
	if ("Mean" == s)
	{
		res = mean;
	}
	else if ("Standard Deviation" == s)
	{
		for (int i = 0; i < numberOfRecord; i++)
		{
			res += pow(arr[i].a[col] - mean,2);
		}
		res /= numberOfRecord;
		res = sqrt(res);
	}
	else if ("Max")
	{
		res = arr[0].a[col];
		for (int i = 1; i < numberOfRecord; i++)
		{
			res = max(res, arr[i].a[col]);
		}
	}
	else if ("Min")
	{
		res = arr[0].a[col];
		for (int i = 1; i < numberOfRecord; i++)
		{
			res = min(res, arr[i].a[col]);
		}
	}
	pInt[N++] = res;
}

void Request_HI(Record *arr, int *&pInt, int &N, int col, int miN, int maX, int step){
	int count = 0;
	for (int i = miN; i < maX; i += step)
	{
		pInt[count++] = arr[i].a[col];
	}
	cout << "asdasd";
}