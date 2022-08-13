#include <iostream>
using namespace std;

void knapsack1_0(int knapsack, int weight[], int value[], int size) {

    int knapsackTable[size + 2][knapsack + 2];

    knapsackTable[0][0] = -1;
    knapsackTable[1][0] = 0;

    for(int i = 1; i < knapsack + 2; i++) {
        knapsackTable[0][i] = i - 1;
    }

    for(int i = 2; i < size + 2; i++) {
        knapsackTable[i][0] = weight[i - 2];
    }    


    for(int i = 1; i < size + 2; i++) {
        for(int j = 1; j < knapsack + 2; j++) {

            if(knapsackTable[0][j] == 0 || knapsackTable[i][0] == 0 ) {
                knapsackTable[i][j] = 0;
                continue;
            }

            if(knapsackTable[0][j] < knapsackTable[i][0]) {
                knapsackTable[i][j] = knapsackTable[i - 1][j];  
                continue;
            }

            knapsackTable[i][j] = max(knapsackTable[i - 1][j], value[i - 2] + ( knapsackTable[i - 1][ (knapsackTable[0][j] - knapsackTable[i][0]) + 1 ]) ) ;
        }
    }
    

    //traversal

     for(int i = 0; i < size + 2; i++) {
        for(int j = 0; j < knapsack + 2; j++) {
            cout <<  knapsackTable[i][j] << "   ";
        }

        cout << endl;
    }
}


int main() {

    int k = 10;
    int w[4] = {1, 3, 4, 6};  
    int v[4] = {20, 30, 10, 50};

    knapsack1_0(k, w, v, 4);

    return 0;
}