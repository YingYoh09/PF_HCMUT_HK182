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

void LoadData(const char*, void* &);
void ReleaseData(void* &);

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &);
void PrintOutput(const char* pRequest, void* pData, void* &pOutput, int);

struct Record {
    // TODO: Please define the detail struct for storing a record here
    public:
        int pregnancies, glucose, bloodPressure, skinThickness;
        int insulin, BMI, diabetesPedigreeFunction, age, outcome;
    public:
        //pregnancies, glucose, bloodPressure, skinThickness,insulin, BMI, diabetesPedigreeFunction, age, outcome
        Record(int a1; int a2; int a3; int a4; int a5; int a) {}
} record;

struct RecManager {
    // TODO: Please define the detail of this struct so that you can manage
    //       the records that you loaded from given the file. If you don't need
    //       such a struct, you can ignore or delete this one.
};

#endif //A02_CORE_H
