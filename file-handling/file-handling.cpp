#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main () {

    string line;

    ifstream infile;
    ofstream outfile;
    outfile.open("experiment.txt",  ios::app);
    infile.open("../add-matrices.cpp");

    while(infile) {
        getline(infile, line);
        outfile << line << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}