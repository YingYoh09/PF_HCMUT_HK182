//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#ifndef A02_CORE_H
#define A02_CORE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>

/// Prototype declaration
void Initialization();
void Finalization();

void LoadData(const char *, void *&);
void ReleaseData(void *&);

void ProcessRequest(const char *pRequest, void *pData, void *&pOutput, int &);
void PrintOutput(const char *pRequest, void *pData, void *&pOutput, int);

struct Record
{
public:
    double a[9];

public:
    //pregnancies, glucose, bloodPressure, skinThickness,insulin, BMI, diabetesPedigreeFunction, age, outcome
    void readData(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9)
    {
        a[0] = a1;
        a[1] = a2;
        a[2] = a3;
        a[3] = a4;
        a[4] = a5;
        a[5] = a6;
        a[6] = a7;
        a[7] = a8;
        a[8] = a9;
    }
    Record() {}
};

struct RecManager
{
    // TODO: Please define the detail of this struct so that you can manage
    //       the records that you loaded from given the file. If you don't need
    //       such a struct, you can ignore or delete this one.
    int pregnancies, glucose, bloodPressure, skinThickness;
    int insulin, BMI, diabetesPedigreeFunction, age, outcome;
};

//get request trong chuỗi bắt đầu từ i
std::string getReq(const char *, int &i);
int getID(std::string);
void deleteSpace(std::string &);
void Request_DI(Record *, int *&, int &, std::string, int);
void Request_HI(Record *arr, int *&pInt, int &N, int col, int miN, int maX, int step);
#endif //A02_CORE_H
