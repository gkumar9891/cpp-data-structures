#include <iostream>
#include <fstream>

using namespace std;

int main () {

    ifstream infile ("../add-matrices.cpp");
    ofstream outfile ("../add-matrices.cpp");

    outfile << "Sum";

    return 0;
}