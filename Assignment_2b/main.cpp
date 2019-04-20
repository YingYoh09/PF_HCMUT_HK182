#include "musketeer.h"

int main(int argc, char** argv) {
    string filename = "input.txt";
        int R, N, ID, M;
        int* E;

        int nEvents = readFile(filename, R, N, ID, M, E);
        
        if (nEvents >= 0)
            advanture(R, N, ID, M, E, nEvents);
    return 0;
}